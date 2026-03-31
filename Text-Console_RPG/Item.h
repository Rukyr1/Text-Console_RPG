//Item.h

#pragma once
#include <string>

class Item  //아이템 정보관리 클래스
{
public:
	// Item 생성자,  name 아이템 이름, price 아이템 가격, 아이템 초기수량, 아이템 사용시 회복량
	Item(const std::string& name = "", int price = 0, int Icount = 1, int heal = 0 ); //("이름",가격,갯수,힐량) 

	const std::string& GetName() const;      //아이템 이름 반환
	int GetPrice() const;                    //아이템 구매
	int GetCount() const;                    //아이템 갯수 추가(갯수 확인용)
	int GetHeal() const;                     //아이템 회복량
	void AddCount(int Pieces);               //아이템 추가
	bool Use();                              //아이템 사용   
	void clear();                            //아이템 정보 초기화,인벤토리에서 제거할때사용

private:
	std::string Iname;   //아이템 이름
	int Iprice;          //아이템 가격 
	int Icount;          //아이템 보유 수량
	int IhealAmount;     //회복량
};