#include "PrintText.h"
#include <iostream>
#include <Windows.h>

void PrintText::typeWrite(const std::string& text) //텍스트 한글자씩
{
	for (char c : text)
	{
		std::cout << c;
		std::cout.flush();
		Sleep(10); // 속도 조절 (밀리초)
	}
	std::cout << std::endl;
}

void PrintText::typeWritecin(const std::string& text) //텍스트 한글자씩 endl 없음
{
	for (char c : text)
	{
		std::cout << c;
		std::cout.flush();
		Sleep(10);
	}
}
