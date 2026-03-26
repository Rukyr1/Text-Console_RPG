#include "Rattata.h"
#include <iostream>
//꼬렛

Rattata::Rattata(int level) : EnemyPokemon()
{
	std::string p_name = "꼬렛";
	p_level = level;

	GenerateStats(level);
}

void Rattata::P_SKill()
{
	std::cout << "몸통박치기" << std::endl;
	//e_damage(임시) = p_attackPower * 3
}

void Rattata::takeDamage(int p_attackPower) {
	//p_hp = p_hp - p_attackPower;

}
