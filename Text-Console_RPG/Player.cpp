#include "Player.h"

Player::Player()
	: PlayerName("")
	, MyPokemon(nullptr)
	, inventory(PlayerName, 10)
{};


Inventory<Item>& Player::GetInventory()
{
	return inventory;
}