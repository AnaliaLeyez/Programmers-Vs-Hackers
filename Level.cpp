#include <iostream> //borrar
#include <vector>
#include <list>
#include "SFML/Graphics.hpp"
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "UI.h"
#include "Map.h"
#include "Manager.h"
#include "TowerMenu.h"
#include "Spot.h"
#include "Tower.h"
#include "Level.h"

int Level::getIdLevel() const { return _idLevel; }
bool Level::getFinisheLevel() const { return _finishedLevel; }
UI Level::getUI() const { return _ui; }
Map Level::getMap() const { return *_map; }
int(*Level::getMapArray())[30] { return _mapArray; }
const std::vector<Spot*> Level::getSpots() const { return _spots; }
Spot Level::getCurrentSpot() const { return _currentMenu->getCurrentSpot(); }
Spot Level::getSpotByNumber(int n) const {
	for (auto& spot : _spots) {
		if (spot->getSpotNumber() == n) { return *spot; }
	}
}
TowerMenu Level::getCurrentMenu() const { return *_currentMenu; }
int Level::getGolden() { return _golden; }
int Level::getEnergy() { return _energy; }
sf::SoundBuffer Level::getBuffer() const { return _buffer; }
sf::Sound Level::getSound() const { return _sound; }
bool Level::getMusicPlaying() const { return _musicPlaying; }
sf::Vector2f Level::getHackerStartPosition() const { return _hackerStartPosition; }
const std::list<Tower*> Level::getTowersAvailable() const { return _towersAvailable; }
std::list<Tower*> Level::getActiveTowers() const { return _activeTowers; }

void Level::setIdLevel(int idLevel) { _idLevel = idLevel; }
void Level::setFinishedLevel(bool finished) { _finishedLevel = finished; }
void Level::setUI(const UI& ui) { _ui = ui; }
void Level::setMap(const Map& map) { *_map = map; }
void Level::setMapArray(const int(&mapArray)[20][30]) { std::copy(&mapArray[0][0], &mapArray[0][0] + 20 * 30, &_mapArray[0][0]); }
void Level::setGolden(int golden) { _golden = golden; }
void Level::setEnergy(int energy) { _energy = energy; }
void Level::setMusicPlaying(bool playing) { _musicPlaying = playing; }
void Level::setSound(bool play) { play ? _sound.play() : _sound.pause(); }
void Level::setTowersAvailable(Tower* towerAvailable) { _towersAvailable.push_back(towerAvailable); }
void Level::setActiveTowers(Tower* tower) { _activeTowers.push_back(tower); }
void Level::setSpot(Spot* sp, int n) {
	for (auto& spot : _spots) {
		if (spot->getSpotNumber() == n) {
			spot->setOccupied(sp->getIsOccupied());
			spot->setCurrentTower(sp->getCurrentTower());
			break;
		}
	}
}
void Level::setCurrentSpot(Spot sp) { _currentMenu->setCurrentSpot(sp); }
void Level::setCurrentMenu(TowerMenu* menu) { _currentMenu = menu; }
void Level::setNoCoinsText()
{
	if (!_font.loadFromFile("fuentes/TowerPrice.ttf")) {
		throw std::runtime_error("Error al cargar la fuente del Price Menu \n");
	}
	_NoCoins.setFont(_font);
	_NoCoins.setCharacterSize(70);
	_NoCoins.setOrigin(_NoCoins.getGlobalBounds().getPosition().x / 2, _NoCoins.getGlobalBounds().height / 2);
	_NoCoins.setPosition(250, 250);
	_NoCoins.setFillColor(sf::Color(255, 0, 0));
	_NoCoins.setString("SALDO INSUFICIENTE");

	_noCoinsClock.restart();
	_displayTimeNoCoins = sf::seconds(3);
	_flagNoCoins = false;
}

