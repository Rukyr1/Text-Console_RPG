#pragma once
#include "Player.h"
#include "Pokemon.h"
#include <string>
#include "BattleManager.h"

class GameManager
{
private:
	Player* player;
	Pokemon* MyPokemon;




public:
	GameManager();
	~GameManager();
	
	void GameStart();
	void SelectCharacter();
	void StartBattle();
	void GameEnding();
};