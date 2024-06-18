#pragma once
#include "Tower.h"
class TowerWenner : public Tower
{
public:
	TowerWenner();
	Tower* clone() const override { return new TowerWenner(*this); }
	void sayHi() override;
	void sayBye() override;
	void upgrade()override;
};


