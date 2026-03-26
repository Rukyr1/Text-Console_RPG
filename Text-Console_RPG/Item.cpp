// Item.cpp

#include "Item.h"
#include <iostream>
#include <string>



Item::Item(const std::string& name, int price, int effect)
	: Iname(name), Iprice(price), Ieffect(effect) {
}

const std::string& Item::GetName() const { return Iname; }
int Item::GetPrice() const { return Iprice; }
int Item::GetEffect() const { return Ieffect; }

void Item::clear()
{
	Iname = "";
	Iprice = 0;
	Ieffect = 0;
}
// 아이템 사용시 이름 출력
void Item::Use() const
{
	if (Iname == "") return;
	std::cout << Iname << "을(를) 사용했습니다!" << std::endl;
}


