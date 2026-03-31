//Item.h

#pragma once
#include <string>

class Item
{
public:

	Item(const std::string& name = "", int price = 0, int Icount = 1, int heal = 0 ); //("이름",가격,갯수,힐량) //수정 "효과" -> "갯수" ->추가 힐

	const std::string& GetName() const;      //아이템이름
	int GetPrice() const;                    //아이템가격
	int GetCount() const;                    //아이템 갯수 추가(개수 확인용)
	int GetHeal() const;                     //아이템 회복량
	void AddCount(int Pieces);               //아이템 갯수 증가용
	bool Use();                              //사용   
	void clear();                            //

private:
	std::string Iname;
	int Iprice;
	int Icount; //갯수 추가
	int IhealAmount;
};