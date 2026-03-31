#include "BattleManager.h"
#include <Windows.h> //Sleep, PlaySound
#include <conio.h> //_getch()
#pragma comment(lib, "WinMM.lib") //PlaySound()

void gotoxy(int x, int y);
void setColor(int color);

BattleManager::BattleManager() //생성자 전투 관련 상태 초기화
	: IsBattle(false) //전투 중 여부
	, IsTurnPass(false) //턴 종료 여부
	, IsEscape(false) //도망 여부
	, AtkChoice(0) //전투 선택
	, BagChoice(0) //가방 선택
	, IsOpenBag(false) //가방 열기 여부
	, EnemyPokemon(nullptr) //적 포켓몬 초기화
	, rd()
	, gen(rd())
{
}

void typeWriter(std::string text)
{
	for (char c : text)
	{
		std::cout << c;
		Sleep(30);
	}
}

class DialogueManager
{
private:
	int startY = 15; // 대화창 시작 위치
	int width = 40;

public:
	void Clear()
	{
		for (int i = 0; i < 4; i++)
		{
			gotoxy(0, startY + i);
			std::cout << std::string(width, ' ');
		}
	}

	void DrawBox()
	{
		gotoxy(0, startY);
		std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";

		for (int i = 1; i <= 2; i++)
		{
			gotoxy(0, startY + i);
			std::cout << "┃                              ┃";
		}

		gotoxy(0, startY + 3);
		std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
	}

	void Print(const std::string& text)
	{
		Clear();
		DrawBox();

		gotoxy(2, startY + 1);
		typeWriter(text);
	}

	void Wait()
	{
		gotoxy(2, startY + 2);
		std::cout << "▶ 계속하려면 아무 키...";
		_getch();
	}
};

BattleManager::~BattleManager() //소멸자 동적 할당된 적 포켓몬 메모리 해제
{
	delete EnemyPokemon;
	EnemyPokemon = nullptr;

}

void BattleManager::RandomEnemy() //랜덤 적 포켓몬 생성 함수
{
	delete EnemyPokemon; //전에 있던 적 포켓몬 제거
	EnemyPokemon = nullptr;

	system("cls"); //화면 초기화

	//랜덤 설정
	std::uniform_int_distribution<> dist(1, 4); //랜덤 범위 설정
	std::random_device rd;
	std::mt19937 gen(rd());
	int RandomNumber = dist(gen); //실제 랜덤 값 생성

	//랜덤 포켓몬 생성
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
	case 4:
		EnemyPokemon = new Oddish();
		break;
	}

}

//전투 시작 함수 결과 반환 승리/패배/도망

