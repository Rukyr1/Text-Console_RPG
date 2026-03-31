#pragma once
#include "Player.h"
#include "Pokemon.h"
#include "Inventory.h"
#include "UIManager.h"
#include "PrintText.h"
#include "Item.h"
#include <random>

enum class BattleResult //전투 결과 값
{
	Win,
	Lose,
	Escape
};

class BattleManager
{
public:
	BattleManager();
	~BattleManager();
	
	BattleResult StartBattle(Pokemon* MyPokemon, Inventory<Item>& inventory, Player* player);
	//함수의 반환타입 함수이름(매개변수);

	

private:
	bool IsBattle; //전투 중 여부
	bool IsTurnPass; //턴 종료 여부
	bool IsEscape; //탈출 성공 여부
	int AtkChoice; //전투 중 선택지
	int BagChoice; //전투 중 가방 선택지
	bool IsOpenBag;

	Pokemon* EnemyPokemon;
	void RandomEnemy();

	UIManager uimanager;
	PrintText printtext;
	Item item;

	std::random_device rd; //랜덤 시드 
	std::mt19937 gen;



};

