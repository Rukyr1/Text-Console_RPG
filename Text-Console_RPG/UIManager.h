#pragma once
#include "Pokemon.h"
#include "Player.h"

class UIManager
{
public:
	UIManager();
	void TitleUi();
	void StarterUiTop();
	void StarterUiBottom();
	void BattleUiTop(Pokemon* MyPokemon, Pokemon* EnemyPokemon);
	void BattleUiBottom();
	void VillageUi(std::string playerName, Pokemon* MyPokemon);
	
	void printHpBar(int currentHp, int maxHp);


private:

	Pokemon* MyPokemon;
	Pokemon* EnemyPokemon;

};

