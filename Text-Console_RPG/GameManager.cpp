#include "GameManager.h"
#include <conio.h> // _getch() 
#include <cstdlib> // system()
#include <Windows.h> // gotoXy
#include <random>
#pragma comment(lib, "WinMM.lib") // PlaySound()
#include <iomanip> // setw
#include <mmstream.h>

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
	// SND_ANYNC: 음악 재생 중에도 다음 코드 실행
	// SND_LOOP: 무한 반복
	PlaySound(TEXT("music/1-01.-Opening.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	uimanager.TitleUi(); //타이틀 UI

	_getch(); // 키 입력

	PlaySound(TEXT("music/pokemon_a_button.wav"), NULL, SND_FILENAME | SND_ASYNC);
	
	Sleep(500);

	system("cls"); // 클리어 시스템

	PlaySound(NULL, 0, 0);

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

// 색상 변경 함수
void setColor(int color) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void GameManager::SelectPokemon()
{
	if (player == nullptr) player = new Player(); // 추가 인벤토리문제 해결용
	//std::string PlayerName;
	Sleep(500);
	std::string s1 = "이름을 입력하세요: ";
	printtext.typeWritecin(s1);
	std::cin >> playerName;
	PlaySound(TEXT("music/pokemon_a_button.wav"), NULL, SND_FILENAME | SND_ASYNC); //Enter 효과음

	Sleep(500);

	//PlaySound(TEXT("music/1-03.-Professor-Oak.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //배경음
	mciSendString(TEXT("open \"music/1-03.-Professor-Oak.wav\" type mpegvideo alias bgm"), NULL, 0, NULL);
	mciSendString(TEXT("play bgm repeat"), NULL, 0, NULL);
	std::string s2 = "안녕하세요. " + playerName + "님!\n";
	printtext.typeWrite(s2);
	Sleep(1000);

	int cursor = 1;
	int key = 0;

	// --- 커서 선택 루프 시작 ---
	while (true)
	{
		gotoxy(0, 0);

		std::cout << "안녕하세요. " << playerName << "님!                      " << std::endl;

		uimanager.StarterUiTop(); //스타팅 포켓몬 선택 UI 상단

		// --- 1. 이상해씨 (선택 시 초록색: 10) ---
		if (cursor == 1) setColor(10);
		if (cursor == 1)
		{
			mciSendString(TEXT("close sfx"), NULL, 0, NULL);
			mciSendString(TEXT("open \"music/001-bulbasaur_1.wav\" alias sfx"), NULL, 0, NULL);
			mciSendString(TEXT("play sfx"), NULL, 0, NULL);
			//PlaySound(TEXT("music/001-bulbasaur_1.wav"), NULL, SND_FILENAME | SND_ASYNC); //이상해씨 울음소리
		}
		std::cout << "  1. 이상해씨   ";
		setColor(7); // 다시 흰색으로 복구

		// --- 2. 파이리 (선택 시 빨간색: 12) ---
		if (cursor == 2) setColor(12);
		if (cursor == 2)
		{
			mciSendString(TEXT("close sfx"), NULL, 0, NULL);
			mciSendString(TEXT("open \"music/004-charmander_1.wav\" alias sfx"), NULL, 0, NULL);
			mciSendString(TEXT("play sfx"), NULL, 0, NULL);
			//PlaySound(TEXT("music/004-charmander_1.wav"), NULL, SND_FILENAME | SND_ASYNC); //파이리 울음소리
		}	
		std::cout << "  2. 파이리   ";
		setColor(7);

		// --- 3. 꼬부기 (선택 시 하늘색: 11) ---
		if (cursor == 3) setColor(11);
		if (cursor == 3)
		{
			mciSendString(TEXT("close sfx"), NULL, 0, NULL);
			mciSendString(TEXT("open \"music/007-squirtle_1.wav\" alias sfx"), NULL, 0, NULL);
			mciSendString(TEXT("play sfx"), NULL, 0, NULL);
			//PlaySound(TEXT("music/007-squirtle_1.wav"), NULL, SND_FILENAME | SND_ASYNC); //꼬부기 울음소리
		}

		std::cout << "  3. 꼬부기    ";
		setColor(7);

		uimanager.StarterUiBottom(); //스타팅 포켓몬 선택 UI 하단

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
			PlaySound(TEXT("music/pokemon_a_button.wav"), NULL, SND_FILENAME | SND_ASYNC);
			mciSendString(TEXT("stop bgm"), NULL, 0, NULL);
			mciSendString(TEXT("close bgm"), NULL, 0, NULL);
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
	printtext.typeWrite(s);
	Sleep(1000);

	if (player == nullptr) {
		std::cout << "에러: 플레이어 객체가 생성되지 않았습니다!" << std::endl;
		return;
	}
	
	std::cout << "스타팅 패키지 : 상처약 x 5, 좋은 상처약 x 5 " << std::endl; //임시 아이템 
	player->GetInventory().AddGold(1000);  //기본 지급 골드
	player->GetInventory().Additem(Item("상처약", 50, 5, 10)); //임시 아이템 인벤토리에 추가 ("아이템 이름" 가격 수량 힐량)
	player->GetInventory().Additem(Item("좋은 상처약", 80, 5, 30));

	GameLoop();
}

void printHpBar(int currentHp, int maxHp)
{
	int barWidth = 20;
	float ratio = (float)currentHp / maxHp;
	if (ratio < 0)
	{
		ratio = 0;
	}
	int filled = (int)(barWidth * ratio);

	for (int i = 0; i < barWidth; ++i)
	{
		if (i < filled) std::cout << "█"; // 실제 2칸 차지
		else std::cout << "░";            // 실제 2칸 차지
	}
}



void GameManager::GameLoop()
{
	PlaySound(TEXT("music/1-06.-Road-to-Viridian-City-–-From-Pallet.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	while (true)
	{
		// SND_ANYNC: 음악 재생 중에도 다음 코드 실행
		// SND_LOOP: 무한 반복
		
		Sleep(500);
		system("cls");

		int choice;
		
		uimanager.VillageUi(playerName, MyPokemon); //마을 UI


		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
			PlaySound(NULL, 0, 0);

			BattleResult result = battlemanager.StartBattle(MyPokemon, player->GetInventory());

			if (result == BattleResult::Lose)
			{
				GameEnding();
				return;
			}
			PlaySound(TEXT("music/1-06.-Road-to-Viridian-City-–-From-Pallet.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			break;
		}
		case 2:
			std::cout << "상점 준비 중..." << std::endl;
			{
            	Store MyStore("포켓몬 센터 상점"); //("상점이름") 
            	MyStore.InStore(player->GetInventory());
            }
			PlaySound(NULL, 0, 0);
			break;
		case 3:
			PlaySound(TEXT("music/1-10.-Pokémon-Center.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			int CenterChoice;
			Sleep(1000);
			uimanager.PokemonCenterUi();
			std::cin >> CenterChoice;
			PlaySound(NULL, 0, 0);
			switch (CenterChoice)
			{
			case 1:
			{

				PlaySound(TEXT("music/healing-pokemon-sound.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				Sleep(500);
				MyPokemon->recoveryHp();
				std::cout << MyPokemon->getName() << "체력을 모두 회복했습니다." << std::endl;
				Sleep(3000);
				PlaySound(TEXT("music/1-06.-Road-to-Viridian-City-–-From-Pallet.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			}
			break;
			case 2:
			{
				std::cout << "포켓몬 센터를 나갑니다." << std::endl;
				PlaySound(TEXT("music/1-06.-Road-to-Viridian-City-–-From-Pallet.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			}
			break;
			default:
				std::cout << "잘못된 입력입니다." << std::endl;
				PlaySound(TEXT("music/1-06.-Road-to-Viridian-City-–-From-Pallet.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			}
			break;
		case 4:
			std::cout << "게임을 종료합니다." << std::endl;
			PlaySound(NULL, 0, 0);
			exit(0);
			break;
		default:
			std::cout << "잘못된 입력입니다. 다시 선택해주세요." << std::endl;
			break;
		}
	}
}

void GameManager::GameEnding()
{
	std::cout << "╔═══════════════════════════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "║                                                                           ║" << std::endl;
	std::cout << "║    ██████╗  █████╗ ███╗   ███╗███████╗ ██████╗ ██╗   ██╗███████╗██████╗   ║" << std::endl;
	std::cout << "║   ██╔════╝ ██╔══██╗████╗ ████║██╔════╝██╔═══██╗██║   ██║██╔════╝██╔══██╗  ║" << std::endl;
	std::cout << "║   ██║  ███╗███████║██╔████╔██║█████╗  ██║   ██║██║   ██║█████╗  ██████╔╝  ║" << std::endl;
	std::cout << "║   ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗  ║" << std::endl;
	std::cout << "║   ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗╚██████╔╝ ╚████╔╝ ███████╗██║  ██║  ║" << std::endl;
	std::cout << "║    ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝ ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝  ║" << std::endl;
	std::cout << "║                                                                           ║" << std::endl;
	std::cout << "╚═══════════════════════════════════════════════════════════════════════════╝" << std::endl;
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	std::cout << "┃                                                                           ┃\n";
	std::cout << "┃                " << MyPokemon->getName() << "가 기절했습니다!!                                  ┃\n";
	std::cout << "┃                                                                           ┃\n";
	std::cout << "┃                교체할 포켓몬이 없습니다...!                               ┃\n";
	std::cout << "┃                                                                           ┃\n";
	std::cout << "┃                                                                           ┃\n";
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	//std::cout << "포켓몬이 기절했습니다...! " << std::endl;
	//std::cout << "교체할 포켓몬이 없습니다...! " << std::endl;
	//std::cout << "태초마을로 돌아갑니다...!" << std::endl;
	//std::cout << "Game Over!!!" << std::endl;
	exit(0);
}

