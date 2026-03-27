#include "EnemyPokemon.h"
#include <vector>
#include <cstdlib>
#include <iostream>

//  데이터 구조
struct PokemonData //순서대로 적포켓몬 이름, 레벨, 기술이름, 기술위력 을 받는 데이터.
{
	std::string name;
	int level;
	std::string skillName;
	int skillPower;
};

// 포켓몬 리스트
static std::vector<PokemonData> EnemyList =
{
	{"피카츄", 5, "전기쇼크", 10},
	{"이브이", 4, "몸통박치기", 8},
	{"야돈", 6, "물대포", 7}
};

EnemyPokemon::EnemyPokemon() : Pokemon()
{
	int index = rand() % EnemyList.size(); // 리스트 중에서 랜덤 선택
	PokemonData data = EnemyList[index];

	PName = data.name;// 선택된 포켓몬의 이름을 입력
	PLevel = data.level;//선택된 포켓몬의 레벨을 입력

	// 랜덤 능력치
	PHp = PLevel * (rand() % 11 + 20); //체력을 20부터 30사이의 값을 구해 레벨과 곱하여 정함
	PAttackPower = PLevel * (rand() % 6 + 5);//공격력을 5부터 10사이의 값을 구해 레벨과 곱하여 정함

	// 기술 정보 저장 (멤버 변수 필요)
	skillName = data.skillName;//기술이름
	skillPower = data.skillPower;//기술위력
}

void EnemyPokemon::sKill()
{
	std::cout << PName << "이(가) "
		<< skillName << " 사용! (위력: "
		<< skillPower << ")" << std::endl;
}
