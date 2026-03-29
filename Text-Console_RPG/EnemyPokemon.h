#pragma once
#include "Pokemon.h"
#include <string>

class EnemyPokemon : public Pokemon
{
private:
	std::string skillName;
	int skillPower;

public:
	EnemyPokemon();

	//void GenerateStats(int level);
	//void skill() override;
};
