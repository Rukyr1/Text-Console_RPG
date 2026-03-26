#include "Charmander.h"
#include <iostream>
//파이리

Charmander::Charmander()  
{
	std::string p_name = "파이리";
	p_level = 5;
	p_hp = 145;
	p_attackPower = 55;
	//p_def = 5
	p_exp = 0;
}

void Charmander::P_SKill() {
	std::cout << "불꽃세레" << std::endl;
	//p_damage(임시) = p_attackPower * 3
}

void Charmander::takeDamage(int p_attackPower) {
	//p_hp = p_hp - p_attackPower;
}
