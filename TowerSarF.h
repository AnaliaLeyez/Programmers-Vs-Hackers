#pragma once
#include "Tower.h"
class TowerSarF : public Tower
{
public:
	TowerSarF();
	Tower* clone() const override { return new TowerSarF(*this); }
	void sayHi() override;
	void sayBye() override;
	void upgrade() override;
};

