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
	const std::string PName; //포켓몬 이름
	int PLevel = 1;
	int PHp = 0;
	int PAttackPower = 0; //공격력
	int PExp = 0; //레벨업에 필요한 경험치는 100 고정

	//int p_def = 30;
	//int p_currentHp;  체력
	//int p_maxHp; 최대체력
	//std::string skill01;
	//std::string skill02;

public:

	Pokemon(std::string name, int hp, int atk);
	~Pokemon() {};

	virtual void sKill() = 0;
	void takeDamage(int p_attackPower);
	void printstatus();

	//void P_LevelUp(); 레벨업 로직 
	//void P_FinalEvolution();  최종 진화
};
