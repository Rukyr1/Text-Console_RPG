#include "Pokemon.h"
#include <iostream>
#include <map>

Pokemon::Pokemon()
{

}

int Pokemon::skill(int skillNum)
{
	return 0;
}

void Pokemon::printStatus()
{
	std::cout << "------------------------------------" << std::endl;
	std::cout << "포켓몬의 상태" << std::endl;
	std::cout << "현재 포켓몬: " << PName << std::endl;
	std::cout << "레벨: " << "Lv. " << PLevel << std::endl;
	std::cout << "HP: " << PCurrentHp << std::endl;
	std::cout << "공격력: " << PAttackPower << std::endl;
	std::cout << "현재 경험치: " << PExp << std::endl;
	std::cout << "------------------------------------" << std::endl;
}

//이상해씨

Bulbasaur::Bulbasaur()
{
	PName = "이상해씨";
	PLevel = 5;
	PMaxHp = 155;
	PCurrentHp = PMaxHp;
	PAttackPower = 45;
	//p_def = 8
	PExp = 0;
}
int Bulbasaur::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [몸통박치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [덩굴채찍]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}


//파이리
Charmander::Charmander()
{
	PName = "파이리";
	PLevel = 5;
	PMaxHp = 145;
	PCurrentHp = PMaxHp;
	PAttackPower = 55;
	//p_def = 5
	PExp = 0;
}
int Charmander::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [할퀴기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [불꽃세레]!" << std::endl;
		return getAttack() + 20;
	}
	//p_damage(임시) = p_attackPower * 3
}

//꼬부기

Squirtle::Squirtle()
{
	PName = "꼬부기";
	PLevel = 5;
	PMaxHp = 150;
	PCurrentHp = PMaxHp;
	PAttackPower = 50;
	//p_def = 10
	PExp = 0;
}

int Squirtle::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << " 의 [몸통박치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << " 의 [물대포]!" << std::endl;
		return getAttack() + 20;
	}
	//p_damage(임시) = p_attackPower * 3
}

void Pokemon::takeDamage(int PAttackPower)
{
	PCurrentHp -= PAttackPower;

	if (PCurrentHp < 0)
	{
		PCurrentHp = 0;
	}

	std::cout << PName << "가" << PAttackPower
		<< "의 데미지를 입었다!" << "[남은 HP: " << PCurrentHp << "]" << std::endl;
}


void Pokemon::levelUp()
{
	if (PLevel >= 10)//최고레벨(10lv) 이후
	{
		std::cout << "은(는) 이미 최고 레벨입니다." << std::endl;
		return;
	}

	PLevel++;
	std::cout << "이(가) 레벨 업 했습니다!" << std::endl;
	//능력치 상승
	int hpGain = PLevel * 20;
	int attackGain = PLevel * 5;

	PMaxHp += hpGain;
	PAttackPower += attackGain;

	//체력 풀 회복
	PCurrentHp = PMaxHp;

	std::cout << "최대 체력이 " << hpGain << ", 공격력이 " << attackGain << " 상승했습니다." << std::endl;
	std::cout << "체력이 모두 회복되었습니다! (현재 HP: " << PCurrentHp << ", 현재 공격력: " << PAttackPower << ") " << std::endl;
	
	//일반 진화 레벨
	if (PLevel == 10)
	{
		evolution();
	}

	//최대 레벨 달성 시 최종 진화
	if (PLevel == 15)
	{
		finalEvolution();
	}
}

void Pokemon::recoveryHp()
{
	PCurrentHp = PMaxHp;
	std::cout << PName << "의 Hp가 " << PMaxHp << "로 회복되었습니다." << std::endl;
}

//진화 보너스
void Pokemon::evolutionBonus(int hpBonus, int atkBonus) {
	PMaxHp += hpBonus;
	PAttackPower += atkBonus;
	PCurrentHp = PMaxHp; // 진화 시 체력 풀 회복

	std::cout << "[진화 보너스] HP +" << hpBonus << ", 공격력 +" << atkBonus << " 상승!" << std::endl;
}

//일반 진화
void Pokemon::evolution()
{
	std::cout << "\n==========!!! 포켓몬 진화 !!!========= = " << std::endl;

	//진화 후의 이름 변경
	static std::map<std::string, std::string> evolutionTable = {
		{"파이리", "리자드"},
		{"꼬부기", "어니부기"},
		{"이상해씨", "이상해풀"}

	};

	if (evolutionTable.count(PName) > 0)
	{
		std::string nextName = evolutionTable[PName];
		std::cout << PName << "(이)가 한계를 뛰어넘어 " << nextName << "(으)로 진화했습니다!" << std::endl;

		PName = nextName;
	}


	evolutionBonus(30, 10);
	std::cout << "======================================" << std::endl;
}

//최종 진화
void Pokemon::finalEvolution()
{
	std::cout << "\n==========!!! 최종 진화 !!!==========" << std::endl;

	//진화 후의 이름 변경
	static std::map<std::string, std::string> finalEvolutionTable = {
		{"리자드", "리자몽"},
		{"어니부기", "거북왕"},
		{"이상해풀", "이상해꽃"},
		// 여기에 몬스터 추가 가능
	};

	if (finalEvolutionTable.count(PName) > 0)
	{
		std::string nextName = finalEvolutionTable[PName];
		std::cout << PName << "(이)가 한계를 뛰어넘어 " << nextName << "(으)로 최종 진화했습니다!" << std::endl;

		PName = nextName;
	}

	//진화 보너스 호출
	evolutionBonus(50, 20);

	std::cout << "======================================" << std::endl;
}
