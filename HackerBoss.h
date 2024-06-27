#pragma once
#include "Hacker.h"

class HackerBoss : public Hacker
{
public:
	HackerBoss();
	int attackUtn() override;
	void saySth() override;
};

