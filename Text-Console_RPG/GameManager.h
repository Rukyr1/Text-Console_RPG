#pragma once
#include "Player.h"
#include <string>
#include "BattleManager.h"
#include "UIManager.h"
#include "PrintText.h"

class GameManager
{
private:
	Player* player;
	Pokemon* MyPokemon;
	

	std::string playerName;

	UIManager uimanager;
	BattleManager battlemanager;
	PrintText printtext;

public:
	GameManager();
	~GameManager();
	
	void GameStart();
	void IntroScreen();
	void SelectPokemon();
	void GameLoop();
	void GameEnding();
	void HiddenStage();
};