// Store.h

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Inventory.h"
#include "Item.h"
#include <Windows.h> 
#include <conio.h>

class Store
{
public:
    //  상점 이름 설정 및 기본 물품 진열
    Store(std::string name = "상점") : storeName(name), storeInven("상점칸수", 10)
    {
        // 상점 기본 아이템.
        storeInven.Additem(Item("상처약", 300, 30, 20));  // 이름, 가격, 개수, 힐량
        storeInven.Additem(Item("좋은상처약", 700, 30, 60));
        // storeInven.Additem(Item("이상한 사탕", 1000, 10, 10)); 추가 못함
    }
    
    void InStore(Inventory<Item>& playerInven) {
        int input = -1;

        while (input != 0) {
            //system("cls");
            ShowItems(); // 상점 목록 출력
            playerInven.Printallgold(); // 플레이어 돈 출력

            std::cout << "구매할 번호 입력 (나가기: 0): ";
            std::cin >> input;

            if (input == 0) break;
             

            // 구ao 실행
            BuyItem(input, playerInven);

            //std::cout << "\n----------------------------------";
            playerInven.Printallgold(); // 실시간 골드 출력
            std::cout << "아무 키나 누르면 목록으로 돌아갑니다..." << std::endl;
            _getch();
        }
    }

    // 상점 보기
    void ShowItems() const
    {
        //std::cout << "==================================" << std::endl;
       // std::cout << "     [" << storeName << "] " << std::endl;

        //std::cout << "           [" << storeName << "] " << std::endl;
        storeInven.Storeitems();
    }

    // 구매 
    // 플레이어의 인벤토리를 참조 받아 수정.
    void BuyItem(int slotIndex, Inventory<Item>& playerInven)
    {
        
        int internalIdx = slotIndex - 1;
        // 슬롯 범위 (1 ~ 상점 용량)
        if (slotIndex < 1 || slotIndex > 10)
        {
            std::cout << "잘못된 번호입니다." << std::endl;
            return;
        }


        //상점 인벤토리에서 해당 번호의 아이템 정보를 가져오기.
        Item& shopItem = storeInven.GetItemShop(slotIndex);

        // 재고가 없는경우 출력
        if (shopItem.GetName() == "" || shopItem.GetCount() <= 0)
        {
            std::cout << "판매할 상품이 없습니다." << std::endl;
            return;
        }

        int price = shopItem.GetPrice();

        // 플레이어 골드 차감
        if (playerInven.UseGold(shopItem.GetPrice()))
        {

            // 정상적으로 동작되면 플레이어 인벤토리에 아이템 추가하고 골드차감
            Item newItem(shopItem.GetName(), shopItem.GetPrice(), 1, shopItem.GetHeal());
            playerInven.Additem(newItem);

            std::cout << "[" << shopItem.GetName() << "] 구매 완료!" << std::endl;

            //상점 재고 감소 
            shopItem.AddCount(-1);
            if (shopItem.GetCount() <= 0)
            {
                shopItem.clear();
                std::cout << "상품의 재고가 없습니다.";
            }
        }


        else
        {
            std::cout << "골드가 부족하여 구매할 수 없습니다." << std::endl;
        }
    }

private:
    std::string storeName;
    Inventory<Item> storeInven; // 상점이 관리하는 인벤토리
};
