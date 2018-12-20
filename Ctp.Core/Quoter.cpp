
#include "stdafx.h"
#include "Quoter.h"
using namespace System::Collections::Generic;
namespace Ctp::Core
{

	public class ResQuoterSpi : public CThostFtdcMdSpi
	{
	public:
		ResQuoterSpi(Quoter^ clr_quoter) :
			clr_quoter(clr_quoter)
		{

		}
		msclr::gcroot<Quoter^> clr_quoter;

		virtual void OnFrontConnected() override
		{
			clr_quoter->RiseOnFrontConnected();
		};

		virtual void OnFrontDisconnected(int reason_code) override
		{
			clr_quoter->RiseOnFrontDisconnected(reason_code);
		}

		virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			clr_quoter->RiseOnRspUserLogin(pRspUserLogin, pRspInfo, nRequestID, bIsLast);
		}

		virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			clr_quoter->RiseOnRspUserLogout(pUserLogout, pRspInfo, nRequestID, bIsLast);
		}


		//订阅行情应答，调用SubscribeMarketData后，通过此接口返回。
		virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)override
		{
			clr_quoter->RiseOnRspSubMarketData(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
		}
		//取消订阅行情应答，当UnSubscribeMarketData后，调用此接口。
		virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)override
		{
			clr_quoter->RiseOnRspUnSubMarketData(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
		};
		//订阅询价应答，当调用SubscribeForQuoteRsp后，通过此接口返回。
		virtual void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)override
		{
			clr_quoter->RiseOnRspSubForQuoteRsp(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
		};
		virtual void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)override
		{
			clr_quoter->RiseOnRspUnSubForQuoteRsp(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
		};
		//询价通知，使用SubscribeForQuoteRsp订阅该询价通知。私有流回报。
		virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) override
		{
			clr_quoter->RiseOnRtnForQuoteRsp(pForQuoteRsp);
		};
		//深度行情通知，当SubscribeMarketData订阅行情后，行情通知由此推送。
		virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData) override
		{
			clr_quoter->RiseOnRtnDepthMarketData(pDepthMarketData);
		}
	};





	Quoter::~Quoter()
	{
		this->!Quoter();
	}

	Quoter::!Quoter()
	{
		if (native != nullptr)
		{
			native->Release();
			native = nullptr;
		}

		if (quoter_spi != nullptr)
		{
			delete quoter_spi;
			quoter_spi = nullptr;
		}
	}

	Quoter::Quoter()
	{
		native = CThostFtdcMdApi::CreateFtdcMdApi();
		quoter_spi = new ResQuoterSpi(this);
		native->RegisterSpi(quoter_spi);
	}
	void Quoter::Init()
	{
		native->Init();
	}

	Int32 Quoter::Join()
	{
		return native->Join();
	}

	void Quoter::Release()
	{
		native->Release();
		native = nullptr;
	}

	String^ Quoter::GetTradingDay()
	{
		return "";
	}

	void Quoter::RegisterFront(String^ pszFrontAddress)
	{
		auto ansi_front_address = ToNativeU8(pszFrontAddress);
		native->RegisterFront(const_cast<char*>(ansi_front_address.c_str()));
		return;
	}
	int Quoter::ReqUserLogin(UserLoginRequestData^ pReqUserLoginField, int nRequestID)
	{
		return  native->ReqUserLogin(&pReqUserLoginField->ToNative(), nRequestID);
	}
	int Quoter::ReqUserLogout(UserLogoutRequestData^ pUserLogout, int nRequestID)
	{
		return  native->ReqUserLogout(&pUserLogout->ToNative(), nRequestID);
	}
	int Quoter::SubscribeMarketData(List<String^>^ list_str, int nCount)
	{
		int result = -2;
		if (list_str->Count>0 && list_str->Count <= 50)
		{
			char **ppInstrumentID = new char*[50];
			char a[50][10];
		    for each (String^ str in list_str)
			{
				int index = list_str->IndexOf(str);
				std::string native_s = ToNativeString(str);
				strncpy_s(a[index], native_s.c_str(), strlen(native_s.c_str()));
				ppInstrumentID[index] = a[index];
			}
			native->SubscribeMarketData(ppInstrumentID, nCount);
			delete[] ppInstrumentID;
			ppInstrumentID = nullptr;
		}
		/*char **ppInstrumentID1 = new char*[50];
		ppInstrumentID1[0] = "ag1901";
		ppInstrumentID1[1] = "ag1812";
		native->SubscribeMarketData(ppInstrumentID1,2);*/
		return result;
	}

	int Quoter::UnSubscribeMarketData(List<String^>^ list_str, int nCount)
	{
		int result = -2;
		if (list_str->Count>0 && list_str->Count <= 50)
		{
			char **ppInstrumentID = new char*[50];
			char a[50][10];
			for each (String^ str in list_str)
			{
				int index = list_str->IndexOf(str);
				std::string native_s = ToNativeString(str);
				strncpy_s(a[index], native_s.c_str(), strlen(native_s.c_str()));
				ppInstrumentID[index] = a[index];
			}
			result = native->UnSubscribeMarketData(ppInstrumentID, nCount);
			delete[] ppInstrumentID;
			ppInstrumentID = nullptr;
		}
		return result;
	}
	int Quoter::SubscribeForQuoteRsp(List<String^>^ list_str, int nCount)
	{
		int result = -2;
		if (list_str->Count>0 && list_str->Count <= 50)
		{
			char **ppInstrumentID = new char*[50];
			char a[50][10];
			for each (String^ str in list_str)
			{
				int index = list_str->IndexOf(str);
				std::string native_s = ToNativeString(str);
				strncpy_s(a[index], native_s.c_str(), strlen(native_s.c_str()));
				ppInstrumentID[index] = a[index];
			}
			result = native->SubscribeForQuoteRsp(ppInstrumentID, nCount);
			delete[] ppInstrumentID;
			ppInstrumentID = nullptr;
		}
		return result;
	}
	int Quoter::UnSubscribeForQuoteRsp(List<String^>^ list_str, int nCount)
	{
		int result = -2;
		if (list_str->Count>0 && list_str->Count <= 50)
		{
			char **ppInstrumentID = new char*[50];
			char a[50][10];
			for each (String^ str in list_str)
			{
				int index = list_str->IndexOf(str);
				std::string native_s = ToNativeString(str);
				strncpy_s(a[index], native_s.c_str(), strlen(native_s.c_str()));
				ppInstrumentID[index] = a[index];
			}
			result = native->UnSubscribeForQuoteRsp(ppInstrumentID, nCount);
			delete[] ppInstrumentID;
			ppInstrumentID = nullptr;
		}
		return result;
	}


	
	 void Quoter::RiseOnFrontConnected() 
	 {
		 OnFrontConnected();
	 };
	 void Quoter::RiseOnFrontDisconnected(int nReason) 
	 {
		 OnFrontDisconnected(nReason);
	 };
	 void Quoter::RiseOnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	 {
		 auto response_data = UserLoginResponseData::FromNative(pRspUserLogin);
		 auto response_info = ResponseInformation::FromNative(pRspInfo);
		 UserLoginResponse(response_data, response_info, nRequestID, bIsLast);
	 };
	 void Quoter::RiseOnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	 {
		 auto response_data = UserLogoutResponseData::FromNative(pUserLogout);
		 auto response_info = ResponseInformation::FromNative(pRspInfo);
		 UserLogoutResponse(response_data, response_info, nRequestID, bIsLast);
	 };
	 void Quoter::RiseOnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	 {
		 auto response_info = ResponseInformation::FromNative(pRspInfo);
		 OnRspError(response_info, nRequestID, bIsLast);
	 };
	 void Quoter::RiseOnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	 {
		 auto response_data = RspSubMarketResponseData::FromNative(pSpecificInstrument);
		 auto response_info = ResponseInformation::FromNative(pRspInfo);
		 OnRspSubMarketData(response_data, response_info, nRequestID, bIsLast);
	 };
	 void Quoter::RiseOnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	 {
		 auto response_data = RspSubMarketResponseData::FromNative(pSpecificInstrument);
		 auto response_info = ResponseInformation::FromNative(pRspInfo);
		 OnRspUnSubMarketData(response_data, response_info, nRequestID, bIsLast);
	 };
	 void Quoter::RiseOnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	 {
		 auto response_data = RspSubMarketResponseData::FromNative(pSpecificInstrument);
		 auto response_info = ResponseInformation::FromNative(pRspInfo);
		 OnRspSubForQuoteRsp(response_data, response_info, nRequestID, bIsLast);
	 };
	 void Quoter::RiseOnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
	 {
		 auto response_data = RspSubMarketResponseData::FromNative(pSpecificInstrument);
		 auto response_info = ResponseInformation::FromNative(pRspInfo);
		 OnRspSubMarketData(response_data, response_info, nRequestID, bIsLast);
	 };
	 void Quoter::RiseOnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
	 {
		 auto response_data = RtnDepthMarketResponseData::FromNative(pDepthMarketData);
		 OnRtnDepthMarketData(response_data);
	 };
	 void Quoter::RiseOnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp)
	 {
		 auto response_data = OnRtnForQuoteResponseData::FromNative(pForQuoteRsp);
		 OnRtnForQuoteRsp(response_data);
	 };

}