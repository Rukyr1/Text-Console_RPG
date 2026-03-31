#include "UIManager.h"
#include <iostream>
#include <Windows.h> // sound
#include <conio.h> //_getch
#include "Pokemon.h"
#include <iomanip> //setw

void gotoxy(int x, int y);
void setColor(int color);

UIManager::UIManager()
{
}

void UIManager::TitleUi()
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
	std::cout << "║               ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═════╝               ║" << std::endl;
	std::cout << "║                                                                       ║" << std::endl;
	std::cout << "╚═══════════════════════════════════════════════════════════════════════╝" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "                          아무 키나 입력하세요";
}

void UIManager::StarterUiTop()
{
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
	std::cout << "┃                                                       ┃" << std::endl;
	std::cout << "┃           [ 스타팅 포켓몬을 선택하세요! ]             ┃" << std::endl;
	std::cout << "┃                                                       ┃" << std::endl;
	std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << std::endl;
	std::cout << "┃                                                       ┃" << std::endl;
	std::cout << "┃                                                       ┃" << std::endl;
	std::cout << "┃      ";
}
void UIManager::StarterUiBottom()
{
	std::cout << "    ┃" << std::endl;
	std::cout << "┃                                                       ┃" << std::endl;
	std::cout << "┃                                                       ┃" << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
	std::cout << " (방향키 ◀ ▶ 이동 / Enter 선택)          " << std::endl;
}

//void UIManager::printHpBar(int currentHp, int maxHp)
//{
//	int barWidth = 20;
//	float ratio = (float)currentHp / maxHp;
//	if (ratio < 0)
//	{
//		ratio = 0;
//	}
//	int filled = (int)(barWidth * ratio);
//
//	for (int i = 0; i < barWidth; ++i)
//	{
//		if (i < filled) std::cout << "█"; // 실제 2칸 차지
//		else std::cout << "░";            // 실제 2칸 차지
//	}
//}

int getKoreanWidth(const std::string& str)
{
	int width = 0;

	for (unsigned char c : str)
	{
		if (c >= 0x80) width += 2; // 한글/특수문자
		else width += 1;
	}

	return width;
}

std::string fixWidth(const std::string& str, int targetWidth)
{
	std::string result = str;
	int width = getKoreanWidth(str);

	int pad = targetWidth - width;
	if (pad < 0) pad = 0;

	result.append(pad, ' ');
	return result;
}

void UIManager::printHpBar(int currentHp, int maxHp)
{
	int barWidth = 20; // 고정

	float ratio = (float)currentHp / maxHp;
	int filled = (int)(ratio * barWidth);

	std::cout << "[";

	for (int i = 0; i < barWidth; i++)
	{
		if (i < filled) std::cout << "█";
		else std::cout << " ";
	}

	std::cout << "]";
}
               
                                              
void UIManager::BattleUiTop(Pokemon* MyPokemon, Pokemon* EnemyPokemon)
{
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	std::cout << "┃  ┌───────────────────────────────┐                           ┃\n";
	std::cout << "┃  │ " << std::left << std::setw(15) << EnemyPokemon->getName() << " L13              │                           ┃\n";
	std::cout << "┃  │ HP: ";
	printHpBar(EnemyPokemon->getHp(), EnemyPokemon->getPMaxHp());
	std::cout << std::right << std::setw(7) << "    │" << "      │\\ //   \\            ┃\n";
	std::cout << "┃  └───────────────────────────────┘      |          \\         ┃\n";
	std::cout << "┃                                         [        \\ /         ┃\n";
	std::cout << "┃                                           ───    ::\\         ┃\n";
	std::cout << "┃                                          \\ _|:/\\_]           ┃\n";
	std::cout << "┃       ---                                 -  -               ┃\n";
	std::cout << "┃     /      \\\\/|                                              ┃\n";
	std::cout << "┃    [        \\  \\                                             ┃\n";
	std::cout << "┃    /\\ ____/    ]                                             ┃\n";
	std::cout << "┃   |       ::  \\            ┌───────────────────────────────┐ ┃\n";
	std::cout << "┃   \\ ::    /:: |            │ " << std::left << std::setw(15) << MyPokemon->getName() << std::right << std::setw(8) <<" L14              │ ┃\n";
	std::cout << "┃      ──────_/_]            │ HP: ";
	printHpBar(MyPokemon->getHp(), MyPokemon->getPMaxHp());
	std::cout << std::right << std::setw(7) << "│" << " ┃\n";

	std::cout << "┃                            └───────────────────────────────┘ ┃\n";
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}

