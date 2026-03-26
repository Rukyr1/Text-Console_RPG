#pragma once

#include <string>
#include <iostream>

class Item
{
public:
	// 이름 가격 효과
	Item(const std::string& name = "", int price = 0, int effect = 0)
		: name_(name), price_(price), effect_(effect) {
	}

	const std::string& GetName() const { return name_; }
	int GetPrice() const { return price_; }
	int GetEffect() const { return effect_; }

	void clear()
	{
		name_ = "";
		price_ = 0;
		effect_ = 0;
	}
	// 아이템 사용시 이름 출력
	void Use() const
	{
		if (name_ == "") return;
		std::cout << name_ << "을(를) 사용했습니다!" << std::endl;
	}

private:
	std::string name_;
	int price_;
	int effect_;
};


// Inventory<T> class 정의
template<typename T>
class Inventory
{
public: //동적 배열 생성
	Inventory(int capacity = 10) : size_(0)
	{
		capacity_ = (capacity <= 0) ? 1 : capacity;

		pItems_ = new T[capacity_];
	}

	~Inventory()//동적배열 해제
	{
		delete[] pItems_;

		pItems_ = nullptr;
	}

	void Additem(const T& item) // 인벤에 아이템 넣기
	{
		if (size_ >= capacity_)
		{
			std::cout << "가방이 꽉 차서(" << item.GetName() << ")을(를) 넣을 수 없습니다" << std::endl;
			return;
		}
		std::cout << "(" << item.GetName() << ")" << "을(를) 가방에 넣었습니다." << std::endl;
		pItems_[size_] = item;
		size_++;
	}

	void Removelastitem() // 인벤에 마지막 아이템 없에기  // 없애기
	{
		if (size_ <= 0)
		{
			std::cout << "가방 비었음" << std::endl;
			return;
		}
		pItems_[size_ - 1].clear();
		size_--;
		std::cout << "마지막 아이템을 제거했습니다." << std::endl;
	}

	void Printallitems() const // 가방안에있는 아이템 출력
	{
		std::cout << "\n 현재 가방 (" << size_ << "/" << capacity_ << ")" << std::endl;
		for (int i = 0; i < size_; i++)
		{
			std::cout << i + 1 << ". " << pItems_[i].GetName()
				<< " | 가격: " << pItems_[i].GetPrice()
				<< " | 효과: " << pItems_[i].GetEffect() << std::endl;
		}
		if (size_ == 0) std::cout << "비어 있음" << std::endl;
		std::cout << "----------------------------------\n" << std::endl;
	}

	void UseItem(int index) {
		// 인덱스 유효성 검사 (사용자 입력은 1부터 시작한다고 가정)
		if (index < 1 || index > size_) {
			std::cout << "아이템이 없습니다." << std::endl;
			return;
		}

		int targetIndex = index - 1; // 배열 인덱스로 변환

		//  아이템 사용 효과 실행 // ""을 사용했습니다. 출력
		pItems_[targetIndex].Use();

		//  아이템 삭제 및 뒤의 아이템들 앞으로 당기기
		for (int i = targetIndex; i < size_ - 1; i++) {
			pItems_[i] = pItems_[i + 1];
		}

		//  마지막 칸 초기화 크기 줄이기
		pItems_[size_ - 1].clear();
		size_--;
	}






private:
	T* pItems_;
	int capacity_;
	int size_;

};



