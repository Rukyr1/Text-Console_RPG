#pragma once
#include "Pokemon.h"
//파이리

class Charmander : public Pokemon{
public:
	Charmander(std::string name, int hp, int atk);
	void P_SKill() override;
	void takeDamage(int p_attackPower);
};

