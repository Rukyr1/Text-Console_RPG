// Inventory.h
#pragma once
#include <iostream>
#include <string>
#include <iomanip>


// 템플릿 기반 인벤토리 클래스
template<typename T>
class Inventory
{
public:
	//복사 생성자 및 대입연산자 금지  
	Inventory(const Inventory& other) = delete;            
	Inventory& operator=(const Inventory& other) = delete; 


	//인벤토리 생성자 owner 소유자 이름 , capacity 인벤토리 최대 칸수 (기본 10칸)
	Inventory(std::string owner = "", int capacity = 10) : IownerName(owner), Isize(0), Igold(0)
	{
		Icapacity = (capacity <= 0) ? 1 : capacity;

		pItems = new T[Icapacity]; // 동적 배열 할당
	}
	// 소멸자 할당된 동적 배열 해제
	~Inventory()
	{
		delete[] pItems;

		pItems = nullptr;
	}

	T* GetItem(int index)   //아이템 포인터 반환 회복아이템을 사용하기위해 추가
	{
		
		if (index < 0 || index >= Isize)
		{
			return nullptr;
		}
		return &pItems[index];
	}



	void Additem(const T& item) // 아이템 추가 (중복시 개수 증가, 신규시 빈슬롯 삽입)
	{
		//동일한 아이템이 있는지 확인하고 추가(이름과 가격)
		for (int i = 0; i < Icapacity; i++) 
		{
			if (pItems[i].GetName() == item.GetName() && pItems[i].GetPrice() == item.GetPrice()) 
			{
				pItems[i].AddCount(item.GetCount());
				//std::cout << item.GetName() << "의 개수가 증가했습니다. (현재: " << pItems[i].GetCount() << "개)" << std::endl;
				return;
			}
		}

		//동일한 아이템이 없다면 빈슬롯 추가
		for (int i = 0; i < Icapacity; i++) 
		{
			if (pItems[i].GetName() == "")
			{
				pItems[i] = item;
				Isize++;
				//std::cout << item.GetName() << " " << item.GetCount() << "개를 가방에 넣었습니다." << std::endl;
				return;
			}
		}
		std::cout << "가방이 꽉 차서(" << item.GetName() << ")을(를) 넣을 수 없습니다!" << std::endl;

	}

	
	void Printallitems() const //소지중인 모든 아이템 및 골드 출력
	{
		//std::cout <<"\n[" << IownerName << "]" << "\n 인벤토리 (" << Isize << "/" << Icapacity << ")" << std::endl;

		bool HasItem = false; //가방에 아이템이 있는지 체크 하는 변수

		for (int i = 0; i < Icapacity; i++)
		{

			if (pItems[i].GetName() != "")// 이름이 있는 아이템만 출력 (비어있는 슬롯은 출력x )
			{
				std::cout << i + 1 << ". " << pItems[i].GetName()
					<< " | 회복량: " << pItems[i].GetHeal()
					<< " | 가격: " << pItems[i].GetPrice()
					<< " | 개수: " << pItems[i].GetCount() << std::endl;
				HasItem = true;
			}
		}
		if (!HasItem) //아이템이 하나도 없다면 출력
		{
			std::cout << "(비어 있습니다.)" << std::endl;
		}
		std::cout << " 소지 골드: " << Igold << " G" << std::endl;
		std::cout << "----------------------------------" << std::endl;
	}


	void UseItem(int index) //아이템 사용
	{
		// 인덱스 검사 (1 ~ 최대 용량)
		if (index < 1 || index > Icapacity)
		{
			std::cout << "잘못된 접근입니다." << std::endl;
			return;
		}

		int targetIndex = index - 1; // 배열 인덱스로 변환



		if (pItems[targetIndex].GetName() == "") // 아이템이 있는지 확인 없다면 "아이템이 없습니다." 출력
		{
			std::cout << "아이템이 없습니다." << std::endl;
			return;
		}

		if (pItems[targetIndex].Use()) //  아이템 사용 성공시 //  ""을 사용했습니다. 출력
		{

			if (pItems[targetIndex].GetCount() <= 0)//  아이템 사용후 남은개수가 0이라면 칸비우기 
			{
				std::cout << pItems[targetIndex].GetName() << "을(를) 모두 소모했습니다." << std::endl;
				pItems[targetIndex].clear();
				UpdateInventory();

			}
		}
	}
	void UpdateInventory() {
		for (int i = 0; i < Icapacity - 1; i++) {
			// 현재 칸이 비어있는데 다음 칸에 아이템이 있다면 당기기
			if (pItems[i].GetName() == "" && pItems[i + 1].GetName() != "") {
				pItems[i] = pItems[i + 1];
				pItems[i + 1].clear();
				// 당긴 후 이전 칸들이 비었을 수 있으므로 i를 다시 0으로 돌리거나 반복 검사
				i = -1;
			}
		}

		// Isize 갱신 (실제 데이터가 있는 칸 수 계산)
		int count = 0;
		for (int i = 0; i < Icapacity; i++) if (pItems[i].GetName() != "") count++;
		Isize = count;
	}


	void AddGold(int gold) // 골드 획득 
	{
		Igold += gold;
		std::cout << gold << "골드를 획득했습니다.";
		//std::cout << "현재: " << Igold << "G" << std::endl;  // 현재 골드 출력
	}

	bool UseGold(int gold) { // 골드 사용

		if (Igold < gold) { // 골드 부족시
			//std::cout << "골드가 부족합니다."; //골드 부족 문구
			//std::cout << "필요: " << gold << "G" << "  현재: " << Igold << "G" << std::endl; // 필요골드 현재골드 출력
			return false;
		}
		Igold -= gold; //골드 사용
		//std::cout << gold << "골드를 사용했습니다." << std::endl; //골드 사용문구
		//std::cout << "남은 골드: " << Igold << "G" << std::endl; //남은 골드 출력
		return true;
	}

	void Printallgold() const //가방안에 있는 아이템과 골드 출력
	{
		std::cout << "현재 골드: " << Igold << "G" << std::endl;
	}

	T* GetItemUse(int index)//회복용 아이템 사용
	{
		if (index < 0 || index >= Icapacity) return nullptr; //사용자
	    

		if (pItems[index].GetName() == "") return nullptr; //빈슬롯
		
		return &pItems[index]; //주소전달용
	}

	T& GetItemShop(int index)//상점용
	{
		return pItems[index - 1];
	}

	void Storeitems() const // 가방안에있는 아이템 출력
	{

		bool HasItem = false; //가방에 아이템이 있는지 체크 하는 변수

		for (int i = 0; i < Icapacity; i++)
		{

			if (pItems[i].GetName() != "")// 이름이 있는 아이템만 출력 (비어있는 슬롯은 출력x )
			{
				std::cout << i + 1 << ". " << pItems[i].GetName()
					<< " | 회복량: " << pItems[i].GetHeal()
					<< " | 가격: " << pItems[i].GetPrice()
					<< " | 개수: " << pItems[i].GetCount() << std::endl;
				HasItem = true;
			}
		}
		if (!HasItem) //아이템이 하나도 없다면 출력
		{
			std::cout << "(비어 있습니다.)" << std::endl;
		}
		std::cout << "----------------------------------" << std::endl;
	}

	
	
	int GetGold() const  //골드
	{
		return Igold;
	}

private:
	T* pItems;
	std::string IownerName;
	int Icapacity;
	int Isize;
	int Igold;

};