void Level::mouseCheck(sf::Vector2i& mousePosition)
{
	sf::Vector2f transformedMousePos = getInverseTransform().transformPoint(sf::Vector2f(mousePosition));
	for (auto& spot : _spots)
	{
		//spot->mouseCheck(mousePosition);  //por que si lo hago con esta linea no funciona? 
		// deberia ser un pasamanos igual que lo es con currentMenu e igual que validateClick
		if (spot->getGlobalBounds().contains(transformedMousePos))
			spot->setMouseHover(true);
		else
			spot->setMouseHover(false);
	}
	if (_currentMenu->getIsVisible() && _currentMenu->getGlobalBounds().contains(transformedMousePos))
	{
		_currentMenu->mouseCheck(mousePosition);
	}

}

bool Level::validateSale(Tower* tower, bool firstSale) {
	int	price;
	if (firstSale)
		price = tower->getPrice();
	else
		price = tower->getPriceUpgrade();
	if (price <= getGolden()) {
		_flagNoCoins = false;
		return true;
	}
	_flagNoCoins = true;
	return false;
}
void Level::sell(Tower* tower, Spot& currentSpot) {
	int price = tower->getPrice();
	setGolden(getGolden() - price);
	/*std::cout << "se compro: " << tower->getName() << std::endl;*/
	_ui.setText(0, std::to_string(getGolden()));
	currentSpot.setCurrentTower(tower);
	currentSpot.setOccupied(true);
}

//void Level::shoot(Bullet* bullet, sf::Vector2f shootingPosition, sf::Vector2f targetPosition)
void Level::shoot(Bullet* blt, Hacker* hacker) //ANA
{
	//_bullets.push_back(Bullet(shootingPosition, targetPosition)); //ADRI
	blt->setEnemyPosition(hacker->getPosition());
	_bullets.push_back(blt); //ANA
	
	auto itB = _bullets.begin();
	while (itB != _bullets.end())
	{
		Bullet* bullet = *itB;

		if (bullet->getBounds().intersects(hacker->getBounds()))
		{
			hacker->takeDamage(bullet->getDamage());
			itB = _bullets.erase(itB);
		}
		else
		{
			++itB;
		}
	}
}

