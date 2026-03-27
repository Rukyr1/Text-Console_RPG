#include "GameManager.h"

GameManager::GameManager()
{
	player = new Player();
	MyPokemon = nullptr;

}

GameManager::~GameManager()
{
	delete player;
	player = nullptr;
	delete MyPokemon;
}

void GameManager::GameStart()
{
	std::string PlayerName;
	std::cout << "이름 입력하세요." << std::endl;
	std::cin >> PlayerName;
	
	std::cout << "안녕하세요. " << PlayerName << "님!" << std::endl;

	player = new Player();

	//MyPokemon* starter = selectStarterPokemon();
	
	int Choice = 0;
	
	std::cout << "스타팅 포켓몬을 선택하세요~" << std::endl;
	std::cout << "1. 이상해씨" << std::endl;
	std::cout << "2. 꼬부기" << std::endl;
	std::cout << "3. 파이리" << std::endl;
	std::cout << "입력: ";
	std::cin >> Choice;

	switch (Choice)
	{
	case 1:
		MyPokemon = new Bulbasaur();
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		std::cout << "잘못된 선택입니다." << std::endl;
		break;
	}

	//std::cout << MyPokemon->PName << "로 게임을 시작합니다" << std::endl;
	//StartBattle();
}

void GameManager::StartBattle()
{
	Pokemon* EnemyPokemon = new Bulbasaur();
	//EnemyPokemon->PName = "야생의 이상해씨";

	//std::cout << EnemyPokemon->PName << "가 나타났다!" << std::endl;

	/*while (MyPokemon->PHp >= 0 && EnemyPokemon->PHp >= 0)
	{
		std::cout << "무엇을 할까?";
	}*/
}

void GameManager::GameEnding()
{
	std::cout << "포켓몬이 기절했습니다...! " << std::endl;
	std::cout << "교체할 포켓몬이 없습니다...! " << std::endl;
	std::cout << "태초마을로 돌아갑니다...!" << std::endl;
	std::cout << "Game Over!!!" << std::endl;
}