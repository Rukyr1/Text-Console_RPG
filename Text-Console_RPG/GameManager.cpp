#include "GameManager.h"
#include <conio.h> // _getch() 
#include <cstdlib> // system()
#include <Windows.h>
#include <random>

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

	SelectPokemon();

	return;
}

void GameManager::SelectPokemon()
{
	std::string PlayerName;
	std::cout << "이름 입력하세요: ";
	std::cin >> PlayerName;
	
	std::cout << "안녕하세요. " << PlayerName << "님!" << std::endl;

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
	StartBattle();


}

void GameManager::StartBattle()
{
	system("cls");

#pragma region 전투 UI
	/*std::cout << "┌──────────────────────────────────────────────────────────────┐\n";
	std::cout << "│                                                              │\n";
	std::cout << "│  ┌──────────────────────────────┐                            │\n";
	std::cout << "│  │ 꼬렛                   L13   │                            │\n";
	std::cout << "│  │      HP: ██████████░░░░░░░░  │                            │\n";
	std::cout << "│  └──────────────────────────────┘                            │\n";
	std::cout << "│                                            /\\                │\n";
	std::cout << "│                                           /  \\               │\n";
	std::cout << "│                                          ( 적포켓몬 )        │\n";
	std::cout << "│                                           \\__/               │\n";
	std::cout << "│                                                              │\n";
	std::cout << "│                                                              │\n";
	std::cout << "│        /\\                                                    │\n";
	std::cout << "│       /  \\                                                   │\n";
	std::cout << "│      ( 내포켓몬 )                                            │\n";
	std::cout << "│       \\__/                 ┌──────────────────────────────┐  │\n";
	std::cout << "│                            │ "<< MyPokemon->getName() <<"                 L14 │  │\n";
	std::cout << "│                            │      HP: ██████████░░░░░░░░  │  │\n";
	std::cout << "│                            └──────────────────────────────┘  │\n";
	std::cout << "├──────────────────────────────────────┬───────────────────────┤\n";
	std::cout << "│  무엇을 할까?                        │ 싸운다      가방      │\n";
	std::cout << "│                                      │ 포켓몬       도망     │\n";
	std::cout << "└──────────────────────────────────────┴───────────────────────┘\n";*/
#pragma endregion

	EnemyPokemon = nullptr;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 3);

	int RandomNumber = dist(gen);
	
	switch (RandomNumber)
	{
	case 1:
		EnemyPokemon = new Bulbasaur(); // 이상해씨
		break;
	case 2:
		EnemyPokemon = new Charmander(); // 파이리
		break;
	case 3:
		EnemyPokemon = new Squirtle(); // 꼬부기
		break;
	}
	
	std::cout << "야생의 " << EnemyPokemon->getName() << "가 나타났다!" << std::endl;
	std::cout << "가랏! " << MyPokemon->getName() << "!!" << std::endl;

	while (true)
	{
		int PlayerChoice;

		std::cout << "무엇을 할까?" << std::endl;
		std::cout << "1.공격 2.가방 3.스탯 4.도망" << std::endl;
		std::cin >> PlayerChoice;

		switch (PlayerChoice)
		{
		case 1:
			std::cout << MyPokemon->getName() <<"의 공격!" << std::endl;
			MyPokemon->skill();
			EnemyPokemon->takeDamage(MyPokemon->getAttack());

			if (EnemyPokemon->getHp() <= 0)
			{
				std::cout << EnemyPokemon->getName() << " 이(가) 쓰러졌다!" << std::endl;
				delete EnemyPokemon;
				EnemyPokemon = nullptr;
				MyPokemon->levelUp();
				GameLoop();
				break;
			}
			// 적 공격
			EnemyPokemon->skill();
			MyPokemon->takeDamage(EnemyPokemon->getAttack());

			if (MyPokemon->getHp() <= 0)
			{
				GameEnding();
				return;
			}
			break;
		case 2:
			std::cout << "가방 목록" << std::endl;
			break;
		case 3:
			MyPokemon->printStatus();
			break;
		case 4:
			std::cout << "무사히 도망쳤다!" << std::endl;
			delete EnemyPokemon;
			EnemyPokemon = nullptr;
			GameLoop();
			break;
		case 5:
			GameEnding();
			return;
		default:
			std::cout << "잘못된 입력입니다. 다시 선택해주세요." << std::endl;
		}
	}
}

void GameManager::GameLoop()
{
	while (true)
	{
		int choice;
		std::cout << "<< [마을] 무엇을 할까? >> " << std::endl;
		std::cout << "1. 풀숲으로 간다(전투)" << std::endl;
		std::cout << "2. 휴식(휴식)" << std::endl;
		std::cout << "3. 종료" << std::endl;
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			StartBattle();
			break;
		case 2:
			MyPokemon->recoveryHp();
			std::cout << MyPokemon->getName() << "체력을 모두 회복했습니다." << std::endl;
			break;
		case 3:
			std::cout << "게임을 종료합니다." << std::endl;
			return;
		default:
			std::cout << "잘못된 입력입니다. 다시 선택해주세요." << std::endl;
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

