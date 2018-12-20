#pragma once
#include "windows.h"
#include <iostream>

void LogOutput(const std::string& str, int color);
//{
//	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); //获取缓冲区句柄 
//	SetConsoleTextAttribute(hCon, color); //设置文本及背景色 
//	std::cout << str.c_str() << std::endl;
//} 

#define LogOK(fmt,...) LogOutput(fmt,50)
#define LogError(fmt,...) LogOutput(fmt,30)
