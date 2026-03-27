//main.cpp
#include "GameManager.h"
#include "Inventory.h"
#include "Item.h"


int main()
{
	GameManager Stage;
	Pokemon Stat;
	Stage.GameStart();
	
	Inventory<Item> MyInven("마을사람1", 10);
	MyInven.PrintStatus();
	MyInven.Additem(Item("ex회복약", 11, 20));
	MyInven.Additem(Item("ex회복약", 12, 20));
	MyInven.PrintStatus();
	//if (PCurrentHp <= 0){
	//	Stage.GameEnding()
	//		stat.printstatus() //현재 상태 출력
	//
	//		return 0;}
	//P_type my_type = P_type::GRASS or FIRE or WATER;
	return 0;
}

