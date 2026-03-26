//Item.h
#pragma once

#include <string>

class Item
{
public:
	// 이름 가격 효과
	Item(const std::string& name = "", int price = 0, int effect = 0);



	const std::string& GetName() const;
	int GetPrice() const;
	int GetEffect() const;

	void clear();

	void Use() const;


private:
	std::string Iname;
	int Iprice;
	int Ieffect;
};