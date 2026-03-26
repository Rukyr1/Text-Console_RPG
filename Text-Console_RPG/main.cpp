//main.cpp
//player 캐릭터 생성 및 Pokemon 부모클래스 생성
#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Player.h"
#include "Bulbasaur.h"
#include "Inventory.h"
#include "Item.h"

int main()
{
	
	//P_type my_type = P_type::GRASS or FIRE or WATER;
	return 0;
}


//Inventory<Item> MyInven(10); //인벤토리 칸수 설정 // 인벤토리칸 필수 제일 위에 올라와야함
//MyInven.Additem(Item("ex회복약", 10, 20)); //인벤에 ex회복약 넣기 //("이름": 가격: 효과:)
//MyInven.UseItem(1); // ex회복약 사용 
//MyInven.Additem(Item("ex회약", 10, 20));
//MyInven.UseItem(2); // 회약 사용  // 번호순으로 저장
//MyInven.Printallitems(); // 가지고 있는 아이템 출력
//MyInven.AddGold(10);// 골드 획득 (10골드) // 골드 획득시 문구 출력
//MyInven.UseGold(100);// 골드 사용 (100골드) // 골드 사용시 문구 출력 
//MyInven.Printallgold();// 가지고 있는 골드 출력 