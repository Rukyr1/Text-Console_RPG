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

//적 포켓몬들
class Oddish : public Pokemon //뚜벅초 //풀
{
public:
	Oddish();
	int skill(int skillNum) override;
};

class Gloom : public Pokemon //냄새꼬 //풀
{
public:
	Gloom();
	int skill(int skillNum) override;
};

class Vileplume : public Pokemon //라플레시아 //풀
{
public:
	Vileplume();
	int skill(int skillNum) override;
};

class Paras : public Pokemon //파라스 //풀
{
public:
	Paras();
	int skill(int skillNum) override;
};

class Parasect : public Pokemon //파라섹트 //풀
{
public:
	Parasect();
	int skill(int skillNum) override;
};

class Bellsprout : public Pokemon //모다피 //풀
{
public:
	Bellsprout();
	int skill(int skillNum) override;
};

class Weepinbell : public Pokemon //우츠동 //풀
{
public:
	Weepinbell();
	int skill(int skillNum) override;
};

class Victreebel : public Pokemon //우츠보트 //풀
{
public:
	Victreebel();
	int skill(int skillNum) override;
};

class Exeggcute : public Pokemon //아라리 //풀
{
public:
	Exeggcute();
	int skill(int skillNum) override;
};

class Exeggutor : public Pokemon //나시 //풀
{
public:
	Exeggutor();
	int skill(int skillNum) override;
};

class Vulpix : public Pokemon //식스테일 //불
{
public:
	Vulpix();
	int skill(int skillNum) override;
};

class Ninetales : public Pokemon //나인테일 //불
{
public:
	Ninetales();
	int skill(int skillNum) override;
};

class Growlithe : public Pokemon //가디 //불
{
public:
	Growlithe();
	int skill(int skillNum) override;
};

class Arcanine : public Pokemon //윈디 //불
{
public:
	Arcanine();
	int skill(int skillNum) override;
};

class Ponyta : public Pokemon //포니타 //불
{
public:
	Ponyta();
	int skill(int skillNum) override;
};

class Rapidash : public Pokemon //날쌩마 //불
{
public:
	Rapidash();
	int skill(int skillNum) override;
};

class Magby : public Pokemon //마그비 //불
{
public:
	Magby();
	int skill(int skillNum) override;
};

class Magmar : public Pokemon //마그마 //불
{
public:
	Magmar();
	int skill(int skillNum) override;
};

class Flareon : public Pokemon //부스터 //불
{
public:
	Flareon();
	int skill(int skillNum) override;
};

class Moltres : public Pokemon //파이어 //불
{
public:
	Moltres();
	int skill(int skillNum) override;
};

class Psyduck : public Pokemon //고라파덕 //물
{
public:
	Psyduck();
	int skill(int skillNum) override;
};

class Golduck : public Pokemon //골덕 //물
{
public:
	Golduck();
	int skill(int skillNum) override;
};

class Poliwag : public Pokemon //발챙이 //물
{
public:
	Poliwag();
	int skill(int skillNum) override;
};

class Poliwhirl : public Pokemon //슈륙챙이 //물
{
public:
	Poliwhirl();
	int skill(int skillNum) override;
};

class Poliwrath : public Pokemon //강챙이 //물
{
public:
	Poliwrath();
	int skill(int skillNum) override;
};

class Tentacool : public Pokemon //왕눈해 //물
{
public:
	Tentacool();
	int skill(int skillNum) override;
};

class Tentacruel : public Pokemon //독파리 //물
{
public:
	Tentacruel();
	int skill(int skillNum) override;
};

class Slowpoke : public Pokemon //야돈 //물
{
public:
	Slowpoke();
	int skill(int skillNum) override;
};

class Slowbro : public Pokemon //야도란 //물
{
public:
	Slowbro();
	int skill(int skillNum) override;
};

class Lapras : public Pokemon //라프라스 //물
{
public:
	Lapras(); 
	int skill(int skillNum) override;
};

class Mewtwo : public Pokemon //뮤츠 //에스퍼
{
public:
	Mewtwo();
	int skill(int skillNum) override;
};

class Mew : public Pokemon //뮤 //에스퍼
{
public:
	Mew();
	int skill(int skillNum) override;
};