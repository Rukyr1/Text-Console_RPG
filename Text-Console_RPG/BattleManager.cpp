#include "BattleManager.h"

BattleManager::BattleManager()
	: IsBattle(false)
	, IsTurnPass(false)
	, IsEscape(false)
	, AtkChoice(0)
	, BagChoice(0)
{
}

//void BattleManager::StartBattle(Pokemon* MyPokemon)
//{	
//	Pokemon* EnemyPokemon = new Bulbasaur();
//
//	//std::cout << "야생의 " << EnemyPokemon->PName << "가 나타났다!" << std::endl;
//
//	/*while (MyPokemon->PHp >= 0 && EnemyPokemon->PHp >= 0)
//	{
//		std::cout << "무엇을 할까?";
//	}*/
//
//	IsBattle = true;
//	//Pokemon->PPrintStats(); 내 포켓몬 스탯(상태) 출력
//	//EnemyPokemon->PPrintStats(); 적 포켓몬 스탯(상태) 출력
//
//	while (IsBattle)
//	{
//		std::cout << "무엇을 할까?" << std::endl;
//		std::cout << "1. 공격 2. 가방 3. 도망" << std::endl;
//		std::cin >> AtkChoice;
//
//		IsTurnPass = false;
//
//		switch (AtkChoice)
//		{
//		case 1:
//			//std::cout << MyPokemon->GetName() << "의 공격!" << std::endl;
//			//EnemyPokemon->takeDamage(MyPokemon->skill());
//			
//			//에너미 포켓몬 데미지가 어쩌구~ if문~
//
//			IsTurnPass = true;
//			break;
//
//		case 2:
//			break;
//
//		case 3:
//			break;
//
//		}
//	}
//}