void UIManager::BattleUiBottom(int cursorX, int cursorY)
{
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━┓\n";

	//std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━┓\n";
	// ===== 1줄 =====
	std::cout << "┃ 무엇을 할까?                          ┃   ";


	if (cursorX == 0 && cursorY == 0) setColor(10);
	std::cout << "▶ 공격";
	setColor(7);

	std::cout << "  ";

	if (cursorX == 1 && cursorY == 0) setColor(11);
	std::cout << " ▶ 가방";
	setColor(7);

	std::cout << "    ┃\n";

	// ===== 2줄 =====
	std::cout << "┃                                       ┃   ";

	if (cursorX == 0 && cursorY == 1) setColor(14);
	std::cout << "▶ 스탯";
	setColor(7);

	std::cout << "   ";

	if (cursorX == 1 && cursorY == 1) setColor(12);
	std::cout << "▶ 도망";
	setColor(7);

	std::cout << "    ┃\n";

	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━┛\n";

	//// 하단
	//std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━┛\n";

	/*std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃                                      ┃                       ┃\n";
	std::cout << "┃                                      ┃                       ┃\n";
	std::cout << "┃  무엇을 할까?                        ┃ 싸운다      가방      ┃\n";
	std::cout << "┃                                      ┃ 포켓몬       도망     ┃\n";
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";*/

}

void UIManager::VillageUi(std::string playerName, Pokemon* MyPokemon, Player* player)
{
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	std::cout << "┃ 🌳 마을 - 안전 지역                                          ┃\n";
	std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃ 플레이어: " << playerName << "                                                ┃\n";
	std::cout << "┃ 보유 골드: "<< player->GetInventory().GetGold() <<"                                              ┃\n";
	std::cout << "┃ 현재 포켓몬: " << MyPokemon->getName() << "  Lv: " << MyPokemon->getLevel() << "  Hp: " << MyPokemon->getHp() << "/" << MyPokemon->getPMaxHp() << "  Atk: " << MyPokemon->getAttack() << "           ┃\n";
	std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃                                                              ┃\n";
	std::cout << "┃   [1] 🌲 풀숲으로 간다                                       ┃\n";
	std::cout << "┃   [2] 🏪 상점                                                ┃\n";
	std::cout << "┃   [3] 🏥 포켓몬 센터                                         ┃\n";
	std::cout << "┃   [4] 🚨 게임 종료                                           ┃\n";
	std::cout << "┃                                                              ┃\n";
	std::cout << "┃                                                              ┃\n";
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}

void UIManager::VillageHiddenUi(std::string playerName, Pokemon* MyPokemon, Player* player)
{
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	std::cout << "┃ 🌳 마을 - 안전 지역                                          ┃\n";
	std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃ 플레이어: " << playerName << "                                                ┃\n";
	std::cout << "┃ 보유 골드: " << player->GetInventory().GetGold() << "                                              ┃\n";
	std::cout << "┃ 현재 포켓몬: " << MyPokemon->getName() << "  Lv: " << MyPokemon->getLevel() << "  Hp: " << MyPokemon->getHp() << "/" << MyPokemon->getPMaxHp() << "  Atk: " << MyPokemon->getAttack() << "           ┃\n";
	std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃                                                              ┃\n";
	std::cout << "┃   [1] 🌲 풀숲으로 간다                                       ┃\n";
	std::cout << "┃   [2] 🏪 상점                                                ┃\n";
	std::cout << "┃   [3] 🏥 포켓몬 센터                                         ┃\n";
	std::cout << "┃   [4] 🚨 게임 종료                                           ┃\n";
	std::cout << "┃   [5] ❓ 히든 스테이지                                       ┃\n";
	std::cout << "┃                                                              ┃\n";
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}

