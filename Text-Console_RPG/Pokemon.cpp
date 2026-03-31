#include "Pokemon.h"
#include <iostream>
#include <map>
#include <vector>

Pokemon::Pokemon()
{

}

int Pokemon::skill(int skillNum)
{
	return 0;
}

struct skill;
struct pokemondata
{
	int level;
	int maxhp;
	int attackpower;

	std::string skill1;
	std::string skill2;
	
};


std::map<std::string, pokemondata> skilllist =
{
	{"이상해씨", {5, 155, 45, "몸통박치기", "덩굴채찍"}},
	{"파이리", {5, 145, 55, "할퀴기", "불꽃세례"}},
	{"꼬부기", {5, 150, 50, "몸통박치기", "물대포"}},
	{"뚜벅초", {13, 260, 65, "몸통박치기", "잎날가르기"}},
	{"냄새꼬", {28, 588, 168, "몸통박치기", "흡수"}},
	{"라플레시아", {32, 704, 224, "몸통박치기", "꽃잎댄스"}},
	{"파라스", {8, 158, 64, "할퀴기", "메가드레인"}},
	{"파라섹트", {24, 600, 216, "할퀴기", "기가드레인"}},
	{"모다피", {13, 299, 91, "몸통박치기", "덩굴채찍"}},
	{"우츠동", {28, 672, 196, "몸통박치기", "잎날가르기"}},
	{"우츠보트", {32, 800, 288, "몸통박치기", "그래스믹서"}},
	{"아라리", {24, 504, 120, "몸통박치기", "씨폭탄"}},
	{"나시", {35, 945, 350, "누르기", "리프스톰"}},
	{"식스테일", {16, 288, 75, "할퀴기", "불꽃세례"}},
	{"나인테일", {28, 644, 196, "할퀴기", "화염방사"}},
	{"가디", {15, 315, 99, "할퀴기", "화염바퀴"}},
	{"윈디", {26, 702, 275, "할퀴기", "플레어드라이브"}},
	{"포니타", {28, 588, 168, "막치기", "불꽃세례"}},
	{"날쌩마", {49, 1078, 441, "막치기", "불꽃세례"}},
	{"마그비", {1, 20, 7, "막치기", "덩굴채찍"}},
	{"마그마", {34, 714, 272, "막치기", "불대문자"}},
	{"부스터", {36, 756, 380, "몸통박치기", "플레어드라이브"}},
	{"파이어", {50, 1350, 450, "칼바람", "오버히트"}},
	{"고라파덕", {28, 588, 168, "막치기", "물대포"}},
	{"골덕", {38, 988, 277, "막치기", "물의파동"}},
	{"발챙이", {10, 195, 52, "몸통박치기", "거품"}},
	{"슈룩챙이", {23, 483, 138, "막치기", "폭포오르기"}},
	{"강챙이", {32, 986, 224, "막치기", "아쿠아브레이크"}},
	{"왕눈해", {5, 89, 21, "몸통박치기", "거품"}},
	{"독파리",{20, 540, 155, "몸통박치기", "거품광선"}},
	{"야돈", {15, 420, 90, "몸통박치기", "물대포"}},
	{"야도란", {37, 1036, 259, "몸통박치기", "물의파동"}},
	{"라프라스", {50, 1520, 366, "누르기", "하이드로펌프"}},
	{"뮤츠", {70, 2100, 840, "염동력", "사이코브레이크"}},
	{"뮤", {100, 3000, 1500, "염동력", "오리진즈슈퍼노바"}}

};

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

//이 코드는 적 포켓몬을 각각 클래스 형태로 직접 구현한 것으로, 생성자에서 이름·레벨·체력·공격력 같은 기본 능력치를 미리 설정하고,
// skill() 함수에서 두 가지 기술 중 하나를 선택해 공격하도록 만든 구조다.
//각 포켓몬은 거의 동일한 구조를 가지며, 차이점은 능력치와 스킬 이름만 다르게 설정되어 있다.
// skill(1)이면 기본 공격, 그 외에는 더 강한 스킬(공격력 + 20)을 사용하는 방식이다.
//전체적으로는 풀, 불, 물, 에스퍼 총 3~4가지 속성 기준으로 약 30마리 이상의 적 포켓몬을 미리 만들어 둔 형태이며, 이를 통해 다양한 적이 등장하도록 구성한 것이다.

