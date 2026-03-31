#include "BattleManager.h"
#include <random>//random
#include <Windows.h>
#include <conio.h> //_getch()
#pragma comment(lib, "WinMM.lib") //PlaySound()

void gotoxy(int x, int y);
void setColor(int color);

BattleManager::BattleManager()
	: IsBattle(false)
	, IsTurnPass(false)
	, IsEscape(false)
	, AtkChoice(0)
	, BagChoice(0)
	, IsOpenBag(false)
	, EnemyPokemon(nullptr)
{
}

BattleManager::~BattleManager()
{
	delete EnemyPokemon;
	EnemyPokemon = nullptr;

}

void BattleManager::RandomEnemy()
{
	delete EnemyPokemon; //전에 있던 적 포켓몬 제거
	EnemyPokemon = nullptr;

	system("cls");

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 5);

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
	case 4:
		EnemyPokemon = new Oddish();
		break;
	}

}

BattleResult BattleManager::StartBattle(Pokemon* MyPokemon, Inventory<Item>& inventory)
{
	PlaySound(TEXT("music/1-07.-Battle-_VS-Wild-Pokémon_.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	Sleep(500);

	RandomEnemy();

	IsBattle = true;
	IsOpenBag = false;

	std::string s = "야생의 " + EnemyPokemon->getName() + "가 나타났다!";
	printtext.typeWrite(s);
	Sleep(500);

	std::string s2 = "가랏! " + MyPokemon->getName() + "!";
	printtext.typeWrite(s2);
	Sleep(500);

	std::cout << std::endl;

	int cursorX = 0;
	int cursorY = 0;

	while (IsBattle)
	{
		bool isSelecting = true;

		while (isSelecting)
		{
			int cursor = cursorY * 2 + cursorX + 1;

			system("cls");

			uimanager.BattleUiTop(MyPokemon, EnemyPokemon);

			std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";

			// ===== 1줄 =====
			std::cout << "┃ ";

			// 왼쪽 (대사)
			std::cout << "무엇을 할까?           ";

			// 오른쪽으로 밀기 (공백 핵심)
			std::cout << "           ┃ ";

			// 오른쪽 (메뉴 1줄)
			if (cursorX == 0 && cursorY == 0) setColor(10);
			std::cout << "   ▶ 공격";
			setColor(7);

			std::cout << "      ";

			if (cursorX == 1 && cursorY == 0) setColor(11);
			std::cout << "▶ 가방";
			setColor(7);
			std::cout << "    ┃";

			std::cout << "\n";

			// ===== 2줄 =====
			std::cout << "┃ ";

			// 왼쪽 (대사 2줄)
			std::cout << "            ";

			std::cout << "                      ┃ ";

			// 오른쪽 (메뉴 2줄)
			if (cursorX == 0 && cursorY == 1) setColor(14);
			std::cout << "   ▶ 스탯";
			setColor(7);

			std::cout << "      ";

			if (cursorX == 1 && cursorY == 1) setColor(12);
			std::cout << "▶ 도망";
			setColor(7);
			std::cout << "    ┃";

			std::cout << "\n";

			std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";

			uimanager.BattleUiBottom();

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
		}

		//uimanager.BattleUiBottom(); //전투 UI 하단

		int cursor = cursorY * 2 + cursorX + 1;

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
				PlaySound(TEXT("music/1-08.-Victory-_VS-Wild-Pokémon_.wav"), NULL, SND_FILENAME | SND_ASYNC); //이겼을 때 bgm
				Sleep(500);

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

				delete EnemyPokemon;
				EnemyPokemon = nullptr;


				IsBattle = false; // 전투 종료 확인

				std::cout << "마을로 돌아가려면 아무 키나 누르세요..." << std::endl;

				_getch();

				PlaySound(NULL, 0, 0);
				return BattleResult::Win;
			}

			// 적 포켓몬 공격
			int AttackToMe = EnemyPokemon->skill(1);
			MyPokemon->takeDamage(AttackToMe);

			if (MyPokemon->getHp() <= 0)
			{
				IsBattle = false;

				return BattleResult::Lose;
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

			
			std::cout << "\n사용할 아이템 번호를 입력하세요 (나가기: 0): ";
			std::cin >> BagChoice;

			if (BagChoice > 0) {
				// 인벤토리에서 아이템 가져오기
				Item* selectedItem = inventory.GetItemUse(BagChoice - 1);

				if (selectedItem != nullptr) {
					// 풀피인지 확인
					if (MyPokemon->getHp() >= MyPokemon->getPMaxHp()) {
						std::cout << "이미 체력이 가득 차 있습니다!" << std::endl;
					}
					// 아이템 사용 
					else if (selectedItem->Use()) {
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
				}
				else {
					std::cout << "해당 번호에 아이템이 없습니다." << std::endl;
				}
			}
			std::cout << "\n아무 키나 누르면 계속합니다...";
			_getch();
			break;
		}
		case 3:
		{
			MyPokemon->printStatus();
			break;
		}
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
	return BattleResult();
}
