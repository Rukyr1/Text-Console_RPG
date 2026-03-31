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
	void PokemonCenterUi();
	
	void printHpBar(int currentHp, int maxHp);
	void EndingUi(Pokemon* MyPokemon);

private:

	Pokemon* MyPokemon;
	Pokemon* EnemyPokemon;

};

