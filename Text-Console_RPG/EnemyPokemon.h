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
	int skill(int skillNum) override;
	std::string getSkill1() { return Pskill1; } //getSkill1()추가 스킬1 이름을 반환
	std::string getSkill2() { return Pskill2; } //getSkill2()추가 스킬2 이름을 반환
	//void GenerateStats(int level);
	//void skill() override;
};
