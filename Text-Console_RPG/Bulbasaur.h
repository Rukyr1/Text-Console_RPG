#pragma once
#include "Pokemon.h"
//이상해씨

class Bulbasaur : public Pokemon{
public:
	Bulbasaur();
	void takeDamage(int p_attackPower);
	void P_SKill() override;
};

