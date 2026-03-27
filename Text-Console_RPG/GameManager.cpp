#include "GameManager.h"
#include <conio.h> // _getch() 
#include <cstdlib> // system()
#include <Windows.h>

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
	/*std::cout << "  ██████╗  ██████╗ ██╗  ██╗███████╗███╗   ███╗ ██████╗ ███╗   ██╗ " << std::endl;
	std::cout << "  ██╔══██╗██╔═══██╗██║ ██╔╝██╔════╝████╗ ████║██╔═══██╗████╗  ██║ " << std::endl;
	std::cout << "  ██████╔╝██║   ██║█████╔╝ █████╗  ██╔████╔██║██║   ██║██╔██╗ ██║ " << std::endl;
	std::cout << "  ██╔═══╝ ██║   ██║██╔═██╗ ██╔══╝  ██║╚██╔╝██║██║   ██║██║╚██╗██║ " << std::endl;
	std::cout << "  ██║     ╚██████╔╝██║  ██╗███████╗██║ ╚═╝ ██║╚██████╔╝██║ ╚████║ " << std::endl;
	std::cout << "  ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ " << std::endl;
	std::cout << "           ██╗    ██╗ ██████╗ ██████╗ ██╗     ██████╗ " << std::endl;
	std::cout << "           ██║    ██║██╔═══██╗██╔══██╗██║     ██╔══██╗" << std::endl;
	std::cout << "           ██║ █╗ ██║██║   ██║██████╔╝██║     ██║  ██║" << std::endl;
	std::cout << "           ██║███╗██║██║   ██║██╔══██╗██║     ██║  ██║" << std::endl;
	std::cout << "           ╚███╔███╔╝╚██████╔╝██║  ██║███████╗██████╔╝" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "                       아무 키나 입력하세요";*/


	std::cout << "╔═══════════════════════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "║                                                                       ║" << std::endl;
	std::cout << "║    ██████╗  ██████╗ ██╗  ██╗███████╗███╗   ███╗ ██████╗ ███╗   ██╗    ║" << std::endl;
	std::cout << "║    ██╔══██╗██╔═══██╗██║ ██╔╝██╔════╝████╗ ████║██╔═══██╗████╗  ██║    ║" << std::endl;
	std::cout << "║    ██████╔╝██║   ██║█████╔╝ █████╗  ██╔████╔██║██║   ██║██╔██╗ ██║    ║" << std::endl;
	std::cout << "║    ██╔═══╝ ██║   ██║██╔═██╗ ██╔══╝  ██║╚██╔╝██║██║   ██║██║╚██╗██║    ║" << std::endl;
	std::cout << "║    ██║     ╚██████╔╝██║  ██╗███████╗██║ ╚═╝ ██║╚██████╔╝██║ ╚████║    ║" << std::endl;
	std::cout << "║    ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝    ║" << std::endl;
	std::cout << "║                                                                       ║" << std::endl;
	std::cout << "║              ██╗    ██╗ ██████╗ ██████╗ ██╗     ██████╗               ║" << std::endl;
	std::cout << "║              ██║    ██║██╔═══██╗██╔══██╗██║     ██╔══██╗              ║" << std::endl;
	std::cout << "║              ██║ █╗ ██║██║   ██║██████╔╝██║     ██║  ██║              ║" << std::endl;
	std::cout << "║              ██║███╗██║██║   ██║██╔══██╗██║     ██║  ██║              ║" << std::endl;
	std::cout << "║              ╚███╔███╔╝╚██████╔╝██║  ██║███████╗██████╔╝              ║" << std::endl;
	std::cout << "║              ╚══╝╚══╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═════╝                 ║" << std::endl;
	std::cout << "║                                                                       ║" << std::endl;
	std::cout << "╚═══════════════════════════════════════════════════════════════════════╝" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "                          아무 키나 입력하세요";


	_getch(); // 키 입력
	system("cls"); // 클리어 시스템

	SelectCharacter();

	return;
}

void GameManager::SelectCharacter()
{
	std::string PlayerName;
	std::cout << "이름 입력하세요: ";
	std::cin >> PlayerName;
	
	std::cout << "안녕하세요. " << PlayerName << "님!" << std::endl;

	player = new Player();

	//MyPokemon* starter = selectStarterPokemon();
	
	int Choice = 0;
	
	std::cout << "스타팅 포켓몬을 선택하세요~" << std::endl;
	std::cout << "1. 이상해씨" << std::endl;
	std::cout << "2. 파이리" << std::endl;
	std::cout << "3. 꼬부기" << std::endl;
	std::cout << "입력: ";
	std::cin >> Choice;

	switch (Choice)
	{
	case 1:
		MyPokemon = new Bulbasaur(); // 이상해씨
		break;
	case 2:
		MyPokemon = new Charmander(); // 파이리
		break;
	case 3:
		MyPokemon = new Squirtle(); // 꼬부기
		break;
	default:
		std::cout << "잘못된 선택입니다." << std::endl;
		break;
	}

	std::cout << MyPokemon->getName() << "로 게임을 시작합니다" << std::endl;
	//StartBattle();


}

void GameManager::StartBattle()
{
	Pokemon* Pokemon = new Bulbasaur();

	std::cout << "야생의 " << Pokemon->getName() << "가 나타났다!" << std::endl;

	/*while (MyPokemon->PHp >= 0 && EnemyPokemon->PHp >= 0)
	{
		std::cout << "무엇을 할까?";
	}*/

	//IsBattle = true;
	//Pokemon->PPrintStats(); 내 포켓몬 스탯(상태) 출력
	//EnemyPokemon->PPrintStats(); 적 포켓몬 스탯(상태) 출력

	while (true)
	{
		int AtkChoice;

		std::cout << "무엇을 할까?" << std::endl;
		std::cout << "1. 공격 2. 가방 3. 도망" << std::endl;
		std::cin >> AtkChoice;

		//IsTurnPass = false;

		switch (AtkChoice)
		{
		case 1:
			//std::cout << Pokemon->getName() << "의 공격!" << std::endl;
			//MyPokemon->skill();
			//Pokemon->takeDamage(Pokemon->takeDamage(int PAttackPower));

			//에너미 포켓몬 데미지가 어쩌구~ if문~

			//IsTurnPass = true;

			std::cout << "이상해씨의 공격!" << std::endl;
			break;

		case 2:
			break;

		case 3:
			break;

		}
	}
}

void GameManager::GameEnding()
{
	std::cout << "포켓몬이 기절했습니다...! " << std::endl;
	std::cout << "교체할 포켓몬이 없습니다...! " << std::endl;
	std::cout << "태초마을로 돌아갑니다...!" << std::endl;
	std::cout << "Game Over!!!" << std::endl;

}

