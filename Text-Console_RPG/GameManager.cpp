#include "GameManager.h"
#include <conio.h> // _getch() 
#include <cstdlib> // system()
#include <Windows.h> // gotoXy
#include <random>
#pragma comment(lib, "WinMM.lib") // PlaySound()
#include <iomanip> // setw

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
	std::cout << "║               ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═════╝               ║" << std::endl;
	std::cout << "║                                                                       ║" << std::endl;
	std::cout << "╚═══════════════════════════════════════════════════════════════════════╝" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "                          아무 키나 입력하세요";

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
// 텍스트 한글자씩
void typeWrite(const std::string& text)
{
	for (char c : text)
	{
		std::cout << c;
		std::cout.flush();
		Sleep(10); // 속도 조절 (밀리초)
	}
	std::cout << std::endl;
}
void typeWritecin(const std::string& text)
{
	for (char c : text)
	{
		std::cout << c;
		std::cout.flush();
		Sleep(10);
	}
}



// 색상 변경 함수
void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void GameManager::SelectPokemon()
{
	std::string PlayerName;
	
	std::string s1 = "이름을 입력하세요: ";
	typeWritecin(s1);
	std::cin >> PlayerName;
	
	std::string s2 = "안녕하세요. " + PlayerName + "님!\n";
	typeWrite(s2);
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


	//std::cout << "스타팅 패키지 : 상처약 x 5, 좋은 상처약 x 5 " << std::endl; //임시 아이템
	//inventory.Additem(Item("상처약", 50, 10)); //임시 아이템 인벤토리에 추가
	//inventory.Additem(Item("상처약", 50, 10));
	//inventory.Additem(Item("상처약", 50, 10));
	//inventory.Additem(Item("상처약", 50, 10));
	//inventory.Additem(Item("상처약", 50, 10));
	//inventory.Additem(Item("좋은 상처약", 80, 30));
	//inventory.Additem(Item("좋은 상처약", 80, 30));
	//inventory.Additem(Item("좋은 상처약", 80, 30));
	//inventory.Additem(Item("좋은 상처약", 80, 30));
	//inventory.Additem(Item("좋은 상처약", 80, 30));

	StartBattle();
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

void GameManager::StartBattle()
{
	system("cls");

	int cursor = 1;
	int key = 0;

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
	PlaySound(TEXT("music/1-07.-Battle-_VS-Wild-Pokémon_.wav"), NULL, SND_FILENAME | SND_ASYNC);
	Sleep(1000);

	// ███████░░░░░░░░
#pragma region 전투 UI
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	std::cout << "┃                                                              ┃\n";
	std::cout << "┃  ┌──────────────────────────────┐                            ┃\n";
	// 왼쪽 정렬(left)과 15칸 고정(setw)으로 이름 길이가 달라도 테두리가 깨지지 않음
	std::cout << "┃  │ " << std::left << std::setw(15) << EnemyPokemon->getName() << " L13              │                            ┃\n";
	std::cout << "┃  │      HP: ";
	printHpBar(EnemyPokemon->getHp(), EnemyPokemon->getPMaxHp()); // HP 바 출력
	std::cout << "  │                            ┃\n";
	std::cout << "┃  └──────────────────────────────┘                            ┃\n";
	std::cout << "┃                                            /\\                ┃\n";
	std::cout << "┃                                           /  \\               ┃\n";
	std::cout << "┃                                          ( 적포켓몬 )        ┃\n";
	std::cout << "┃                                           \\__/               ┃\n";
	std::cout << "┃                                                              ┃\n";
	std::cout << "┃                                                              ┃\n";
	std::cout << "┃        /\\                                                    ┃\n";
	std::cout << "┃       /  \\                                                   ┃\n";
	std::cout << "┃      ( 내포켓몬 )                                            ┃\n";
	std::cout << "┃       \\__/                 ┌──────────────────────────────┐  ┃\n";
	std::cout << "┃                            │ " << std::left << std::setw(15) << MyPokemon->getName() << " L14 │  ┃\n";
	std::cout << "┃                            │      HP: ";
	printHpBar(MyPokemon->getHp(), MyPokemon->getPMaxExp()); // 내 HP 바 출력
	std::cout << "  │  ┃\n";
	std::cout << "┃                            └──────────────────────────────┘  ┃\n";
	std::cout << "├──────────────────────────────────────┬───────────────────────┤\n";
	std::cout << "┃  무엇을 할까?                        ┃ 싸운다      가방      ┃\n";
	std::cout << "┃                                      ┃ 포켓몬       도망     ┃\n";
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
#pragma endregion

	bool IsBattle = true;
	bool IsOpenBag = true;

	std::string s = "야생의 " + EnemyPokemon->getName() + "가 나타났다!";
	typeWrite(s);
	Sleep(500);

	std::string s2 = "가랏! " + MyPokemon->getName() + "!!";
	typeWrite(s2);
	Sleep(500);

	std::cout << std::endl;

	while (IsBattle)
	{
		system("cls"); // UI 갱신

		std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		std::cout << "┃                                                              ┃\n";
		std::cout << "┃  ┌──────────────────────────────┐                            ┃\n";
		// 왼쪽 정렬(left)과 15칸 고정(setw)으로 이름 길이가 달라도 테두리가 깨지지 않음
		std::cout << "┃  │ " << std::left << std::setw(15) << EnemyPokemon->getName() << " L13              │                            ┃\n";
		std::cout << "┃  │      HP: ";
		printHpBar(EnemyPokemon->getHp(), EnemyPokemon->getPMaxHp()); // HP 바 출력
		std::cout << "  │                            ┃\n";
		std::cout << "┃  └──────────────────────────────┘                            ┃\n";
		std::cout << "┃                                            /\\                ┃\n";
		std::cout << "┃                                           /  \\               ┃\n";
		std::cout << "┃                                          ( 적포켓몬 )        ┃\n";
		std::cout << "┃                                           \\__/               ┃\n";
		std::cout << "┃                                                              ┃\n";
		std::cout << "┃                                                              ┃\n";
		std::cout << "┃        /\\                                                    ┃\n";
		std::cout << "┃       /  \\                                                   ┃\n";
		std::cout << "┃      ( 내포켓몬 )                                            ┃\n";
		std::cout << "┃       \\__/                 ┌──────────────────────────────┐  ┃\n";
		std::cout << "┃                            │ " << std::left << std::setw(15) << MyPokemon->getName() << " L14 │  ┃\n";
		std::cout << "┃                            │      HP: ";
		printHpBar(MyPokemon->getHp(), MyPokemon->getPMaxExp()); // 내 HP 바 출력
		std::cout << "  │  ┃\n";
		std::cout << "┃                            └──────────────────────────────┘  ┃\n";
		std::cout << "├──────────────────────────────────────┬───────────────────────┤\n";
		std::cout << "┃  무엇을 할까?                        ┃ 싸운다      가방      ┃\n";
		std::cout << "┃                                      ┃ 포켓몬       도망     ┃\n";
		std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

		/*std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		std::cout << "┃                                                              ┃\n";
		std::cout << "┃  ┌──────────────────────────────┐                            ┃\n";
		std::cout << "┃  │ " << EnemyPokemon->getName() << "      L13             │                            ┃\n";
		std::cout << "┃  │      HP: ██████████░░░░░░░░  │                            ┃\n";
		std::cout << "┃  └──────────────────────────────┘                            ┃\n";
		std::cout << "┃                                            /\\                ┃\n";
		std::cout << "┃                                           /  \\               ┃\n";
		std::cout << "┃                                          ( 적포켓몬 )        ┃\n";
		std::cout << "┃                                           \\__/               ┃\n";
		std::cout << "┃                                                              ┃\n";
		std::cout << "┃                                                              ┃\n";
		std::cout << "┃        /\\                                                    ┃\n";
		std::cout << "┃       /  \\                                                   ┃\n";
		std::cout << "┃      ( 내포켓몬 )                                            ┃\n";
		std::cout << "┃       \\__/                 ┌──────────────────────────────┐  ┃\n";
		std::cout << "┃                            │ " << MyPokemon->getName() << "                 L14 │  ┃\n";
		std::cout << "┃                            │      HP: ██████████░░░░░░░░  │  ┃\n";
		std::cout << "┃                            └──────────────────────────────┘  ┃\n";
		std::cout << "├──────────────────────────────────────┬───────────────────────┤\n";
		std::cout << "┃  무엇을 할까?                        ┃ 싸운다      가방      ┃\n";
		std::cout << "┃                                      ┃ 포켓몬       도망     ┃\n";
		std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";*/

		int PlayerChoice;

		std::cout << "무엇을 할까?" << std::endl;
		std::cout << "1.공격 2.가방 3.스탯 4.도망" << std::endl;
		std::cin >> PlayerChoice;

		switch (PlayerChoice)
		{
			case 1: // 공격 상황(현재는 항상 선공)
			{
				int SkillChoice;
				std::cout << "기술 선택: ( [1] / [2] ): "; // 스킬(현재 2가지) 중 선택
				std::cin >> SkillChoice;

				// 내 포켓몬 공격
				int AttackToEnemy = MyPokemon->skill(SkillChoice); // 스킬 번호 계산
				EnemyPokemon->takeDamage(AttackToEnemy); // 적에게 데미지

				// 적 쓰러짐
				if (EnemyPokemon->getHp() <= 0)
				{
					PlaySound(NULL, 0, 0);
					PlaySound(TEXT("music/1-08.-Victory-_VS-Wild-Pokémon_.wav"), NULL, SND_FILENAME | SND_ASYNC);
					Sleep(500);

					std::cout << EnemyPokemon->getName() << " 이(가) 쓰러졌다!" << std::endl;
					if (MyPokemon->getPExp() < MyPokemon->getPMaxExp())
					{
						int NewExp = MyPokemon->getPExp() + 50;
						MyPokemon->setPExp(NewExp);
						std::cout << "경험치 50을 획득했습니다!" << std::endl;
						if (MyPokemon->getPExp() >= MyPokemon->getPMaxExp())
						{
							int NewExp = MyPokemon->getPExp() - 100;
							MyPokemon->setPExp(NewExp);
							MyPokemon->levelUp();
							break;
						}
					}
					
					delete EnemyPokemon;
					EnemyPokemon = nullptr;

					//MyPokemon->levelUp(); // 경험치 획득

					IsBattle = false; // 전투 종료 확인

					_getch();

					PlaySound(NULL, 0, 0);
					GameLoop(); // 마을? 복귀(게임 종료 전까지 반복 순환)
					break;
				}
				
				// 적 포켓몬 공격
				int AttackToMe = EnemyPokemon->skill(1);
				MyPokemon->takeDamage(AttackToMe);

				if (MyPokemon->getHp() <= 0)
				{
					IsBattle = false;
					GameEnding();
					return;
				}

				std::cout << "다음 턴으로 넘어가려면 아무 키나 누르세요..." << std::endl;
				_getch();

				break;
			}

			case 2:
			{
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
			}
			case 3:
			{
				MyPokemon->printStatus();
				break;
			}
			case 4:
			{
				std::cout << "무사히 도망쳤다!" << std::endl;
				delete EnemyPokemon;
				EnemyPokemon = nullptr;

				IsBattle = false;
				GameLoop();
				break;
			}
			case 5:
			{
				IsBattle = false;
				GameEnding();
				return;
			}
			default:
			{
				if (MyPokemon->getHp() < MyPokemon->getPMaxHp())
				{
					inventory.UseItem(1); //아이템 사용
					int NewHp = MyPokemon->getHp() + 10; //임시 아이템 체력 +10
					MyPokemon->setHP(NewHp); //체력 설정
					std::cout << "아이템을 사용했습니다!" << std::endl;
					break;
				}
				else
				{
					std::cout << "체력이 가득 차 있어 아이템 사용이 불가합니다." << std::endl;
					break;
				}
				break;

				std::cout << "잘못된 입력입니다. 다시 선택해주세요." << std::endl;
			}
		}
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
		std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		std::cout << "┃ 🌳 마을 - 안전 지역                                          ┃\n";
		std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		std::cout << "┃ 플레이어: 김훈철                                             ┃\n";
		std::cout << "┃ 보유 골드: 1200G                                             ┃\n";
		std::cout << "┃ 현재 포켓몬: " << MyPokemon->getName() << "(Lv.5 / HP: 45 / 60)                     ┃\n";
		std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
		std::cout << "┃                                                              ┃\n";
		std::cout << "┃   [1] 🌲 풀숲으로 간다                                       ┃\n";
		std::cout << "┃   [2] 🏪 상점                                                ┃\n";
		std::cout << "┃   [3] 🏥 포켓몬 센터                                         ┃\n";
		std::cout << "┃   [4] 🚨 게임 종료                                           ┃\n";
		std::cout << "┃                                                              ┃\n";
		std::cout << "┃                                                              ┃\n";
		std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";


		std::cin >> choice;

		switch (choice)
		{
		case 1:
			PlaySound(NULL, 0, 0);
			StartBattle();
			break;
		case 2:
			std::cout << "상점 준비 중..." << std::endl;
			//PlaySound(NULL, 0, 0);
			break;
		case 3:
			MyPokemon->recoveryHp();
			std::cout << MyPokemon->getName() << "체력을 모두 회복했습니다." << std::endl;
			break;
		case 4:
			std::cout << "게임을 종료합니다." << std::endl;
			PlaySound(NULL, 0, 0);
			exit(0);
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
	exit(0);
}

