#pragma once
#include <iostream>
#include <string>

//Pokemon.h 
class Pokemon //포켓몬 클래스 멤버변수 -> 레벨, 체력, 공격력, 경험치
			  //멤버 함수 -> 공격 -> virtual void Attack() 
{
protected:
	std::string p_name; //포켓몬 이름 // const 제거
	//std::string skill01;
	//std::string skill02;
	int p_level = 1;
	int p_hp = 0;
	int p_attackPower = 0; //공격력
	//int p_def = 30;
	int p_exp = 0; //레벨업에 필요한 경험치는 100 고정

	//int p_currentHp;  체력
	//int p_maxHp; 최대체력
public:

	Pokemon() {};
	~Pokemon() {};

	virtual void P_SKill() = 0;
	void takeDamage(int p_attackPower);

	void P_Printstatus()
	{
	std::cout << "------------------------------------" << std::endl;
	std::cout << "* 현재 능력치" << std::endl;
	std::cout << "닉네임: " << p_name << std::endl;
	std::cout << "레벨: " << "Lv. " << p_level << std::endl;
	std::cout << "HP: " << p_hp << std::endl;
	std::cout << "공격력: " << p_attackPower << std::endl;
	std::cout << "현재 경험치: " << p_exp << std::endl;  
	std::cout << "------------------------------------" << std::endl;
	}; //포켓몬 현재 상태 출력

	//void P_LevelUp(); 레벨업 로직 
	//void P_FinalEvolution();  최종 진화
};
