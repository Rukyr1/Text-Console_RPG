#pragma once
#include "Player.h"
#include <string>
#include "BattleManager.h"

class GameManager
{
private:
	Player* player;
	Pokemon* MyPokemon;
	Pokemon* EnemyPokemon;




public:
	GameManager();
	~GameManager();
	
	void GameStart();
	void SelectPokemon();
	void StartBattle();
	void GameEnding();
};