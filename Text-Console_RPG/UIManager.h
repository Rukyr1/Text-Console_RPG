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
	void BattleUiBottom(int cursorX, int cursorY);
	void VillageUi(std::string playerName, Pokemon* MyPokemon, Player* player);
	void VillageHiddenUi(std::string playerName, Pokemon* MyPokemon, Player* player);
	void PokemonCenterUi();
	void ShopUi();
	void ShopBuyUi();
	void ShopSellUi();

	void printHpBar(int currentHp, int maxHp);
	void EndingUi(Pokemon* MyPokemon); //게임종료(전투패배)시 나타나는 엔딩UI 정의 입니다.

private:

	Pokemon* MyPokemon;
	Pokemon* EnemyPokemon;
	Inventory<Item> inventory;

};

