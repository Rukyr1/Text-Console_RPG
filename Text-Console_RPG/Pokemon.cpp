#include "Pokemon.h"
#include <iostream>
void Pokemon::sKill()
{

}

void Pokemon::takeDamage(int p_attackPower)
{
	std::cout << PName << " 가 대미지를 입었다!" << std::endl;
}

void Pokemon::printstatus()
{
	std::cout << "------------------------------------" << std::endl;
	std::cout << "포켓몬의 상태" << std::endl;
	std::cout << "현재 포켓몬: " << PName << std::endl;
	std::cout << "레벨: " << "Lv. " << PLevel << std::endl;
	std::cout << "HP: " << PHp << std::endl;
	std::cout << "공격력: " << PAttackPower << std::endl;
	std::cout << "현재 경험치: " << PExp << std::endl;
	std::cout << "------------------------------------" << std::endl;
};