
#pragma once
#include "TraderDataTypes.h"
using namespace System::Text;
/*
	//盘中 180.168.146.187:10001
	//盘后 180.168.146.187:10030
*/

class CThostFtdcTraderApi;
class CThostFtdcTraderSpi;

namespace Ctp::Core
{
	public ref class Trader
	{
	public:
		Trader();
		!Trader();
		~Trader();

		void Init();

		void Release();

		Int32 Join();

		String^ GetApiVersion();

		void RegisterFront(String^ front_address);
		void RegisterNameServer(String^ name_server_address);

		void RegisterFensUserInfo(FensUserInfo^ fens_user_info);

		void SubscribePrivateTopic(SubscriptionMode mode);

		void SubscribePublicTopic(SubscriptionMode mode);

		Int32 RequestAuthenticate(AuthenticateRequestData^ auth_req_data, Int32 request_id);
		Int32 RequestLogin(UserLoginRequestData^ login_req_data, Int32 request_id);
		Int32 RequserLogout(UserLogoutRequestData^ login_req_data, Int32 request_id);
		Int32 ReqQryOrder(QryOrderRequestData^ pQryOrder, int nRequestID);
		Int32 ReqQryTradingAccount(QryAccountRequestData^ pQryTradingAccount, Int32 request_id);
		Int32 ReqOrderInsert(OrderInsertRequestData^ pInputOrder, int nRequestID);
		Int32 ReqQryInvestorPosition(InvestorPositionRequestData^ pQryInvestorPositionDetail, int nRequestID);
		Int32 ReqOrderAction(OrderActionRequestData^ pInputOrderAction, int nRequestID);

		Int32 ReqQryTransferSerial(QryTransferSerialRequestData^pQryTransferSerial, int nRequestID);
		Int32 ReqAccountregister(AccountregisterRequestData ^pQryAccountregister, int nRequestID);
		Int32 ReqContractBank(ContractBankRequestData^pQryContractBank, int nRequestID);
		Int32 ReqFromBankToFutureByFuture(FromBankToFutureByFutureRequestData^pQryFromBankToFutureByFuture, int nRequestID);
		Int32 ReqFromFutureToBankByFuture(FromFutureToBankByFutureRequestData^pQryFromFutureToBankByFuture, int nRequestID);
		Int32 ReqTradingAccountPasswordUpdate(TradingAccountPasswordUpdateRequestData^pQryTradingAccountPasswordUpdate, int nRequestID);
		Int32 ReqQueryBankAccountMoneyByFuture(QueryBankAccountMoneyByFutureRequestData^pQryQueryBankAccountMoneyByFuture, int nRequestID);

		Int32 ReqUserPasswordUpdate(UserPasswordUpdateRequestData ^pUserPasswordUpdate, int nRequestID);
		Int32 ReqQueryMaxOrderVolume(QueryMaxOrderVolumeRequestData ^pQueryMaxOrderVolume, int nRequestID);
		Int32 ReqQryTrade(TradeRequestData ^pQryTrade, int nRequestID);
		Int32 ReqQryInvestorPositionDetail(InvestorPositionDetailRequestData ^pQryInvestorPositionDetail, int nRequestID);
		Int32 ReqQryInvestor(InvestorRequestData ^pQryInvestor, int nRequestID);
		Int32 ReqQryTradingCode(TradingCodeRequestData ^pQryTradingCode, int nRequestID);
		Int32 ReqQryInstrumentMarginRate(InstrumentMarginRateRequestData ^pQryInstrumentMarginRate, int nRequestID);
		Int32 ReqQryInstrumentCommissionRate(InstrumentCommissionRateRequestData ^pQryInstrumentCommissionRate, int nRequestID);
		Int32 ReqQryInstrument(InstrumentRequestData ^pQryInstrument, int nRequestID);
		Int32 ReqQryQrySettlementInfo(QrySettlementInfoRequestData ^pQryQrySettlementInfo, int nRequestID);
		Int32 ReqQryQrySettlementInfoConfirm(QrySettlementInfoConfirmRequestData ^pQryQrySettlementInfoConfirm, int nRequestID);
		Int32 ReqSettlementInfoConfirm(SettlementInfoConfirmRequestData ^pSettlementInfoConfirm, int nRequestID);
		Int32 ReqQryNotice(NoticeRequestData ^pQryNotice, int nRequestID);
		Int32 ReqQryTradingNotice(TradingNoticeRequestData ^pQryTradingNotice, int nRequestID);

	public: // events
		delegate void FrontConnectedEventHandler();
		event FrontConnectedEventHandler^ FrontConnected;
		ref class FrontDisconnectedEventArgs
		{
		public:
			Int32 ReasonCode;
		};
		delegate void FrontDisconnectedEventHandler(FrontDisconnectedEventArgs^ e);
		event FrontDisconnectedEventHandler^ FrontDisconnected;

		ref class HeartBeatWarningEventArgs
		{
		public:
			Int32 TimeElapsed;
		};
		delegate void HeartBeatWarningEventHandler(HeartBeatWarningEventArgs^ e);
		event HeartBeatWarningEventHandler^ HeartBeatWarning;

		ref class AuthenticateResponseEventArgs
		{
		public:
			Int32 RequestID;
			bool IsLast;
			AuthenticateResponseData^ AuthResponseData;
			ResponseInformation^ ResponseInfo;
		};
		delegate void AuthenticateResponseEventHandler(AuthenticateResponseEventArgs^ e);
		event AuthenticateResponseEventHandler^ AuthenticateResponse;

		ref class UserLoginResponseEventArgs
		{
		public:
			Int32 RequestID;
			bool IsLast;
			UserLoginResponseData^ LoginResonseData;
			ResponseInformation^ ResponseInfo;
		};
		delegate void UserLoginResponseEventHandler(UserLoginResponseEventArgs^ e);
		event UserLoginResponseEventHandler^ UserLoginResponse;

		ref class UserLogoutResponseEventArgs
		{
		public:
			Int32 RequestID;
			bool IsLast;
			UserLogoutResponseData^ LogoutResonseData;
			ResponseInformation^ ResponseInfo;
		};
		delegate void UserLogoutResponseEventHandler(UserLogoutResponseEventArgs^ e);
		event UserLogoutResponseEventHandler^ UserLogoutResponse;

		ref class RspQryOrderEventArgs
		{
		public:
			Int32 RequestID;
			bool IsLast;
			RtnOrderResponseData^ QryOrderResData;
			ResponseInformation^ ResponseInfo;
		};
		delegate void ResQryOrderEventHandler(RspQryOrderEventArgs^ e);
		event ResQryOrderEventHandler^ OnRspQryOrder;

		ref class QryAccountResEventArgs
		{
		public:
			Int32 RequestID;
			bool IsLast;

			QryAccountResponseData^ QryAccountResData;
			ResponseInformation^ ResponseInfo;
		};
		delegate void QryAccountResEventHandler(QryAccountResEventArgs^ e);
		event QryAccountResEventHandler^ OnRspQryTradingAccount;

		ref class OrderInsertResEventArgs
		{
		public:
			Int32 RequestID;
			bool IsLast;

			OrderInsertResponseData^ OrderInsertResData;
			ResponseInformation^ ResponseInfo;
		};
		delegate void OrderInsertResEventHandler(OrderInsertResEventArgs^ e);
		event OrderInsertResEventHandler^ OnRspOrderInsert;

		ref class ErrRtnOrderInsertResEventArgs
		{
		public:
			OrderInsertResponseData ^ OrderInsertResData;
			ResponseInformation^ ResponseInfo;
		};
		delegate void ErrRtnOrderInsertResEventHandler(ErrRtnOrderInsertResEventArgs^ e);
		event ErrRtnOrderInsertResEventHandler^ OnErrRtnOrderInsert;

		ref class RspOnRtnOrderEventArgs
		{
		public:
			RtnOrderResponseData ^ RtnOrderResData;
		};
		delegate void OnRtnOrderEventHandler(RspOnRtnOrderEventArgs^ e);
		event OnRtnOrderEventHandler^ OnRtnOrder;

		ref class RspOnRtnTradeEventArgs
		{
		public:
			RtnTradeResponseData ^ RtnTradeResData;
		};
		delegate void OnRtnTradeEventHandler(RspOnRtnTradeEventArgs^ e);
		event OnRtnTradeEventHandler^ OnRtnTrade;

		delegate void OnInvestorPositionEventHandler(InvestorPositionResponseData^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnInvestorPositionEventHandler^ OnRspQryInvestorPosition;

		delegate void OnOrderActionEventHandler(OrderActionResponseData^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnOrderActionEventHandler^ OnRspOrderAction;

		delegate void OnQryTransferSerialEventHandler(QryTransferSerialResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnQryTransferSerialEventHandler^ OnRspQryTransferSerial;

		delegate void OnQryAccountregisterEventHandler(AccountregisterResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnQryAccountregisterEventHandler^ OnRspQryAccountregister;

		delegate void OnQryContractBankEventHandler(ContractBankResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnQryContractBankEventHandler^ OnRspQryContractBank;

		delegate void OnQryFromBankToFutureByFutureEventHandler(FromBankToFutureByFutureResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnQryFromBankToFutureByFutureEventHandler^ OnRspQryFromBankToFutureByFuture;

		delegate void OnRtnFromBankToFutureByFutureEventHandler(RtnFromBankToFutureByFutureResponseData ^ ResponseData);
		event OnRtnFromBankToFutureByFutureEventHandler^ OnRtnFromBankToFutureByFuture;


		delegate void OnQryFromFutureToBankByFutureEventHandler(FromFutureToBankByFutureResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnQryFromFutureToBankByFutureEventHandler^ OnRspQryFromFutureToBankByFuture;

		delegate void OnRtnFromFutureToBankByFutureEventHandler(OnRtnFromFutureToBankByFutureResponseData ^ ResponseData);
		event OnRtnFromFutureToBankByFutureEventHandler^ OnRtnFromFutureToBankByFuture;

		delegate void OnQryTradingAccountPasswordUpdateEventHandler(TradingAccountPasswordUpdateResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnQryTradingAccountPasswordUpdateEventHandler^ OnRspQryTradingAccountPasswordUpdate;

		delegate void OnQryQueryBankAccountMoneyByFutureEventHandler(QueryBankAccountMoneyByFutureResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnQryQueryBankAccountMoneyByFutureEventHandler^ OnRspQryQueryBankAccountMoneyByFuture;

		delegate void RtnQueryBankBalanceByFutureEventHandler(RtnNotifyQueryAccountFieldResponseData ^ ResponseData);
		event RtnQueryBankBalanceByFutureEventHandler^ OnRtnNotifyQueryAccountField;


		delegate void OnUserPasswordUpdateEventHandler(UserPasswordUpdateResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnUserPasswordUpdateEventHandler^ OnRspUserPasswordUpdate;

		delegate void OnQueryMaxOrderVolumeEventHandler(QueryMaxOrderVolumeResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnQueryMaxOrderVolumeEventHandler^ OnRspQueryMaxOrderVolume;

		delegate void OnTradeEventHandler(TradeResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnTradeEventHandler^ OnRspQryTrade;

		delegate void OnInvestorPositionDetailEventHandler(InvestorPositionDetailResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnInvestorPositionDetailEventHandler^ OnRspQryInvestorPositionDetail;

		delegate void OnInvestorEventHandler(InvestorResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnInvestorEventHandler^ OnRspQryInvestor;
	
		delegate void OnTradingCodeEventHandler(TradingCodeResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnTradingCodeEventHandler^ OnRspQryTradingCode;

		delegate void OnInstrumentMarginRateEventHandler(InstrumentMarginRateResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnInstrumentMarginRateEventHandler^ OnRspQryInstrumentMarginRate;
		                                     
		delegate void OnInstrumentCommissionRateEventHandler(InstrumentCommissionRateResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnInstrumentCommissionRateEventHandler^ OnRspQryInstrumentCommissionRate;

		delegate void OnInstrumentEventHandler(InstrumentResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnInstrumentEventHandler^ OnRspQryInstrument;

		delegate void OnQrySettlementInfoEventHandler(QrySettlementInfoResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnQrySettlementInfoEventHandler^ OnRspQrySettlementInfo;

		delegate void OnQrySettlementInfoConfirmEventHandler(QrySettlementInfoConfirmResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnQrySettlementInfoConfirmEventHandler^ OnRspQrySettlementInfoConfirm;

		delegate void OnSettlementInfoConfirmEventHandler(SettlementInfoConfirmResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnSettlementInfoConfirmEventHandler^ OnRspSettlementInfoConfirm;

		delegate void OnNoticeEventHandler(NoticeResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnNoticeEventHandler^ OnRspQryNotice;

		delegate void OnTradingNoticeEventHandler(TradingNoticeResponseData ^ ResponseData,
			ResponseInformation^ ResponseInfo, Int32 RequestID, bool IsLast);
		event OnTradingNoticeEventHandler^ OnRspQryTradingNotice;


	internal: // event raisers
		void RaiseFrontConnected();
		void RaiseFrontDisconnected(Int32 reason_code);
		void RaiseHeartBeatWarning(Int32 time_elapsed);
		void RaiseAuthenticateResponse(CThostFtdcRspAuthenticateField* pRspAuthenticateField,
			CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);
		void RaiseUserLoginResponse(CThostFtdcRspUserLoginField* pRspUserLogin,
			CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);
		void RaiseUserLogoutResponse(CThostFtdcUserLogoutField *pUserLogout,
			CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseOnRspQryOrder(CThostFtdcOrderField  *pOrder,
			CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount,
			CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


		void RaiseOnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseOnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo);
		void RaiseOnRtnOrder(CThostFtdcOrderField *pOrder);
		void RaiseOnRtnTrade(CThostFtdcTradeField *pTrade);
		void RaiseQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		void RaiseQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		void RaiseQryAccountregister(CThostFtdcAccountregisterField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseQryContractBank(CThostFtdcContractBankField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseQryFromBankToFutureByFuture(CThostFtdcReqTransferField  *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer);

		void RaiseQryFromFutureToBankByFuture(CThostFtdcReqTransferField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseOnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer);
		void RaiseQryTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseQryQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount);

		void RaiseOnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseOnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseOnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseOnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseOnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseOnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseOnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseOnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseOnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseOnRspQrySettlementInfo(CThostFtdcSettlementInfoField  *pQrySettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseOnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField  *pQrySettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseOnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField  *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseOnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void RaiseOnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	private:;
			CThostFtdcTraderSpi * trader_spi = nullptr;
			CThostFtdcTraderApi* native = nullptr;
	};
}


