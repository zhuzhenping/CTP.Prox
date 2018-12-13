#pragma once
#include "ctph/ThostFtdcTraderApi.h"
#include "ctph/ThostFtdcMdApi.h"

#pragma comment (lib, "ctph/thostmduserapi.lib")
#pragma comment (lib, "ctph/thosttraderapi.lib")
#include<iostream>

int static  nRequestID=0;
class CTraderHandler : public CThostFtdcTraderSpi
{
private:
	CThostFtdcTraderApi * m_ptraderapi;
public:
	void connect()
	{
		m_ptraderapi = CThostFtdcTraderApi::CreateFtdcTraderApi();
		m_ptraderapi->RegisterSpi(this);
		m_ptraderapi->SubscribePublicTopic(THOST_TERT_RESTART);
		m_ptraderapi->SubscribePrivateTopic(THOST_TERT_RESTART); //设置私有流订阅模式
		std::string adress = "tcp://180.168.146.187:10001";
		m_ptraderapi->RegisterFront(const_cast<char *>(adress.c_str()));
		m_ptraderapi->Init();
		//输出API版本信息
		
		

		//LogOK(m_ptraderapi->GetApiVersion(),30);
		
	}


	void OnFrontConnected();
	void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


};