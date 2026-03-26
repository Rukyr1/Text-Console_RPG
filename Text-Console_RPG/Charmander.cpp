#include "Charmander.h"
#include <iostream>
//파이리

Charmander::Charmander(std::string name, int hp, int atk) : Pokemon(name, hp, atk) {
	std::string p_name = "파이리";
	p_level = 5;
	p_hp = 18;
	p_attackPower = 5;
	//p_def = 5
	p_exp = 0;
}

void P_SKill() {
	std::cout << "불꽃세레" << std::endl;
	//p_damage(임시) = p_attackPower * 3
}

void takeDamage(int p_attackPower) {
	//p_hp = p_hp - p_attackPower;
}
