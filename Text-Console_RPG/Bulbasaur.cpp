#include "Bulbasaur.h"
#include <iostream>
//이상해씨

Bulbasaur::Bulbasaur(std::string name, int hp, int atk) : Pokemon(name, hp, atk) {
	std::string p_name = "이상해씨";
	p_level = 5;
	p_hp = 22;
	p_attackPower = 3;
	//p_def = 8
	p_exp = 0;
}

void P_SKill() {
	std::cout << "덩쿨채찍!" << std::endl;
	//p_damage(임시) = p_attackPower * 3
}

void takeDamage(int p_attackPower) {
	//p_hp = p_hp - p_attackPower;
}