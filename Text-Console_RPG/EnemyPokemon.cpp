#include "EnemyPokemon.h"
#include <cstdlib>

EnemyPokemon::EnemyPokemon(): Pokemon() 
{
    PLevel = 1;
}

// 랜덤 능력치 생성
void EnemyPokemon::GenerateStats(int level)
{
    PLevel = level;

    PHp = level * (rand() % 11 + 20);      // 20~30
    PAttackPower = level * (rand() % 6 + 5); // 5~10
}
