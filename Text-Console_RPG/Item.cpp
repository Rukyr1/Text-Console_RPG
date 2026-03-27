// Item.cpp
#pragma once
#include "Item.h"
#include <iostream>
#include <string>



Item::Item(const std::string& name, int price, int effect)
	: Iname(name), Iprice(price), Ieffect(effect) {
}

const std::string& Item::GetName() const { return Iname; }
int Item::GetPrice() const { return Iprice; }
int Item::GetEffect() const { return Ieffect; }

// 아이템 사용시 이름 출력
void Item::Use() const
{
	if (Iname == "") return;
	std::cout << Iname << "을(를) 사용했습니다!" << std::endl;
}

void Item::clear()
{
	Iname = "";
	Iprice = 0;
	Ieffect = 0;
}



//Inventory<Item> MyInven("모험가",10); //인벤토리 ("인벤토리 이름",인벤토리 칸수 설정) // 
//MyInven.Additem(Item("ex회복약", 10, 20)); //인벤에 ex회복약 넣기 //("이름": 가격: 효과:)
//MyInven.UseItem(1); // ex회복약 사용 
//MyInven.Additem(Item("ex회약", 10, 20));
//MyInven.UseItem(2); // 회약 사용  // 이런식으로 번호순으로 저장
//MyInven.Printallitems(); // 가지고 있는 아이템 출력
//MyInven.AddGold(10);// 골드 획득 (10골드) 골드 획득시 문구 출력
//MyInven.UseGold(100);// 골드 사용 (100골드) 골드 사용시 문구 출력 
//MyInven.Printallgold();// 가지고 있는 골드 출력 