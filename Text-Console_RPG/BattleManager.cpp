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

void BattleManager::RandomEnemy(Pokemon* MyPokemon) //랜덤 적 포켓몬 생성 함수
{
	delete EnemyPokemon; //전에 있던 적 포켓몬 제거
	EnemyPokemon = nullptr;

	system("cls"); //화면 초기화

	int myLevel = MyPokemon->getLevel();

	if (myLevel <= 5) //내 포켓몬 레벨이 5이하일 때
	{
		//랜덤 설정
		std::uniform_int_distribution<> dist(1, 6); //랜덤 범위 설정
		int RandomNumber = dist(gen); //실제 랜덤 값 생성

		//랜덤 포켓몬 생성
		switch (RandomNumber)
		{
		case 1:
			EnemyPokemon = new Bulbasaur(); //이상해씨 5레벨
			break;
		case 2:
			EnemyPokemon = new Charmander(); //파이리 5레벨
			break;
		case 3:
			EnemyPokemon = new Squirtle(); //꼬부기 5레벨
			break;
		case 4:
			EnemyPokemon = new Paras(); //파라스 8레벨
			break;
		case 5:
			EnemyPokemon = new Magby(); //마그비 1레벨
		case 6:
			EnemyPokemon = new Tentacool(); //왕눈해 5레벨
			break;
		}
	}
	else if (myLevel <= 8)
	{
		//랜덤 설정
		std::uniform_int_distribution<> dist(1, 6); //랜덤 범위 설정
		int RandomNumber = dist(gen); //실제 랜덤 값 생성

		//랜덤 포켓몬 생성
		switch (RandomNumber)
		{
		case 1:
			EnemyPokemon = new Oddish(); //뚜벅초 13레벨
			break;
		case 2:
			EnemyPokemon = new Bellsprout(); //모다피 13레벨
			break;
		case 3:
			EnemyPokemon = new Vulpix();//식스테일 16레벨
			break;
		case 4:
			EnemyPokemon = new Growlithe();//가디 15레벨
			break;
		case 5:
			EnemyPokemon = new Poliwag();//발챙이 10레벨
			break;
		case 6:
			EnemyPokemon = new Slowpoke();//야돈 15레벨
			break;
		}
	}
	else //9이상일때
	{
		//랜덤 설정
		std::uniform_int_distribution<> dist(1, 21); //랜덤 범위 설정
		int RandomNumber = dist(gen); //실제 랜덤 값 생성

		//랜덤 포켓몬 생성
		switch (RandomNumber)
		{
		case 1:
			EnemyPokemon = new Gloom();//냄새꼬 28레벨
			break;
		case 2:
			EnemyPokemon = new Vileplume();//라플레시아 32레벨
			break;
		case 3:
			EnemyPokemon = new Parasect();//파라섹트 24레벨
			break;
		case 4:
			EnemyPokemon = new Weepinbell();//우츠동 28레벨
			break;
		case 5:
			EnemyPokemon = new Victreebel();//우츠보트 32레벨
			break;
		case 6:
			EnemyPokemon = new Exeggcute();//아라리 24레벨
			break;
		case 7:
			EnemyPokemon = new Exeggutor();//나시 35레벨
			break;
		case 8:
			EnemyPokemon = new Ninetales();//나인테일 28레벨
			break;
		case 9:
			EnemyPokemon = new Arcanine();//윈디 26레벨
			break;
		case 10:
			EnemyPokemon = new Ponyta();//포니타 28레벨
			break;
		case 11:
			EnemyPokemon = new Rapidash();//날쌩마 49레벨
			break;
		case 12:
			EnemyPokemon = new Magmar();//마그마 34레벨
			break;
		case 13:
			EnemyPokemon = new Flareon();//부스터 36레벨
			break;
		case 14:
			EnemyPokemon = new Moltres();//파이어 50레벨
			break;
		case 15:
			EnemyPokemon = new Psyduck();//고라파덕 28레벨
			break;
		case 16:
			EnemyPokemon = new Golduck();//골덕 38레벨
			break;
		case 17:
			EnemyPokemon = new Poliwhirl();//슈륙챙이 23레벨
			break;
		case 18:
			EnemyPokemon = new Poliwrath();//강챙이 32레벨
			break;
		case 19:
			EnemyPokemon = new Tentacruel();//독파리 20레벨
			break;
		case 20:
			EnemyPokemon = new Slowbro();//야도란 37레벨
			break;
		case 21:
			EnemyPokemon = new Lapras();//라프라스 50레벨
			break;
		}
	}
	

}

//전투 시작 함수 결과 반환 승리/패배/도망

