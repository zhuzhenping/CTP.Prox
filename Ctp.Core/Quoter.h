
#pragma once
#include "TraderDataTypes.h"
using namespace System::Collections::Generic;
namespace Ctp::Core
{
	public ref class Quoter
	{
	public:
		Quoter();
		!Quoter();
		~Quoter();

		void Init();
		void Release();
		Int32 Join();


		CThostFtdcMdApi* native = nullptr;


	

		delegate void OnFrontConnectedHandler();
		event OnFrontConnectedHandler^ OnFrontConnected;

		delegate void OnFrontDisconnectedHandler(int nReason);
		event OnFrontDisconnectedHandler^ OnFrontDisconnected;

		delegate void UserLoginResponseEventHandler(UserLoginResponseData^ pRspUserLogin, ResponseInformation ^pRspInfo, int nRequestID, bool bIsLast);
		event UserLoginResponseEventHandler^ UserLoginResponse;

		delegate void UserLogoutResponseEventHandler(UserLogoutResponseData^ pRspUserLogin, ResponseInformation ^pRspInfo, int nRequestID, bool bIsLast);
		event UserLogoutResponseEventHandler^ UserLogoutResponse;

		delegate void OnRspErrorEventHandler(ResponseInformation ^pRspInfo, int nRequestID, bool bIsLast);
		event OnRspErrorEventHandler^ OnRspError;

		delegate void OnRspSubMarketDataHandler(RspSubMarketResponseData^ pSpecificInstrument, ResponseInformation ^pRspInfo, int nRequestID, bool bIsLast);
		event OnRspSubMarketDataHandler^ OnRspSubMarketData;

		delegate void OnOnRspUnSubMarketDataHandler(RspSubMarketResponseData^ pSpecificInstrument, ResponseInformation ^pRspInfo, int nRequestID, bool bIsLast);
		event OnOnRspUnSubMarketDataHandler^ OnRspUnSubMarketData;

		delegate void OnRspSubForQuoteRspHandler(RspSubMarketResponseData^ pSpecificInstrument, ResponseInformation ^pRspInfo, int nRequestID, bool bIsLast);
		event OnRspSubForQuoteRspHandler^ OnRspSubForQuoteRsp;

		delegate void OnRspUnSubForQuoteRspHandler(RspSubMarketResponseData^ pSpecificInstrument, ResponseInformation ^pRspInfo, int nRequestID, bool bIsLast);
		event OnRspUnSubForQuoteRspHandler^ OnRspUnSubForQuoteRsp;

		delegate void OnRtnDepthMarketDataHandler(RtnDepthMarketResponseData^ pDepthMarketData);
		event OnRtnDepthMarketDataHandler^ OnRtnDepthMarketData;

		delegate void OnRtnForQuoteRspHandler(OnRtnForQuoteResponseData^ pForQuoteRsp);
		event OnRtnForQuoteRspHandler^ OnRtnForQuoteRsp;

	



		String^ GetTradingDay();
		void RegisterFront(String^ pszFrontAddress);
		int ReqUserLogin(UserLoginRequestData^ pReqUserLoginField, int nRequestID);
		int ReqUserLogout(UserLogoutRequestData^ pUserLogout, int nRequestID);
		int SubscribeMarketData(List<String^>^ ppInstrumentID, int nCount) ;
		int UnSubscribeMarketData(List<String^>^ ppInstrumentID, int nCount);
		int SubscribeForQuoteRsp(List<String^>^ ppInstrumentID, int nCount);
		int UnSubscribeForQuoteRsp(List<String^>^ ppInstrumentID, int nCount);

		void RiseOnFrontConnected();
		void RiseOnFrontDisconnected(int nReason) ;
		void RiseOnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
		void RiseOnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RiseOnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
		void RiseOnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
		void RiseOnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
		void RiseOnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RiseOnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
		void RiseOnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData) ;
		void RiseOnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) ;

	private:
		CThostFtdcMdSpi * quoter_spi = nullptr;

	};
}