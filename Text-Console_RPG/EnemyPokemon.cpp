#include "EnemyPokemon.h"
#include <cstdlib>

EnemyPokemon::EnemyPokemon(): Pokemon() 
{
    p_level = 1;  
}

// 랜덤 능력치 생성
void EnemyPokemon::GenerateStats(int level)
{
    p_level = level;

    p_hp = level * (rand() % 11 + 20);      // 20~30
    p_attackPower = level * (rand() % 6 + 5); // 5~10
}
