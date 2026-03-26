#pragma once
#include "Pokemon.h"
//파이리

class Charmander : public Pokemon{
public:
	Charmander();
	void takeDamage(int p_attackPower);
	void P_SKill() override;
};

