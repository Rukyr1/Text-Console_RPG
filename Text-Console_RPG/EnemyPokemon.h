#pragma once
#include "Pokemon.h"

class EnemyPokemon : public Pokemon
{
public:
    EnemyPokemon(); 
    void GenerateStats(int level);
};

