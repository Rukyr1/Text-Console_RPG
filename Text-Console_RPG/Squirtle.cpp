#include "Squirtle.h"
#include <iostream>
//꼬부기

Squirtle::Squirtle() 
{
	std::string p_name = "꼬부기";
	p_level = 5;
	p_hp = 150;
	p_attackPower = 50;
	//p_def = 10
	p_exp = 0;
}

void Squirtle::P_SKill() {
	std::cout << "물대포" << std::endl;
	//p_damage(임시) = p_attackPower * 3
}

void Squirtle::takeDamage(int p_attackPower) {
	//p_hp = p_hp - p_attackPower;

}
