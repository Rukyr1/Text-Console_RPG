//main.cpp
#include "GameManager.h"
#include <Windows.h> // gotoXy

int main()
{
	SetConsoleTitle(L"십칠색조의 pokemon.exe"); //콘솔 창 이름 변경

	GameManager Stage;
	//Pokemon Stat;
	Stage.IntroScreen();

	//	Stage.GameEnding()
	//	stat.printstatus() //현재 상태 출력

	//P_type my_type = P_type::GRASS or FIRE or WATER;
	return 0;
}

