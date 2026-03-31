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
	audio.OpeningBgm();

	uimanager.TitleUi(); //타이틀 UI

	_getch(); // 키 입력

	audio.EnterSfx();
	
	Sleep(500);

	system("cls"); // 클리어 시스템

	PlaySound(NULL, 0, 0);

	//SelectPokemon();
	IntroScreen();

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

void GameManager::IntroScreen()
{
	Sleep(1000);
	audio.IntroBgm();
	Sleep(700);

	std::string s1 = "음, 잘 왔네!";
	printtext.typeWriteSlow(s1);
	_getch();
	PlaySound(TEXT("music/pokemon_a_button.wav"), NULL, SND_FILENAME | SND_ASYNC); //Enter 효과음
	Sleep(200);
	std::string s2 = "포켓몬스터의 세계에 온 것을 환영한다!";
	printtext.typeWriteSlow(s2);
	_getch();
	PlaySound(TEXT("music/pokemon_a_button.wav"), NULL, SND_FILENAME | SND_ASYNC); //Enter 효과음
	Sleep(200);
	std::string s3 = "그런데 자네, 모험은 이번이 처음인가?";
	printtext.typeWriteSlow(s3);
	Sleep(200);
	std::string s4 = "괜찮으면 내가 요모조모로 알려주겠네.";
	printtext.typeWriteSlow(s4);
	Sleep(300);
	std::string s5 = "자네의 이름은 뭔가?";
	printtext.typeWriteSlow(s5);
	Sleep(400);

	std::string s6 = "이름을 입력하세요: ";
	printtext.typeWritecin(s6);
	std::cin >> playerName;
	audio.EnterSfx();
	std::string s7 = "흠... ";
	printtext.typeWriteSlow200(s7);
	Sleep(300);
	std::string s8 = "[" + playerName + "]라고 하는가. ";
	Sleep(500);
	printtext.typeWriteSlow20(s8);
	std::string s9 = "좋은 이름이군!";
	Sleep(500);
	printtext.typeWrite20(s9);
	_getch();
	std::string s10 = "이 세계에는 포켓몬스터, ";
	printtext.typeWriteSlow20(s10);
	Sleep(300);
	std::string s11 = "줄여서 “포켓몬”이라 불리는 신비한 생물이 곳곳마다 살고 있네.";
	printtext.typeWrite20(s11);
	_getch();
	std::string s12 = "자네에게 포켓몬을 주겠네. ";
	printtext.typeWriteSlow20(s12);
	Sleep(500);
	std::string s13 = "데리고 여행을 떠나 보게나.";
	printtext.typeWrite20(s13);
	Sleep(300);

	std::cout << std::endl;

	std::string s14 = "여정을 떠난다.(계속하려면 아무 키나 입력하세요..)";
	printtext.typeWrite(s14);
	_getch();
	SelectPokemon();
}