BattleResult BattleManager::StartBattle(Pokemon* MyPokemon, Inventory<Item>& inventory)
{
	//전투 BGM
	PlaySound(TEXT("music/1-07.-Battle-_VS-Wild-Pokémon_.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	Sleep(500);

	RandomEnemy(); //랜덤 적 생성

	IsBattle = true;
	IsOpenBag = false;

	//전투 시작 연출 출력
	std::string s = "야생의 " + EnemyPokemon->getName() + "가 나타났다!";
	printtext.typeWrite(s);
	Sleep(500);

	std::string s2 = "가랏! " + MyPokemon->getName() + "!";
	printtext.typeWrite(s2);
	Sleep(500);

	std::cout << std::endl;


	int cursorX = 0;
	int cursorY = 0;


	//전투 루프
	while (IsBattle)
	{
		int cursor = 0;
		bool isSelecting = true;

		while (isSelecting)
		{
			system("cls");

			uimanager.BattleUiTop(MyPokemon, EnemyPokemon);
			uimanager.BattleUiBottom(cursorX, cursorY);

			int key = _getch();

			if (key == 224)
			{
				key = _getch();

				if (key == 72 && cursorY > 0) cursorY--;
				if (key == 80 && cursorY < 1) cursorY++;
				if (key == 75 && cursorX > 0) cursorX--;
				if (key == 77 && cursorX < 1) cursorX++;
			}
			else if (key == 13)
			{
				isSelecting = false;
			}

			cursor = cursorY * 2 + cursorX + 1;
		}

		//uimanager.BattleUiBottom(); //전투 UI 하단

		/*gotoxy(0, 0);
		uimanager.BattleUiTop(MyPokemon, EnemyPokemon);
		uimanager.BattleUiBottom(cursorY, cursorY);*/

		switch (cursor)
		{
		case 1: // 공격 상황(현재는 항상 선공)
		{
			int SkillChoice;
			std::cout << "기술 선택: ( [1] / [2] ): "; // 스킬(현재 2가지) 중 선택
			std::cin >> SkillChoice;

			// 내 포켓몬 공격
			int AttackToEnemy = MyPokemon->skill(SkillChoice); // 스킬 번호 계산
			EnemyPokemon->takeDamage(AttackToEnemy); // 적에게 데미지

			if (EnemyPokemon->getHp() <= 0) // 적 쓰러짐
			{
				PlaySound(NULL, 0, 0);
				//승리 BGM
				PlaySound(TEXT("music/1-08.-Victory-_VS-Wild-Pokémon_.wav"), NULL, SND_FILENAME | SND_ASYNC);

				std::cout << EnemyPokemon->getName() << " 이(가) 쓰러졌다!" << std::endl;
				if (MyPokemon->getPExp() < MyPokemon->getPMaxExp()) //승리시 보상 경험치
				{

					int NewExp = MyPokemon->getPExp() + 50;
					MyPokemon->setPExp(NewExp);
					std::cout << "경험치 50을 획득했습니다!" << std::endl;
					if (MyPokemon->getPExp() >= MyPokemon->getPMaxExp()) //경험치 100도달시 레벨업
					{
						int NewExp = MyPokemon->getPExp() - 100; //경험치 0으로 초기화
						MyPokemon->setPExp(NewExp);
						MyPokemon->levelUp();
					}
				}

				std::uniform_int_distribution<> DropChance(1, 100); //랜덤 범위 설정
				int DropRoll = DropChance(gen);

				//아이템 드랍 확률 50%
				if (DropRoll <= 50) //1에서 50의 수가 선택되면 작동
				{
					std::uniform_int_distribution<> ItemChance(1, 100);
					int ItemRoll = ItemChance(gen); //실제 랜덤 값 생성

					if (ItemRoll <= 70)
					{
						Item potion("상처약", 50, 1);
						inventory.Additem(potion);
						std::cout << "상처약을 획득했다!" << std::endl;
					}
					else
					{
						Item potion2("고급 상처약", 100, 1);
						inventory.Additem(potion2);
						std::cout << "고급 상처약을 획득했다!" << std::endl;
					}


				}

				std::uniform_int_distribution<> goldDist(50, 500); //50~500 사이

				int gold = goldDist(gen); //실제 랜덤 값 생성
				inventory.AddGold(gold);

				//적 제거
				delete EnemyPokemon;
				EnemyPokemon = nullptr;


				IsBattle = false; // 전투 종료 확인

				std::cout << "마을로 돌아가려면 아무 키나 누르세요..." << std::endl;

				_getch();

				PlaySound(NULL, 0, 0);
				return BattleResult::Win; //승리 반환
			}

			// 적 포켓몬 공격
			int AttackToMe = EnemyPokemon->skill(1);
			MyPokemon->takeDamage(AttackToMe);

			if (MyPokemon->getHp() <= 0) //포켓몬 Hp 확인
			{
				IsBattle = false;

				return BattleResult::Lose; //패배 반환
			}

			std::cout << "다음 턴으로 넘어가려면 아무 키나 누르세요..." << std::endl;
			_getch();
			break;
		}

		//가방
		case 2:
		{
			IsOpenBag = true;
			std::cout << "가방 목록" << std::endl;
			inventory.Printallitems();
			std::cout << "\n사용할 아이템 번호를 입력하세요 (나가기: 0): ";
			std::cin >> BagChoice;

			if (BagChoice > 0)
			{
				// 인벤토리에서 아이템 가져오기
				Item* selectedItem = inventory.GetItemUse(BagChoice - 1);

				if (selectedItem != nullptr)
				{
					// 풀피인지 확인
					if (MyPokemon->getHp() >= MyPokemon->getPMaxHp())
					{
						std::cout << "이미 체력이 가득 차 있습니다!" << std::endl;
					}
					// 아이템 사용 
					else if (selectedItem->Use())
					{
						int healAmount = selectedItem->GetHeal(); //아이템 힐량 가져오기
						int currentHp = MyPokemon->getHp();       //현재 체력확인
						int maxHp = MyPokemon->getPMaxHp();       //최대 채력 확인

						// 체력 회복용 최대체력 초과 금지
						int nextHp = (currentHp + healAmount > maxHp) ? maxHp : currentHp + healAmount;
						MyPokemon->setHP(nextHp);

						std::cout << "\n" << selectedItem->GetName() << "을(를) 사용하여 HP가 "
							<< healAmount << "만큼 회복되었습니다!" << std::endl;

						// 아이템 사용후 적턴으로 넘기기 
						//int AttackToMe = EnemyPokemon->skill(1); //적턴으로 넘기기
						//MyPokemon->takeDamage(AttackToMe); // 데미지 받기
						inventory.UpdateInventory(); //인벤토리 정리용
					}
					int BagChoice;

					std::cout << "0. 인벤토리 나가기!" << std::endl;
					std::cout << "입력 하세요: ";
					std::cin >> BagChoice;

					if (BagChoice == 1)
					{
						if (MyPokemon->getHp() < MyPokemon->getPMaxHp())
						{
							inventory.UseItem(1); //아이템 사용
							int NewHp = MyPokemon->getHp() + 10; //임시 아이템 체력 +10
							MyPokemon->setHP(NewHp); //체력 설정
							std::cout << "아이템을 사용했습니다!" << std::endl;
							break;
						}
						else {
							std::cout << "해당 번호에 아이템이 없습니다." << std::endl;
						}
					}
					/*std::cout << "\n아무 키나 누르면 계속합니다...";
					_getch();*/
					//인벤토리 종료
					else if (BagChoice == 0)
					{
						std::cout << "인벤토리를 나갑니다!" << std::endl;
						IsOpenBag = false;
					}
					break;
				}

			}
				//스탯	
		case 3:
		{
			MyPokemon->printStatus();
			_getch();
			break;
		}
		//도망
		case 4:
		{
			IsBattle = false;
			std::cout << "무사히 도망쳤다!" << std::endl;
			delete EnemyPokemon;
			EnemyPokemon = nullptr;
			//GameLoop();
			return BattleResult::Escape;
		}
		default:
		{
			std::cout << "잘못된 입력입니다. 다시 선택해주세요." << std::endl;
			break;
		}
			
		}
		}
	}
}

