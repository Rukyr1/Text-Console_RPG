#pragma once
#include "Player.h"
#include "Pokemon.h"
#include "EnemyPokemon.h"
#include "Inventory.h"



class BattleManager
{
public:
	BattleManager();
	void StartBattle();
	

private:
	bool IsBattle; //전투 중 여부
	bool IsTurnPass; //턴 종료 여부
	bool IsEscape; //탈출 성공 여부
	int AtkChoice; //전투 중 선택지
	int BagChoice; //전투 중 가방 선택지
	
};

