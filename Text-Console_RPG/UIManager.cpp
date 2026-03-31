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
	std::cout << "┃  ┌──────────────────────────────┐                            ┃\n";
	std::cout << "┃  │ " << std::left << std::setw(15) << EnemyPokemon->getName() << " L13             │                            ┃\n";
	std::cout << "┃  │      HP: ";
	printHpBar(EnemyPokemon->getHp(), EnemyPokemon->getPMaxHp()); // HP 바 출력
	std::cout << "│       │\\ //   \\            ┃\n";
	std::cout << "┃  └──────────────────────────────┘       |          \\         ┃\n";
	std::cout << "┃                                         [        \\ /         ┃\n";
	std::cout << "┃                                           ───    ::\          ┃\n";
	std::cout << "┃                                          \\ _|:/\\_]           ┃\n";
	std::cout << "┃       ---                                 -  -               ┃\n";
	std::cout << "┃     /      \\\\/|                                              ┃\n";
	std::cout << "┃    [        \\  \\                                             ┃\n";
	std::cout << "┃    /\\ ____/    ]                                             ┃\n";
	std::cout << "┃   |       ::  \\            ┌──────────────────────────────┐  ┃\n";
	std::cout << "┃   \\ ::    /:: |            │ " << std::left << std::setw(15) << MyPokemon->getName() << " L14              │  ┃\n";
	std::cout << "┃      ──────_/_]            │      HP: ";
	printHpBar(MyPokemon->getHp(), MyPokemon->getPMaxHp()); // 내 HP 바 출력
	std::cout << "│  ┃\n";
	std::cout << "┃                            └──────────────────────────────┘  ┃\n";
}

void UIManager::BattleUiBottom()
{


	//std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━┓\n";

	//// 1행
	//std::cout << "┃ ";
	//if (cursor == 1) setColor(10);
	//std::cout << "▶ 공격";
	//setColor(7);
	//std::cout << "                 ┃ ";

	//if (cursor == 2) setColor(11);
	//std::cout << "가방";
	//setColor(7);
	//std::cout << "                ┃\n";

	//// 중간선
	//std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━┫\n";

	//// 2행
	//std::cout << "┃ ";
	//if (cursor == 3) setColor(14);
	//std::cout << "▶ 포켓몬";
	//setColor(7);
	//std::cout << "             ┃ ";

	//if (cursor == 4) setColor(12);
	//std::cout << "도망";
	//setColor(7);
	//std::cout << "                ┃\n";

	//// 하단
	//std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━┛\n";

	/*std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃                                      ┃                       ┃\n";
	std::cout << "┃                                      ┃                       ┃\n";
	std::cout << "┃  무엇을 할까?                        ┃ 싸운다      가방      ┃\n";
	std::cout << "┃                                      ┃ 포켓몬       도망     ┃\n";
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";*/

}

void UIManager::VillageUi(std::string playerName, Pokemon* MyPokemon)
{
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	std::cout << "┃ 🌳 마을 - 안전 지역                                          ┃\n";
	std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃ 플레이어: " << playerName << "                                                 ┃\n";
	std::cout << "┃ 보유 골드:                                                 ┃\n";
	std::cout << "┃ 현재 포켓몬: " << MyPokemon->getName() << "  Lv: " << MyPokemon->getLevel() << "  Hp: " << MyPokemon->getHp() << "/" << MyPokemon->getPMaxHp() << "               ┃\n";
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

void UIManager::PokemonCenterUi()
{
	system("cls");
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	std::cout << "┃                          POKEMON CENTER                            ┃\n";
	std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃                                                                    ┃\n";
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
	std::cout << "┃                                               │   [ 1 ] 쉬게하다 │ ┃\n";
	std::cout << "┃                                               │                  │ ┃\n";
	std::cout << "┃::─────────────────────────────────────────────│   [ 2 ] 그만두다 │ ┃\n";
	std::cout << "┃:::::::::::::::::::::::::::::::::::::::::::::::│                  │ ┃\n";
	std::cout << "│:::::::::::::::::::::::::::::::::::::::::::::::└──────────────────┘ ┃\n";
	std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";
	std::cout << "┃                                                                    ┃\n";
	std::cout << "┃    안녕하세요! 포켓몬 센터입니다!                                  ┃\n";
	std::cout << "┃    당신의 포켓몬을 쉬게 하겠습니까?                                ┃\n";
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
                                                                                                                                                 
                                         