#include "EnemyPokemon.h"
#include <vector>
#include <cstdlib>
#include <iostream>

//EnemyList에 저장된 여러 포켓몬 데이터 중 하나를 랜덤으로 선택해 적 포켓몬을 생성하고, 그 정보(이름, 타입, 레벨, 스킬)를 객체에 설정하는 구조다.
//이후 레벨을 기반으로 체력과 공격력을 랜덤하게 계산해 능력치를 정하고,
//전투 시 skill() 함수로 스킬을 사용하며 공격력을 반환한다.

//  데이터 구조
struct PokemonData //타입, 이름, 레벨, 기술1, 기술2 를 저장하는 데이터
{
    std::string PType; //타입
	std::string name; //적 포켓몬 이름
	int level; //레벨
	std::string skillName1; //스킬1
	std::string skillName2; //스킬2
};

// 포켓몬 리스트
static std::vector<PokemonData> EnemyList =
{
    {"GRASS", "뚜벅초", 13, "몸통박치기", "잎날가르기"},
    {"GRASS", "냄새꼬", 28, "몸통박치기", "흡수"},
    {"GRASS", "라플레시아", 32, "몸통박치기", "꽃잎댄스"},
    {"GRASS", "파라스", 8, "할퀴기", "메가드레인"},
    {"GRASS", "파라섹트", 24, "할퀴기", "기가드레인"},
    {"GRASS", "모다피", 13, "몸통박치기", "덩굴채찍"},
    {"GRASS", "우츠동", 28, "몸통박치기", "잎날가르기"},
    {"GRASS", "우츠보트", 32, "몸통박치기", "그래스믹서"},
    {"GRASS", "아라리", 24, "몸통박치기", "씨폭탄"},
    {"GRASS", "나시", 35, "누르기", "리프스톰"},
    {"FIRE", "식스테일", 16, "할퀴기", "불꽃세례"},
    {"FIRE", "나인테일", 28, "할퀴기", "화염방사"},
    {"FIRE", "가디", 15, "할퀴기", "화염바퀴"},
    {"FIRE", "윈디", 26, "할퀴기", "플레어드라이브"},
    {"FIRE", "포니타", 28, "막치기", "불꽃세례"},
    {"FIRE", "날쌩마", 49, "막치기", "불꽃세례"},
    {"FIRE", "마그비", 1, "막치기", "덩굴채찍"},
    {"FIRE", "마그마", 34, "막치기", "불대문자"},
    {"FIRE", "부스터", 36, "몸통박치기", "플레어드라이브"},
    {"FIRE", "파이어", 50, "칼바람", "오버히트"},
    {"WATER", "고라파덕", 28, "막치기", "물대포"},
    {"WATER", "골덕", 38, "막치기", "물의파동"},
    {"WATER", "발챙이", 10, "몸통박치기", "거품"},
    {"WATER", "슈룩챙이", 23, "막치기", "폭포오르기"},
    {"WATER", "강챙이", 32, "막치기", "아쿠아브레이크"},
    {"WATER", "왕눈해", 5, "몸통박치기", "거품"},
    {"WATER", "독파리", 20, "몸통박치기", "거품광선"},
    {"WATER", "야돈", 15, "몸통박치기", "물대포"},
    {"WATER", "야도란", 37, "몸통박치기", "물의파동"},
    {"WATER", "라프라스", 50, "누르기", "하이드로펌프"},
    {"Psychic", "뮤츠", 70, "염동력", "사이코브레이크"},
    {"Psychic", "뮤", 100, "염동력", "오리진즈슈퍼노바"}
};

EnemyPokemon::EnemyPokemon() : Pokemon()
{
    int index = rand() % EnemyList.size(); // 리스트 중에서 랜덤 선택
    PokemonData data = EnemyList[index];

    PType = data.PType; //타입 입력
    PName = data.name; //이름 입력
    PLevel = data.level; //레벨 입력

    // 랜덤 능력치
    PMaxHp = PLevel * (rand() % 11 + 20); //레벨 * (20부터 30)
    PCurrentHp = PMaxHp; //현재 체력
    PAttackPower = PLevel * (rand() % 6 + 5); //레벨 * (10부터 20)
    PExp = 0;

    //  스킬 2개 저장
    Pskill1 = data.skillName1;
    getSkill1(); //스킬 1 이름을 반환
    Pskill2 = data.skillName2;
    getSkill2(); //스킬 2 이름을 반환
}

//void EnemyPokemon::skill()
//{
//	std::cout << PName 
//		<< "이(가) "<< skillName 
//		<< " 사용! (위력: "<< skillPower << ")" << std::endl;
//}
int EnemyPokemon::skill(int skillNum)
{
    if (skillNum == 1)
    {
        std::cout << PName << "의 [" << Pskill1 << "]!" << std::endl;
        return getAttack();
    }
    else
    {
        std::cout << PName << "의 [" << Pskill2 << "]!" << std::endl;
        return getAttack() + 20;
    }
}