void UIManager::PokemonCenterUi()
{
	system("cls");
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	std::cout << "┃                          POKEMON CENTER                            ┃\n";
	std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃                                                                    ┃\n";
	std::cout << "┃          ────────────           ____                               ┃\n";
	std::cout << "┃         │            │         |__ _|                              ┃\n";
	std::cout << "┃        / ──────────── \\       /      \\                             ┃\n";
	std::cout << "┃ ──────│ │            │ │     |  /\\ /\\ |               ───── ────── ┃\n";
	std::cout << "┃      ││ │            │ │    /[│ 0  0 │]\\             │     │       ┃\n";
	std::cout << "┃      ││ │            │ │────\\   ────   /──────────  /│     │       ┃\n";           
	std::cout << "┃      ││ │            │ │      [ \\  / ]            │  │     │       ┃\n";
	std::cout << "┃      ││ │ ────────── │ │     / \\ \\/ / \\           │  │:::::│       ┃\n";
	std::cout << "┃      ││ /            \\ │     |  \\_\/  |        ┌──────────────────┐ ┃\n";
	std::cout << "┃      ─────────────────────────────────────────│                  │ ┃\n";
	std::cout << "┃                                               │  [ 1 ] 쉬게하다  │ ┃\n";
	std::cout << "┃                                               │                  │ ┃\n";
	std::cout << "┃::─────────────────────────────────────────────│  [ 2 ] 그만두다  │ ┃\n";
	std::cout << "┃:::::::::::::::::::::::::::::::::::::::::::::::│                  │ ┃\n";
	std::cout << "│:::::::::::::::::::::::::::::::::::::::::::::::└──────────────────┘ ┃\n";
	std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃                                                                    ┃\n";
	std::cout << "┃    안녕하세요! 포켓몬 센터입니다!                                  ┃\n";
	std::cout << "┃    당신의 포켓몬을 쉬게 하겠습니까?                                ┃\n";
	std::cout << "┃                                                                    ┃\n";
	std::cout << "╚━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}


void UIManager::ShopUi()
{
	system("cls");
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	std::cout << "┃                            POKEMON SHOP                            ┃\n";
	std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃                                                                    ┃\n";
	std::cout << "┃                                 __ _                               ┃\n";
	std::cout << "┃                               /      \\                             ┃\n";
	std::cout << "┃ ──────                       |  /\\ /\\                 ───── ────── ┃\n";
	std::cout << "┃      │       ───────────     [│ 0  0 │]              │     │       ┃\n";
	std::cout << "┃      │──────|           |───    ────     ─────────  /│     │       ┃\n";
	std::cout << "┃      │       ────   ────      [ \\  / ]            │  │     │       ┃\n";
	std::cout << "┃      │       ────│ │────      |\\ \\/ /|        ┌──────────────────┐ ┃\n";
	std::cout << "┃      │      │           │     |  \\_\/ |        │   [ 1 ] 구 매    │ ┃\n";
	std::cout << "┃      ─────│               │───────────────────│                  │ ┃\n";
	std::cout << "┃           │               │                   │   [ 2 ] 판 매    │ ┃\n";
	std::cout << "┃            ───────────────                    │                  │ ┃\n";
	std::cout << "┃::─────────────────────────────────────────────│   [ 3 ] 나가기   │ ┃\n";
	std::cout << "┃:::::::::::::::::::::::::::::::::::::::::::::::│                  │ ┃\n";
	std::cout << "│:::::::::::::::::::::::::::::::::::::::::::::::└──────────────────┘ ┃\n";
	std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃                                                                    ┃\n";
	std::cout << "┃    어서오세요! 포켓몬 상점입니다!                                  ┃\n";
	std::cout << "┃    물건을 사러  오셨군요!                                          ┃\n";
	std::cout << "┃                                                                    ┃\n";
	std::cout << "╚━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}
void UIManager::ShopBuyUi()
{
	system("cls");
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	std::cout << "┃                            POKEMON SHOP                            ┃\n";
	std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃                                                                    ┃\n";
	std::cout << "┃                                 __ _                               ┃\n";
	std::cout << "┃                               /      \\                             ┃\n";
	std::cout << "┃ ──────                       |  /\\ /\\                 ───── ────── ┃\n";
	std::cout << "┃      │       ───────────     [│ 0  0 │]              │     │       ┃\n";
	std::cout << "┃  ┌───────────────────────┐──    ────     ─────────  /│     │       ┃\n";
	std::cout << "┃  |                       |    [ \\  / ]            │  │     │       ┃\n";
	std::cout << "┃  |                       │────|\\ \\/ /|        ┌──────────────────┐ ┃\n";
	std::cout << "┃  │  상처약       300원   │    |  \\_\/ |        │   [ 1 ] 구 매    │ ┃\n";
	std::cout << "┃  │                       │────────────────────│                  │ ┃\n";
	std::cout << "┃  │  좋은상처약    700원  │                    │   [ 2 ] 판 매    │ ┃\n";
	std::cout << "┃  │                       │                    │                  │ ┃\n";
	std::cout << "┃::│                       │────────────────────│   [ 0 ] 나가기   │ ┃\n";
	std::cout << "┃::└───────────────────────┘::::::::::::::::::::│                  │ ┃\n";
	std::cout << "│:::::::::::::::::::::::::::::::::::::::::::::::└──────────────────┘ ┃\n";
	std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃                                                                    ┃\n";
	std::cout << "┃    어서오세요! 포켓몬 상점입니다!                                  ┃\n";
	std::cout << "┃    물건을 사러  오셨군요!                                          ┃\n";
	std::cout << "┃                                                                    ┃\n";
	std::cout << "╚━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}
void UIManager::ShopSellUi()
{
	system("cls");
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	std::cout << "┃                            POKEMON SHOP                            ┃\n";
	std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃                                                                    ┃\n";
	std::cout << "┃                                 __ _                               ┃\n";
	std::cout << "┃                               /      \\                             ┃\n";
	std::cout << "┃ ──────                       |  /\\ /\\                 ───── ────── ┃\n";
	std::cout << "┃      │       ───────────     [│ 0  0 │]              │     │       ┃\n";
	std::cout << "┃  ┌───────────────────────┐──    ────     ─────────  /│     │       ┃\n";
	std::cout << "┃  |                       |    [ \\  / ]            │  │     │       ┃\n";
	std::cout << "┃  |  상처약       150원    │────|\\ \\/ /|        ┌──────────────────┐ ┃\n";
	std::cout << "┃  │                       │    |  \\_\/ |        │   [ 1 ] 구 매    │ ┃\n";
	std::cout << "┃  │  좋은상처약    350원    │────────────────────│                  │ ┃\n";
	std::cout << "┃  │                       │                    │   [ 2 ] 판 매    │ ┃\n";
	std::cout << "┃  │  이상한사탕    2400원   │                    │                  │ ┃\n";
	std::cout << "┃::│                       │────────────────────│   [ 0 ] 나가기   │ ┃\n";
	std::cout << "┃::└───────────────────────┘::::::::::::::::::::│                  │ ┃\n";
	std::cout << "│:::::::::::::::::::::::::::::::::::::::::::::::└──────────────────┘ ┃\n";
	std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃                                                                    ┃\n";
	std::cout << "┃    어서오세요! 포켓몬 상점입니다!                                  ┃\n";
	std::cout << "┃    물건을 팔러  오셨군요!                                          ┃\n";
	std::cout << "┃                                                                    ┃\n";
	std::cout << "╚━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}
//     ┌----   
//    [     \\ 
// * \\      ] 
//*** ┌   ──┐  
//*[*\\     \\ 
// \\ \\    │] 
//   \\__──__  
//             
                                                                                                                         
 //   ---─┐   
 // /         
 // [     / **
 // ┌  ──  /**
 ///  ::  \\] 
 //[│ :::  /  
 // __──__┘                                   
                                                         
//       ┌----  
//     [     \\
//    \\      ]
//      ─── ─┐ 
//  __/   \\ \\
// (  \\     │]
//   \\__──__  

             
//      ───    
//    /     ]  
//   (         
//     ──── \\ 
//  /      \\ ]
//  -│     │ ] 
//   __──__┘/  
                                                                                                                                                 
void UIManager::EndingUi(Pokemon* MyPokemon)
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
} //게임 종료 시 나타나는 UI입니다. 원래 GameManeger.cpp의 GameEnding()안에 있었는데 UIManager로 분할 컴파일 하면서 이동했습니다.