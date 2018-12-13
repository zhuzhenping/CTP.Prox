#include "stdafx.h"
#include "CTraderHandler.h"
#include "logger.h"
void  CTraderHandler::OnFrontConnected()
{
	LogOK("Connect Success", 30);
	//¿ªÊ¼µÇÂ½
	CThostFtdcReqUserLoginField reqUserLogin = { 0 };
	strcpy_s(reqUserLogin.BrokerID,"9999");
	strcpy_s(reqUserLogin.UserID, "131259");
	strcpy_s(reqUserLogin.Password, "asdfjkl;");
	m_ptraderapi->ReqUserLogin(&reqUserLogin, nRequestID++);
}

void CTraderHandler::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	LogOK("Login Success", 30);
}
