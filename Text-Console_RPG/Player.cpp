#include "Player.h"

Player::Player() 
{
	std::cout << "------- 플레이어의 이름을 입력하세요! -------" << std::endl;
	std::cout << "나의 이름은...!: " << PlayerName << std::endl;
	std::cin >> PlayerName;
};