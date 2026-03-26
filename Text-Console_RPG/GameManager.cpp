#include "GameManager.h"

GameManager::GameManager()
{
	player = new Player();
	

}

GameManager::~GameManager()
{
	delete player;
	player = nullptr;

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


	

}
