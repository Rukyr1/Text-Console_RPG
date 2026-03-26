#include "Pokemon.h"

void Pokemon::takeDamage(int p_attackPower)
{
    p_hp -= p_attackPower; //나중에 p_damage(임시로 바뀔수있음)
    std::cout << p_name << " 가 대미지를 입었다!" << std::endl;
}

