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

// 커서 (0,0) 조정
void gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hConsole, pos);
}
// 텍스트 한글자씩
void typeWrite(const std::string& text)
{
	for (char c : text)
	{
		std::cout << c;
		std::cout.flush();
		Sleep(20); // 속도 조절 (밀리초)
	}
	std::cout << std::endl;
}
// 색상 변경 함수
void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void GameManager::SelectPokemon()
{
	std::string PlayerName;
	std::cout << "이름 입력하세요: ";
	std::cin >> PlayerName;

	std::cout << "안녕하세요. " << PlayerName << "님!" << std::endl;
	Sleep(1000);

	int cursor = 1;
	int key = 0;

	// --- 커서 선택 루프 시작 ---
	while (true)
	{
		gotoxy(0, 0);

		std::cout << "안녕하세요. " << PlayerName << "님!                      " << std::endl;
		std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
		std::cout << "┃                                                       ┃" << std::endl;
		std::cout << "┃           [ 스타팅 포켓몬을 선택하세요! ]             ┃" << std::endl;
		std::cout << "┃                                                       ┃" << std::endl;
		std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << std::endl;
		std::cout << "┃                                                       ┃" << std::endl;
		std::cout << "┃                                                       ┃" << std::endl;
		std::cout << "┃      ";
		// --- 1. 이상해씨 (선택 시 초록색: 10) ---
		if (cursor == 1) setColor(10);
		std::cout << "  1. 이상해씨   ";
		setColor(7); // 다시 흰색으로 복구

		// --- 2. 파이리 (선택 시 빨간색: 12) ---
		if (cursor == 2) setColor(12);
		std::cout << "  2. 파이리   ";
		setColor(7);

		// --- 3. 꼬부기 (선택 시 하늘색: 11) ---
		if (cursor == 3) setColor(11);
		std::cout << "  3. 꼬부기    ";
		setColor(7);

		std::cout << "    ┃" << std::endl;
		std::cout << "┃                                                       ┃" << std::endl;
		std::cout << "┃                                                       ┃" << std::endl;
		std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
		std::cout << " (방향키 ◀ ▶ 이동 / Enter 선택)          " << std::endl;

		key = _getch(); // 키보드 입력 받기

		if (key == 224) // 방향키 특수 값
		{
			key = _getch();
			if (key == 75) // 왼쪽 방향키
			{
				if (cursor > 1) cursor--;
			}
			else if (key == 77) // 오른쪽 방향키
			{
				if (cursor < 3) cursor++;
			}
		}
		else if (key == 13) // Enter 키
		{
			break; // 루프 탈출
		}
	}
	// --- 커서 선택 루프 종료 ---

	// 선택된 cursor 값에 따라 객체 생성
	switch (cursor)
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
	}



	std::string s = MyPokemon->getName() + "로 게임을 시작합니다";
	typeWrite(s);
	Sleep(1000);


	std::cout << "스타팅 패키지 : 상처약 x 5, 좋은 상처약 x 5 " << std::endl; //임시 아이템
	inventory.Additem(Item("상처약", 50, 10)); //임시 아이템 인벤토리에 추가
	inventory.Additem(Item("상처약", 50, 10));
	inventory.Additem(Item("상처약", 50, 10));
	inventory.Additem(Item("상처약", 50, 10));
	inventory.Additem(Item("상처약", 50, 10));
	inventory.Additem(Item("좋은 상처약", 80, 30));
	inventory.Additem(Item("좋은 상처약", 80, 30));
	inventory.Additem(Item("좋은 상처약", 80, 30));
	inventory.Additem(Item("좋은 상처약", 80, 30));
	inventory.Additem(Item("좋은 상처약", 80, 30));


	std::cout << MyPokemon->getName() << "로 게임을 시작합니다" << std::endl;

	StartBattle();
}

//void SetColor(int Color)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
//}

void GameManager::StartBattle()
{
	system("cls");

#pragma region 전투 UI
	//std::cout << "┌──────────────────────────────────────────────────────────────┐\n";
	//std::cout << "│                                                              │\n";
	//std::cout << "│  ┌──────────────────────────────┐                            │\n";
	//std::cout << "│  │ 꼬렛                   L13   │                            │\n";
	//std::cout << "│  │      HP: ██████████░░░░░░░░  │                            │\n";
	//std::cout << "│  └──────────────────────────────┘                            │\n";
	//std::cout << "│                                            /\\                │\n";
	//std::cout << "│                                           /  \\               │\n";
	//std::cout << "│                                          ( 적포켓몬 )        │\n";
	//std::cout << "│                                           \\__/               │\n";
	//std::cout << "│                                                              │\n";
	//std::cout << "│                                                              │\n";
	//std::cout << "│        /\\                                                    │\n";
	//std::cout << "│       /  \\                                                   │\n";
	//std::cout << "│      ( 내포켓몬 )                                            │\n";
	//std::cout << "│       \\__/                 ┌──────────────────────────────┐  │\n";
	//std::cout << "│                            │ "<< MyPokemon->getName() <<"                 L14 │  │\n";
	//std::cout << "│                            │      HP: ██████████░░░░░░░░  │  │\n";
	//std::cout << "│                            └──────────────────────────────┘  │\n";
	//std::cout << "├──────────────────────────────────────┬───────────────────────┤\n";
	//std::cout << "│  무엇을 할까?                        │ 싸운다      가방      │\n";
	//std::cout << "│                                      │ 포켓몬       도망     │\n";
	//std::cout << "└──────────────────────────────────────┴───────────────────────┘\n";
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
	
	bool IsBattle = true;
	bool IsOpenBag = true;

	std::string s = "야생의 " + EnemyPokemon->getName() + "가 나타났다!";
	typeWrite(s);
	Sleep(500);

	std::cout << std::endl;

	std::string s2 = "가랏! " + MyPokemon->getName() + "!!";
	typeWrite(s2);
	Sleep(500);

	std::cout << std::endl;


	while (IsBattle)
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
				IsBattle = false;
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
			IsOpenBag = true;
			std::cout << "가방 목록" << std::endl;
			inventory.Printallitems();
			
			int BagChoice;

			std::cout << "4. 인벤토리 나가기!" << std::endl;
		

			std::cout << "입력 하세요: ";
			std::cin >> BagChoice;

			if (BagChoice == 1)
			{

				inventory.UseItem(1); //아이템 사용
				int NewHp = MyPokemon->getHp() + 10; //임시 아이템 체력 +10
				MyPokemon->setHP(NewHp); //체력 설정
				std::cout << "아이템을 사용했습니다!" << std::endl;
				break;
			}
			else if (BagChoice == 4)
			{
				std::cout << "인벤토리를 나갑니다!" << std::endl;
				IsOpenBag = false;
				break;
			}
			break;
		case 3:
			MyPokemon->printStatus();
			break;
		case 4:
			std::cout << "무사히 도망쳤다!" << std::endl;
			delete EnemyPokemon;
			EnemyPokemon = nullptr;
			IsBattle = false;
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

