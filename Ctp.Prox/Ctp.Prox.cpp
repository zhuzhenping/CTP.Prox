// Ctp.Prox.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include "datatype.h"
#include "CTraderHandler.h"
using namespace std;


int main()
{
	CTraderHandler  trader;
	trader.connect();
	system("pause");
	return 0;
}


