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
void Level::setMapArray(const int(&mapArray)[22][30]) {
	std::copy(&mapArray[0][0], &mapArray[0][0] + 22 * 30, &_mapArray[0][0]);
}
void Level::setGolden(int golden) { _golden = golden; }
void Level::setEnergy(int energy) { _energy = energy; }
void Level::setMusicPlaying(bool playing) { _musicPlaying = playing; }
void Level::setSound(bool play) { play ? _sound.play() : _sound.pause(); }
void Level::setTowersAvailable(Tower* towerAvailable) { _towersAvailable.push_back(towerAvailable); }
void Level::setActiveTowers(Tower* tower) { _activeTowers.push_back(tower); }
void Level::setSpot(Spot* sp)
{
	for (auto& spot : _spots)
	{
		if (spot->getSpotNumber() == sp->getSpotNumber())
		{
			spot->setOccupied(sp->getIsOccupied());
			spot->setCurrentTower(&sp->getCurrentTower());
			break;
		}
	}
}
void Level::setSpots(int arr[][30], std::vector<Spot*>& spots, int cant) {
	for (int i = 0; i < cant; i++)
	{
		Spot* sp = new Spot();
		spots.push_back(sp);
	}
	//Ubicar spots
	int index = 0;
	for (int x = 0; x < 30; x++)
	{
		for (int y = 0; y < 20; y++)
		{
			if (arr[y][x] == 6 && index < cant)
			{
				spots[index]->setPosition(32 * x, 32 * y);
				spots[index]->setSpotNumber(index + 1);
				index++;
			}
		}
	}
}
void Level::setCurrentSpot(Spot sp) { _currentMenu->setCurrentSpot(sp); }
void Level::setCurrentMenu(TowerMenu* menu) { _currentMenu = menu; }
void Level::setNoCoinsText()
{
	if (!_font.loadFromFile("fuentes/TowerPrice.ttf"))
	{
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


void Level::decreaseEnergy(int amount) {
	_energy -= amount;
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
	int price;
	if (currentSpot.getIsOccupied()) { price = tower->getPriceUpgrade(); }
	else { price = tower->getPrice(); }

	setGolden(getGolden() - price);

	_ui.setText(0, std::to_string(getGolden()));
	currentSpot.setCurrentTower(tower);
	currentSpot.setOccupied(true);
}
void Level::resellTower(Spot& sp) {
	Tower* tower = &sp.getCurrentTower();
	int resaleValue = tower->getSalesValue();
	std::cout << "Valor reventa:" << resaleValue << std::endl;
	setGolden(getGolden() + resaleValue); // Agregar el valor de reventa al oro del jugador
	_ui.setText(0, std::to_string(getGolden()));
	sp.clearCurrentTower(); // Limpiar la torre del spot
	sp.setOccupied(false); // Marcar el spot como no ocupado
	_activeTowers.remove(tower);

}

//void Level::shoot(Bullet* bullet, sf::Vector2f shootingPosition, sf::Vector2f targetPosition)
void Level::shoot(sf::Vector2f shootingPosition, sf::Vector2f targetPosition, int damage, int type, Hacker* hacker)
{
	switch (type)
	{
	case 1:
		_bullets.push_back(new BulletA(shootingPosition, targetPosition, damage));
		break;
	case 2:
		_bullets.push_back(new BulletB(shootingPosition, targetPosition, damage));
		break;
	case 3:
		_bullets.push_back(new BulletC(shootingPosition, targetPosition, damage));
		break;
	case 4:
		_bullets.push_back(new BulletD(shootingPosition, targetPosition, damage));
		break;
	}

	auto it = _bullets.begin();
	while (it != _bullets.end())
	{
		Bullet* bullet = *it;

		if (bullet->getTransform().transformRect(bullet->getBounds()).intersects(hacker->getBounds()))
		{
			hacker->takeDamage(bullet->getDamage());
			std::cout << "Vida Hacker" << hacker->getLife() << std::endl;
			delete bullet;
			it = _bullets.erase(it);
		}
		else
		{
			++it;

		}
	}

	//ACA SE PODRIA PONER LA LOGICA PARA QUE SE BORRE LA BALA
}

void Level::checkLevelCompletion() {
	if (_currentWave == _totalWaves && _enemies.empty()) {
		_finishedLevel = true;
	}
}

void Level::setGameOverText()
{
	if (!_font.loadFromFile("fuentes/TowerPrice.ttf")) {
		throw std::runtime_error("Error al cargar la fuente del Price Menu");
	}
	_gameOver.setFont(_font);
	_gameOver.setCharacterSize(70);
	//_gameOver.setOrigin(_gameOver.getGlobalBounds().width/ 2, _gameOver.getGlobalBounds().height / 2);
	_gameOver.setPosition(300, 250);
	_gameOver.setFillColor(sf::Color(255, 0, 0));
	_gameOver.setString("GAME OVER");

	if (!_textureGameOverSkull.loadFromFile("img/complementarias/Rip.png")) {
		throw std::runtime_error("Error al cargar la calavera de GameOver");
	}
	_gameOverSkull.setTexture(_textureGameOverSkull);
	_gameOverSkull.setPosition(400, 150);
	_gameOverSkull.setScale(0.5, 0.5);
	_gameOverSkull.setOrigin(_gameOverSkull.getGlobalBounds().width / 2, _gameOverSkull.getGlobalBounds().height / 2);
}

void Level::update(sf::Vector2i& mousePosition) {
	checkLevelCompletion();
	if (!getFinisheLevel()) {
		mouseCheck(mousePosition);

		if (_waveClock.getElapsedTime().asSeconds() >= _timeBetweenWaves && _currentWave <= 3) {
			spawnWave(); // Generar una nueva oleada de enemigos
		}

		// Actualizar los enemigos en el nivel
		for (auto& hacker : _enemies) {
			hacker->update(getMapArray());

			if (hacker->getEnd() == true) {
				if (getEnergy()- hacker->attackUtn()>=0) {
					_dying = true;
					decreaseEnergy(hacker->attackUtn());
				}
				else {
					setEnergy(0);
					_flagGameOver = true;
					setGameOverText();
				}
				_ui.setText(1, std::to_string(getEnergy()));
				break; // Si encontramos un enemigo en el final, no necesitamos seguir buscando
			}
			else {
				_dying = false;
			}
		}


		for (auto& spot : _spots)
		{
			for (auto& hacker : _enemies)
			{
				if (spot->getIsOccupied() &&
					spot->getTransform().transformRect((
						spot->getCurrentTower().getBounds())).intersects(hacker->getBounds()
						))
				{
					//std::cout << "COliSIONO" << std::endl;
					if (spot->getCurrentTower().canShoot())
					{
						shoot(spot->getPosition(),
							hacker->getPosition(),
							spot->getCurrentTower().getDamage(),
							spot->getCurrentTower().getType(), hacker);
					}
				}
			}
		}

		for (auto& bullet : _bullets) {
			bullet->update();
		}

		auto itH = _enemies.begin();
		while (itH != _enemies.end()) {
			Hacker* hacker = *itH;
			hacker->update(getMapArray());
			if (hacker->getLife() <= 0) {
				itH = _enemies.erase(itH);
			}
			else {
				++itH;
			}

			for (auto& hacker : _enemies) {
				if (hacker->getEnd() == true) {
					if (getEnergy() - 20 >= 0) {
						_dying = true;
						setEnergy(getEnergy() - 20);
						_ui.setText(1, std::to_string(getEnergy()));
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
		if (getIdLevel() < 4) { // aca digo que solo puede llegar hasta el nivel 4
			std::cout << "NIVEL 2:" << std::endl;
			//Manager::getInstance().setNumberLevel(getIdLevel() + 1); // cambia al siguiente nivel
		}
		else {
			// lógica para cuando se termina el juego, cuando se pasaron todos los niveles
		}
	}
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
	if (!_flagGameOver) {
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
		if (_noCoinsClock.getElapsedTime() < _displayTimeNoCoins && _flagNoCoins) {
			target.draw(_NoCoins, states); // Dibujar el texto
		}
	}
	else {
		target.draw(_gameOverSkull, states);
		target.draw(_gameOver, states);
	}

}