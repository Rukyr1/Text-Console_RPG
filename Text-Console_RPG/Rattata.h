#pragma once
#include "EnemyPokemon.h"
//꼬렛
class Rattata : public EnemyPokemon
{
public:
	Rattata(int level);
	void takeDamage(int p_attackPower);
	void P_SKill() override;
};

