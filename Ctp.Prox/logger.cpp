#include "stdafx.h"
#include "logger.h"

void LogOutput(const std::string& str, int color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��������� 
	SetConsoleTextAttribute(hCon, color); //�����ı�������ɫ 
	std::cout << str.c_str() << std::endl;
} 