void GameManager::SelectPokemon()
{
	/*std::string s6 = "이름을 입력하세요: ";
	printtext.typeWritecin(s6);
	std::cin >> playerName;*/
	if (player == nullptr) player = new Player(); // 추가 인벤토리문제 해결용
	//std::string PlayerName;
	Sleep(500);
	system("cls");
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
			audio.BulbasaurSfx();
		}
		std::cout << "  1. 이상해씨   ";
		setColor(7); // 다시 흰색으로 복구

		// --- 2. 파이리 (선택 시 빨간색: 12) ---
		if (cursor == 2) setColor(12);
		if (cursor == 2)
		{
			audio.CharmanderSfx();
		}	
		std::cout << "  2. 파이리   ";
		setColor(7);

		// --- 3. 꼬부기 (선택 시 하늘색: 11) ---
		if (cursor == 3) setColor(11);
		if (cursor == 3)
		{
			audio.SquirtleSfx();
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
			audio.EnterSfx();
			audio.StopAudio();
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

	std::string s3 = MyPokemon->getName() + "로 게임을 시작합니다";
	printtext.typeWrite(s3);
	Sleep(500);

	if (player == nullptr) {
		std::cout << "에러: 플레이어 객체가 생성되지 않았습니다!" << std::endl;
		return;
	}
	
	std::string s4 = "스타팅 패키지 : 상처약 x 5, 좋은 상처약 x 5";//임시 아이템
	printtext.typeWrite(s4);
	Sleep(1000);
	player->GetInventory().AddGold(1000);  //기본 지급 골드
	player->GetInventory().Additem(Item("상처약", 150, 5, 20)); //임시 아이템 인벤토리에 추가 ("아이템 이름",가격,수량,힐량)
	player->GetInventory().Additem(Item("좋은상처약", 350, 5, 60));

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


//------------마을------------
void GameManager::GameLoop()
{
	audio.VillageBgm();
	while (true)
	{
		// SND_ANYNC: 음악 재생 중에도 다음 코드 실행
		// SND_LOOP: 무한 반복
		
		Sleep(500);
		system("cls");

		int choice;
		
		uimanager.VillageUi(playerName, MyPokemon, player); //마을 UI


		std::cin >> choice;

		switch (choice)
		{
		case 1: //전투
		{
			//PlaySound(NULL, 0, 0);

			BattleResult result = battlemanager.StartBattle(MyPokemon, player->GetInventory(), player, false);

			if (result == BattleResult::Lose)
			{
				GameEnding();
				return;
			}
			audio.VillageBgm();
			break;
		}
		case 2: //상점
		{
			audio.CenterShopBgm();
			int ShopChoice;
			uimanager.ShopUi(player);
			std::cout << "입력: ";
			std::cin >> ShopChoice;

			if (ShopChoice == 1) //구매
			{
				uimanager.ShopBuyUi(player);
				store.InStore(player->GetInventory());
			}
			else if (ShopChoice == 2) //판매
			{
				int SellChoice;
				uimanager.ShopSellUi(player);
				std::cin >> SellChoice;
				if (SellChoice == 0)
				{
					std::cout << "포켓몬 상점을 나갑니다." << std::endl;
					Sleep(1000);
					PlaySound(NULL, 0, 0);
					audio.VillageBgm();
					break;
				}
				else
				{
					std::cout << "아직 판매할 수 없습니다. 다음에 다시 방문하세요~!" << std::endl;
					Sleep(1000);
					audio.VillageBgm();
					break;
				}
				//판매기능
			}
			else if (ShopChoice == 0) //나가기
			{
				std::cout << "포켓몬 상점을 나갑니다." << std::endl;
				Sleep(1000);
				audio.VillageBgm();
				break;
			}
			else
			{
				std::cout << "잘못된 입력입니다." << std::endl;
			}
			
        }
			PlaySound(NULL, 0, 0);
			break;
		case 3: //회복
			audio.CenterShopBgm();
			int CenterChoice;
			Sleep(1000);
			uimanager.PokemonCenterUi();
			std::cout << "입력: ";
			std::cin >> CenterChoice;
			PlaySound(NULL, 0, 0);
			switch (CenterChoice)
			{
			case 1:
			{
				audio.HealSfx();
				Sleep(500);
				MyPokemon->recoveryHp();
				std::cout << MyPokemon->getName() << "체력을 모두 회복했습니다." << std::endl;
				Sleep(3000);
				audio.VillageBgm();
				
			}
			break;
			case 2:
			{
				std::cout << "포켓몬 센터를 나갑니다." << std::endl;
				audio.VillageBgm();
			}
			break;
			default:
				std::cout << "잘못된 입력입니다." << std::endl;
				audio.VillageBgm();
			}
			break;
		case 4: //종료
			std::cout << "게임을 종료합니다." << std::endl;
			PlaySound(NULL, 0, 0);
			exit(0);
			break;
		case 5:
		{
			audio.EnterSfx();
		
			if (MyPokemon->getLevel() >= 10)//히든 스테이지 충족 조건
			{
				std::cout << "조건을 만족했습니다! 히든 스테이지로 이동합니다..." << std::endl;
				PlaySound(NULL, 0, 0); 

				system("cls");
				BattleResult result = battlemanager.StartBattle(MyPokemon, player->GetInventory(), player, true);

				//HiddenStage(); 
				audio.VillageBgm();
				
			}
			else //레벨 부족할 시
			{
				std::cout << "레벨이 부족합니다! (현재 레벨: " << MyPokemon->getLevel() << " / 필요 레벨: 10)" << std::endl;
				Sleep(1500);
			}
			break;
		}
		case 6:
		{
			PlaySound(NULL, 0, 0);
			system("cls");
			
			BattleResult result = battlemanager.StartBattle(MyPokemon, player->GetInventory(), player, true);
			break;
		}
		default:
			std::cout << "잘못된 입력입니다. 다시 선택해주세요." << std::endl;
			break;
		}
	}
}

void GameManager::GameEnding() //게임종료시 호출되는 함수입니다.여기서 게임종료란 전투에서 패배입니다.
{
	Sleep(500); //500ms(0.5.초 일시정지)
	system("cls"); //콘솔화면 클리어 시스템
	
	audio.EndingBgm();
	uimanager.EndingUi(MyPokemon); //uimanger객체생성, MyPokemon으로 인자를 받아 EndingUi를 불러옵니다.
	exit(0);
}

