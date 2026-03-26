#include "Squirtle.h"
#include <iostream>
//꼬부기

Squirtle::Squirtle(std::string name, int hp, int atk) : Pokemon(name, hp, atk) {
	std::string p_name = "꼬부기";
	p_level = 5;
	p_hp = 20;
	p_attackPower = 4;
	//p_def = 10
	p_exp = 0;
}

void P_SKill() {
	std::cout << "물대포" << std::endl;
	//p_damage(임시) = p_attackPower * 3
}

void takeDamage(int p_attackPower) {
	//p_hp = p_hp - p_attackPower;

}
