#include "Rattata.h"
#include <iostream>
//꼬렛

Rattata::Rattata(int level) : EnemyPokemon()
{
	std::string PName = "꼬렛";
	PLevel = level;

	GenerateStats(level);
}

void Rattata::sKill()
{
	std::cout << "몸통박치기" << std::endl;
	//e_damage(임시) = p_attackPower * 3
}

void Rattata::takeDamage(int p_attackPower) {
	//p_hp = p_hp - p_attackPower;

}