BattleResult BattleManager::StartBattle(Pokemon* MyPokemon, Inventory<Item>& inventory, Player* player,bool isBoss)
{
	IsBattle = true;
	IsOpenBag = false;

	if (EnemyPokemon != nullptr)
	{
		delete EnemyPokemon;
		EnemyPokemon = nullptr;
	}

	//전투 BGM
	if (isBoss)
	{
		setColor(12);
		audio.BossBgm();
	}
	else
	{
		setColor(7);
		audio.BattleWild();
	}
	if (isBoss)
	{
		EnemyPokemon = new Mewtwo();
		
	}
	else
	{
		RandomEnemy(MyPokemon); //랜덤 적 생성
	}

	int cursorX = 0;
	int cursorY = 0;

	Sleep(700);

	uimanager.BattleUiTop(MyPokemon, EnemyPokemon);
	uimanager.BattleUiBottom(cursorX, cursorY);

	//전투 시작 연출 출력
	std::string s = "야생의 " + EnemyPokemon->getName() + "가 나타났다!";
	printtext.typeWrite(s);
	Sleep(500);

	std::string s2 = "가랏! " + MyPokemon->getName() + "!";
	printtext.typeWrite(s2);
	Sleep(500);

	std::cout << std::endl;

	std::cout << "다음 턴으로 넘어가려면 아무 키나 누르세요...";
	_getch();


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
			std::cout << "기술 선택: 1." << MyPokemon->getSkillName(1) << " 2." << MyPokemon->getSkillName(2) << std::endl;; // 스킬(현재 2가지) 중 선택
			std::cout << "입력: ";
			std::cin >> SkillChoice;

			//엔터 키 잔여물을 제거 멋대로 넘어가는 것을 방지
		    //숫자외 다른 문구 입력시 오류로 인해 추가 (인벤토리에서도 같은 문제가 발생하여서 추가)
			if (std::cin.fail())
			{
				std::cin.clear();
			}
			std::cin.ignore(1024, '\n');


			// 내 포켓몬 공격
			int AttackToEnemy = MyPokemon->skill(SkillChoice); // 스킬 번호 계산
			EnemyPokemon->takeDamage(AttackToEnemy); // 적에게 데미지

			if (EnemyPokemon->getHp() <= 0) // 적 쓰러짐
			{
				PlaySound(NULL, 0, 0);
				//승리 BGM
				audio.BattleWildVictory();
				//PlaySound(TEXT("music/1-08.-Victory-_VS-Wild-Pokémon_.wav"), NULL, SND_FILENAME | SND_ASYNC);

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
						audio.LevelUp();
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
					audio.ItemReward();

					if (ItemRoll <= 50)
					{
						Item potion("상처약", 150, 1, 20);
						inventory.Additem(potion);
						std::cout << "상처약을 획득했다!" << std::endl;
					}
					else if(51 <= ItemRoll && ItemRoll <= 80 )
					{
						Item potion2("좋은상처약", 350, 1, 60);
						inventory.Additem(potion2);
						std::cout << "좋은상처약을 획득했다!" << std::endl;
					}
					else
					{
						Item candy("이상한 사탕", 2400, 1, 1);
						player->GetInventory().Additem(candy);
						std::cout << "이상한사탕을 획득했다!" << std::endl;
					}
				}

				std::uniform_int_distribution<> goldDist(50, 300); //50~300 사이

				int gold = goldDist(gen); //실제 랜덤 값 생성
				inventory.AddGold(gold); //전투보상 골드 획득

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
				std::cout << "[" << MyPokemon->getName() << "] 은(는) 쓰러졌다..." << std::endl;
				std::cout << "다음 턴으로 넘어가려면 아무 키나 누르세요...";
				_getch();
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
			inventory.Printallitems();
			std::cout << "사용할 아이템 번호를 입력하세요 (나가기: 0): ";
			std::cin >> BagChoice;

			//숫자외 다른 문구 입력시 오류로 인해 추가 (인벤토리에서도 같은 문제가 발생하여서 추가)
			if (std::cin.fail()) std::cin.clear();
			std::cin.ignore(1024, '\n');

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
					else if (BagChoice == 0)
					{
						std::cout << "인벤토리를 나갑니다!" << std::endl;
						IsOpenBag = false;
						break;
					}
					else
					{
						std::cout << "해당 번호에 아이템이 없습니다." << std::endl;
					}
				}
				std::cout << "아무 키나 누르면 계속합니다...";
				_getch();
			}
			break;
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
			PlaySound(NULL, 0, 0);
			IsBattle = false;
			std::cout << "무사히 도망쳤다!" << std::endl;
			std::cout << "아무 키나 누르면 계속합니다...";
			_getch();
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