//뚜벅초 //풀

Oddish::Oddish()
{
	PName = "뚜벅초"; //포켓몬이름
	PLevel = 13; //레벨
	PMaxHp = 260; //최대체력
	PCurrentHp = PMaxHp; // 현재체력
	PAttackPower = 65; // 공격력
	//p_def = 10
	PExp = 0; //경험치
}
int Oddish::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [몸통박치기]!" << std::endl;
		return getAttack(); //기술 사용시 getAttack() 을 반환
	}
	else
	{
		std::cout << PName << "의 [잎날가르기]!" << std::endl;
		return getAttack() + 20;  //기술 사용시 getAttack() 을 반환
	}
}

//냄새꼬 //풀

Gloom::Gloom()
{
	PName = "냄새꼬";
	PLevel = 28;
	PMaxHp = 588;
	PCurrentHp = PMaxHp;
	PAttackPower = 168;
	//p_def = 12
	PExp = 0;
}
int Gloom::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [몸통박치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [흡수]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//라플레시아 //풀

Vileplume::Vileplume()
{
	PName = "라플레시아";
	PLevel = 32;
	PMaxHp = 704;
	PCurrentHp = PMaxHp;
	PAttackPower = 224;
	//p_def = 14
	PExp = 0;
}
int Vileplume::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [몸통박치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [꽃잎댄스]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//파라스 //풀

Paras::Paras()
{
	PName = "파라스";
	PLevel = 8;
	PMaxHp = 158;
	PCurrentHp = PMaxHp;
	PAttackPower = 64;
	//p_def = 9
	PExp = 0;
}
int Paras::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [할퀴기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [메가드레인]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//파라섹트 //풀

Parasect::Parasect()
{
	PName = "파라섹트";
	PLevel = 24;
	PMaxHp = 600;
	PCurrentHp = PMaxHp;
	PAttackPower = 216;
	//p_def = 13
	PExp = 0;
}
int Parasect::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [할퀴기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [기가드레인]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//모다피 //풀

Bellsprout::Bellsprout()
{
	PName = "모다피";
	PLevel = 13;
	PMaxHp = 299;
	PCurrentHp = PMaxHp;
	PAttackPower = 91;
	//p_def = 6
	PExp = 0;
}
int Bellsprout::skill(int skillNum)
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

//우츠동 //풀

Weepinbell::Weepinbell()
{
	PName = "우츠동";
	PLevel = 28;
	PMaxHp = 672;
	PCurrentHp = PMaxHp;
	PAttackPower = 196;
	//p_def = 9
	PExp = 0;
}
int Weepinbell::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [몸통박치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [잎날가르기]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//우츠보트 //풀

Victreebel::Victreebel()
{
	PName = "우츠보트";
	PLevel = 32;
	PMaxHp = 800;
	PCurrentHp = PMaxHp;
	PAttackPower = 288;
	//p_def = 10
	PExp = 0;
}
int Victreebel::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [몸통박치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [그래스믹서]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//아라리 //풀

Exeggcute::Exeggcute()
{
	PName = "아라리";
	PLevel = 24;
	PMaxHp = 504;
	PCurrentHp = PMaxHp;
	PAttackPower = 120;
	//p_def = 12
	PExp = 0;
}
int Exeggcute::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [몸통박치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [씨폭탄]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//나시 //풀

Exeggutor::Exeggutor()
{
	PName = "나시";
	PLevel = 35;
	PMaxHp = 945;
	PCurrentHp = PMaxHp;
	PAttackPower = 350;
	//p_def = 13
	PExp = 0;
}
int Exeggutor::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [누르기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [리프스톰]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//식스테일 //불

Vulpix::Vulpix()
{
	PName = "식스테일";
	PLevel = 16;
	PMaxHp = 288;
	PCurrentHp = PMaxHp;
	PAttackPower = 75;
	//p_def = 6
	PExp = 0;
}
int Vulpix::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [할퀴기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [불꽆세례]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//나인테일 //불

Ninetales::Ninetales()
{
	PName = "나인테일";
	PLevel = 28;
	PMaxHp = 644;
	PCurrentHp = PMaxHp;
	PAttackPower = 196;
	//p_def = 9
	PExp = 0;
}
int Ninetales::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [할퀴기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [화염방사]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//가디 //불

Growlithe::Growlithe()
{
	PName = "가디";
	PLevel = 15;
	PMaxHp = 315;
	PCurrentHp = PMaxHp;
	PAttackPower = 99;
	//p_def = 6
	PExp = 0;
}
int Growlithe::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [할퀴기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [화염바퀴]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//윈디 //불

Arcanine::Arcanine()
{
	PName = "윈디";
	PLevel = 26;
	PMaxHp = 702;
	PCurrentHp = PMaxHp;
	PAttackPower = 275;
	//p_def = 11
	PExp = 0;
}
int Arcanine::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [할퀴기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [플레어드라이브]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//포니타 //불

Ponyta::Ponyta()
{
	PName = "포니타";
	PLevel = 28;
	PMaxHp = 588;
	PCurrentHp = PMaxHp;
	PAttackPower = 168;
	//p_def = 9
	PExp = 0;
}
int Ponyta::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [막치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [불꽃세례]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//날쌩마 //불

Rapidash::Rapidash()
{
	PName = "날쌩마";
	PLevel = 49;
	PMaxHp = 1078;
	PCurrentHp = PMaxHp;
	PAttackPower = 441;
	//p_def = 10
	PExp = 0;
}
int Rapidash::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [막치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [회오리불꽃]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//마그비 //불

Magby::Magby()
{
	PName = "마그비";
	PLevel = 1;
	PMaxHp = 20;
	PCurrentHp = PMaxHp;
	PAttackPower = 7;
	//p_def = 6
	PExp = 0;
}
int Magby::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [막치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [불꽃세례]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//마그마 //불

Magmar::Magmar()
{
	PName = "마그마";
	PLevel = 34;
	PMaxHp = 714;
	PCurrentHp = PMaxHp;
	PAttackPower = 272;
	//p_def = 9
	PExp = 0;
}
int Magmar::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [막치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [불대문자]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//부스터 //불

Flareon::Flareon()
{
	PName = "부스터";
	PLevel = 36;
	PMaxHp = 756;
	PCurrentHp = PMaxHp;
	PAttackPower = 380;
	//p_def = 9
	PExp = 0;
}
int Flareon::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [몸통박치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [플레어드라이브]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//파이어 //불

Moltres::Moltres()
{
	PName = "파이어";
	PLevel = 50;
	PMaxHp = 1350;
	PCurrentHp = PMaxHp;
	PAttackPower = 450;
	//p_def = 12
	PExp = 0;
}
int Moltres::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [칼바람]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [오버히트]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//고라파덕 //물

Psyduck::Psyduck()
{
	PName = "고라파덕";
	PLevel = 28;
	PMaxHp = 588;
	PCurrentHp = PMaxHp;
	PAttackPower = 168;
	//p_def = 7
	PExp = 0;
}
int Psyduck::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [막치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [물대포]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//골덕 //물

Golduck::Golduck()
{
	PName = "골덕";
	PLevel = 38;
	PMaxHp = 988;
	PCurrentHp = PMaxHp;
	PAttackPower = 277;
	//p_def = 11
	PExp = 0;
}
int Golduck::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [막치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [물의파동]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//발챙이 //물

Poliwag::Poliwag()
{
	PName = "발챙이";
	PLevel = 10;
	PMaxHp = 195;
	PCurrentHp = PMaxHp;
	PAttackPower = 52;
	//p_def = 7
	PExp = 0;
}
int Poliwag::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [몸통박치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [거품]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//슈륙챙이 //물

Poliwhirl::Poliwhirl()
{
	PName = "슈륙챙이";
	PLevel = 23;
	PMaxHp = 483;
	PCurrentHp = PMaxHp;
	PAttackPower = 138;
	//p_def = 9
	PExp = 0;
}
int Poliwhirl::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [막치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [폭포오르기]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//강챙이 //물

Poliwrath::Poliwrath()
{
	PName = "강챙이";
	PLevel = 32;
	PMaxHp = 986;
	PCurrentHp = PMaxHp;
	PAttackPower = 224;
	//p_def = 13
	PExp = 0;
}
int Poliwrath::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [막치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [아쿠아브레이크]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//왕눈해 //물

Tentacool::Tentacool()
{
	PName = "왕눈해";
	PLevel = 5;
	PMaxHp = 89;
	PCurrentHp = PMaxHp;
	PAttackPower = 21;
	//p_def = 5
	PExp = 0;
}
int Tentacool::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [몸통박치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [거품]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//독파리 //물

Tentacruel::Tentacruel()
{
	PName = "독파리";
	PLevel = 20;
	PMaxHp = 540;
	PCurrentHp = PMaxHp;
	PAttackPower = 155;
	//p_def = 10
	PExp = 0;
}
int Tentacruel::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [몸통박치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [거품광선]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//야돈 //물

Slowpoke::Slowpoke()
{
	PName = "야돈";
	PLevel = 15;
	PMaxHp = 420;
	PCurrentHp = PMaxHp;
	PAttackPower = 90;
	//p_def = 10
	PExp = 0;
}
int Slowpoke::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [몸통박치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [물대포]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//야도란 //물

Slowbro::Slowbro()
{
	PName = "야도란";
	PLevel = 37;
	PMaxHp = 1036;
	PCurrentHp = PMaxHp;
	PAttackPower = 259;
	//p_def = 15
	PExp = 0;
}
int Slowbro::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [몸통박치기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [물의파동]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//라프라스 //물

Lapras::Lapras()
{
	PName = "라프라스";
	PLevel = 50;
	PMaxHp = 1520;
	PCurrentHp = PMaxHp;
	PAttackPower = 366;
	//p_def = 11
	PExp = 0;
}
int Lapras::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [누르기]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [하이드로펌프]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//뮤츠 //에스퍼

Mewtwo::Mewtwo()
{
	PName = "뮤츠";
	PLevel = 70;
	PMaxHp = 2100;
	PCurrentHp = PMaxHp;
	PAttackPower = 840;
	//p_def = 12
	PExp = 0;
}
int Mewtwo::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [염동력]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [사이코브레이크]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
}

//뮤 //에스퍼

Mew::Mew()
{
	PName = "뮤";
	PLevel = 100;
	PMaxHp = 3000;
	PCurrentHp = PMaxHp;
	PAttackPower = 1500;
	//p_def = 20
	PExp = 0;
}
int Mew::skill(int skillNum)
{
	if (skillNum == 1)
	{
		std::cout << PName << "의 [염동력]!" << std::endl;
		return getAttack();
	}
	else
	{
		std::cout << PName << "의 [오리진즈슈퍼노바]!" << std::endl;
		return getAttack() + 20; // 3배 데미지 리턴
	}
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
	std::cout << getName() << "이(가) 레벨 업 했습니다!" << std::endl;
	//능력치 상승
	int hpGain = PLevel * 20;
	int attackGain = PLevel * 5;

	PMaxHp += hpGain;
	PAttackPower += attackGain;

	//체력 풀 회복
	PCurrentHp = PMaxHp;

	std::cout << "최대 체력이 " << hpGain << ", 공격력이 " << attackGain << " 상승했습니다." << std::endl;
	std::cout << "체력이 모두 회복되었습니다! (현재 HP: " << PCurrentHp << ", 현재 공격력: " << PAttackPower << ") " << std::endl;
	
	//기본 진화 레벨
	if (PLevel == 7)
	{
		evolution();
	}

	//최대 레벨 달성 시 최종 진화
	if (PLevel == 10)
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
void Pokemon::evolutionBonus(int hpBonus, int atkBonus) 
{
	PMaxHp += hpBonus;
	PAttackPower += atkBonus;
	PCurrentHp = PMaxHp; // 진화 시 체력 풀 회복

	std::cout << "[진화 보너스] HP +" << hpBonus << ", 공격력 +" << atkBonus << " 상승!" << std::endl;
}


void Pokemon::evolution()
{
	std::cout << "\n==========!!! 포켓몬 진화 !!!==========" << std::endl;

	static std::map<std::string, std::string> evolutionTable =
	{
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
	static std::map<std::string, std::string> finalEvolutionTable = 
	{
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
	evolutionBonus(50, 30);

	std::cout << "======================================" << std::endl;
}
