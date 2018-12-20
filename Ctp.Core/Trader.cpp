
#include "stdafx.h"
#include "Trader.h"

namespace Ctp::Core
{
	public class ResTraderSpi : public CThostFtdcTraderSpi
	{
	public:
		ResTraderSpi(Trader^ clr_trader)
			:_clr_trader(clr_trader)
		{

		}

		msclr::gcroot<Trader^> _clr_trader;

		virtual void OnFrontConnected() override
		{
			_clr_trader->RaiseFrontConnected();
		};

		virtual void OnFrontDisconnected(int reason_code) override
		{
			_clr_trader->RaiseFrontDisconnected(reason_code);
		}

		virtual void OnHeartBeatWarning(int time_elapsed) override
		{
			_clr_trader->RaiseHeartBeatWarning(time_elapsed);
		}

		virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			_clr_trader->RaiseAuthenticateResponse(pRspAuthenticateField, pRspInfo, nRequestID, bIsLast);
		}

		virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			_clr_trader->RaiseUserLoginResponse(pRspUserLogin, pRspInfo, nRequestID, bIsLast);
		}

		virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			_clr_trader->RaiseUserLogoutResponse(pUserLogout, pRspInfo, nRequestID, bIsLast);
		}
		//查询报单
		virtual void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)override
		{
			_clr_trader->RaiseOnRspQryOrder(pOrder, pRspInfo, nRequestID, bIsLast);
		}
		//查询资金账户
		virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)override
		{
			_clr_trader->RaiseRspQryTradingAccount(pTradingAccount, pRspInfo, nRequestID, bIsLast);
		}

		//**报单录入**
		virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			_clr_trader->RaiseOnRspOrderInsert(pInputOrder, pRspInfo, nRequestID, bIsLast);
		};
		virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) override
		{
			_clr_trader->RaiseOnErrRtnOrderInsert(pInputOrder, pRspInfo);
		};
		virtual void OnRtnOrder(CThostFtdcOrderField *pOrder) override
		{
			_clr_trader->RaiseOnRtnOrder(pOrder);
		};
		virtual void OnRtnTrade(CThostFtdcTradeField *pTrade) override
		{
			_clr_trader->RaiseOnRtnTrade(pTrade);
		};
		//**报单录入**

		virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)override
		{
			_clr_trader->RaiseQryInvestorPosition(pInvestorPosition, pRspInfo, nRequestID, bIsLast);
		};

		virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)override
		{
			_clr_trader->RaiseRspOrderAction(pInputOrderAction, pRspInfo, nRequestID, bIsLast);
		};

		virtual void OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)override
		{
			_clr_trader->RaiseQryTransferSerial(pTransferSerial, pRspInfo, nRequestID, bIsLast);
		}

		virtual void  OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)override
		{
			_clr_trader->RaiseQryAccountregister(pAccountregister, pRspInfo, nRequestID, bIsLast);
		}

		virtual void OnRspQryContractBank(CThostFtdcContractBankField   *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)override
		{
			_clr_trader->RaiseQryContractBank(pContractBank, pRspInfo, nRequestID, bIsLast);
		}

		virtual void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField  *pFromBankToFutureByFuture, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)override
		{
			_clr_trader->RaiseQryFromBankToFutureByFuture(pFromBankToFutureByFuture, pRspInfo, nRequestID, bIsLast);
		}

		virtual void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer)override
		{
			_clr_trader->RaiseRtnFromBankToFutureByFuture(pRspTransfer);
		}

		virtual void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer)override
		{
			_clr_trader->RaiseOnRtnFromFutureToBankByFuture(pRspTransfer);
		}

		virtual void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pFromFutureToBankByFuture, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)override
		{
			_clr_trader->RaiseQryFromFutureToBankByFuture(pFromFutureToBankByFuture, pRspInfo, nRequestID, bIsLast);
		}

		virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)override
		{
			_clr_trader->RaiseQryTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate, pRspInfo, nRequestID, bIsLast);
		}

		virtual void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pQueryBankAccountMoneyByFuture, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)override
		{
			_clr_trader->RaiseQryQueryBankAccountMoneyByFuture(pQueryBankAccountMoneyByFuture, pRspInfo, nRequestID, bIsLast);
		}

		virtual void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount) override
		{
			_clr_trader->RaiseRtnQueryBankBalanceByFuture(pNotifyQueryAccount);
		}





		virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			_clr_trader->RaiseOnRspUserPasswordUpdate(pUserPasswordUpdate, pRspInfo, nRequestID, bIsLast);
		}
		virtual void OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			_clr_trader->RaiseOnRspQueryMaxOrderVolume(pQueryMaxOrderVolume, pRspInfo, nRequestID, bIsLast);
		}
		virtual void OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			_clr_trader->RaiseOnRspQryTrade(pTrade, pRspInfo, nRequestID, bIsLast);
		}
		virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			_clr_trader->RaiseOnRspQryInvestorPositionDetail(pInvestorPositionDetail, pRspInfo, nRequestID, bIsLast);
		}
		virtual void OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			_clr_trader->RaiseOnRspQryInvestor(pInvestor, pRspInfo, nRequestID, bIsLast);
		}
		virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			_clr_trader->RaiseOnRspQryTradingCode(pTradingCode, pRspInfo, nRequestID, bIsLast);
		}
		virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			_clr_trader->RaiseOnRspQryInstrumentMarginRate(pInstrumentMarginRate, pRspInfo, nRequestID, bIsLast);
		}
		virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			_clr_trader->RaiseOnRspQryInstrumentCommissionRate(pInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast);
		}
		virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			_clr_trader->RaiseOnRspQryInstrument(pInstrument, pRspInfo, nRequestID, bIsLast);
		}
		virtual void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)  override
		{
			_clr_trader->RaiseOnRspQrySettlementInfo(pSettlementInfo, pRspInfo, nRequestID, bIsLast);
		}
		virtual void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pQrySettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			_clr_trader->RaiseOnRspQrySettlementInfoConfirm(pQrySettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
		}
		virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			_clr_trader->RaiseOnRspSettlementInfoConfirm(pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
		}
		virtual void OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			_clr_trader->RaiseOnRspQryNotice(pNotice, pRspInfo, nRequestID, bIsLast);
		}
		virtual void OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			_clr_trader->RaiseOnRspQryTradingNotice(pTradingNotice, pRspInfo, nRequestID, bIsLast);
		}
	};

	Trader::~Trader()
	{
		this->!Trader();
	}

	Trader::!Trader()
	{
		if (native != nullptr)
		{
			native->Release();
			native = nullptr;
		}

		if (trader_spi != nullptr)
		{
			delete trader_spi;
			trader_spi = nullptr;
		}
	}

	Trader::Trader()
	{
		native = CThostFtdcTraderApi::CreateFtdcTraderApi();
		trader_spi = new ResTraderSpi(this);
		native->RegisterSpi(trader_spi);
	}

	void Trader::Init()
	{
		native->Init();
	}

	Int32 Trader::Join()
	{
		return native->Join();
	}

	String^ Trader::GetApiVersion()
	{
		return U8ToClr(native->GetApiVersion());
	}

	void Trader::RegisterFront(String^ front_address)
	{
		auto ansi_front_address = ToNativeU8(front_address);
		native->RegisterFront(const_cast<char*>(ansi_front_address.c_str()));
		return;
	}

	void Trader::RegisterNameServer(String^ name_server_address)
	{
		auto ansi_name_server_address = ToNativeU8(name_server_address);
		native->RegisterNameServer(const_cast<char*>(ansi_name_server_address.c_str()));
		return;
	}

	void Trader::RegisterFensUserInfo(FensUserInfo^ fens_user_info)
	{
		native->RegisterFensUserInfo(&fens_user_info->ToNative());
	}

	void Trader::SubscribePrivateTopic(SubscriptionMode mode)
	{
		native->SubscribePrivateTopic(static_cast<THOST_TE_RESUME_TYPE>(mode));
	}

	void Trader::SubscribePublicTopic(SubscriptionMode mode)
	{
		native->SubscribePublicTopic(static_cast<THOST_TE_RESUME_TYPE>(mode));
	}

	Int32 Trader::RequestAuthenticate(AuthenticateRequestData^ auth_req_data, Int32 request_id)
	{
		return native->ReqAuthenticate(&auth_req_data->ToNative(), request_id);
	}

	Int32 Trader::RequestLogin(UserLoginRequestData^ login_req_data, Int32 request_id)
	{
		return native->ReqUserLogin(&login_req_data->ToNative(), request_id);
	}
	Int32 Trader::RequserLogout(UserLogoutRequestData^ logout_req_data, Int32 request_id)
	{
		return  native->ReqUserLogout(&logout_req_data->ToNative(), request_id);
	}
	Int32 Trader::ReqQryOrder(QryOrderRequestData^ pQryOrder, int nRequestID)
	{
		return  native->ReqQryOrder(&pQryOrder->ToNative(), nRequestID);
	}
	//查询资金账户
	Int32 Trader::ReqQryTradingAccount(QryAccountRequestData^ req_data, Int32 request_id)
	{
		return  native->ReqQryTradingAccount(&req_data->ToNative(), request_id);
	}
	//报单录入请求
	Int32 Trader::ReqOrderInsert(OrderInsertRequestData^ pInputOrder, int nRequestID)
	{
		return  native->ReqOrderInsert(&pInputOrder->ToNative(), nRequestID);
	}
	Int32 Trader::ReqQryInvestorPosition(InvestorPositionRequestData^ pQryInvestorPositionDetail, int nRequestID)
	{
		return  native->ReqQryInvestorPosition(&pQryInvestorPositionDetail->ToNative(), nRequestID);
	}
	Int32 Trader::ReqOrderAction(OrderActionRequestData^ pInputOrderAction, int nRequestID)
	{
		return  native->ReqOrderAction(&pInputOrderAction->ToNative(), nRequestID);
	}
	Int32 Trader::ReqQryTransferSerial(QryTransferSerialRequestData^ pQryTransferSerial, int nRequestID)
	{
		return  native->ReqQryTransferSerial(&pQryTransferSerial->ToNative(), nRequestID);
	}

	Int32 Trader::ReqAccountregister(AccountregisterRequestData^ pQryAccountregister, int nRequestID)
	{
		return  native->ReqQryAccountregister(&pQryAccountregister->ToNative(), nRequestID);
	}
	Int32 Trader::ReqContractBank(ContractBankRequestData^ pQryContractBank, int nRequestID)
	{
		return  native->ReqQryContractBank(&pQryContractBank->ToNative(), nRequestID);
	}
	Int32 Trader::ReqFromBankToFutureByFuture(FromBankToFutureByFutureRequestData^ pQryFromBankToFutureByFuture, int nRequestID)
	{
		return  native->ReqFromBankToFutureByFuture(&pQryFromBankToFutureByFuture->ToNative(), nRequestID);
	}
	Int32 Trader::ReqFromFutureToBankByFuture(FromFutureToBankByFutureRequestData^ pQryFromFutureToBankByFuture, int nRequestID)
	{
		return  native->ReqFromFutureToBankByFuture(&pQryFromFutureToBankByFuture->ToNative(), nRequestID);
	}
	Int32 Trader::ReqTradingAccountPasswordUpdate(TradingAccountPasswordUpdateRequestData^ pQryTradingAccountPasswordUpdate, int nRequestID)
	{
		return  native->ReqTradingAccountPasswordUpdate(&pQryTradingAccountPasswordUpdate->ToNative(), nRequestID);
	}
	Int32 Trader::ReqQueryBankAccountMoneyByFuture(QueryBankAccountMoneyByFutureRequestData^ pQryQueryBankAccountMoneyByFuture, int nRequestID)
	{
		return  native->ReqQueryBankAccountMoneyByFuture(&pQryQueryBankAccountMoneyByFuture->ToNative(), nRequestID);
	}


	Int32 Trader::ReqUserPasswordUpdate(UserPasswordUpdateRequestData ^pUserPasswordUpdate, int nRequestID)
	{
		return  native->ReqUserPasswordUpdate(&pUserPasswordUpdate->ToNative(), nRequestID);
	}
	Int32 Trader::ReqQueryMaxOrderVolume(QueryMaxOrderVolumeRequestData ^pQueryMaxOrderVolume, int nRequestID)
	{
		return  native->ReqQueryMaxOrderVolume(&pQueryMaxOrderVolume->ToNative(), nRequestID);
	}
	Int32 Trader::ReqQryTrade(TradeRequestData ^pQryTrade, int nRequestID)
	{
		return  native->ReqQryTrade(&pQryTrade->ToNative(), nRequestID);
	}
	Int32 Trader::ReqQryInvestorPositionDetail(InvestorPositionDetailRequestData ^pQryInvestorPositionDetail, int nRequestID)
	{
		return  native->ReqQryInvestorPositionDetail(&pQryInvestorPositionDetail->ToNative(), nRequestID);
	}
	Int32 Trader::ReqQryInvestor(InvestorRequestData ^pQryInvestor, int nRequestID)
	{
		return  native->ReqQryInvestor(&pQryInvestor->ToNative(), nRequestID);
	}
	Int32 Trader::ReqQryTradingCode(TradingCodeRequestData ^pQryTradingCode, int nRequestID)
	{
		return  native->ReqQryTradingCode(&pQryTradingCode->ToNative(), nRequestID);
	}
	Int32 Trader::ReqQryInstrumentMarginRate(InstrumentMarginRateRequestData ^pQryInstrumentMarginRate, int nRequestID)
	{
		return  native->ReqQryInstrumentMarginRate(&pQryInstrumentMarginRate->ToNative(), nRequestID);
	}
	Int32 Trader::ReqQryInstrumentCommissionRate(InstrumentCommissionRateRequestData ^pQryInstrumentCommissionRate, int nRequestID)
	{
		return  native->ReqQryInstrumentCommissionRate(&pQryInstrumentCommissionRate->ToNative(), nRequestID);
	}
	Int32 Trader::ReqQryInstrument(InstrumentRequestData ^pQryInstrument, int nRequestID)
	{
		return  native->ReqQryInstrument(&pQryInstrument->ToNative(), nRequestID);
	}
	Int32 Trader::ReqQryQrySettlementInfo(QrySettlementInfoRequestData ^pQryQrySettlementInfo, int nRequestID)
	{
		return  native->ReqQrySettlementInfo(&pQryQrySettlementInfo->ToNative(), nRequestID);
	}
	Int32 Trader::ReqQryQrySettlementInfoConfirm(QrySettlementInfoConfirmRequestData ^pQryQrySettlementInfoConfirm, int nRequestID)
	{
		return  native->ReqQrySettlementInfoConfirm(&pQryQrySettlementInfoConfirm->ToNative(), nRequestID);
	}
	Int32 Trader::ReqSettlementInfoConfirm(SettlementInfoConfirmRequestData ^pSettlementInfoConfirm, int nRequestID)
	{
		return  native->ReqSettlementInfoConfirm(&pSettlementInfoConfirm->ToNative(), nRequestID);
	}
	Int32 Trader::ReqQryNotice(NoticeRequestData ^pQryNotice, int nRequestID)
	{
		return  native->ReqQryNotice(&pQryNotice->ToNative(), nRequestID);
	}
	Int32 Trader::ReqQryTradingNotice(TradingNoticeRequestData ^pQryTradingNotice, int nRequestID)
	{
		return  native->ReqQryTradingNotice(&pQryTradingNotice->ToNative(), nRequestID);
	}

	void Trader::Release()
	{
		native->Release();
		native = nullptr;
	}


	void Trader::RaiseUserLoginResponse(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		auto e = gcnew UserLoginResponseEventArgs;
		auto response_data = UserLoginResponseData::FromNative(pRspUserLogin);
		e->LoginResonseData = response_data;
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		e->ResponseInfo = response_info;
		e->IsLast = bIsLast;
		e->RequestID = nRequestID;
		UserLoginResponse(e);

	}

	void Trader::RaiseUserLogoutResponse(CThostFtdcUserLogoutField *pUserLogout,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto e = gcnew UserLogoutResponseEventArgs;
		auto response_data = UserLogoutResponseData::FromNative(pUserLogout);
		e->LogoutResonseData = response_data;
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		e->ResponseInfo = response_info;
		UserLogoutResponse(e);
	}

	void Trader::RaiseOnRspQryOrder(CThostFtdcOrderField *pOrder,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto e = gcnew RspQryOrderEventArgs;
		auto response_data = RtnOrderResponseData::FromNative(pOrder);
		e->QryOrderResData = response_data;
		e->RequestID = nRequestID;
		e->IsLast = bIsLast;
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		e->ResponseInfo = response_info;
		OnRspQryOrder(e);
	}

	void Trader::RaiseRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount,
		CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto e = gcnew QryAccountResEventArgs;
		auto response_data = QryAccountResponseData::FromNative(pTradingAccount);
		e->QryAccountResData = response_data;
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		e->ResponseInfo = response_info;
		OnRspQryTradingAccount(e);
	}

	void Trader::RaiseOnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto e = gcnew OrderInsertResEventArgs;
		auto response_data = OrderInsertResponseData::FromNative(pInputOrder);
		e->OrderInsertResData = response_data;
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		e->ResponseInfo = response_info;
		OnRspOrderInsert(e);
	}

	void Trader::RaiseOnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo)
	{
		auto e = gcnew ErrRtnOrderInsertResEventArgs;
		auto response_data = OrderInsertResponseData::FromNative(pInputOrder);
		e->OrderInsertResData = response_data;
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		e->ResponseInfo = response_info;
		OnErrRtnOrderInsert(e);
	}

	void Trader::RaiseOnRtnOrder(CThostFtdcOrderField *pOrder)
	{
		auto e = gcnew RspOnRtnOrderEventArgs;
		auto response_data = RtnOrderResponseData::FromNative(pOrder);
		e->RtnOrderResData = response_data;
		OnRtnOrder(e);
	}

	void Trader::RaiseOnRtnTrade(CThostFtdcTradeField *pTrade)
	{
		auto e = gcnew RspOnRtnTradeEventArgs;
		auto response_data = RtnTradeResponseData::FromNative(pTrade);
		e->RtnTradeResData = response_data;
		OnRtnTrade(e);
	}
	void Trader::RaiseQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_data = InvestorPositionResponseData::FromNative(pInvestorPosition);
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		OnRspQryInvestorPosition(response_data, response_info, nRequestID, bIsLast);
	}

	void Trader::RaiseRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_data = OrderActionResponseData::FromNative(pInputOrderAction);
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		OnRspOrderAction(response_data, response_info, nRequestID, bIsLast);
	}

	void Trader::RaiseQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = QryTransferSerialResponseData::FromNative(pTransferSerial);

		OnRspQryTransferSerial(response_data, response_info, nRequestID, bIsLast);
	}

	void Trader::RaiseQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = AccountregisterResponseData::FromNative(pAccountregister);
		OnRspQryAccountregister(response_data, response_info, nRequestID, bIsLast);
	}

	void Trader::RaiseQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = ContractBankResponseData::FromNative(pContractBank);
		OnRspQryContractBank(response_data, response_info, nRequestID, bIsLast);
	}

	void Trader::RaiseQryFromBankToFutureByFuture(CThostFtdcReqTransferField    *pFromBankToFutureByFuture, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = FromBankToFutureByFutureResponseData::FromNative(pFromBankToFutureByFuture);
		OnRspQryFromBankToFutureByFuture(response_data, response_info, nRequestID, bIsLast);

	}
	void Trader::RaiseRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer)
	{
		auto response_data = RtnFromBankToFutureByFutureResponseData::FromNative(pRspTransfer);
		OnRtnFromBankToFutureByFuture(response_data);
	}

	void Trader::RaiseQryFromFutureToBankByFuture(CThostFtdcReqTransferField *pFromFutureToBankByFuture, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = FromFutureToBankByFutureResponseData::FromNative(pFromFutureToBankByFuture);
		OnRspQryFromFutureToBankByFuture(response_data, response_info, nRequestID, bIsLast);
	}

	void Trader::RaiseOnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer)
	{
		auto response_data = OnRtnFromFutureToBankByFutureResponseData::FromNative(pRspTransfer);
		OnRtnFromFutureToBankByFuture(response_data);
	}
	void Trader::RaiseQryTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = TradingAccountPasswordUpdateResponseData::FromNative(pTradingAccountPasswordUpdate);
		OnRspQryTradingAccountPasswordUpdate(response_data, response_info, nRequestID, bIsLast);
	}

	void Trader::RaiseQryQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pQueryBankAccountMoneyByFuture, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = QueryBankAccountMoneyByFutureResponseData::FromNative(pQueryBankAccountMoneyByFuture);
		OnRspQryQueryBankAccountMoneyByFuture(response_data, response_info, nRequestID, bIsLast);
	}

	void Trader::RaiseRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount)
	{
		auto response_data = RtnNotifyQueryAccountFieldResponseData::FromNative(pNotifyQueryAccount);
		OnRtnNotifyQueryAccountField(response_data);
	}


	void Trader::RaiseAuthenticateResponse(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		auto e = gcnew AuthenticateResponseEventArgs();
		auto response_data = AuthenticateResponseData::FromNative(pRspAuthenticateField);
		e->AuthResponseData = response_data;
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		e->ResponseInfo = response_info;
		e->IsLast = bIsLast;
		e->RequestID = nRequestID;
		AuthenticateResponse(e);
	}

	void Trader::RaiseHeartBeatWarning(Int32 time_elapsed)
	{
		auto e = gcnew HeartBeatWarningEventArgs();
		e->TimeElapsed = time_elapsed;
		HeartBeatWarning(e);
	}

	void Trader::RaiseFrontDisconnected(Int32 reason_code)
	{
		auto e = gcnew FrontDisconnectedEventArgs();
		e->ReasonCode = reason_code;
		FrontDisconnected(e);
	}

	void Trader::RaiseFrontConnected()
	{
		FrontConnected();
	}


	void Trader::RaiseOnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = UserPasswordUpdateResponseData::FromNative(pUserPasswordUpdate);
		OnRspUserPasswordUpdate(response_data, response_info, nRequestID, bIsLast);
	}
	void Trader::RaiseOnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = QueryMaxOrderVolumeResponseData::FromNative(pQueryMaxOrderVolume);
		OnRspQueryMaxOrderVolume(response_data, response_info, nRequestID, bIsLast);
	}
	void Trader::RaiseOnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = TradeResponseData::FromNative(pTrade);
		OnRspQryTrade(response_data, response_info, nRequestID, bIsLast);
	}
	void Trader::RaiseOnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = InvestorPositionDetailResponseData::FromNative(pInvestorPositionDetail);
		OnRspQryInvestorPositionDetail(response_data, response_info, nRequestID, bIsLast);
	}
	void Trader::RaiseOnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = InvestorResponseData::FromNative(pInvestor);
		OnRspQryInvestor(response_data, response_info, nRequestID, bIsLast);
	}
	void Trader::RaiseOnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = TradingCodeResponseData::FromNative(pTradingCode);
		OnRspQryTradingCode(response_data, response_info, nRequestID, bIsLast);
	}
	void Trader::RaiseOnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = InstrumentMarginRateResponseData::FromNative(pInstrumentMarginRate);
		OnRspQryInstrumentMarginRate(response_data, response_info, nRequestID, bIsLast);
	}
	void Trader::RaiseOnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = InstrumentCommissionRateResponseData::FromNative(pInstrumentCommissionRate);
		OnRspQryInstrumentCommissionRate(response_data, response_info, nRequestID, bIsLast);
	}
	void Trader::RaiseOnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = InstrumentResponseData::FromNative(pInstrument);
		OnRspQryInstrument(response_data, response_info, nRequestID, bIsLast);
	}
	void Trader::RaiseOnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pQrySettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = QrySettlementInfoResponseData::FromNative(pQrySettlementInfo);
		OnRspQrySettlementInfo(response_data, response_info, nRequestID, bIsLast);
	}
	void Trader::RaiseOnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField  *pQrySettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = QrySettlementInfoConfirmResponseData::FromNative(pQrySettlementInfoConfirm);
		OnRspQrySettlementInfoConfirm(response_data, response_info, nRequestID, bIsLast);
	}
	void Trader::RaiseOnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = SettlementInfoConfirmResponseData::FromNative(pSettlementInfoConfirm);
		OnRspSettlementInfoConfirm(response_data, response_info, nRequestID, bIsLast);
	}
	void Trader::RaiseOnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = NoticeResponseData::FromNative(pNotice);
		OnRspQryNotice(response_data, response_info, nRequestID, bIsLast);
	}
	void Trader::RaiseOnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		auto response_info = ResponseInformation::FromNative(pRspInfo);
		auto response_data = TradingNoticeResponseData::FromNative(pTradingNotice);
		OnRspQryTradingNotice(response_data, response_info, nRequestID, bIsLast);
	}
}