#pragma once
#include<iostream>
#include<string>

//Player.h
class Player //플레이어 클래스
{
protected:
	std::string PlayerName; // 멤버변수 : 플레이어 이름 -> 플레이어는 별명만 입력 받으면 끝

public:

<<<<<<< HEAD
	Player(); //생성자(매개변수 플레이어 이름
=======
	Player();
	//{ }; //생성자(매개변수 플레이어 이름

>>>>>>> cfc44ed3bbd5762b46f4a8e80d1ceb443a88f9a3

	virtual ~Player() {}; //소멸자

};

