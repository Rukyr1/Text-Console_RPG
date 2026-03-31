// Item.cpp
#pragma once
#include "Item.h"
#include <iostream>
#include <string>



Item::Item(const std::string& name, int price, int count, int heal)  // 아이템("이름" 가격 개수 힐량)
	: Iname(name), Iprice(price), Icount(count), IhealAmount(heal) {
}

const std::string& Item::GetName() const { return Iname; }
int Item::GetPrice() const { return Iprice; }
int Item::GetCount() const { return Icount; }
int Item::GetHeal()  const { return IhealAmount; } //힐 추가

void Item::AddCount(int Pieces)
{
	Icount += Pieces;
}

bool Item::Use() //아이템 사용시 출력
{
	if (Icount > 0)
	{
		Icount--;
		std::cout << Iname << "을(를) 1개 사용했습니다! (남은 개수:" << Icount << ")";
		return true;
	}
	std::cout << Iname << "아이템이 부족합니다." << std::endl; //아이템 부족시 출력
	return false;
}


void Item::clear()
{
	Iname = "";
	Iprice = 0;
	Icount = 0;
	IhealAmount = 0;
}






//Inventory<Item> MyInven(10); //인벤토리이름 (인벤토리칸수 설정) 
//
//MyInven.Additem(Item("회복약", 10, 1)); //인벤에 ex회복약 추가 //("이름": 가격: 개수:)
//MyInven.UseItem(1); // 회복약 사용 
// 
//MyInven.Additem(Item("고급회복약", 10, 1));
//MyInven.UseItem(2); // 고급회복약 사용  // 번호순으로 저장 
//MyInven.Additem(Item("회복약", 10, 1)); 이름과 가격이 같은 아이템의 경우 같은 아이템의 수치증가
// 
//MyInven.Printallitems(); // 인벤토리에 소지한 아이템 골드 출력
//
//MyInven.AddGold(10);// 골드 획득 (10골드) 골드 획득시 문구 출력
//MyInven.UseGold(100);// 골드 사용 (100골드) 골드 사용시 문구 출력 
//MyInven.Printallgold();// 가지고 있는 골드 출력 
//Store MyStore("마을 상점"); 상점추가 ("상점이름")
//MyStore.InStore(MyInven); 상점연결