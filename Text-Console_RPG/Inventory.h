// Inventory.h
#pragma once
#include <iostream>
#include <string>

// Inventory<T> class 정의
template<typename T>
class Inventory
{
public:
	//복사 금지 설정   // & 참조 사용
	Inventory(const Inventory& other) = delete;            // 복사 생성자 금지
	Inventory& operator=(const Inventory& other) = delete; // 대입 연산자 금지


	//동적 배열 생성
	Inventory(std::string owner = "", int capacity = 10) : IownerName(owner), Isize(0), Igold(0)
	{
		Icapacity = (capacity <= 0) ? 1 : capacity;

		pItems = new T[Icapacity];
	}

	~Inventory()//동적배열 해제
	{
		delete[] pItems;

		pItems = nullptr;
	}



	void Additem(const T& item) // 인벤에 아이템 넣기
	{
		if (Isize >= Icapacity)
		{
			std::cout << "가방이 꽉 차서(" << item.GetName() << ")을(를) 넣을 수 없습니다!" << std::endl;
			return;
		}
		std::cout << "(" << item.GetName() << ")" << "을(를) 가방에 넣었습니다." << std::endl;
		pItems[Isize] = item;
		Isize++;
	}

	void Removelastitem() // 인벤에 마지막 아이템 없에기  // 없애기
	{
		if (Isize <= 0)
		{
			std::cout << "가방이 비어있습니다." << std::endl;
			return;
		}
		pItems[Isize - 1].clear();
		Isize--;
		std::cout << "아이템을 제거했습니다!" << std::endl;
	}

	void Printallitems() const // 가방안에있는 아이템 출력
	{
		std::cout << "[" << IownerName << "]" << "\n 현재 가방 (" << Isize << "/" << Icapacity << ")" << std::endl;
		for (int i = 0; i < Isize; i++)
		{
			std::cout << i + 1 << ". " << pItems[i].GetName()
				<< " | 가격: " << pItems[i].GetPrice()
				<< " | 효과: " << pItems[i].GetEffect() << std::endl;
		}
		if (Isize == 0) std::cout << "비어 있습니다." << std::endl;
		std::cout << "----------------------------------\n" << std::endl;
	}

	void UseItem(int index) {
		// 인덱스 유효성 검사 (사용자 입력은 1부터 시작한다고 가정)
		if (index < 1 || index > Isize) {
			std::cout << "아이템이 없습니다." << std::endl;
			return;
		}

		int targetIndex = index - 1; // 배열 인덱스로 변환

		//  아이템 사용 효과 실행 // ""을 사용했습니다. 출력
		pItems[targetIndex].Use();

		//  아이템 삭제 및 뒤의 아이템들 앞으로 당기기
		for (int i = targetIndex; i < Isize - 1; i++) {
			pItems[i] = pItems[i + 1];
		}

		//  마지막 칸 초기화 크기 줄이기
		pItems[Isize - 1].clear();
		Isize--;
	}

	void AddGold(int gold) // 골드 획득 
	{
		Igold += gold;
		std::cout << gold << "골드를 획득했습니다.";
		std::cout << "현재: " << Igold << "G" << std::endl;  // 현재 골드 출력
	}

	bool UseGold(int gold) { // 골드 사용

		if (Igold < gold) { // 골드 부족시
			std::cout << "골드가 부족합니다."; //골드 부족 문구
			std::cout << "필요: " << gold << "G" << "  현재: " << Igold << "G" << std::endl; // 필요골드 현재골드 출력
			return false;
		}
		Igold -= gold; //골드 사용
		std::cout << gold << "골드를 사용했습니다." << std::endl; //골드 사용문구
		std::cout << "남은 골드: " << Igold << "G" << std::endl; //남은 골드 출력
		return true;
	}

	void Printallgold() const
	{
		std::cout << "\n 현재 골드: " << Igold << "G" << std::endl;
	}

	void PrintStatus() const {
		std::cout << "\n[" << IownerName << "]" << std::endl;
		std::cout << " [소지 골드] " << Igold << " G" << std::endl;
		std::cout << " [인벤토리] (" << Isize << "/" << Icapacity << ")" << std::endl;
		for (int i = 0; i < Isize; i++) {
			std::cout << i + 1 << ". " << pItems[i].GetName() << " (가격: " << pItems[i].GetPrice() << "G)" << std::endl;
		}
		if (Isize == 0) std::cout << " (비어 있습니다.)" << std::endl;
		std::cout << "================================\n" << std::endl;
	}

	

private:
	T* pItems;
	std::string IownerName;
	int Icapacity;
	int Isize;
	int Igold;

};