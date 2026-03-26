//main.cpp
//player 캐릭터 생성 및 Pokemon 부모클래스 생성
#include<iostream>
#include<string>
#include "Pokemon.h"
#include "Bulbasaur.h"


//포켓몬 타입 정의
enum class  P_type //일단 스타팅 포켓몬 타입 3개만
{
	GRASS,
	FIRE,
	WATER
};

int main()
{
	//P_type my_type = P_type::GRASS or FIRE or WATER;
	return 0;
}


// Inventory<Item> MyInven(120); //인벤토리 칸수
// MyInven.Additem(Item("회복약", 10, 20)); //인벤에 회복약 넣기 //(이름 가격 효과)
// MyInven.Printallitems(); // 가지고 있는 아wlrma이템 출력
// MyInven.UseItem(1); // 회복약 사용