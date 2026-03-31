#pragma once
#include "Pokemon.h"
#include <string>

class EnemyPokemon : public Pokemon
{
private:
	std::string PType; //포켓몬 타입
	std::string Pskill1; //EnemyPokemon.cpp 의 기술이름을 넣기위한 변수
	std::string Pskill2; //EnemyPokemon.cpp 의 기술이름을 넣기위한 변수

public:
	EnemyPokemon();

	//void GenerateStats(int level);
	//void skill() override;
};
