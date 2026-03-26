#pragma once
#include "Player.h"
#include "Pokemon.h"
#include <string>

class GameManager
{
private:
	Player* player;
	Pokemon* MyPokemon;

	


public:
	GameManager();
	~GameManager();
	
	void GameStart();

	
	
};

