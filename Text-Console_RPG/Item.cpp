// Item.cpp
#include "Item.h"
#include <iostream>
#include <string>


//아이템 생성자 , 아이템 이름, 아이템의 가격, 초기보유수량, 아이템 사용시 회복량
Item::Item(const std::string& name, int price, int count, int heal)  
	: Iname(name), Iprice(price), Icount(count), IhealAmount(heal) {
}

const std::string& Item::GetName() const { return Iname; } //아이템 이름 반환 
int Item::GetPrice() const { return Iprice; } // 아이템 가격 반환
int Item::GetCount() const { return Icount; } // 아이템 개수 반환
int Item::GetHeal()  const { return IhealAmount; } //회복량 반환

//아이템 개수 추가 
void Item::AddCount(int Pieces) 
{
	Icount += Pieces; //추가할 아이템 양
}

bool Item::Use() //아이템 사용로직
{
	if (Icount > 0) //아이템이 남아있는지 확인
	{
		Icount--; //개수 차감
		std::cout << Iname << "을(를) 1개 사용했습니다! (남은 개수:" << Icount << ")";
		return true;
	}
	std::cout << Iname << "아이템이 부족합니다." << std::endl; //아이템이 0개일시 출력
	return false;
}


void Item::clear()// 아이템 데이터 초기화
{
	Iname = "";
	Iprice = 0;
	Icount = 0;
	IhealAmount = 0;
}





// 인벤토리 생성 (소유자 이름: "플레이어", 칸수: 10)
//Inventory<Item> MyInven(10); //인벤토리이름 (인벤토리칸수 설정) 

// 아이템 획득 ("이름", 가격, 개수, 회복량)
//MyInven.Additem(Item("회복약", 10, 1)); //인벤에 ex회복약 추가 

// 아이템 사용 (1번 슬롯의 아이템 사용)
//MyInven.UseItem(1); 

// 2번 슬롯에 아이템 추가및 사용
//MyInven.Additem(Item("고급회복약", 10, 1));
//MyInven.UseItem(2); // 고급회복약 사용  

//이름과 가격이 같다면 기존 아이템의 개수 증가
//MyInven.Additem(Item("회복약", 10, 1)); 

// 인벤토리에 소지한 아이템 골드 출력
//MyInven.Printallitems(); 

//골드 획득과 사용시 
//MyInven.AddGold(10);// 골드 획득 (10골드) 
//MyInven.UseGold(100);// 골드 사용 (100골드) 

// 가지고있는 골드만 출력
//MyInven.Printallgold(); 

//상점 시스템 사용시
//Store MyStore("마을 상점"); 상점추가 ("상점이름")
//MyStore.InStore(MyInven); 상점연결