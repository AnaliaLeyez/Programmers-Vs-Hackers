#pragma once
#include "Tower.h"
class TowerKloster : public Tower
{
public:
	TowerKloster();
	Tower* clone() const override { return new TowerKloster(*this); }
	void sayHi() override;
	void sayBye() override;
	void upgrade() override;
};
