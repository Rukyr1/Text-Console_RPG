#include "UIManager.h"
#include <iostream>
#include <Windows.h> // sound
#include <conio.h> //_getch
#include "Pokemon.h"
#include <iomanip> //setw

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

void UIManager::printHpBar(int currentHp, int maxHp)
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

void UIManager::BattleUiTop(Pokemon* MyPokemon, Pokemon* EnemyPokemon)
{
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	std::cout << "┃                                                              ┃\n";
	std::cout << "┃  ┌──────────────────────────────┐                            ┃\n";
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
	printHpBar(MyPokemon->getHp(), MyPokemon->getPMaxHp()); // 내 HP 바 출력
	std::cout << "  │  ┃\n";
	std::cout << "┃                            └──────────────────────────────┘  ┃\n";
}
void UIManager::BattleUiBottom()
{
	std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃  무엇을 할까?                        ┃ 싸운다      가방      ┃\n";
	std::cout << "┃                                      ┃ 포켓몬       도망     ┃\n";
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}

void UIManager::VillageUi(std::string playerName, Pokemon* MyPokemon)
{
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	std::cout << "┃ 🌳 마을 - 안전 지역                                          ┃\n";
	std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃ 플레이어: " << playerName << "                                             ┃\n";
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
}

