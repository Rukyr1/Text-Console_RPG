#pragma once
#include "Pokemon.h"
//이상해씨

class Bulbasaur : public Pokemon{
public:
	Bulbasaur(std::string name, int hp, int atk);
	void P_SKill() override;
	void takeDamage(int p_attackPower);
};

