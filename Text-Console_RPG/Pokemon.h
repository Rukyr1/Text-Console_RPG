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
	int PAttackPower = 0; //공격력
	int PExp = 0; //레벨업에 필요한 경험치는 100 고정
	int PMaxExp = 100; //진우님 제가 레벨업 수정하느라 임시로 추가했습니다. 나중에 손봐주세요
	int PCurrentHp;
	int PMaxHp;

	//int p_def = 30;
	//std::string skill01;
	//std::string skill02;

public:

	Pokemon();
	virtual ~Pokemon() {};

	virtual int skill(int skillNum) = 0;
	virtual void takeDamage(int PAttackPower);
	void printStatus();
	void levelUp();
	void recoveryHp();
	void finalEvolution();
	void evolutionBonus(int hpBonus, int atkBonus);


	std::string getName() { return PName; }
	int getAttack() { return PAttackPower; }
	int getHp() { return PCurrentHp; }
	int getPMaxHp() { return PMaxHp; }
	int getPExp() { return PExp; } //이것도...
	int getPMaxExp() { return PMaxExp; } //이것도...
	void setHP(int NewHp) { PCurrentHp = NewHp; } //이것도...
	void setPExp(int NewExp) { PExp = NewExp;  } //이것도....
};

class Bulbasaur : public Pokemon //이상해씨
{
public:
	Bulbasaur();
	int skill(int skillNum) override;
};

class Charmander : public Pokemon //파이리
{
public:
	Charmander();
	int skill(int skillNum) override;
};

class Squirtle : public Pokemon //꼬부기
{
public:
	Squirtle();
	int skill(int skillNum) override;
};