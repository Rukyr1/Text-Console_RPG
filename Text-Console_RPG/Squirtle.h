#pragma once
#include "Pokemon.h"
//꼬부기

class Squirtle : public Pokemon{
public:
	Squirtle();
	void takeDamage(int p_attackPower);
	void P_SKill() override;
};

