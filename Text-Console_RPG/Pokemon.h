#pragma once
#include <iostream>
#include <string>

//Pokemon.h 

//포켓몬 타입 정의
enum class  PType //일단 스타팅 포켓몬 타입 3개만
{
	GRASS,
	FIRE,
	WATER
};

class Pokemon //포켓몬 클래스 멤버변수 -> 레벨, 체력, 공격력, 경험치
			  //멤버 함수 -> 공격 -> virtual void Attack() 
{
protected:
	std::string PName; //포켓몬 이름
	int PLevel = 1;
	int PHp = 0;
	int PAttackPower = 0; //공격력
	int PExp = 0; //레벨업에 필요한 경험치는 100 고정
	int PCurrentHp;  
	int PMaxHp; 

	//int p_def = 30;
	//std::string skill01;
	//std::string skill02;

public:

	Pokemon();
	virtual ~Pokemon() {};

	virtual void skill();
	virtual void takeDamage(int PAttackPower);
	void printStatus();
	void levelUp(); 
	void finalEvolution();  
	void evolutionBonus(int hpBonus, int atkBonus);
};

class Bulbasaur : public Pokemon //이상해씨
{
public:
	Bulbasaur();
	void skill() override;
	void takeDamage(int PAttackPower) override;
};

class Charmander : public Pokemon //파이리
{
public:
	Charmander();
	void takeDamage(int p_attackPower);
	void skill() override;
};

class Squirtle : public Pokemon //꼬부기
{
public:
	Squirtle();
	void takeDamage(int p_attackPower);
	void skill() override;
};