void Level::update(sf::Vector2i& mousePosition) {
	if (!getFinisheLevel()) {
		mouseCheck(mousePosition);

		if (_waveClock.getElapsedTime().asSeconds() >= _timeBetweenWaves && _currentWave <= 3) {  /// cambiar el 3 por cantidad de oleadas
			spawnWave(); // Generar una nueva oleada de enemigos
		}
		// Actualizar los enemigos en el nivel
		for (auto& hacker : _enemies) {

			hacker->update(getMapArray());
			//std::cout<< hacker->getPosition().x << " " << hacker->getPosition().y <<std::endl;
			//agregar más lógica para las colisiones
		}

		for (auto& tower : _activeTowers)
		{
			//std::cout << tower._visualRange.getPosition().x << " " << tower._visualRange.getPosition().y << std::endl;

			for (auto& hacker : _enemies)
			{


				// CON ESTE CODIGO VIEJO ENTRA AL IF, CON EL NUEVO NO
				sf::Vector2f posicionTorre = tower->getSprite().getPosition();
				// Obtiene los límites globales del sprite del objetivo
				sf::FloatRect limitesObjetivo = hacker->getSprite().getGlobalBounds();
				// Calcula la posición del centro del sprite del objetivo, que analía me explique que pasa acá.
				sf::Vector2f centroObjetivo( limitesObjetivo.width / 2, limitesObjetivo.height / 2);
				// Calcula la distancia entre los centros de la torre y el objetivo
				float distancia = std::sqrt(std::pow(centroObjetivo.x - posicionTorre.x, 2) + std::pow(centroObjetivo.y - posicionTorre.y, 2));
				float radioTorre = tower->getVisualRange().getRadius();
				if (tower->canShoot())
				{
					if (distancia <= radioTorre) {
						tower->setBullet(tower->getPosition(), hacker->getPosition()); //setBullet deberia usar polimorfismo para que segun la torre se setee la bala deseada
						Bullet* bullet = tower->getBullet(); //problema: al iniciar la bala debo decir de que tipo es y tambien su posicion inicial y direccion
						shoot(bullet, hacker);
					}
				}



				//if (tower->getVisualRange().getGlobalBounds().intersects(hacker->_collisionRect.getGlobalBounds()))
				if (tower->isCollision(*hacker)) 
				{
					if (tower->canShoot()) {
						//shoot(tower->getVisualRange().getPosition(), hacker->_collisionRect.getPosition()); //ADRI
						Bullet* bullet = tower->getBullet();
						bullet->setDirection(hacker->_collisionRect.getPosition());
						bullet->setEnemyPosition(hacker->_collisionRect.getPosition());
						shoot(bullet, hacker);
						//std::cout << hacker->_collisionRect.getPosition().x << " " << hacker->_collisionRect.getPosition().y<< std::endl;
					}
				}


			}
		}
		for (auto& bullet : _bullets) {
			bullet->update();
		}

		auto itH = _enemies.begin();
		while (itH != _enemies.end())
		{
			Hacker* hacker = *itH;
			hacker->update(getMapArray());

			if (hacker->getLife() <= 0)
			{
				itH = _enemies.erase(itH);
			}
			else
			{
				++itH;
			}

			for (auto& hacker : _enemies) {
				if (hacker->getEnd() == true) {
					if (getEnergy() - 20 >= 0) {
						if (hacker->_cooldown > 20) { //configurar los get y set con _cooldown en private
							//if (getEnergy() - 20 >= 0 ) { //hay que dar un margen de tiempo al ataque xq sino resta mucho de golpe
							_dying = true;
							setEnergy(getEnergy() - 20);
							_ui.setText(1, std::to_string(getEnergy()));
							hacker->_cooldown = 0;
						}
						hacker->_cooldown++;
					}
					else {
						_flagGameOver = true;
						setGameOverText();
					}
					break; // Si encontramos un enemigo en el final, no necesitamos seguir buscando
				}
				else {
					_dying = false;
				}
			}

			// Verificar si se ha completado el nivel
			if (_currentWave > 3 && _enemies.empty()) {
				setFinishedLevel(true);
			}
			if (_currentMenu->getIsVisible()) {
				_currentMenu->update(mousePosition);
			}
			
		}
	}
	else {
		if (getIdLevel() < 4) { //aca digo que solo puede llegar hasta el nivel 4
			Manager::getInstance().setNumberLevel(getIdLevel() + 1); //cambia al siguiente nivel
		}
		else {
			//logica para cuando se termina el juego, cuando se pasaron todos los niveles
		}
	}
}


void Level::setGameOverText()
{
	if (!_font.loadFromFile("fuentes/TowerPrice.ttf")) {
		throw std::runtime_error("Error al cargar la fuente del Price Menu");
	}
	_gameOver.setFont(_font);
	_gameOver.setCharacterSize(70);
	_gameOver.setOrigin(_gameOver.getGlobalBounds().getPosition().x / 2, _gameOver.getGlobalBounds().height / 2);
	_gameOver.setPosition(300, 250);
	_gameOver.setFillColor(sf::Color(255, 0, 0));
	_gameOver.setString("GAME OVER");
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	states.transform *= getTransform();
	target.draw(*_map, states);
	_dying ? target.draw(_UTNRed, states) : target.draw(_UTN, states);
	target.draw(_ui, states);
	for (Spot* spot : _spots)
	{
		target.draw(*spot, states);
	}
	for (const auto& hacker : _enemies)
	{
		if (hacker->getLife() > 0) {
			target.draw(*hacker, states);
		}
	}
	if (_currentMenu->getIsVisible())
	{
		target.draw(*_currentMenu, states);
	}

	for (auto& bullet : _bullets)
	{
		target.draw(*bullet, states);
	}

	//NUEVO:
	if (_noCoinsClock.getElapsedTime() < _displayTimeNoCoins && _flagNoCoins) {
		target.draw(_NoCoins, states); // Dibujar el texto
	}

	if (_flagGameOver) {
		target.draw(_gameOver, states);
	}
}