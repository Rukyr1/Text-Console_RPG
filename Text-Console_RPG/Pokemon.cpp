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

//이상해씨

class Bulbasaur : public Pokemon {
public:
	Bulbasaur();
	void takeDamage(int p_attackPower);
	void sKill() override;
};

Bulbasaur::Bulbasaur()
{
	std::string PName = "이상해씨";
	PLevel = 5;
	PHp = 155;
	PAttackPower = 45;
	//p_def = 8
	PExp = 0;
}

void Bulbasaur::sKill() {
	std::cout << "덩쿨채찍!" << std::endl;
	//p_damage(임시) = p_attackPower * 3
}

void Bulbasaur::takeDamage(int p_attackPower) {
	//p_hp = p_hp - p_attackPower;
}

//파이리

class Charmander : public Pokemon {
public:
	Charmander();
	void takeDamage(int p_attackPower);
	void sKill() override;
};

Charmander::Charmander()
{
	std::string PName = "파이리";
	PLevel = 5;
	PHp = 145;
	PAttackPower = 55;
	//p_def = 5
	PExp = 0;
}

void Charmander::sKill() {
	std::cout << "불꽃세레" << std::endl;
	//p_damage(임시) = p_attackPower * 3
}

void Charmander::takeDamage(int p_attackPower) {
	//p_hp = p_hp - p_attackPower;
}

class Squirtle : public Pokemon {
public:
	Squirtle();
	void takeDamage(int p_attackPower);
	void sKill() override;
};

//꼬부기

Squirtle::Squirtle()
{
	std::string PName = "꼬부기";
	PLevel = 5;
	PHp = 150;
	PAttackPower = 50;
	//p_def = 10
	PExp = 0;
}

void Squirtle::sKill() {
	std::cout << "물대포" << std::endl;
	//p_damage(임시) = p_attackPower * 3
}

void Squirtle::takeDamage(int p_attackPower) {
	//p_hp = p_hp - p_attackPower;

}