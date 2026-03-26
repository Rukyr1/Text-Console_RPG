#pragma once
#include "Pokemon.h"
//꼬부기

class Squirtle : public Pokemon{
public:
	Squirtle(std::string name, int hp, int atk);
	void P_SKill() override;
	void takeDamage(int p_attackPower);
};

