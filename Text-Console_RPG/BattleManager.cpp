#include "BattleManager.h"
#include <random>//random
#include <Windows.h>
#include <conio.h> //_getch()
#pragma comment(lib, "WinMM.lib") //PlaySound()

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

	while (IsBattle)
	{
		system("cls"); //UI 갱신

		uimanager.BattleUiTop(MyPokemon, EnemyPokemon); //전투 UI 상단
		uimanager.BattleUiBottom(); //전투 UI 하단

		int PlayerChoice; //전투 중 선택지

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

			int BagChoice;

			std::cout << "4. 인벤토리 나가기!" << std::endl;
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
				else
				{
					std::cout << "체력이 가득 차 있어 아이템 사용이 불가합니다." << std::endl;
					break;
				}
			}
			else if (BagChoice == 4)
			{
				std::cout << "인벤토리를 나갑니다!" << std::endl;
				IsOpenBag = false;
				break;
			}
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
