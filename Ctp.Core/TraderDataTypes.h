#pragma once
using namespace System::Text;
#include <atlstr.h>
namespace Ctp::Core
{
	template <typename array_type>
	void copy_string_to_array(String^ clr_string, array_type& array_reference)
	{
		if (clr_string == nullptr || clr_string->Length == 0)
		{
			return;
		}
		auto u8_str = ToNativeU8(clr_string);
		std::memcpy(&array_reference, u8_str.c_str(), u8_str.size());
	}
	public enum class LoginMode : char
	{
		Trade = THOST_FTDC_LM_Trade,
		Transfer = THOST_FTDC_LM_Transfer
	};
	public enum class SubscriptionMode
	{
		Restart = THOST_TE_RESUME_TYPE::THOST_TERT_RESTART,
		Resume = THOST_TE_RESUME_TYPE::THOST_TERT_RESUME,
		Quick = THOST_TE_RESUME_TYPE::THOST_TERT_QUICK
	};
	public ref class FensUserInfo
	{
	public:
		property String^ BrokerID;
		String^	UserID;
		LoginMode LoginMode;
	internal:
		CThostFtdcFensUserInfoField ToNative()
		{
			CThostFtdcFensUserInfoField native = { 0 };
			copy_string_to_array(BrokerID, native.BrokerID);
			native.LoginMode = static_cast<char>(LoginMode);
			copy_string_to_array(UserID, native.UserID);
			return native;
		}
	};
	public ref class AuthenticateRequestData
	{
	public:
		CThostFtdcReqAuthenticateField ToNative()
		{
			CThostFtdcReqAuthenticateField native = { 0 };
			copy_string_to_array(BrokerID, native.BrokerID);
			copy_string_to_array(UserID, native.UserID);
			copy_string_to_array(UserProductInfo, native.UserProductInfo);
			copy_string_to_array(AuthCode, native.AuthCode);
			return native;
		}
		String^ BrokerID;
		String^ UserID;
		String^ UserProductInfo;
		String^ AuthCode;
	};
	public ref class UserLoginRequestData
	{
	public:
		CThostFtdcReqUserLoginField ToNative()
		{
			CThostFtdcReqUserLoginField native = { 0 };
			copy_string_to_array(TradingDay, native.TradingDay);
			copy_string_to_array(BrokerID, native.BrokerID);
			copy_string_to_array(UserID, native.UserID);
			copy_string_to_array(Password, native.Password);
			copy_string_to_array(UserProductInfo, native.UserProductInfo);
			copy_string_to_array(InterfaceProductInfo, native.InterfaceProductInfo);
			copy_string_to_array(ProtocolInfo, native.ProtocolInfo);
			copy_string_to_array(MacAddress, native.MacAddress);
			copy_string_to_array(OneTimePassword, native.OneTimePassword);
			copy_string_to_array(ClientIPAddress, native.ClientIPAddress);
			copy_string_to_array(LoginRemark, native.LoginRemark);
			return native;
		}
		String^	TradingDay;
		String^	BrokerID;
		String^	UserID;
		String^	Password;
		String^	UserProductInfo;
		String^	InterfaceProductInfo;
		String^	ProtocolInfo;
		String^	MacAddress;
		String^	OneTimePassword;
		String^	ClientIPAddress;
		String^	LoginRemark;
	};
	public ref class UserLoginResponseData
	{
	public:                                      
		static UserLoginResponseData^ FromNative(CThostFtdcRspUserLoginField* native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rsp = gcnew UserLoginResponseData;
			rsp->TradingDay = U8ToClr(native->TradingDay);
			rsp->LoginTime = U8ToClr(native->LoginTime);
			rsp->BrokerID = U8ToClr(native->BrokerID);
			rsp->UserID = U8ToClr(native->UserID);
			rsp->SystemName = U8ToClr(native->SystemName);
			rsp->FrontID = native->FrontID;
			rsp->SessionID = native->SessionID;
			rsp->MaxOrderRef = U8ToClr(native->MaxOrderRef);
			rsp->SHFETime = U8ToClr(native->SHFETime);
			rsp->DCETime = U8ToClr(native->DCETime);
			rsp->CZCETime = U8ToClr(native->CZCETime);
			rsp->FFEXTime = U8ToClr(native->FFEXTime);
			rsp->INETime = U8ToClr(native->INETime);
			return rsp;
		}
		String^ TradingDay;
		String^ LoginTime;
		String^ BrokerID;
		String^ UserID;
		String^ SystemName;
		Int32	FrontID;
		Int32	SessionID;
		String^ MaxOrderRef;
		String^ SHFETime;
		String^ DCETime;
		String^ CZCETime;
		String^ FFEXTime;
		String^ INETime;
	};
	public ref class UserLogoutRequestData
	{
	public:
		CThostFtdcUserLogoutField ToNative()
		{
			CThostFtdcUserLogoutField native = { 0 };
			copy_string_to_array(BrokerID, native.BrokerID);
			copy_string_to_array(UserID, native.UserID);
			return native;
		}
		String^	BrokerID;
		String^	UserID;
	};
	public ref class UserLogoutResponseData
	{
	public:
		static UserLogoutResponseData^ FromNative(CThostFtdcUserLogoutField* native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew UserLogoutResponseData;
			rspdata->BrokerID = U8ToClr(native->BrokerID);
			rspdata->UserID = U8ToClr(native->UserID);
			return rspdata;
		}
		String^	BrokerID;
		String^	UserID;
	};
	public ref class QryOrderRequestData
	{
	public:
		CThostFtdcQryOrderField ToNative()
		{
			CThostFtdcQryOrderField native = { 0 };
			copy_string_to_array(BrokerID, native.BrokerID);
			copy_string_to_array(InvestorID, native.InvestorID);
			copy_string_to_array(InstrumentID, native.InstrumentID);
			copy_string_to_array(ExchangeID, native.ExchangeID);
			copy_string_to_array(OrderSysID, native.OrderSysID);
			copy_string_to_array(InsertTimeStart, native.InsertTimeStart);
			copy_string_to_array(InsertTimeEnd, native.InsertTimeEnd);
			copy_string_to_array(InvestUnitID, native.InvestUnitID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///合约代码
		String^ InstrumentID;
		///交易所代码
		String^ ExchangeID;
		///报单编号
		String^ OrderSysID;
		///开始时间
		String^ InsertTimeStart;
		///结束时间
		String^ InsertTimeEnd;
		///投资单元代码
		String^ InvestUnitID;
	};
	//查询报单返回数据为--> RtnOrderResponseData
	public ref class QryAccountRequestData
	{
	public:
		CThostFtdcQryTradingAccountField ToNative()
		{
			CThostFtdcQryTradingAccountField native = { 0 };
			copy_string_to_array(BrokerID, native.BrokerID);
			copy_string_to_array(InvestorID, native.InvestorID);
			copy_string_to_array(CurrencyID, native.CurrencyID);
			copy_string_to_array(BizType, native.BizType);
			copy_string_to_array(AccountID, native.AccountID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///币种代码
		String^ CurrencyID;
		///业务类型
		String^ BizType;
		///投资者帐号
		String^ AccountID;
	};
	public ref class QryAccountResponseData
	{
	public:
		static QryAccountResponseData^ FromNative(CThostFtdcTradingAccountField* native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew QryAccountResponseData;
			rspdata->BrokerID = U8ToClr(native->BrokerID);
			rspdata->AccountID = U8ToClr(native->AccountID);
			rspdata->PreMortgage = native->PreMortgage;
			rspdata->PreCredit = native->PreCredit;
			rspdata->PreDeposit = native->PreDeposit;
			rspdata->PreBalance = native->PreBalance;
			rspdata->PreMargin = native->PreMargin;
			rspdata->InterestBase = native->InterestBase;
			rspdata->Interest = native->Interest;
			rspdata->Deposit = native->Deposit;
			rspdata->Withdraw = native->Withdraw;
			rspdata->FrozenMargin = native->FrozenMargin;
			rspdata->FrozenCash = native->FrozenCash;
			rspdata->FrozenCommission = native->FrozenCommission;
			rspdata->CurrMargin = native->CurrMargin;
			rspdata->CashIn = native->CashIn;
			rspdata->CloseProfit = native->CloseProfit;
			rspdata->PositionProfit = native->PositionProfit;
			rspdata->Balance = native->Balance;
			rspdata->Available = native->Available;
			rspdata->WithdrawQuota = native->WithdrawQuota;
			rspdata->Reserve = native->Reserve;
			rspdata->TradingDay = U8ToClr(native->TradingDay);
			rspdata->SettlementID = native->SettlementID;
			rspdata->Credit = native->Credit;
			rspdata->Mortgage = native->Mortgage;
			rspdata->ExchangeMargin = native->ExchangeMargin;
			rspdata->DeliveryMargin = native->DeliveryMargin;
			rspdata->ExchangeDeliveryMargin = native->ExchangeDeliveryMargin;
			rspdata->ReserveBalance = native->ReserveBalance;
			rspdata->CurrencyID = U8ToClr(native->CurrencyID);
			rspdata->PreFundMortgageIn = native->PreFundMortgageIn;
			rspdata->PreFundMortgageOut = native->PreFundMortgageOut;
			rspdata->FundMortgageIn = native->FundMortgageIn;
			rspdata->FundMortgageOut = native->FundMortgageOut;
			rspdata->FundMortgageAvailable = native->FundMortgageAvailable;
			rspdata->MortgageableFund = native->MortgageableFund;
			rspdata->SpecProductMargin = native->SpecProductMargin;
			rspdata->SpecProductFrozenMargin = native->SpecProductFrozenMargin;
			rspdata->SpecProductCommission = native->SpecProductCommission;
			rspdata->SpecProductFrozenCommission = native->SpecProductFrozenCommission;
			rspdata->SpecProductPositionProfit = native->SpecProductPositionProfit;
			rspdata->SpecProductCloseProfit = native->SpecProductCloseProfit;
			rspdata->SpecProductPositionProfitByAlg = native->SpecProductPositionProfitByAlg;
			rspdata->SpecProductExchangeMargin = native->SpecProductExchangeMargin;
			rspdata->BizType = native->BizType;
			rspdata->FrozenSwap = native->FrozenSwap;
			rspdata->RemainSwap = native->RemainSwap;
			return rspdata;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者帐号
		String^ AccountID;
		///上次质押金额
		double PreMortgage;
		///上次信用额度
		double  PreCredit;
		///上次存款额
		double  PreDeposit;
		///上次结算准备金
		double  PreBalance;
		///上次占用的保证金
		double  PreMargin;
		///利息基数
		double  InterestBase;
		///利息收入
		double  Interest;
		///入金金额
		double  Deposit;
		///出金金额
		double  Withdraw;
		///冻结的保证金
		double  FrozenMargin;
		///冻结的资金
		double  FrozenCash;
		///冻结的手续费
		double  FrozenCommission;
		///当前保证金总额
		double  CurrMargin;
		///资金差额
		double  CashIn;
		///手续费
		double  Commission;
		///平仓盈亏
		double  CloseProfit;
		///持仓盈亏
		double  PositionProfit;
		///期货结算准备金
		double  Balance;
		///可用资金
		double  Available;
		///可取资金
		double  WithdrawQuota;
		///基本准备金
		double  Reserve;
		///交易日
		String^ TradingDay;
		///结算编号
		int SettlementID;
		///信用额度
		double Credit;
		///质押金额
		double Mortgage;
		///交易所保证金
		double ExchangeMargin;
		///投资者交割保证金
		double DeliveryMargin;
		///交易所交割保证金
		double ExchangeDeliveryMargin;
		///保底期货结算准备金
		double ReserveBalance;
		///币种代码
		String^ CurrencyID;
		///上次货币质入金额
		double  PreFundMortgageIn;
		///上次货币质出金额
		double  PreFundMortgageOut;
		///货币质入金额
		double  FundMortgageIn;
		///货币质出金额
		double  FundMortgageOut;
		///货币质押余额
		double  FundMortgageAvailable;
		///可质押货币金额
		double  MortgageableFund;
		///特殊产品占用保证金
		double  SpecProductMargin;
		///特殊产品冻结保证金
		double  SpecProductFrozenMargin;
		///特殊产品手续费
		double  SpecProductCommission;
		///特殊产品冻结手续费
		double  SpecProductFrozenCommission;
		///特殊产品持仓盈亏
		double  SpecProductPositionProfit;
		///特殊产品平仓盈亏
		double  SpecProductCloseProfit;
		///根据持仓盈亏算法计算的特殊产品持仓盈亏
		double  SpecProductPositionProfitByAlg;
		///特殊产品交易所保证金
		double  SpecProductExchangeMargin;
		///业务类型
		char BizType;
		///延时换汇冻结金额
		double FrozenSwap;
		///剩余换汇额度
		double RemainSwap;
	};
	//报单录入请求
	public ref class OrderInsertRequestData
	{
	public:
		CThostFtdcInputOrderField ToNative()
		{
			CThostFtdcInputOrderField  native = { 0 };
			copy_string_to_array(BrokerID, native.BrokerID);
			copy_string_to_array(InvestorID, native.InvestorID);
			copy_string_to_array(ExchangeID, native.ExchangeID);
			copy_string_to_array(InstrumentID, native.InstrumentID);
			copy_string_to_array(UserID, native.UserID);
			native.OrderPriceType = OrderPriceType;
			native.Direction = Direction;
			native.CombOffsetFlag[0] = CombOffsetFlag;
			native.CombHedgeFlag[0] = CombHedgeFlag;
			native.LimitPrice = LimitPrice;
			native.VolumeTotalOriginal = VolumeTotalOriginal;
			native.TimeCondition = TimeCondition;
			native.VolumeCondition = VolumeCondition;
			native.MinVolume = MinVolume;
			native.ContingentCondition = ContingentCondition;
			native.StopPrice = StopPrice;
			native.ForceCloseReason = ForceCloseReason;
			native.IsAutoSuspend = IsAutoSuspend;
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///用户代码
		String^	UserID;
		///合约代码
		String^ InstrumentID;
		///报单引用
		String^ OrderRef;
		///报单价格条件
		char OrderPriceType;
		///买卖方向
		char Direction;
		///组合开平标志
		char CombOffsetFlag;
		///组合投机套保标志
		char CombHedgeFlag;
		///价格
		double LimitPrice;
		///数量
		Int32 VolumeTotalOriginal;
		///有效期类型
		char TimeCondition;
		///GTD日期
		String^ GTDDate;
		///成交量类型
		char VolumeCondition;
		///最小成交量
		Int32 MinVolume;
		///触发条件
		char ContingentCondition;
		///止损价
		Int32 StopPrice;
		///强平原因
		char ForceCloseReason;
		///自动挂起标志
		Int32 IsAutoSuspend;
		///业务单元
		String^	BusinessUnit;
		///请求编号
		Int32	RequestID;
		///用户强评标志
		Int32	UserForceClose;
		///互换单标志
		Int32	IsSwapOrder;
		///交易所代码
		String^	ExchangeID;
		///投资单元代码
		String^	InvestUnitID;
		///资金账号
		String^	AccountID;
		///币种代码
		String^	CurrencyID;
		///交易编码
		String^	ClientID;
		///IP地址
		String^	IPAddress;
		///Mac地址
		String^	MacAddress;
	};
	//报单录入请求响应，当执行ReqOrderInsert后有字段填写不对之类的CTP报错则通过此接口返回
	//OnRsnativeInsert和OnErrRtnOrderInsert共有
	public ref class OrderInsertResponseData
	{
	public:
		static OrderInsertResponseData^ FromNative(CThostFtdcInputOrderField* native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew OrderInsertResponseData;
			rspdata->BrokerID = U8ToClr(native->BrokerID);
			rspdata->InvestorID = U8ToClr(native->InvestorID);
			rspdata->InstrumentID = U8ToClr(native->InstrumentID);
			rspdata->OrderRef = U8ToClr(native->OrderRef);
			rspdata->TimeCondition = native->TimeCondition;
			rspdata->OrderPriceType = native->OrderPriceType;
			rspdata->Direction = native->Direction;
			rspdata->CombOffsetFlag = U8ToClr(native->CombOffsetFlag);
			rspdata->CombHedgeFlag = U8ToClr(native->CombHedgeFlag);
			rspdata->LimitPrice = native->LimitPrice;
			rspdata->VolumeTotalOriginal = native->VolumeTotalOriginal;
			rspdata->TimeCondition = native->TimeCondition;
			rspdata->GTDDate = U8ToClr(native->GTDDate);
			rspdata->VolumeCondition = native->VolumeCondition;
			rspdata->MinVolume = native->MinVolume;
			rspdata->ContingentCondition = native->ContingentCondition;
			rspdata->StopPrice = native->StopPrice;
			rspdata->ForceCloseReason = native->ForceCloseReason;
			rspdata->IsAutoSuspend = native->IsAutoSuspend;
			rspdata->BusinessUnit = U8ToClr(native->BusinessUnit);
			rspdata->RequestID = native->RequestID;
			rspdata->UserForceClose = native->UserForceClose;
			rspdata->IsSwapOrder = native->IsSwapOrder;
			rspdata->ExchangeID = U8ToClr(native->ExchangeID);
			rspdata->InvestUnitID = U8ToClr(native->InvestUnitID);
			rspdata->AccountID = U8ToClr(native->AccountID);
			rspdata->CurrencyID = U8ToClr(native->CurrencyID);
			rspdata->ClientID = U8ToClr(native->ClientID);
			rspdata->IPAddress = U8ToClr(native->IPAddress);
			rspdata->MacAddress = U8ToClr(native->MacAddress);
			return rspdata;
		}
		///经纪公司代码
		String^	BrokerID;
		///投资者代码
		String^	InvestorID;
		///合约代码
		String^	InstrumentID;
		///报单引用
		String^	OrderRef;
		///用户代码
		String^	UserID;
		///报单价格条件
		char	OrderPriceType;
		///买卖方向
		char	Direction;
		///组合开平标志
		String^	CombOffsetFlag;
		///组合投机套保标志
		String^	CombHedgeFlag;
		///价格
		double	LimitPrice;
		///数量
		int	VolumeTotalOriginal;
		///有效期类型
		char	TimeCondition;
		///GTD日期
		String^	GTDDate;
		///成交量类型
		char	VolumeCondition;
		///最小成交量
		int	MinVolume;
		///触发条件
		char	ContingentCondition;
		///止损价
		double	StopPrice;
		///强平原因
		char	ForceCloseReason;
		///自动挂起标志
		int	IsAutoSuspend;
		///业务单元
		String^	BusinessUnit;
		///请求编号
		int	RequestID;
		///用户强评标志
		int	UserForceClose;
		///互换单标志
		int	IsSwapOrder;
		///交易所代码
		String^	ExchangeID;
		///投资单元代码
		String^	InvestUnitID;
		///资金账号
		String^	AccountID;
		///币种代码
		String^	CurrencyID;
		///交易编码
		String^	ClientID;
		///IP地址
		String^	IPAddress;
		///Mac地址
		String^	MacAddress;
	};
	public ref class RtnOrderResponseData
	{
	public:
		static RtnOrderResponseData^ FromNative(CThostFtdcOrderField* native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew RtnOrderResponseData;
			///经纪公司代码
			rspdata->BrokerID = U8ToClr(native->BrokerID);
			///投资者代码
			rspdata->InvestorID = U8ToClr(native->InvestorID);
			///合约代码
			rspdata->InstrumentID = U8ToClr(native->InstrumentID);
			///报单引用
			rspdata->OrderRef = U8ToClr(native->OrderRef);
			///用户代码
			rspdata->UserID = U8ToClr(native->UserID);
			///报单价格条件
			rspdata->OrderPriceType = native->OrderPriceType;
			///买卖方向
			rspdata->Direction = native->Direction;
			///组合开平标志
			rspdata->CombOffsetFlag = U8ToClr(native->CombOffsetFlag);
			///组合投机套保标志
			rspdata->CombHedgeFlag = U8ToClr(native->CombHedgeFlag);
			///价格
			rspdata->LimitPrice = native->LimitPrice;
			///数量
			rspdata->VolumeTotalOriginal = native->VolumeTotalOriginal;
			///有效期类型
			rspdata->TimeCondition = native->TimeCondition;
			///GTD日期
			rspdata->GTDDate = U8ToClr(native->GTDDate);
			///成交量类型
			rspdata->VolumeCondition = native->VolumeCondition;
			///最小成交量
			rspdata->MinVolume = native->MinVolume;
			///触发条件
			rspdata->ContingentCondition = native->ContingentCondition;
			///止损价
			rspdata->StopPrice = native->StopPrice;
			///强平原因
			rspdata->ForceCloseReason = native->ForceCloseReason;
			///自动挂起标志
			rspdata->IsAutoSuspend = native->IsAutoSuspend;
			///业务单元
			rspdata->BusinessUnit = U8ToClr(native->BusinessUnit);
			///请求编号
			rspdata->RequestID = native->RequestID;
			///本地报单编号
			rspdata->OrderLocalID = U8ToClr(native->OrderLocalID);
			///交易所代码
			rspdata->ExchangeID = U8ToClr(native->ExchangeID);
			///会员代码
			rspdata->ParticipantID = U8ToClr(native->ParticipantID);
			///客户代码
			rspdata->ClientID = U8ToClr(native->ClientID);
			///合约在交易所的代码
			rspdata->ExchangeInstID = U8ToClr(native->ExchangeInstID);
			///交易所交易员代码
			rspdata->TraderID = U8ToClr(native->TraderID);
			///安装编号
			rspdata->InstallID = native->InstallID;
			///报单提交状态
			rspdata->OrderSubmitStatus = native->OrderSubmitStatus;
			///报单提示序号
			rspdata->NotifySequence = native->NotifySequence;
			///交易日
			rspdata->TradingDay = U8ToClr(native->TradingDay);
			///结算编号
			rspdata->SettlementID = native->SettlementID;
			///报单编号
			rspdata->OrderSysID = U8ToClr(native->OrderSysID);
			///报单来源
			rspdata->OrderSource = native->OrderSource;
			///报单类型
			rspdata->OrderType = native->OrderType;
			///今成交数量
			rspdata->VolumeTraded = native->VolumeTraded;
			///剩余数量
			rspdata->VolumeTotal = native->VolumeTotal;
			///报单日期
			rspdata->InsertDate = U8ToClr(native->InsertDate);
			///委托时间
			rspdata->InsertTime = U8ToClr(native->InsertTime);
			///激活时间
			rspdata->ActiveTime = U8ToClr(native->ActiveTime);
			///挂起时间
			rspdata->SuspendTime = U8ToClr(native->SuspendTime);
			///最后修改时间
			rspdata->UpdateTime = U8ToClr(native->UpdateTime);
			///撤销时间
			rspdata->CancelTime = U8ToClr(native->CancelTime);
			///最后修改交易所交易员代码
			rspdata->ActiveTraderID = U8ToClr(native->ActiveTraderID);
			///结算会员编号
			rspdata->ClearingPartID = U8ToClr(native->ClearingPartID);
			///序号
			rspdata->SequenceNo = native->SequenceNo;
			///前置编号
			rspdata->FrontID = native->FrontID;
			///会话编号
			rspdata->SessionID = native->SessionID;
			///用户端产品信息
			rspdata->UserProductInfo = U8ToClr(native->UserProductInfo);
			///状态信息
			rspdata->StatusMsg = AnsiToClr(native->StatusMsg);
			///用户强评标志
			rspdata->UserForceClose = native->UserForceClose;
			///操作用户代码
			rspdata->ActiveUserID = U8ToClr(native->ActiveUserID);
			///经纪公司报单编号
			rspdata->BrokerOrderSeq = native->BrokerOrderSeq;
			///相关报单
			rspdata->RelativeOrderSysID = U8ToClr(native->RelativeOrderSysID);
			///郑商所成交数量
			rspdata->ZCETotalTradedVolume = native->ZCETotalTradedVolume;
			///互换单标志
			rspdata->IsSwapOrder = native->IsSwapOrder;
			///营业部编号
			rspdata->BranchID = U8ToClr(native->BranchID);
			///投资单元代码
			rspdata->InvestUnitID = U8ToClr(native->InvestUnitID);
			///资金账号
			rspdata->AccountID = U8ToClr(native->AccountID);
			///币种代码
			rspdata->CurrencyID = U8ToClr(native->CurrencyID);
			///IP地址
			rspdata->IPAddress = U8ToClr(native->IPAddress);
			///报单状态 很关键
			rspdata->OrderStatus = native->OrderStatus;
			///Mac地址
			rspdata->MacAddress = U8ToClr(native->MacAddress);
			return rspdata;
		}
		///经纪公司代码
		String^	BrokerID;
		///投资者代码
		String^	InvestorID;
		///合约代码
		String^	InstrumentID;
		///报单引用
		String^	OrderRef;
		///用户代码
		String^	UserID;
		///报单价格条件
		char	OrderPriceType;
		///买卖方向
		char	Direction;
		///组合开平标志
		String^	CombOffsetFlag;
		///组合投机套保标志
		String^	CombHedgeFlag;
		///价格
		double	LimitPrice;
		///数量
		int	VolumeTotalOriginal;
		///有效期类型
		char	TimeCondition;
		///GTD日期
		String^	GTDDate;
		///成交量类型
		char	VolumeCondition;
		///最小成交量
		int	MinVolume;
		///触发条件
		char	ContingentCondition;
		///止损价
		double	StopPrice;
		///强平原因
		char	ForceCloseReason;
		///自动挂起标志
		int	IsAutoSuspend;
		///业务单元
		String^	BusinessUnit;
		///请求编号
		int	RequestID;
		///本地报单编号
		String^	OrderLocalID;
		///交易所代码
		String^	ExchangeID;
		///会员代码
		String^	ParticipantID;
		///客户代码
		String^	ClientID;
		///合约在交易所的代码
		String^	ExchangeInstID;
		///交易所交易员代码
		String^	TraderID;
		///安装编号
		int	InstallID;
		///报单提交状态
		char	OrderSubmitStatus;
		///报单提示序号
		int	NotifySequence;
		///交易日
		String^	TradingDay;
		///结算编号
		int	SettlementID;
		///报单编号
		String^	OrderSysID;
		///报单来源
		char	OrderSource;
		///报单状态
		char	OrderStatus;
		///报单类型
		char	OrderType;
		///今成交数量
		int	VolumeTraded;
		///剩余数量
		int	VolumeTotal;
		///报单日期
		String^	InsertDate;
		///委托时间
		String^	InsertTime;
		///激活时间
		String^	ActiveTime;
		///挂起时间
		String^	SuspendTime;
		///最后修改时间
		String^	UpdateTime;
		///撤销时间
		String^	CancelTime;
		///最后修改交易所交易员代码
		String^	ActiveTraderID;
		///结算会员编号
		String^	ClearingPartID;
		///序号
		int	SequenceNo;
		///前置编号
		int	FrontID;
		///会话编号
		int	SessionID;
		///用户端产品信息
		String^	UserProductInfo;
		///状态信息
		String^	StatusMsg;
		///用户强评标志
		int	UserForceClose;
		///操作用户代码
		String^	ActiveUserID;
		///经纪公司报单编号
		int	BrokerOrderSeq;
		///相关报单
		String^	RelativeOrderSysID;
		///郑商所成交数量
		int	ZCETotalTradedVolume;
		///互换单标志
		int	IsSwapOrder;
		///营业部编号
		String^	BranchID;
		///投资单元代码
		String^	InvestUnitID;
		///资金账号
		String^	AccountID;
		///币种代码
		String^	CurrencyID;
		///IP地址
		String^	IPAddress;
		///Mac地址
		String^	MacAddress;
	};
	public ref class RtnTradeResponseData
	{
	public:
		static RtnTradeResponseData^ FromNative(CThostFtdcTradeField* native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew RtnTradeResponseData;
			rspdata->BrokerID = U8ToClr(native->BrokerID);
			rspdata->InvestorID = U8ToClr(native->InvestorID);
			rspdata->InstrumentID = U8ToClr(native->InstrumentID);
			rspdata->OrderRef = U8ToClr(native->OrderRef);
			rspdata->UserID = U8ToClr(native->UserID);
			rspdata->ExchangeID = U8ToClr(native->ExchangeID);
			rspdata->TradeID = U8ToClr(native->TradeID);
			rspdata->Direction = native->Direction;
			rspdata->OrderSysID = U8ToClr(native->OrderSysID);
			rspdata->ParticipantID = U8ToClr(native->ParticipantID);
			rspdata->ClientID = U8ToClr(native->ClientID);
			rspdata->TradingRole = native->TradingRole;
			rspdata->ExchangeInstID = U8ToClr(native->ExchangeInstID);
			rspdata->OffsetFlag = native->OffsetFlag;
			rspdata->HedgeFlag = native->HedgeFlag;
			rspdata->Price = native->Price;
			rspdata->Volume = native->Volume;
			rspdata->TradeDate = U8ToClr(native->TradeDate);
			rspdata->TradeTime = U8ToClr(native->TradeTime);
			rspdata->TradeType = native->TradeType;
			rspdata->PriceSource = native->PriceSource;
			rspdata->TraderID = U8ToClr(native->TraderID);
			rspdata->OrderLocalID = U8ToClr(native->OrderLocalID);
			rspdata->ClearingPartID = U8ToClr(native->ClearingPartID);
			rspdata->BusinessUnit = U8ToClr(native->BusinessUnit);
			rspdata->SequenceNo = native->SequenceNo;
			rspdata->TradingDay = U8ToClr(native->TradingDay);
			rspdata->SettlementID = native->SettlementID;
			rspdata->BrokerOrderSeq = native->BrokerOrderSeq;
			rspdata->TradeSource = native->TradeSource;
			rspdata->InvestUnitID = U8ToClr(native->InvestUnitID);
			return rspdata;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///合约代码
		String^ InstrumentID;
		///报单引用
		String^ OrderRef;
		///用户代码
		String^ UserID;
		///交易所代码
		String^ ExchangeID;
		///成交编号
		String^ TradeID;
		///买卖方向
		char Direction;
		///报单编号
		String^ OrderSysID;
		///会员代码
		String^ ParticipantID;
		///客户代码
		String^ ClientID;
		///交易角色
		char TradingRole;
		///合约在交易所的代码
		String^ ExchangeInstID;
		///开平标志
		char OffsetFlag;
		///投机套保标志
		char HedgeFlag;
		///价格
		double Price;
		///数量
		Int32 Volume;
		///成交时期
		String^ TradeDate;
		///成交时间
		String^ TradeTime;
		///成交类型
		char TradeType;
		///成交价来源
		char PriceSource;
		///交易所交易员代码
		String^ TraderID;
		///本地报单编号
		String^ OrderLocalID;
		///结算会员编号
		String^ ClearingPartID;
		///业务单元
		String^ BusinessUnit;
		///序号
		Int32 SequenceNo;
		///交易日
		String^ TradingDay;
		///结算编号
		Int32 SettlementID;
		///经纪公司报单编号
		Int32 BrokerOrderSeq;
		///成交来源
		char TradeSource;
		///投资单元代码
		String^ InvestUnitID;
	};
	public ref class InvestorPositionRequestData
	{
	public:
		CThostFtdcQryInvestorPositionField   ToNative()
		{
			CThostFtdcQryInvestorPositionField    native = { 0 };
			copy_string_to_array(BrokerID, native.BrokerID);
			copy_string_to_array(InvestorID, native.InvestorID);
			copy_string_to_array(ExchangeID, native.ExchangeID);
			copy_string_to_array(InstrumentID, native.InstrumentID);
			copy_string_to_array(InvestUnitID, native.InvestUnitID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^  InvestorID;
		///合约代码
		String^  InstrumentID;
		///交易所代码
		String^  ExchangeID;
		///投资单元代码
		String^  InvestUnitID;
	};
	public ref class InvestorPositionResponseData
	{
	public:
		static InvestorPositionResponseData^ FromNative(CThostFtdcInvestorPositionField  * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew InvestorPositionResponseData;
			rspdata->BrokerID = U8ToClr(native->BrokerID);
			rspdata->InvestorID = U8ToClr(native->InvestorID);
			rspdata->InstrumentID = U8ToClr(native->InstrumentID);
			rspdata->HedgeFlag = native->HedgeFlag;
			rspdata->PosiDirection = native->PosiDirection;
			rspdata->PositionDate = native->PositionDate;
			rspdata->YdPosition = native->YdPosition;
			rspdata->Position = native->Position;
			rspdata->LongFrozen = native->LongFrozen;
			rspdata->ShortFrozen = native->ShortFrozen;
			rspdata->LongFrozenAmount = native->LongFrozenAmount;
			rspdata->ShortFrozenAmount = native->ShortFrozenAmount;
			rspdata->OpenVolume = native->OpenVolume;
			rspdata->CloseVolume = native->CloseVolume;
			rspdata->OpenAmount = native->OpenAmount;
			rspdata->CloseAmount = native->CloseAmount;
			rspdata->PositionCost = native->PositionCost;
			rspdata->PreMargin = native->PreMargin;
			rspdata->UseMargin = native->UseMargin;
			rspdata->FrozenMargin = native->FrozenMargin;
			rspdata->FrozenCash = native->FrozenCash;
			rspdata->FrozenCommission = native->FrozenCommission;
			rspdata->CashIn = native->CashIn;
			rspdata->Commission = native->Commission;
			rspdata->CloseProfit = native->CloseProfit;
			rspdata->PositionProfit = native->PositionProfit;
			rspdata->PreSettlementPrice = native->PreSettlementPrice;
			rspdata->SettlementPrice = native->SettlementPrice;
			rspdata->TradingDay = U8ToClr(native->TradingDay);
			rspdata->SettlementID = native->SettlementID;
			rspdata->OpenCost = native->OpenCost;
			rspdata->ExchangeMargin = native->ExchangeMargin;
			rspdata->CombPosition = native->CombPosition;
			rspdata->CombLongFrozen = native->CombLongFrozen;
			rspdata->CombShortFrozen = native->CombShortFrozen;
			rspdata->CloseProfitByDate = native->CloseProfitByDate;
			rspdata->CloseProfitByTrade = native->CloseProfitByTrade;
			rspdata->TodayPosition = native->TodayPosition;
			rspdata->MarginRateByMoney = native->MarginRateByMoney;
			rspdata->MarginRateByVolume = native->MarginRateByVolume;
			rspdata->StrikeFrozen = native->StrikeFrozen;
			rspdata->StrikeFrozenAmount = native->StrikeFrozenAmount;
			rspdata->AbandonFrozen = native->AbandonFrozen;
			rspdata->ExchangeID = U8ToClr(native->ExchangeID);
			rspdata->YdStrikeFrozen = native->YdStrikeFrozen;
			rspdata->InvestUnitID = U8ToClr(native->InvestUnitID);
			return rspdata;
		}
		///合约代码
		String^	InstrumentID;
		///经纪公司代码
		String^	BrokerID;
		///投资者代码
		String^	InvestorID;
		///持仓多空方向
		char	PosiDirection;
		///投机套保标志
		char	HedgeFlag;
		///持仓日期
		char	PositionDate;
		///上日持仓
		int	YdPosition;
		///今日持仓
		int	Position;
		///多头冻结
		int	LongFrozen;
		///空头冻结
		int	ShortFrozen;
		///开仓冻结金额
		double	LongFrozenAmount;
		///开仓冻结金额
		double	ShortFrozenAmount;
		///开仓量
		int	OpenVolume;
		///平仓量
		int	CloseVolume;
		///开仓金额
		double	OpenAmount;
		///平仓金额
		double	CloseAmount;
		///持仓成本
		double	PositionCost;
		///上次占用的保证金
		double	PreMargin;
		///占用的保证金
		double	UseMargin;
		///冻结的保证金
		double	FrozenMargin;
		///冻结的资金
		double	FrozenCash;
		///冻结的手续费
		double	FrozenCommission;
		///资金差额
		double	CashIn;
		///手续费
		double	Commission;
		///平仓盈亏
		double	CloseProfit;
		///持仓盈亏
		double	PositionProfit;
		///上次结算价
		double	PreSettlementPrice;
		///本次结算价
		double	SettlementPrice;
		///交易日
		String^	TradingDay;
		///结算编号
		int	SettlementID;
		///开仓成本
		double	OpenCost;
		///交易所保证金
		double	ExchangeMargin;
		///组合成交形成的持仓
		int	CombPosition;
		///组合多头冻结
		int	CombLongFrozen;
		///组合空头冻结
		int	CombShortFrozen;
		///逐日盯市平仓盈亏
		double	CloseProfitByDate;
		///逐笔对冲平仓盈亏
		double	CloseProfitByTrade;
		///今日持仓
		int	TodayPosition;
		///保证金率
		double	MarginRateByMoney;
		///保证金率(按手数)
		double	MarginRateByVolume;
		///执行冻结
		int	StrikeFrozen;
		///执行冻结金额
		double	StrikeFrozenAmount;
		///放弃执行冻结
		int	AbandonFrozen;
		///交易所代码
		String^	ExchangeID;
		///执行冻结的昨仓
		int	YdStrikeFrozen;
		///投资单元代码
		String^	InvestUnitID;
	};
	public ref class OrderActionRequestData
	{
	public:
		CThostFtdcInputOrderActionField ToNative()
		{
			CThostFtdcInputOrderActionField  native = { 0 };
			copy_string_to_array(BrokerID, native.BrokerID);
			copy_string_to_array(InvestorID, native.InvestorID);
			copy_string_to_array(ExchangeID, native.ExchangeID);
			copy_string_to_array(OrderSysID, native.OrderSysID);
			native.ActionFlag = ActionFlag;
			copy_string_to_array(UserID, native.UserID);
			copy_string_to_array(InstrumentID, native.InstrumentID);
			return native;
		}
		String^ BrokerID;
		String^ InvestorID;
		Int32 OrderActionRef;
		String^ OrderRef;
		Int32 RequestID;
		Int32 FrontID;
		Int32 SessionID;
		String^ ExchangeID;
		String^ OrderSysID;
		char ActionFlag;
		double LimitPrice;
		Int32 VolumeChange;
		String^ UserID;
		String^ InstrumentID;
		String^ InvestUnitID;
		String^ IPAddress;
		String^ MacAddress;
	};
	public ref class OrderActionResponseData
	{
	public:
		static OrderActionResponseData^ FromNative(CThostFtdcInputOrderActionField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew OrderActionResponseData;
			rspdata->BrokerID = U8ToClr(native->BrokerID);
			rspdata->InvestorID = U8ToClr(native->InvestorID);
			rspdata->OrderRef = U8ToClr(native->OrderRef);
			rspdata->OrderActionRef = native->OrderActionRef;
			rspdata->RequestID = native->RequestID;
			rspdata->FrontID = native->FrontID;
			rspdata->SessionID = native->SessionID;
			rspdata->ExchangeID = U8ToClr(native->ExchangeID);
			rspdata->OrderSysID = U8ToClr(native->OrderSysID);
			rspdata->ActionFlag = native->ActionFlag;
			rspdata->LimitPrice = native->LimitPrice;
			rspdata->VolumeChange = native->VolumeChange;
			rspdata->UserID = U8ToClr(native->UserID);
			rspdata->InstrumentID = U8ToClr(native->InstrumentID);
			rspdata->InvestUnitID = U8ToClr(native->InvestUnitID);
			rspdata->IPAddress = U8ToClr(native->IPAddress);
			rspdata->MacAddress = U8ToClr(native->MacAddress);
			return rspdata;
		}
		String^BrokerID;
		String^InvestorID;
		int OrderActionRef;
		String^OrderRef;
		int RequestID;
		int FrontID;
		int SessionID;
		String^ExchangeID;
		String^OrderSysID;
		char ActionFlag;
		double LimitPrice;
		int VolumeChange;
		String^UserID;
		String^InstrumentID;
		String^InvestUnitID;
		String^IPAddress;
		String^MacAddress;
	};
	public ref class ResponseInformation
	{
	public:
		static ResponseInformation^ FromNative(CThostFtdcRspInfoField* native)
		{
			auto rsp = gcnew ResponseInformation;
			if (native != nullptr)
			{
				rsp->ErrorID = native->ErrorID;
				rsp->ErrorMsg = AnsiToClr(native->ErrorMsg);
			}
			return rsp;
		}
		Int32   ErrorID = -1;
		String^	ErrorMsg = "返回空结果";
	};
	public ref class AuthenticateResponseData
	{
	public:
		static AuthenticateResponseData^ FromNative(CThostFtdcRspAuthenticateField* native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rsp = gcnew AuthenticateResponseData;
			rsp->BrokerID = U8ToClr(native->BrokerID);
			rsp->UserID = U8ToClr(native->UserID);
			rsp->UserProductInfo = U8ToClr(native->UserProductInfo);
			return rsp;
		}
		String^	BrokerID;
		String^	UserID;
		String^	UserProductInfo;
	};
	public ref class QryTransferSerialRequestData
	{
	public:
		CThostFtdcQryTransferSerialField ToNative()
		{
			CThostFtdcQryTransferSerialField native = { 0 };
			copy_string_to_array(BrokerID, native.BrokerID);
			copy_string_to_array(AccountID, native.AccountID);
			copy_string_to_array(BankID, native.BankID);
			copy_string_to_array(CurrencyID, native.CurrencyID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者帐号
		String^ AccountID;
		///银行编码
		String^ BankID;
		///币种代码
		String^ CurrencyID;
	};
	public ref class QryTransferSerialResponseData
	{
	public:
		static QryTransferSerialResponseData^ FromNative(CThostFtdcTransferSerialField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rsp = gcnew QryTransferSerialResponseData;
			rsp->TradingDay = U8ToClr(native->TradingDay);
			rsp->PlateSerial = native->PlateSerial;
			rsp->TradeDate = U8ToClr(native->TradeDate);
			rsp->TradingDay = U8ToClr(native->TradingDay);
			rsp->TradeTime = U8ToClr(native->TradeTime);
			rsp->TradeCode = U8ToClr(native->TradeCode);
			rsp->SessionID = native->SessionID;
			rsp->BankID = U8ToClr(native->BankID);
			rsp->BankBranchID = U8ToClr(native->BankBranchID);
			rsp->BankAccType = native->BankAccType;
			rsp->BankAccount = U8ToClr(native->BankAccount);
			rsp->BankSerial = U8ToClr(native->BankSerial);
			rsp->BrokerID = U8ToClr(native->BrokerID);
			rsp->BrokerBranchID = U8ToClr(native->BrokerBranchID);
			rsp->FutureAccType = native->FutureAccType;
			rsp->AccountID = U8ToClr(native->AccountID);
			rsp->InvestorID = U8ToClr(native->InvestorID);
			rsp->FutureSerial = native->FutureSerial;
			rsp->IdCardType = native->IdCardType;
			rsp->IdentifiedCardNo = U8ToClr(native->IdentifiedCardNo);
			rsp->CurrencyID = U8ToClr(native->CurrencyID);
			rsp->TradeAmount = native->TradeAmount;
			rsp->CustFee = native->CustFee;
			rsp->BrokerFee = native->BrokerFee;
			rsp->AvailabilityFlag = native->AvailabilityFlag;
			rsp->OperatorCode = U8ToClr(native->OperatorCode);
			rsp->BankNewAccount = U8ToClr(native->BankNewAccount);
			rsp->ErrorID = native->ErrorID;
			rsp->ErrorMsg = AnsiToClr(native->ErrorMsg);
			return rsp;
		}
		///平台流水号
		int PlateSerial;
		///交易发起方日期
		String^ TradeDate;
		///交易日期
		String^ TradingDay;
		///交易时间
		String^ TradeTime;
		///交易代码
		String^ TradeCode;
		///会话编号
		int SessionID;
		///银行编码
		String^ BankID;
		///银行分支机构编码
		String^ BankBranchID;
		///银行帐号类型
		char BankAccType;
		///银行帐号
		String^ BankAccount;
		///银行流水号
		String^ BankSerial;
		///期货公司编码
		String^ BrokerID;
		///期商分支机构代码
		String^ BrokerBranchID;
		///期货公司帐号类型
		char FutureAccType;
		///投资者帐号
		String^ AccountID;
		///投资者代码
		String^ InvestorID;
		///期货公司流水号
		int FutureSerial;
		///证件类型
		char IdCardType;
		///证件号码
		String^ IdentifiedCardNo;
		///币种代码
		String^ CurrencyID;
		///交易金额
		double TradeAmount;
		///应收客户费用
		double CustFee;
		///应收期货公司费用
		double BrokerFee;
		///有效标志
		char AvailabilityFlag;
		///操作员
		String^ OperatorCode;
		///新银行帐号
		String^ BankNewAccount;
		///错误代码
		int ErrorID;
		///错误信息
		String^ ErrorMsg;
	};
	public ref class AccountregisterRequestData
	{
	public:
		CThostFtdcQryAccountregisterField   ToNative()
		{
			CThostFtdcQryAccountregisterField   native = { 0 };
			copy_string_to_array(BrokerID, native.BrokerID);
			copy_string_to_array(AccountID, native.AccountID);
			copy_string_to_array(BankID, native.BankID);
			copy_string_to_array(BankBranchID, native.BankBranchID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者帐号
		String^ AccountID;
		///银行编码
		String^ BankID;
		///银行分支机构编码
		String^ BankBranchID;
		///币种代码
		String^ CurrencyID;
	};
	public ref class ContractBankRequestData
	{
	public:
		CThostFtdcQryContractBankField  ToNative()
		{
			CThostFtdcQryContractBankField  native = { 0 };
			copy_string_to_array(BrokerID, native.BrokerID);
			copy_string_to_array(BankID, native.BankID);
			copy_string_to_array(BankBrchID, native.BankBrchID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///银行代码
		String^ BankID;
		///银行分中心代码
		String^ BankBrchID;
	};
	public ref class FromBankToFutureByFutureRequestData
	{
	public:
		CThostFtdcReqTransferField  ToNative()
		{
			CThostFtdcReqTransferField  native = { 0 };
			copy_string_to_array(BrokerID, native.BrokerID);
			copy_string_to_array(TradeCode, native.TradeCode);
			copy_string_to_array(BankID, native.BankID);
			copy_string_to_array(BankBranchID, native.BankBranchID);
			copy_string_to_array(BrokerBranchID, native.BrokerBranchID);
			copy_string_to_array(TradeDate, native.TradeDate);
			copy_string_to_array(TradeTime, native.TradeTime);
			copy_string_to_array(BankSerial, native.BankSerial);
			copy_string_to_array(TradingDay, native.TradingDay);
			native.PlateSerial = PlateSerial;
			native.LastFragment = LastFragment;
			native.SessionID = SessionID;
			copy_string_to_array(CustomerName, native.CustomerName);
			native.IdCardType = IdCardType;
			copy_string_to_array(IdentifiedCardNo, native.IdentifiedCardNo);
			native.CustType = CustType;
			copy_string_to_array(BankAccount, native.BankAccount);
			copy_string_to_array(BankPassWord, native.BankPassWord);
			copy_string_to_array(AccountID, native.AccountID);
			copy_string_to_array(Password, native.Password);
			native.InstallID = InstallID;
			native.FutureSerial = FutureSerial;
			copy_string_to_array(UserID, native.UserID);
			native.VerifyCertNoFlag = VerifyCertNoFlag;
			copy_string_to_array(CurrencyID, native.CurrencyID);
			native.TradeAmount = TradeAmount;
			native.FutureFetchAmount = FutureFetchAmount;
			native.FeePayFlag = FeePayFlag;
			native.CustFee = CustFee;
			native.BrokerFee = BrokerFee;
			copy_string_to_array(Message, native.Message);
			copy_string_to_array(Digest, native.Digest);
			native.BankAccType = BankAccType;
			copy_string_to_array(DeviceID, native.DeviceID);
			native.BankSecuAccType = BankSecuAccType;
			copy_string_to_array(BrokerIDByBank, native.BrokerIDByBank);
			copy_string_to_array(BankSecuAcc, native.BankSecuAcc);
			native.BankPwdFlag = BankPwdFlag;
			native.SecuPwdFlag = SecuPwdFlag;
			copy_string_to_array(OperNo, native.OperNo);
			native.RequestID = RequestID;
			native.TID = TID;
			native.TransferStatus = TransferStatus;
			copy_string_to_array(LongCustomerName, native.LongCustomerName);
			return native;
		}
		///业务功能码
		String^ TradeCode;
		///银行代码
		String^ BankID;
		///银行分支机构代码
		String^ BankBranchID;
		///期商代码
		String^ BrokerID;
		///期商分支机构代码
		String^ BrokerBranchID;
		///交易日期
		String^ TradeDate;
		///交易时间
		String^ TradeTime;
		///银行流水号
		String^ BankSerial;
		///交易系统日期 
		String^ TradingDay;
		///银期平台消息流水号
		Int32 PlateSerial;
		///最后分片标志
		char LastFragment;
		///会话号
		Int32 SessionID;
		///客户姓名
		String^ CustomerName;
		///证件类型
		char IdCardType;
		///证件号码
		String^ IdentifiedCardNo;
		///客户类型
		char CustType;
		///银行帐号
		String^ BankAccount;
		///银行密码
		String^ BankPassWord;
		///投资者帐号
		String^ AccountID;
		///期货密码
		String^ Password;
		///安装编号
		Int32 InstallID;
		///期货公司流水号
		Int32 FutureSerial;
		///用户标识
		String^ UserID;
		///验证客户证件号码标志
		char VerifyCertNoFlag;
		///币种代码
		String^ CurrencyID;
		///转帐金额
		double TradeAmount;
		///期货可取金额
		double FutureFetchAmount;
		///费用支付标志
		char FeePayFlag;
		///应收客户费用
		double CustFee;
		///应收期货公司费用
		double BrokerFee;
		///发送方给接收方的消息
		String^ Message;
		///摘要
		String^ Digest;
		///银行帐号类型
		char BankAccType;
		///渠道标志
		String^ DeviceID;
		///期货单位帐号类型
		char BankSecuAccType;
		///期货公司银行编码
		String^ BrokerIDByBank;
		///期货单位帐号
		String^ BankSecuAcc;
		///银行密码标志
		char BankPwdFlag;
		///期货资金密码核对标志
		char SecuPwdFlag;
		///交易柜员
		String^ OperNo;
		///请求编号
		Int32 RequestID;
		///交易ID
		Int32 TID;
		///转账交易状态
		char TransferStatus;
		///长客户姓名
		String^ LongCustomerName;
	};
	public ref class FromFutureToBankByFutureRequestData
	{
	public:
		CThostFtdcReqTransferField  ToNative()
		{
			CThostFtdcReqTransferField  native = { 0 };
			copy_string_to_array(BrokerID, native.BrokerID);
			copy_string_to_array(TradeCode, native.TradeCode);
			copy_string_to_array(BankID, native.BankID);
			copy_string_to_array(BankBranchID, native.BankBranchID);
			copy_string_to_array(BrokerBranchID, native.BrokerBranchID);
			copy_string_to_array(TradeDate, native.TradeDate);
			copy_string_to_array(TradeTime, native.TradeTime);
			copy_string_to_array(BankSerial, native.BankSerial);
			copy_string_to_array(TradingDay, native.TradingDay);
			native.PlateSerial = PlateSerial;
			native.LastFragment = LastFragment;
			native.SessionID = SessionID;
			copy_string_to_array(CustomerName, native.CustomerName);
			native.IdCardType = IdCardType;
			copy_string_to_array(IdentifiedCardNo, native.IdentifiedCardNo);
			native.CustType = CustType;
			copy_string_to_array(BankAccount, native.BankAccount);
			copy_string_to_array(BankPassWord, native.BankPassWord);
			copy_string_to_array(AccountID, native.AccountID);
			copy_string_to_array(Password, native.Password);
			native.InstallID = InstallID;
			native.FutureSerial = FutureSerial;
			copy_string_to_array(UserID, native.UserID);
			native.VerifyCertNoFlag = VerifyCertNoFlag;
			copy_string_to_array(CurrencyID, native.CurrencyID);
			native.TradeAmount = TradeAmount;
			native.FutureFetchAmount = FutureFetchAmount;
			native.FeePayFlag = FeePayFlag;
			native.CustFee = CustFee;
			native.BrokerFee = BrokerFee;
			copy_string_to_array(Message, native.Message);
			copy_string_to_array(Digest, native.Digest);
			native.BankAccType = BankAccType;
			copy_string_to_array(DeviceID, native.DeviceID);
			native.BankSecuAccType = BankSecuAccType;
			copy_string_to_array(BrokerIDByBank, native.BrokerIDByBank);
			copy_string_to_array(BankSecuAcc, native.BankSecuAcc);
			native.BankPwdFlag = BankPwdFlag;
			native.SecuPwdFlag = SecuPwdFlag;
			copy_string_to_array(OperNo, native.OperNo);
			native.RequestID = RequestID;
			native.TID = TID;
			native.TransferStatus = TransferStatus;
			copy_string_to_array(LongCustomerName, native.LongCustomerName);
			return native;
		}
		///业务功能码
		String^ TradeCode;
		///银行代码
		String^ BankID;
		///银行分支机构代码
		String^ BankBranchID;
		///期商代码
		String^ BrokerID;
		///期商分支机构代码
		String^ BrokerBranchID;
		///交易日期
		String^ TradeDate;
		///交易时间
		String^ TradeTime;
		///银行流水号
		String^ BankSerial;
		///交易系统日期 
		String^ TradingDay;
		///银期平台消息流水号
		Int32 PlateSerial;
		///最后分片标志
		char LastFragment;
		///会话号
		Int32 SessionID;
		///客户姓名
		String^ CustomerName;
		///证件类型
		char IdCardType;
		///证件号码
		String^ IdentifiedCardNo;
		///客户类型
		char CustType;
		///银行帐号
		String^ BankAccount;
		///银行密码
		String^ BankPassWord;
		///投资者帐号
		String^ AccountID;
		///期货密码
		String^ Password;
		///安装编号
		Int32 InstallID;
		///期货公司流水号
		Int32 FutureSerial;
		///用户标识
		String^ UserID;
		///验证客户证件号码标志
		char VerifyCertNoFlag;
		///币种代码
		String^ CurrencyID;
		///转帐金额
		double TradeAmount;
		///期货可取金额
		double FutureFetchAmount;
		///费用支付标志
		char FeePayFlag;
		///应收客户费用
		double CustFee;
		///应收期货公司费用
		double BrokerFee;
		///发送方给接收方的消息
		String^ Message;
		///摘要
		String^ Digest;
		///银行帐号类型
		char BankAccType;
		///渠道标志
		String^ DeviceID;
		///期货单位帐号类型
		char BankSecuAccType;
		///期货公司银行编码
		String^ BrokerIDByBank;
		///期货单位帐号
		String^ BankSecuAcc;
		///银行密码标志
		char BankPwdFlag;
		///期货资金密码核对标志
		char SecuPwdFlag;
		///交易柜员
		String^ OperNo;
		///请求编号
		Int32 RequestID;
		///交易ID
		Int32 TID;
		///转账交易状态
		char TransferStatus;
		///长客户姓名
		String^ LongCustomerName;
	};
	public ref class TradingAccountPasswordUpdateRequestData
	{
	public:
		CThostFtdcTradingAccountPasswordUpdateField  ToNative()
		{
			CThostFtdcTradingAccountPasswordUpdateField  native = { 0 };
			copy_string_to_array(BrokerID, native.BrokerID);
			copy_string_to_array(AccountID, native.AccountID);
			copy_string_to_array(OldPassword, native.OldPassword);
			copy_string_to_array(NewPassword, native.NewPassword);
			copy_string_to_array(CurrencyID, native.CurrencyID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者帐号
		String^ AccountID;
		///原来的口令
		String^ OldPassword;
		///新的口令
		String^ NewPassword;
		///币种代码
		String^ CurrencyID;
	};
	public ref class QueryBankAccountMoneyByFutureRequestData
	{
	public:
		CThostFtdcReqQueryAccountField ToNative()
		{
			CThostFtdcReqQueryAccountField native = { 0 };
			copy_string_to_array(BrokerID, native.BrokerID);
			copy_string_to_array(TradeCode, native.TradeCode);
			copy_string_to_array(BankID, native.BankID);
			copy_string_to_array(BankBranchID, native.BankBranchID);
			copy_string_to_array(BrokerID, native.BrokerID);
			copy_string_to_array(BrokerBranchID, native.BrokerBranchID);
			copy_string_to_array(TradeDate, native.TradeDate);
			copy_string_to_array(TradeTime, native.TradeTime);
			copy_string_to_array(BankSerial, native.BankSerial);
			copy_string_to_array(TradingDay, native.TradingDay);
			native.PlateSerial = PlateSerial;
			native.LastFragment = LastFragment;
			native.SessionID = SessionID;
			copy_string_to_array(CustomerName, native.CustomerName);
			native.IdCardType = IdCardType;
			copy_string_to_array(IdentifiedCardNo, native.IdentifiedCardNo);
			native.CustType = CustType;
			copy_string_to_array(BankAccount, native.BankAccount);
			copy_string_to_array(BankPassWord, native.BankPassWord);
			copy_string_to_array(AccountID, native.AccountID);
			copy_string_to_array(Password, native.Password);
			native.FutureSerial = FutureSerial;
			native.InstallID = InstallID;
			copy_string_to_array(UserID, native.UserID);
			native.VerifyCertNoFlag = VerifyCertNoFlag;
			copy_string_to_array(CurrencyID, native.CurrencyID);
			copy_string_to_array(Digest, native.Digest);
			native.BankAccType = BankAccType;
			copy_string_to_array(DeviceID, native.DeviceID);
			native.BankSecuAccType = BankSecuAccType;
			copy_string_to_array(BrokerIDByBank, native.BrokerIDByBank);
			copy_string_to_array(BankSecuAcc, native.BankSecuAcc);
			native.BankPwdFlag = BankPwdFlag;
			native.SecuPwdFlag = SecuPwdFlag;
			copy_string_to_array(OperNo, native.OperNo);
			native.RequestID = RequestID;
			native.TID = TID;
			copy_string_to_array(LongCustomerName, native.LongCustomerName);
			return native;
		}
		///业务功能码
		String^ TradeCode;
		///银行代码
		String^ BankID;
		///银行分支机构代码
		String^ BankBranchID;
		///期商代码
		String^ BrokerID;
		///期商分支机构代码
		String^ BrokerBranchID;
		///交易日期
		String^ TradeDate;
		///交易时间
		String^ TradeTime;
		///银行流水号
		String^ BankSerial;
		///交易系统日期 
		String^ TradingDay;
		///银期平台消息流水号
		Int32 PlateSerial;
		///最后分片标志
		char LastFragment;
		///会话号
		Int32 SessionID;
		///客户姓名
		String^ CustomerName;
		///证件类型
		char IdCardType;
		///证件号码
		String^ IdentifiedCardNo;
		///客户类型
		char CustType;
		///银行帐号
		String^ BankAccount;
		///银行密码
		String^ BankPassWord;
		///投资者帐号
		String^ AccountID;
		///期货密码
		String^ Password;
		///期货公司流水号
		Int32 FutureSerial;
		///安装编号
		Int32 InstallID;
		///用户标识
		String^ UserID;
		///验证客户证件号码标志
		char VerifyCertNoFlag;
		///币种代码
		String^ CurrencyID;
		///摘要
		String^ Digest;
		///银行帐号类型
		char BankAccType;
		///渠道标志
		String^ DeviceID;
		///期货单位帐号类型
		char BankSecuAccType;
		///期货公司银行编码
		String^ BrokerIDByBank;
		///期货单位帐号
		String^ BankSecuAcc;
		///银行密码标志
		char BankPwdFlag;
		///期货资金密码核对标志
		char SecuPwdFlag;
		///交易柜员
		String^ OperNo;
		///请求编号
		Int32 RequestID;
		///交易ID
		Int32 TID;
		///长客户姓名
		String^ LongCustomerName;
	};
	public ref class UserPasswordUpdateRequestData
	{
	public:
		CThostFtdcUserPasswordUpdateField  ToNative()
		{
			CThostFtdcUserPasswordUpdateField  native = { 0 };
			///经纪公司代码
			copy_string_to_array(BrokerID, native.BrokerID);
			///用户代码
			copy_string_to_array(UserID, native.UserID);
			///原来的口令
			copy_string_to_array(OldPassword, native.OldPassword);
			///新的口令
			copy_string_to_array(NewPassword, native.NewPassword);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///用户代码
		String^ UserID;
		///原来的口令
		String^ OldPassword;
		///新的口令
		String^ NewPassword;
	};
	public ref class QueryMaxOrderVolumeRequestData
	{
	public:
		CThostFtdcQueryMaxOrderVolumeField  ToNative()
		{
			CThostFtdcQueryMaxOrderVolumeField  native = { 0 };
			///经纪公司代码
			copy_string_to_array(BrokerID, native.BrokerID);
			///投资者代码
			copy_string_to_array(InvestorID, native.InvestorID);
			///合约代码
			copy_string_to_array(InstrumentID, native.InstrumentID);
			///买卖方向
			native.Direction = Direction;
			///开平标志
			native.OffsetFlag = OffsetFlag;
			///投机套保标志
			native.HedgeFlag = HedgeFlag;
			///最大允许报单数量
			native.MaxVolume = MaxVolume;
			///交易所代码
			copy_string_to_array(ExchangeID, native.ExchangeID);
			///投资单元代码
			copy_string_to_array(InvestUnitID, native.InvestUnitID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///合约代码
		String^ InstrumentID;
		///买卖方向
		char Direction;
		///开平标志
		char OffsetFlag;
		///投机套保标志
		char HedgeFlag;
		///最大允许报单数量
		Int32 MaxVolume;
		///交易所代码
		String^ ExchangeID;
		///投资单元代码
		String^ InvestUnitID;
	};
	public ref class TradeRequestData
	{
	public:
		CThostFtdcQryTradeField  ToNative()
		{
			CThostFtdcQryTradeField  native = { 0 };
			///经纪公司代码
			copy_string_to_array(BrokerID, native.BrokerID);
			///投资者代码
			copy_string_to_array(InvestorID, native.InvestorID);
			///合约代码
			copy_string_to_array(InstrumentID, native.InstrumentID);
			///交易所代码
			copy_string_to_array(ExchangeID, native.ExchangeID);
			///成交编号
			copy_string_to_array(TradeID, native.TradeID);
			///开始时间
			copy_string_to_array(TradeTimeStart, native.TradeTimeStart);
			///结束时间
			copy_string_to_array(TradeTimeEnd, native.TradeTimeEnd);
			///投资单元代码
			copy_string_to_array(InvestUnitID, native.InvestUnitID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///合约代码
		String^ InstrumentID;
		///交易所代码
		String^ ExchangeID;
		///成交编号
		String^ TradeID;
		///开始时间
		String^ TradeTimeStart;
		///结束时间
		String^ TradeTimeEnd;
		///投资单元代码
		String^ InvestUnitID;
	};
	public ref class InvestorPositionDetailRequestData
	{
	public:
		CThostFtdcQryInvestorPositionDetailField  ToNative()
		{
			CThostFtdcQryInvestorPositionDetailField  native = { 0 };
			///经纪公司代码
			copy_string_to_array(BrokerID, native.BrokerID);
			///投资者代码
			copy_string_to_array(InvestorID, native.InvestorID);
			///合约代码
			copy_string_to_array(InstrumentID, native.InstrumentID);
			///交易所代码
			copy_string_to_array(ExchangeID, native.ExchangeID);
			///投资单元代码
			copy_string_to_array(InvestUnitID, native.InvestUnitID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///合约代码
		String^ InstrumentID;
		///交易所代码
		String^ ExchangeID;
		///投资单元代码
		String^ InvestUnitID;
	};
	public ref class InvestorRequestData
	{
	public:
		CThostFtdcQryInvestorField  ToNative()
		{
			CThostFtdcQryInvestorField  native = { 0 };
			///经纪公司代码
			copy_string_to_array(BrokerID, native.BrokerID);
			///投资者代码
			copy_string_to_array(InvestorID, native.InvestorID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
	};
	public ref class TradingCodeRequestData
	{
	public:
		CThostFtdcQryTradingCodeField  ToNative()
		{
			CThostFtdcQryTradingCodeField  native = { 0 };
			///经纪公司代码
			copy_string_to_array(BrokerID, native.BrokerID);
			///投资者代码
			copy_string_to_array(InvestorID, native.InvestorID);
			///交易所代码
			copy_string_to_array(ExchangeID, native.ExchangeID);
			///客户代码
			copy_string_to_array(ClientID, native.ClientID);
			///交易编码类型
			native.ClientIDType = ClientIDType;
			///投资单元代码
			copy_string_to_array(InvestUnitID, native.InvestUnitID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///交易所代码
		String^ ExchangeID;
		///客户代码
		String^ ClientID;
		///交易编码类型
		char ClientIDType;
		///投资单元代码
		String^ InvestUnitID;
	};
	public ref class InstrumentMarginRateRequestData
	{
	public:
		CThostFtdcQryInstrumentMarginRateField  ToNative()
		{
			CThostFtdcQryInstrumentMarginRateField  native = { 0 };
			///经纪公司代码
			copy_string_to_array(BrokerID, native.BrokerID);
			///投资者代码
			copy_string_to_array(InvestorID, native.InvestorID);
			///合约代码
			copy_string_to_array(InstrumentID, native.InstrumentID);
			///投机套保标志
			native.HedgeFlag = HedgeFlag;
			///交易所代码
			copy_string_to_array(ExchangeID, native.ExchangeID);
			///投资单元代码
			copy_string_to_array(InvestUnitID, native.InvestUnitID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///合约代码
		String^ InstrumentID;
		///投机套保标志
		char HedgeFlag;
		///交易所代码
		String^ ExchangeID;
		///投资单元代码
		String^ InvestUnitID;
	};
	public ref class InstrumentCommissionRateRequestData
	{
	public:
		CThostFtdcQryInstrumentCommissionRateField  ToNative()
		{
			CThostFtdcQryInstrumentCommissionRateField  native = { 0 };
			///经纪公司代码
			copy_string_to_array(BrokerID, native.BrokerID);
			///投资者代码
			copy_string_to_array(InvestorID, native.InvestorID);
			///合约代码
			copy_string_to_array(InstrumentID, native.InstrumentID);
			///交易所代码
			copy_string_to_array(ExchangeID, native.ExchangeID);
			///投资单元代码
			copy_string_to_array(InvestUnitID, native.InvestUnitID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///合约代码
		String^ InstrumentID;
		///交易所代码
		String^ ExchangeID;
		///投资单元代码
		String^ InvestUnitID;
	};
	public ref class InstrumentRequestData
	{
	public:
		CThostFtdcQryInstrumentField  ToNative()
		{
			CThostFtdcQryInstrumentField  native = { 0 };
			///合约代码
			copy_string_to_array(InstrumentID, native.InstrumentID);
			///交易所代码
			copy_string_to_array(ExchangeID, native.ExchangeID);
			///合约在交易所的代码
			copy_string_to_array(ExchangeInstID, native.ExchangeInstID);
			///产品代码
			copy_string_to_array(ProductID, native.ProductID);
			return native;
		}
		///合约代码
		String^ InstrumentID;
		///交易所代码
		String^ ExchangeID;
		///合约在交易所的代码
		String^ ExchangeInstID;
		///产品代码
		String^ ProductID;
	};
	public ref class QrySettlementInfoRequestData
	{
	public:
		CThostFtdcQrySettlementInfoField  ToNative()
		{
			CThostFtdcQrySettlementInfoField  native = { 0 };
			///经纪公司代码
			copy_string_to_array(BrokerID, native.BrokerID);
			///投资者代码
			copy_string_to_array(InvestorID, native.InvestorID);
			///交易日
			copy_string_to_array(TradingDay, native.TradingDay);
			///投资者帐号
			copy_string_to_array(AccountID, native.AccountID);
			///币种代码
			copy_string_to_array(CurrencyID, native.CurrencyID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///交易日
		String^ TradingDay;
		///投资者帐号
		String^ AccountID;
		///币种代码
		String^ CurrencyID;
	};
	public ref class QrySettlementInfoConfirmRequestData
	{
	public:
		CThostFtdcQrySettlementInfoConfirmField  ToNative()
		{
			CThostFtdcQrySettlementInfoConfirmField  native = { 0 };
			///经纪公司代码
			copy_string_to_array(BrokerID, native.BrokerID);
			///投资者代码
			copy_string_to_array(InvestorID, native.InvestorID);
			///投资者帐号
			copy_string_to_array(AccountID, native.AccountID);
			///币种代码
			copy_string_to_array(CurrencyID, native.CurrencyID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///投资者帐号
		String^ AccountID;
		///币种代码
		String^ CurrencyID;
	};
	public ref class SettlementInfoConfirmRequestData
	{
	public:
		CThostFtdcSettlementInfoConfirmField  ToNative()
		{
			CThostFtdcSettlementInfoConfirmField  native = { 0 };
			///经纪公司代码
			copy_string_to_array(BrokerID, native.BrokerID);
			///投资者代码
			copy_string_to_array(InvestorID, native.InvestorID);
			///确认日期
			copy_string_to_array(ConfirmDate, native.ConfirmDate);
			///确认时间
			copy_string_to_array(ConfirmTime, native.ConfirmTime);
			///结算编号
			native.SettlementID = SettlementID;
			///投资者帐号
			copy_string_to_array(AccountID, native.AccountID);
			///币种代码
			copy_string_to_array(CurrencyID, native.CurrencyID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///确认日期
		String^ ConfirmDate;
		///确认时间
		String^ ConfirmTime;
		///结算编号
		Int32 SettlementID;
		///投资者帐号
		String^ AccountID;
		///币种代码
		String^ CurrencyID;
	};
	public ref class NoticeRequestData
	{
	public:
		CThostFtdcQryNoticeField  ToNative()
		{
			CThostFtdcQryNoticeField  native = { 0 };
			///经纪公司代码
			copy_string_to_array(BrokerID, native.BrokerID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
	};
	public ref class TradingNoticeRequestData
	{
	public:
		CThostFtdcQryTradingNoticeField  ToNative()
		{
			CThostFtdcQryTradingNoticeField  native = { 0 };
			///经纪公司代码
			copy_string_to_array(BrokerID, native.BrokerID);
			///投资者代码
			copy_string_to_array(InvestorID, native.InvestorID);
			///投资单元代码
			copy_string_to_array(InvestUnitID, native.InvestUnitID);
			return native;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///投资单元代码
		String^ InvestUnitID;
	};
	public ref class AccountregisterResponseData
	{
	public:
		static AccountregisterResponseData^ FromNative(CThostFtdcAccountregisterField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rsp = gcnew AccountregisterResponseData;
			rsp->TradeDay = U8ToClr(native->TradeDay);
			rsp->BankID = U8ToClr(native->BankID);
			rsp->BankBranchID = U8ToClr(native->BankBranchID);
			rsp->BankAccount = U8ToClr(native->BankAccount);
			rsp->BrokerID = U8ToClr((native->BrokerID));
			rsp->BrokerBranchID = U8ToClr((native->BrokerBranchID));
			rsp->AccountID = U8ToClr((native->AccountID));
			rsp->IdCardType = native->IdCardType;
			rsp->IdentifiedCardNo = U8ToClr((native->IdentifiedCardNo));
			rsp->CustomerName = AnsiToClr((native->CustomerName));
			rsp->CurrencyID = U8ToClr((native->CurrencyID));
			rsp->OpenOrDestroy = native->OpenOrDestroy;
			rsp->RegDate = U8ToClr((native->RegDate));
			rsp->OutDate = U8ToClr((native->OutDate));
			rsp->TID = native->TID;
			rsp->CustType = native->CustType;
			rsp->BankAccType = native->BankAccType;
			rsp->LongCustomerName = AnsiToClr((native->LongCustomerName));
			return rsp;
		}
		///交易日期
		String^ TradeDay;
		///银行编码
		String^ BankID;
		///银行分支机构编码
		String^ BankBranchID;
		///银行帐号
		String^ BankAccount;
		///期货公司编码
		String^ BrokerID;
		///期货公司分支机构编码
		String^ BrokerBranchID;
		///投资者帐号
		String^ AccountID;
		///证件类型
		char IdCardType;
		///证件号码
		String^ IdentifiedCardNo;
		///客户姓名
		String^ CustomerName;
		///币种代码
		String^ CurrencyID;
		///开销户类别
		char OpenOrDestroy;
		///签约日期
		String^ RegDate;
		///解约日期
		String^ OutDate;
		///交易ID
		int TID;
		///客户类型
		char CustType;
		///银行帐号类型
		char BankAccType;
		///长客户姓名
		String^ LongCustomerName;
	};
	public ref class ContractBankResponseData
	{
	public:
		static ContractBankResponseData^ FromNative(CThostFtdcContractBankField    * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rsp = gcnew ContractBankResponseData;
			rsp->BrokerID = U8ToClr(native->BrokerID);
			rsp->BankID = U8ToClr(native->BankID);
			rsp->BankBrchID = U8ToClr(native->BankBrchID);
			rsp->BankName = AnsiToClr(native->BankName);
			return rsp;
		}
		///经纪公司代码
		String^ BrokerID;
		///银行代码
		String^ BankID;
		///银行分中心代码
		String^ BankBrchID;
		///银行名称
		String^ BankName;
	};
	public ref class FromBankToFutureByFutureResponseData
	{
	public:
		static FromBankToFutureByFutureResponseData^ FromNative(CThostFtdcReqTransferField  * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rsp = gcnew FromBankToFutureByFutureResponseData;
			rsp->TradeCode = U8ToClr((native->TradeCode));
			rsp->BankID = U8ToClr((native->BankID));
			rsp->BankBranchID = U8ToClr((native->BankBranchID));
			rsp->BrokerID = U8ToClr((native->BrokerID));
			rsp->BrokerBranchID = U8ToClr((native->BrokerBranchID));
			rsp->TradeDate = U8ToClr((native->TradeDate));
			rsp->TradeTime = U8ToClr((native->TradeTime));
			rsp->BankSerial = U8ToClr((native->BankSerial));
			rsp->TradingDay = U8ToClr((native->TradingDay));
			rsp->PlateSerial = native->PlateSerial;
			rsp->LastFragment = native->LastFragment;
			rsp->SessionID = native->SessionID;
			rsp->CustomerName = AnsiToClr((native->CustomerName));
			rsp->IdCardType = native->IdCardType;
			rsp->IdentifiedCardNo = U8ToClr((native->IdentifiedCardNo));
			rsp->CustType = native->CustType;
			rsp->BankAccount = U8ToClr((native->BankAccount));
			rsp->BankPassWord = U8ToClr((native->BankPassWord));
			rsp->AccountID = U8ToClr((native->AccountID));
			rsp->Password = U8ToClr((native->Password));
			rsp->InstallID = native->InstallID;
			rsp->FutureSerial = native->FutureSerial;
			rsp->UserID = U8ToClr((native->UserID));
			rsp->VerifyCertNoFlag = native->VerifyCertNoFlag;
			rsp->CurrencyID = U8ToClr((native->CurrencyID));
			rsp->TradeAmount = native->TradeAmount;
			rsp->FutureFetchAmount = native->FutureFetchAmount;
			rsp->FeePayFlag = native->FeePayFlag;
			rsp->CustFee = native->CustFee;
			rsp->BrokerFee = native->BrokerFee;
			rsp->Message = AnsiToClr((native->Message));
			rsp->Digest = U8ToClr((native->Digest));
			rsp->BankAccType = native->BankAccType;
			rsp->DeviceID = U8ToClr((native->DeviceID));
			rsp->BankSecuAccType = native->BankSecuAccType;
			rsp->BrokerIDByBank = U8ToClr((native->BrokerIDByBank));
			rsp->BankSecuAcc = U8ToClr((native->BankSecuAcc));
			rsp->BankPwdFlag = native->BankPwdFlag;
			rsp->SecuPwdFlag = native->SecuPwdFlag;
			rsp->OperNo = U8ToClr((native->OperNo));
			rsp->RequestID = native->RequestID;
			rsp->TID = native->TID;
			rsp->TransferStatus = native->TransferStatus;
			rsp->LongCustomerName = AnsiToClr((native->LongCustomerName));
			return rsp;
		}
		///业务功能码
		String^ TradeCode;
		///银行代码
		String^ BankID;
		///银行分支机构代码
		String^ BankBranchID;
		///期商代码
		String^ BrokerID;
		///期商分支机构代码
		String^ BrokerBranchID;
		///交易日期
		String^ TradeDate;
		///交易时间
		String^ TradeTime;
		///银行流水号
		String^ BankSerial;
		///交易系统日期 
		String^ TradingDay;
		///银期平台消息流水号
		int PlateSerial;
		///最后分片标志
		char LastFragment;
		///会话号
		int SessionID;
		///客户姓名
		String^ CustomerName;
		///证件类型
		char IdCardType;
		///证件号码
		String^ IdentifiedCardNo;
		///客户类型
		char CustType;
		///银行帐号
		String^ BankAccount;
		///银行密码
		String^ BankPassWord;
		///投资者帐号
		String^ AccountID;
		///期货密码
		String^ Password;
		///安装编号
		int InstallID;
		///期货公司流水号
		int FutureSerial;
		///用户标识
		String^ UserID;
		///验证客户证件号码标志
		char VerifyCertNoFlag;
		///币种代码
		String^ CurrencyID;
		///转帐金额
		double TradeAmount;
		///期货可取金额
		double FutureFetchAmount;
		///费用支付标志
		double FeePayFlag;
		///应收客户费用
		double CustFee;
		///应收期货公司费用
		double BrokerFee;
		///发送方给接收方的消息
		String^ Message;
		///摘要
		String^ Digest;
		///银行帐号类型
		double BankAccType;
		///渠道标志
		String^ DeviceID;
		///期货单位帐号类型
		char BankSecuAccType;
		///期货公司银行编码
		String^ BrokerIDByBank;
		///期货单位帐号
		String^ BankSecuAcc;
		///银行密码标志
		char BankPwdFlag;
		///期货资金密码核对标志
		char SecuPwdFlag;
		///交易柜员
		String^ OperNo;
		///请求编号
		int RequestID;
		///交易ID
		int TID;
		///转账交易状态
		char TransferStatus;
		///长客户姓名
		String^ LongCustomerName;
	};
	public ref class RtnFromBankToFutureByFutureResponseData
	{
	public:
		static RtnFromBankToFutureByFutureResponseData^ FromNative(CThostFtdcRspTransferField   * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rsp = gcnew RtnFromBankToFutureByFutureResponseData;
			rsp->TradeCode = U8ToClr((native->TradeCode));
			rsp->BankID = U8ToClr((native->BankID));
			rsp->BankBranchID = U8ToClr((native->BankBranchID));
			rsp->BrokerID = U8ToClr((native->BrokerID));
			rsp->BrokerBranchID = U8ToClr((native->BrokerBranchID));
			rsp->TradeDate = U8ToClr((native->TradeDate));
			rsp->TradeTime = U8ToClr((native->TradeTime));
			rsp->BankSerial = U8ToClr((native->BankSerial));
			rsp->TradingDay = U8ToClr((native->TradingDay));
			rsp->PlateSerial = native->PlateSerial;
			rsp->LastFragment = native->LastFragment;
			rsp->SessionID = native->SessionID;
			rsp->CustomerName = AnsiToClr((native->CustomerName));
			rsp->IdCardType = native->IdCardType;
			rsp->IdentifiedCardNo = U8ToClr((native->IdentifiedCardNo));
			rsp->CustType = native->CustType;
			rsp->BankAccount = U8ToClr((native->BankAccount));
			rsp->BankPassWord = U8ToClr((native->BankPassWord));
			rsp->AccountID = U8ToClr((native->AccountID));
			rsp->Password = U8ToClr((native->Password));
			rsp->InstallID = native->InstallID;
			rsp->FutureSerial = native->FutureSerial;
			rsp->UserID = U8ToClr((native->UserID));
			rsp->VerifyCertNoFlag = native->VerifyCertNoFlag;
			rsp->CurrencyID = U8ToClr((native->CurrencyID));
			rsp->TradeAmount = native->TradeAmount;
			rsp->FutureFetchAmount = native->FutureFetchAmount;
			rsp->FeePayFlag = native->FeePayFlag;
			rsp->CustFee = native->CustFee;
			rsp->BrokerFee = native->BrokerFee;
			rsp->Message = AnsiToClr((native->Message));
			rsp->Digest = U8ToClr((native->Digest));
			rsp->BankAccType = native->BankAccType;
			rsp->DeviceID = U8ToClr((native->DeviceID));
			rsp->BankSecuAccType = native->BankSecuAccType;
			rsp->BrokerIDByBank = U8ToClr((native->BrokerIDByBank));
			rsp->BankSecuAcc = U8ToClr((native->BankSecuAcc));
			rsp->BankPwdFlag = native->BankPwdFlag;
			rsp->SecuPwdFlag = native->SecuPwdFlag;
			rsp->OperNo = U8ToClr((native->OperNo));
			rsp->RequestID = native->RequestID;
			rsp->TID = native->TID;
			rsp->TransferStatus = native->TransferStatus;
			rsp->ErrorID = native->ErrorID;
			rsp->ErrorMsg = AnsiToClr((native->ErrorMsg));
			rsp->LongCustomerName = AnsiToClr((native->LongCustomerName));
			return rsp;
		}
		///业务功能码
		String^ TradeCode;
		///银行代码
		String^ BankID;
		///银行分支机构代码
		String^ BankBranchID;
		///期商代码
		String^ BrokerID;
		///期商分支机构代码
		String^ BrokerBranchID;
		///交易日期
		String^ TradeDate;
		///交易时间
		String^ TradeTime;
		///银行流水号
		String^ BankSerial;
		///交易系统日期 
		String^ TradingDay;
		///银期平台消息流水号
		int PlateSerial;
		///最后分片标志
		char LastFragment;
		///会话号
		int SessionID;
		///客户姓名
		String^ CustomerName;
		///证件类型
		char IdCardType;
		///证件号码
		String^ IdentifiedCardNo;
		///客户类型
		char CustType;
		///银行帐号
		String^ BankAccount;
		///银行密码
		String^ BankPassWord;
		///投资者帐号
		String^ AccountID;
		///期货密码
		String^ Password;
		///安装编号
		int InstallID;
		///期货公司流水号
		int FutureSerial;
		///用户标识
		String^ UserID;
		///验证客户证件号码标志
		char VerifyCertNoFlag;
		///币种代码
		String^ CurrencyID;
		///转帐金额
		double TradeAmount;
		///期货可取金额
		double FutureFetchAmount;
		///费用支付标志
		double FeePayFlag;
		///应收客户费用
		double CustFee;
		///应收期货公司费用
		double BrokerFee;
		///发送方给接收方的消息
		String^ Message;
		///摘要
		String^ Digest;
		///银行帐号类型
		double BankAccType;
		///渠道标志
		String^ DeviceID;
		///期货单位帐号类型
		char BankSecuAccType;
		///期货公司银行编码
		String^ BrokerIDByBank;
		///期货单位帐号
		String^ BankSecuAcc;
		///银行密码标志
		char BankPwdFlag;
		///期货资金密码核对标志
		char SecuPwdFlag;
		///交易柜员
		String^ OperNo;
		///请求编号
		int RequestID;
		///交易ID
		int TID;
		///转账交易状态
		char TransferStatus;
		///错误代码
		int ErrorID;
		///错误信息
		String^ ErrorMsg;
		///长客户姓名
		String^ LongCustomerName;
	};
	public ref class FromFutureToBankByFutureResponseData
	{
	public:
		static FromFutureToBankByFutureResponseData^ FromNative(CThostFtdcReqTransferField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rsp = gcnew FromFutureToBankByFutureResponseData;
			rsp->TradeCode = U8ToClr((native->TradeCode));
			rsp->BankID = U8ToClr((native->BankID));
			rsp->BankBranchID = U8ToClr((native->BankBranchID));
			rsp->BrokerID = U8ToClr((native->BrokerID));
			rsp->BrokerBranchID = U8ToClr((native->BrokerBranchID));
			rsp->TradeDate = U8ToClr((native->TradeDate));
			rsp->TradeTime = U8ToClr((native->TradeTime));
			rsp->BankSerial = U8ToClr((native->BankSerial));
			rsp->TradingDay = U8ToClr((native->TradingDay));
			rsp->PlateSerial = native->PlateSerial;
			rsp->LastFragment = native->LastFragment;
			rsp->SessionID = native->SessionID;
			rsp->CustomerName = AnsiToClr((native->CustomerName));
			rsp->IdCardType = native->IdCardType;
			rsp->IdentifiedCardNo = U8ToClr((native->IdentifiedCardNo));
			rsp->CustType = native->CustType;
			rsp->BankAccount = U8ToClr((native->BankAccount));
			rsp->BankPassWord = U8ToClr((native->BankPassWord));
			rsp->AccountID = U8ToClr((native->AccountID));
			rsp->Password = U8ToClr((native->Password));
			rsp->InstallID = native->InstallID;
			rsp->FutureSerial = native->FutureSerial;
			rsp->UserID = U8ToClr((native->UserID));
			rsp->VerifyCertNoFlag = native->VerifyCertNoFlag;
			rsp->CurrencyID = U8ToClr((native->CurrencyID));
			rsp->TradeAmount = native->TradeAmount;
			rsp->FutureFetchAmount = native->FutureFetchAmount;
			rsp->FeePayFlag = native->FeePayFlag;
			rsp->CustFee = native->CustFee;
			rsp->BrokerFee = native->BrokerFee;
			rsp->Message = AnsiToClr((native->Message));
			rsp->Digest = U8ToClr((native->Digest));
			rsp->BankAccType = native->BankAccType;
			rsp->DeviceID = U8ToClr((native->DeviceID));
			rsp->BankSecuAccType = native->BankSecuAccType;
			rsp->BrokerIDByBank = U8ToClr((native->BrokerIDByBank));
			rsp->BankSecuAcc = U8ToClr((native->BankSecuAcc));
			rsp->BankPwdFlag = native->BankPwdFlag;
			rsp->SecuPwdFlag = native->SecuPwdFlag;
			rsp->OperNo = U8ToClr((native->OperNo));
			rsp->RequestID = native->RequestID;
			rsp->TID = native->TID;
			rsp->TransferStatus = native->TransferStatus;
			rsp->LongCustomerName = AnsiToClr((native->LongCustomerName));
			return rsp;
		}
		///业务功能码
		String^ TradeCode;
		///银行代码
		String^ BankID;
		///银行分支机构代码
		String^ BankBranchID;
		///期商代码
		String^ BrokerID;
		///期商分支机构代码
		String^ BrokerBranchID;
		///交易日期
		String^ TradeDate;
		///交易时间
		String^ TradeTime;
		///银行流水号
		String^ BankSerial;
		///交易系统日期 
		String^ TradingDay;
		///银期平台消息流水号
		int PlateSerial;
		///最后分片标志
		char LastFragment;
		///会话号
		int SessionID;
		///客户姓名
		String^ CustomerName;
		///证件类型
		char IdCardType;
		///证件号码
		String^ IdentifiedCardNo;
		///客户类型
		char CustType;
		///银行帐号
		String^ BankAccount;
		///银行密码
		String^ BankPassWord;
		///投资者帐号
		String^ AccountID;
		///期货密码
		String^ Password;
		///安装编号
		int InstallID;
		///期货公司流水号
		int FutureSerial;
		///用户标识
		String^ UserID;
		///验证客户证件号码标志
		char VerifyCertNoFlag;
		///币种代码
		String^ CurrencyID;
		///转帐金额
		double TradeAmount;
		///期货可取金额
		double FutureFetchAmount;
		///费用支付标志
		double FeePayFlag;
		///应收客户费用
		double CustFee;
		///应收期货公司费用
		double BrokerFee;
		///发送方给接收方的消息
		String^ Message;
		///摘要
		String^ Digest;
		///银行帐号类型
		double BankAccType;
		///渠道标志
		String^ DeviceID;
		///期货单位帐号类型
		char BankSecuAccType;
		///期货公司银行编码
		String^ BrokerIDByBank;
		///期货单位帐号
		String^ BankSecuAcc;
		///银行密码标志
		char BankPwdFlag;
		///期货资金密码核对标志
		char SecuPwdFlag;
		///交易柜员
		String^ OperNo;
		///请求编号
		int RequestID;
		///交易ID
		int TID;
		///转账交易状态
		char TransferStatus;
		///长客户姓名
		String^ LongCustomerName;
	};
	public ref class OnRtnFromFutureToBankByFutureResponseData
	{
	public:
		static OnRtnFromFutureToBankByFutureResponseData^ FromNative(CThostFtdcRspTransferField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rsp = gcnew OnRtnFromFutureToBankByFutureResponseData;
			rsp->TradeCode = U8ToClr((native->TradeCode));
			rsp->BankID = U8ToClr((native->BankID));
			rsp->BankBranchID = U8ToClr((native->BankBranchID));
			rsp->BrokerID = U8ToClr((native->BrokerID));
			rsp->BrokerBranchID = U8ToClr((native->BrokerBranchID));
			rsp->TradeDate = U8ToClr((native->TradeDate));
			rsp->TradeTime = U8ToClr((native->TradeTime));
			rsp->BankSerial = U8ToClr((native->BankSerial));
			rsp->TradingDay = U8ToClr((native->TradingDay));
			rsp->PlateSerial = native->PlateSerial;
			rsp->LastFragment = native->LastFragment;
			rsp->SessionID = native->SessionID;
			rsp->CustomerName = AnsiToClr((native->CustomerName));
			rsp->IdCardType = native->IdCardType;
			rsp->IdentifiedCardNo = U8ToClr((native->IdentifiedCardNo));
			rsp->CustType = native->CustType;
			rsp->BankAccount = U8ToClr((native->BankAccount));
			rsp->BankPassWord = U8ToClr((native->BankPassWord));
			rsp->AccountID = U8ToClr((native->AccountID));
			rsp->Password = U8ToClr((native->Password));
			rsp->InstallID = native->InstallID;
			rsp->FutureSerial = native->FutureSerial;
			rsp->UserID = U8ToClr((native->UserID));
			rsp->VerifyCertNoFlag = native->VerifyCertNoFlag;
			rsp->CurrencyID = U8ToClr((native->CurrencyID));
			rsp->TradeAmount = native->TradeAmount;
			rsp->FutureFetchAmount = native->FutureFetchAmount;
			rsp->FeePayFlag = native->FeePayFlag;
			rsp->CustFee = native->CustFee;
			rsp->BrokerFee = native->BrokerFee;
			rsp->Message = AnsiToClr((native->Message));
			rsp->Digest = U8ToClr((native->Digest));
			rsp->BankAccType = native->BankAccType;
			rsp->DeviceID = U8ToClr((native->DeviceID));
			rsp->BankSecuAccType = native->BankSecuAccType;
			rsp->BrokerIDByBank = U8ToClr((native->BrokerIDByBank));
			rsp->BankSecuAcc = U8ToClr((native->BankSecuAcc));
			rsp->BankPwdFlag = native->BankPwdFlag;
			rsp->SecuPwdFlag = native->SecuPwdFlag;
			rsp->OperNo = U8ToClr((native->OperNo));
			rsp->RequestID = native->RequestID;
			rsp->TID = native->TID;
			rsp->TransferStatus = native->TransferStatus;
			rsp->ErrorID = native->ErrorID;
			rsp->ErrorMsg = AnsiToClr((native->ErrorMsg));
			rsp->LongCustomerName = AnsiToClr((native->LongCustomerName));
			return rsp;
		}
		///业务功能码
		String^ TradeCode;
		///银行代码
		String^ BankID;
		///银行分支机构代码
		String^ BankBranchID;
		///期商代码
		String^ BrokerID;
		///期商分支机构代码
		String^ BrokerBranchID;
		///交易日期
		String^ TradeDate;
		///交易时间
		String^ TradeTime;
		///银行流水号
		String^ BankSerial;
		///交易系统日期 
		String^ TradingDay;
		///银期平台消息流水号
		int PlateSerial;
		///最后分片标志
		char LastFragment;
		///会话号
		int SessionID;
		///客户姓名
		String^ CustomerName;
		///证件类型
		char IdCardType;
		///证件号码
		String^ IdentifiedCardNo;
		///客户类型
		char CustType;
		///银行帐号
		String^ BankAccount;
		///银行密码
		String^ BankPassWord;
		///投资者帐号
		String^ AccountID;
		///期货密码
		String^ Password;
		///安装编号
		int InstallID;
		///期货公司流水号
		int FutureSerial;
		///用户标识
		String^ UserID;
		///验证客户证件号码标志
		char VerifyCertNoFlag;
		///币种代码
		String^ CurrencyID;
		///转帐金额
		double TradeAmount;
		///期货可取金额
		double FutureFetchAmount;
		///费用支付标志
		double FeePayFlag;
		///应收客户费用
		double CustFee;
		///应收期货公司费用
		double BrokerFee;
		///发送方给接收方的消息
		String^ Message;
		///摘要
		String^ Digest;
		///银行帐号类型
		double BankAccType;
		///渠道标志
		String^ DeviceID;
		///期货单位帐号类型
		char BankSecuAccType;
		///期货公司银行编码
		String^ BrokerIDByBank;
		///期货单位帐号
		String^ BankSecuAcc;
		///银行密码标志
		char BankPwdFlag;
		///期货资金密码核对标志
		char SecuPwdFlag;
		///交易柜员
		String^ OperNo;
		///请求编号
		int RequestID;
		///交易ID
		int TID;
		///转账交易状态
		char TransferStatus;
		///错误代码
		int ErrorID;
		///错误信息
		String^ ErrorMsg;
		///长客户姓名
		String^ LongCustomerName;
	};
	public ref class TradingAccountPasswordUpdateResponseData
	{
	public:
		static TradingAccountPasswordUpdateResponseData^ FromNative(CThostFtdcTradingAccountPasswordUpdateField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rsp = gcnew TradingAccountPasswordUpdateResponseData;
			rsp->BrokerID = U8ToClr((native->BrokerID));
			rsp->AccountID = U8ToClr((native->AccountID));
			rsp->OldPassword = U8ToClr((native->OldPassword));
			rsp->NewPassword = U8ToClr((native->NewPassword));
			rsp->CurrencyID = U8ToClr((native->CurrencyID));
			return rsp;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者帐号
		String^ AccountID;
		///原来的口令
		String^ OldPassword;
		///新的口令
		String^ NewPassword;
		///币种代码
		String^ CurrencyID;
	};
	public ref class QueryBankAccountMoneyByFutureResponseData
	{
	public:
		static QueryBankAccountMoneyByFutureResponseData^ FromNative(CThostFtdcReqQueryAccountField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rsp = gcnew QueryBankAccountMoneyByFutureResponseData;
			rsp->TradeCode = U8ToClr((native->TradeCode));
			rsp->BankID = U8ToClr((native->BankID));
			rsp->BankBranchID = U8ToClr((native->BankBranchID));
			rsp->BrokerID = U8ToClr((native->BrokerID));
			rsp->BrokerBranchID = U8ToClr((native->BrokerBranchID));
			rsp->TradeDate = U8ToClr((native->TradeDate));
			rsp->TradeTime = U8ToClr((native->TradeTime));
			rsp->BankSerial = U8ToClr((native->BankSerial));
			rsp->TradingDay = U8ToClr((native->TradingDay));
			rsp->PlateSerial = native->PlateSerial;
			rsp->LastFragment = native->LastFragment;
			rsp->SessionID = native->SessionID;
			rsp->CustomerName = AnsiToClr((native->CustomerName));
			rsp->IdCardType = native->IdCardType;
			rsp->IdentifiedCardNo = U8ToClr((native->IdentifiedCardNo));
			rsp->CustType = native->CustType;
			rsp->BankAccount = U8ToClr((native->BankAccount));
			rsp->BankPassWord = U8ToClr((native->BankPassWord));
			rsp->AccountID = U8ToClr((native->AccountID));
			rsp->Password = U8ToClr((native->Password));
			rsp->FutureSerial = native->FutureSerial;
			rsp->InstallID = native->InstallID;
			rsp->UserID = U8ToClr((native->UserID));
			rsp->VerifyCertNoFlag = native->VerifyCertNoFlag;
			rsp->CurrencyID = U8ToClr((native->CurrencyID));
			rsp->Digest = U8ToClr((native->Digest));
			rsp->BankAccType = native->BankAccType;
			rsp->DeviceID = U8ToClr((native->DeviceID));
			rsp->BankSecuAccType = native->BankSecuAccType;
			rsp->BrokerIDByBank = U8ToClr((native->BrokerIDByBank));
			rsp->BankSecuAcc = U8ToClr((native->BankSecuAcc));
			rsp->BankPwdFlag = native->BankPwdFlag;
			rsp->SecuPwdFlag = native->SecuPwdFlag;
			rsp->OperNo = U8ToClr((native->OperNo));
			rsp->RequestID = native->RequestID;
			rsp->TID = native->TID;
			rsp->LongCustomerName = AnsiToClr((native->LongCustomerName));
			return rsp;
		}
		///业务功能码
		String^ TradeCode;
		///银行代码
		String^ BankID;
		///银行分支机构代码
		String^ BankBranchID;
		///期商代码
		String^ BrokerID;
		///期商分支机构代码
		String^ BrokerBranchID;
		///交易日期
		String^ TradeDate;
		///交易时间
		String^ TradeTime;
		///银行流水号
		String^ BankSerial;
		///交易系统日期 
		String^ TradingDay;
		///银期平台消息流水号
		int PlateSerial;
		///最后分片标志
		char LastFragment;
		///会话号
		int SessionID;
		///客户姓名
		String^ CustomerName;
		///证件类型
		char IdCardType;
		///证件号码
		String^ IdentifiedCardNo;
		///客户类型
		char CustType;
		///银行帐号
		String^ BankAccount;
		///银行密码
		String^ BankPassWord;
		///投资者帐号
		String^ AccountID;
		///期货密码
		String^ Password;
		///期货公司流水号
		int FutureSerial;
		///安装编号
		int InstallID;
		///用户标识
		String^ UserID;
		///验证客户证件号码标志
		char VerifyCertNoFlag;
		///币种代码
		String^ CurrencyID;
		///摘要
		String^ Digest;
		///银行帐号类型
		double BankAccType;
		///渠道标志
		String^ DeviceID;
		///期货单位帐号类型
		char BankSecuAccType;
		///期货公司银行编码
		String^ BrokerIDByBank;
		///期货单位帐号
		String^ BankSecuAcc;
		///银行密码标志
		char BankPwdFlag;
		///期货资金密码核对标志
		char SecuPwdFlag;
		///交易柜员
		String^ OperNo;
		///请求编号
		int RequestID;
		///交易ID
		int TID;
		///长客户姓名
		String^ LongCustomerName;
	};

	public ref class RtnNotifyQueryAccountFieldResponseData
	{
	public:
		static RtnNotifyQueryAccountFieldResponseData^ FromNative(CThostFtdcNotifyQueryAccountField  * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rsp = gcnew RtnNotifyQueryAccountFieldResponseData;
			rsp->TradeCode = U8ToClr((native->TradeCode));
			rsp->BankID = U8ToClr((native->BankID));
			rsp->BankBranchID = U8ToClr((native->BankBranchID));
			rsp->BrokerID = U8ToClr((native->BrokerID));
			rsp->BrokerBranchID = U8ToClr((native->BrokerBranchID));
			rsp->TradeDate = U8ToClr((native->TradeDate));
			rsp->TradeTime = U8ToClr((native->TradeTime));
			rsp->BankSerial = U8ToClr((native->BankSerial));
			rsp->TradingDay = U8ToClr((native->TradingDay));
			rsp->PlateSerial = native->PlateSerial;
			rsp->LastFragment = native->LastFragment;
			rsp->SessionID = native->SessionID;
			rsp->CustomerName = AnsiToClr((native->CustomerName));
			rsp->IdCardType = native->IdCardType;
			rsp->IdentifiedCardNo = U8ToClr((native->IdentifiedCardNo));
			rsp->CustType = native->CustType;
			rsp->BankAccount = U8ToClr((native->BankAccount));
			rsp->BankPassWord = U8ToClr((native->BankPassWord));
			rsp->AccountID = U8ToClr((native->AccountID));
			rsp->Password = U8ToClr((native->Password));
			rsp->FutureSerial = native->FutureSerial;
			rsp->InstallID = native->InstallID;
			rsp->UserID = U8ToClr((native->UserID));
			rsp->VerifyCertNoFlag = native->VerifyCertNoFlag;
			rsp->CurrencyID = U8ToClr((native->CurrencyID));
			rsp->Digest = U8ToClr((native->Digest));
			rsp->BankAccType = native->BankAccType;
			rsp->DeviceID = U8ToClr((native->DeviceID));
			rsp->BankSecuAccType = native->BankSecuAccType;
			rsp->BrokerIDByBank = U8ToClr((native->BrokerIDByBank));
			rsp->BankSecuAcc = U8ToClr((native->BankSecuAcc));
			rsp->BankPwdFlag = native->BankPwdFlag;
			rsp->SecuPwdFlag = native->SecuPwdFlag;
			rsp->OperNo = U8ToClr((native->OperNo));
			rsp->RequestID = native->RequestID;
			rsp->TID = native->TID;
			rsp->BankUseAmount= native->BankUseAmount;
			rsp->BankFetchAmount= native->BankFetchAmount;
			rsp->ErrorID = native->ErrorID;
			rsp->ErrorMsg= AnsiToClr(native->ErrorMsg);
			rsp->LongCustomerName = AnsiToClr((native->LongCustomerName));
			return rsp;
		}
		///业务功能码
		String^ TradeCode;
		///银行代码
		String^ BankID;
		///银行分支机构代码
		String^ BankBranchID;
		///期商代码
		String^ BrokerID;
		///期商分支机构代码
		String^ BrokerBranchID;
		///交易日期
		String^ TradeDate;
		///交易时间
		String^ TradeTime;
		///银行流水号
		String^ BankSerial;
		///交易系统日期 
		String^ TradingDay;
		///银期平台消息流水号
		int PlateSerial;
		///最后分片标志
		char LastFragment;
		///会话号
		int SessionID;
		///客户姓名
		String^ CustomerName;
		///证件类型
		char IdCardType;
		///证件号码
		String^ IdentifiedCardNo;
		///客户类型
		char CustType;
		///银行帐号
		String^ BankAccount;
		///银行密码
		String^ BankPassWord;
		///投资者帐号
		String^ AccountID;
		///期货密码
		String^ Password;
		///期货公司流水号
		int FutureSerial;
		///安装编号
		int InstallID;
		///用户标识
		String^ UserID;
		///验证客户证件号码标志
		char VerifyCertNoFlag;
		///币种代码
		String^ CurrencyID;
		///摘要
		String^ Digest;
		///银行帐号类型
		char BankAccType;
		///渠道标志
		String^ DeviceID;
		///期货单位帐号类型
		char BankSecuAccType;
		///期货公司银行编码
		String^ BrokerIDByBank;
		///期货单位帐号
		String^ BankSecuAcc;
		///银行密码标志
		char BankPwdFlag;
		///期货资金密码核对标志
		char SecuPwdFlag;
		///交易柜员
		String^ OperNo;
		///请求编号
		int RequestID;
		///交易ID
		int TID;
		///银行可用金额
		double BankUseAmount;
		///银行可取金额
		double BankFetchAmount;
		///错误代码
		int ErrorID;
		///错误信息
		String^ ErrorMsg;
		///长客户姓名
		String^ LongCustomerName;
	};




	public ref class UserPasswordUpdateResponseData
	{
	public:
		static UserPasswordUpdateResponseData^ FromNative(CThostFtdcUserPasswordUpdateField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew UserPasswordUpdateResponseData;
			///经纪公司代码
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///用户代码
			rspdata->UserID = U8ToClr((native->UserID));
			///原来的口令
			rspdata->OldPassword = U8ToClr((native->OldPassword));
			///新的口令
			rspdata->NewPassword = U8ToClr((native->NewPassword));
			return rspdata;
		}
		///经纪公司代码
		String^ BrokerID;
		///用户代码
		String^ UserID;
		///原来的口令
		String^ OldPassword;
		///新的口令
		String^ NewPassword;
	};
	public ref class QueryMaxOrderVolumeResponseData
	{
	public:
		static QueryMaxOrderVolumeResponseData^ FromNative(CThostFtdcQueryMaxOrderVolumeField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew QueryMaxOrderVolumeResponseData;
			///经纪公司代码
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///投资者代码
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///合约代码
			rspdata->InstrumentID = U8ToClr((native->InstrumentID));
			///买卖方向
			rspdata->Direction = native->Direction;
			///开平标志
			rspdata->OffsetFlag = native->OffsetFlag;
			///投机套保标志
			rspdata->HedgeFlag = native->HedgeFlag;
			///最大允许报单数量
			rspdata->MaxVolume = native->MaxVolume;
			///交易所代码
			rspdata->ExchangeID = U8ToClr((native->ExchangeID));
			///投资单元代码
			rspdata->InvestUnitID = U8ToClr((native->InvestUnitID));
			return rspdata;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///合约代码
		String^ InstrumentID;
		///买卖方向
		char Direction;
		///开平标志
		char OffsetFlag;
		///投机套保标志
		char HedgeFlag;
		///最大允许报单数量
		char MaxVolume;
		///交易所代码
		String^ ExchangeID;
		///投资单元代码
		String^ InvestUnitID;
	};
	public ref class TradeResponseData
	{
	public:
		static TradeResponseData^ FromNative(CThostFtdcTradeField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew TradeResponseData;
			///经纪公司代码
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///投资者代码
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///合约代码
			rspdata->InstrumentID = U8ToClr((native->InstrumentID));
			///报单引用
			rspdata->OrderRef = U8ToClr((native->OrderRef));
			///用户代码
			rspdata->UserID = U8ToClr((native->UserID));
			///交易所代码
			rspdata->ExchangeID = U8ToClr((native->ExchangeID));
			///成交编号
			rspdata->TradeID = U8ToClr((native->TradeID));
			///买卖方向
			rspdata->Direction = native->Direction;
			///报单编号
			rspdata->OrderSysID = U8ToClr((native->OrderSysID));
			///会员代码
			rspdata->ParticipantID = U8ToClr((native->ParticipantID));
			///客户代码
			rspdata->ClientID = U8ToClr((native->ClientID));
			///交易角色
			rspdata->TradingRole = native->TradingRole;
			///合约在交易所的代码
			rspdata->ExchangeInstID = U8ToClr((native->ExchangeInstID));
			///开平标志
			rspdata->OffsetFlag = native->OffsetFlag;
			///投机套保标志
			rspdata->HedgeFlag = native->HedgeFlag;
			///价格
			rspdata->Price = native->Price;
			///数量
			rspdata->Volume = native->Volume;
			///成交时期
			rspdata->TradeDate = U8ToClr((native->TradeDate));
			///成交时间
			rspdata->TradeTime = U8ToClr((native->TradeTime));
			///成交类型
			rspdata->TradeType = native->TradeType;
			///成交价来源
			rspdata->PriceSource = native->PriceSource;
			///交易所交易员代码
			rspdata->TraderID = U8ToClr((native->TraderID));
			///本地报单编号
			rspdata->OrderLocalID = U8ToClr((native->OrderLocalID));
			///结算会员编号
			rspdata->ClearingPartID = U8ToClr((native->ClearingPartID));
			///业务单元
			rspdata->BusinessUnit = U8ToClr((native->BusinessUnit));
			///序号
			rspdata->SequenceNo = native->SequenceNo;
			///交易日
			rspdata->TradingDay = U8ToClr((native->TradingDay));
			///结算编号
			rspdata->SettlementID = native->SettlementID;
			///经纪公司报单编号
			rspdata->BrokerOrderSeq = native->BrokerOrderSeq;
			///成交来源
			rspdata->TradeSource = native->TradeSource;
			///投资单元代码
			rspdata->InvestUnitID = U8ToClr((native->InvestUnitID));
			return rspdata;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///合约代码
		String^ InstrumentID;
		///报单引用
		String^ OrderRef;
		///用户代码
		String^ UserID;
		///交易所代码
		String^ ExchangeID;
		///成交编号
		String^ TradeID;
		///买卖方向
		char Direction;
		///报单编号
		String^ OrderSysID;
		///会员代码
		String^ ParticipantID;
		///客户代码
		String^ ClientID;
		///交易角色
		char TradingRole;
		///合约在交易所的代码
		String^ ExchangeInstID;
		///开平标志
		char OffsetFlag;
		///投机套保标志
		char HedgeFlag;
		///价格
		double Price;
		///数量
		int Volume;
		///成交时期
		String^ TradeDate;
		///成交时间
		String^ TradeTime;
		///成交类型
		char TradeType;
		///成交价来源
		char PriceSource;
		///交易所交易员代码
		String^ TraderID;
		///本地报单编号
		String^ OrderLocalID;
		///结算会员编号
		String^ ClearingPartID;
		///业务单元
		String^ BusinessUnit;
		///序号
		int SequenceNo;
		///交易日
		String^ TradingDay;
		///结算编号
		int SettlementID;
		///经纪公司报单编号
		int BrokerOrderSeq;
		///成交来源
		int TradeSource;
		///投资单元代码
		String^ InvestUnitID;
	};
	public ref class InvestorPositionDetailResponseData
	{
	public:
		static InvestorPositionDetailResponseData^ FromNative(CThostFtdcInvestorPositionDetailField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew InvestorPositionDetailResponseData;
			///合约代码
			rspdata->InstrumentID = U8ToClr((native->InstrumentID));
			///经纪公司代码
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///投资者代码
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///投机套保标志
			rspdata->HedgeFlag = native->HedgeFlag;
			///买卖
			rspdata->Direction = native->Direction;
			///开仓日期
			rspdata->OpenDate = U8ToClr((native->OpenDate));
			///成交编号
			rspdata->TradeID = U8ToClr((native->TradeID));
			///数量
			rspdata->Volume = native->Volume;
			///开仓价
			rspdata->OpenPrice = native->OpenPrice;
			///交易日
			rspdata->TradingDay = U8ToClr((native->TradingDay));
			///结算编号
			rspdata->SettlementID = native->SettlementID;
			///成交类型
			rspdata->TradeType = native->TradeType;
			///组合合约代码
			rspdata->CombInstrumentID = U8ToClr((native->CombInstrumentID));
			///交易所代码
			rspdata->ExchangeID = U8ToClr((native->ExchangeID));
			///逐日盯市平仓盈亏
			rspdata->CloseProfitByDate = native->CloseProfitByDate;
			///逐笔对冲平仓盈亏
			rspdata->CloseProfitByTrade = native->CloseProfitByTrade;
			///逐日盯市持仓盈亏
			rspdata->PositionProfitByDate = native->PositionProfitByDate;
			///逐笔对冲持仓盈亏
			rspdata->PositionProfitByTrade = native->PositionProfitByTrade;
			///投资者保证金
			rspdata->Margin = native->Margin;
			///交易所保证金
			rspdata->ExchMargin = native->ExchMargin;
			///保证金率
			rspdata->MarginRateByMoney = native->MarginRateByMoney;
			///保证金率(按手数)
			rspdata->MarginRateByVolume = native->MarginRateByVolume;
			///昨结算价
			rspdata->LastSettlementPrice = native->LastSettlementPrice;
			///结算价
			rspdata->SettlementPrice = native->SettlementPrice;
			///平仓量
			rspdata->CloseVolume = native->CloseVolume;
			///平仓金额
			rspdata->CloseAmount = native->CloseAmount;
			///投资单元代码
			rspdata->InvestUnitID = U8ToClr((native->InvestUnitID));
			return rspdata;
		}
		///合约代码
		String^ InstrumentID;
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///投机套保标志
		char HedgeFlag;
		///买卖
		char Direction;
		///开仓日期
		String^ OpenDate;
		///成交编号
		String^ TradeID;
		///数量
		int Volume;
		///开仓价
		double OpenPrice;
		///交易日
		String^ TradingDay;
		///结算编号
		int SettlementID;
		///成交类型
		char TradeType;
		///组合合约代码
		String^ CombInstrumentID;
		///交易所代码
		String^ ExchangeID;
		///逐日盯市平仓盈亏
		double CloseProfitByDate;
		///逐笔对冲平仓盈亏
		double CloseProfitByTrade;
		///逐日盯市持仓盈亏
		double PositionProfitByDate;
		///逐笔对冲持仓盈亏
		double PositionProfitByTrade;
		///投资者保证金
		double Margin;
		///交易所保证金
		double ExchMargin;
		///保证金率
		double MarginRateByMoney;
		///保证金率(按手数)
		double MarginRateByVolume;
		///昨结算价
		double LastSettlementPrice;
		///结算价
		double SettlementPrice;
		///平仓量
		int CloseVolume;
		///平仓金额
		double CloseAmount;
		///投资单元代码
		String^ InvestUnitID;
	};
	public ref class InvestorResponseData
	{
	public:
		static InvestorResponseData^ FromNative(CThostFtdcInvestorField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew InvestorResponseData;
			///投资者代码
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///经纪公司代码
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///投资者分组代码
			rspdata->InvestorGroupID = U8ToClr((native->InvestorGroupID));
			///投资者名称
			rspdata->InvestorName = U8ToClr((native->InvestorName));
			///证件类型
			rspdata->IdentifiedCardType = native->IdentifiedCardType;
			///证件号码
			rspdata->IdentifiedCardNo = U8ToClr((native->IdentifiedCardNo));
			///是否活跃
			rspdata->IsActive = native->IsActive;
			///联系电话
			rspdata->Telephone = U8ToClr((native->Telephone));
			///通讯地址
			rspdata->Address = U8ToClr((native->Address));
			///开户日期
			rspdata->OpenDate = U8ToClr((native->OpenDate));
			///手机
			rspdata->Mobile = U8ToClr((native->Mobile));
			///手续费率模板代码
			rspdata->CommModelID = U8ToClr((native->CommModelID));
			///保证金率模板代码
			rspdata->MarginModelID = U8ToClr((native->MarginModelID));
			return rspdata;
		}
		///投资者代码
		String^ InvestorID;
		///经纪公司代码
		String^ BrokerID;
		///投资者分组代码
		String^ InvestorGroupID;
		///投资者名称
		String^ InvestorName;
		///证件类型
		char IdentifiedCardType;
		///证件号码
		String^ IdentifiedCardNo;
		///是否活跃
		int IsActive;
		///联系电话
		String^ Telephone;
		///通讯地址
		String^ Address;
		///开户日期
		String^ OpenDate;
		///手机
		String^ Mobile;
		///手续费率模板代码
		String^ CommModelID;
		///保证金率模板代码
		String^ MarginModelID;
	};
	public ref class TradingCodeResponseData
	{
	public:
		static TradingCodeResponseData^ FromNative(CThostFtdcTradingCodeField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew TradingCodeResponseData;
			///投资者代码
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///经纪公司代码
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///交易所代码
			rspdata->ExchangeID = U8ToClr((native->ExchangeID));
			///客户代码
			rspdata->ClientID = U8ToClr((native->ClientID));
			///是否活跃
			rspdata->IsActive = native->IsActive;
			///交易编码类型
			rspdata->ClientIDType = native->ClientIDType;
			///营业部编号
			rspdata->BranchID = U8ToClr((native->BranchID));
			///业务类型
			rspdata->BizType = native->BizType;
			///投资单元代码
			rspdata->InvestUnitID = U8ToClr((native->InvestUnitID));
			return rspdata;
		}
		///投资者代码
		String^ InvestorID;
		///经纪公司代码
		String^ BrokerID;
		///交易所代码
		String^ ExchangeID;
		///客户代码
		String^ ClientID;
		///是否活跃
		int IsActive;
		///交易编码类型
		char ClientIDType;
		///营业部编号
		String^ BranchID;
		///业务类型
		char BizType;
		///投资单元代码
		String^ InvestUnitID;
	};
	public ref class InstrumentMarginRateResponseData
	{
	public:
		static InstrumentMarginRateResponseData^ FromNative(CThostFtdcInstrumentMarginRateField  * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew InstrumentMarginRateResponseData;
			///合约代码
			rspdata->InstrumentID = U8ToClr((native->InstrumentID));
			///投资者范围
			rspdata->InvestorRange = native->InvestorRange;
			///经纪公司代码
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///投资者代码
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///投机套保标志
			rspdata->HedgeFlag = native->HedgeFlag;
			///多头保证金率
			rspdata->LongMarginRatioByMoney = native->LongMarginRatioByMoney;
			///多头保证金费
			rspdata->LongMarginRatioByVolume = native->LongMarginRatioByVolume;
			///空头保证金率
			rspdata->ShortMarginRatioByMoney =native->ShortMarginRatioByMoney;
			///空头保证金费
			rspdata->ShortMarginRatioByVolume = native->ShortMarginRatioByVolume;
			///是否相对交易所收取
			rspdata->IsRelative = native->IsRelative;
			///交易所代码
			rspdata->ExchangeID = U8ToClr((native->ExchangeID));
			///投资单元代码
			rspdata->InvestUnitID = U8ToClr((native->InvestUnitID));
			return rspdata;
		}
		///合约代码
		String^ InstrumentID;
		///投资者范围
		char InvestorRange;
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///投机套保标志
		char HedgeFlag;
		///多头保证金率
		double LongMarginRatioByMoney;
		///多头保证金费
		double LongMarginRatioByVolume;
		///空头保证金率
		double ShortMarginRatioByMoney;
		///空头保证金费
		double ShortMarginRatioByVolume;
		///是否相对交易所收取
		int IsRelative;
		///交易所代码
		String^ ExchangeID;
		///投资单元代码
		String^ InvestUnitID;
	};
	public ref class InstrumentCommissionRateResponseData
	{
	public:
		static InstrumentCommissionRateResponseData^ FromNative(CThostFtdcInstrumentCommissionRateField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew InstrumentCommissionRateResponseData;
			///合约代码
			rspdata->InstrumentID = U8ToClr((native->InstrumentID));
			///投资者范围
			rspdata->InvestorRange = native->InvestorRange;
			///经纪公司代码
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///投资者代码
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///开仓手续费率
			rspdata->OpenRatioByMoney = native->OpenRatioByMoney;
			///开仓手续费
			rspdata->OpenRatioByVolume = native->OpenRatioByVolume;
			///平仓手续费率
			rspdata->CloseRatioByMoney = native->CloseRatioByMoney;
			///平仓手续费
			rspdata->CloseRatioByVolume = native->CloseRatioByVolume;
			///平今手续费率
			rspdata->CloseTodayRatioByMoney = native->CloseTodayRatioByMoney;
			///平今手续费
			rspdata->CloseTodayRatioByVolume = native->CloseTodayRatioByVolume;
			///交易所代码
			rspdata->ExchangeID = U8ToClr((native->ExchangeID));
			///业务类型
			rspdata->BizType = native->BizType;
			///投资单元代码
			rspdata->InvestUnitID = U8ToClr((native->InvestUnitID));
			return rspdata;
		}
		///合约代码
		String^ InstrumentID;
		///投资者范围
		char InvestorRange;
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///开仓手续费率
		double OpenRatioByMoney;
		///开仓手续费
		double OpenRatioByVolume;
		///平仓手续费率
		double CloseRatioByMoney;
		///平仓手续费
		double CloseRatioByVolume;
		///平今手续费率
		double CloseTodayRatioByMoney;
		///平今手续费
		double CloseTodayRatioByVolume;
		///交易所代码
		String^ ExchangeID;
		///业务类型
		char BizType;
		///投资单元代码
		String^ InvestUnitID;
	};
	public ref class InstrumentResponseData
	{
	public:
		static InstrumentResponseData^ FromNative(CThostFtdcInstrumentField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew InstrumentResponseData;
			///合约代码
			rspdata->InstrumentID = U8ToClr((native->InstrumentID));
			///交易所代码
			rspdata->ExchangeID = U8ToClr((native->ExchangeID));
			///合约名称
			rspdata->InstrumentName = U8ToClr((native->InstrumentName));
			///合约在交易所的代码
			rspdata->ExchangeInstID = U8ToClr((native->ExchangeInstID));
			///产品代码
			rspdata->ProductID = U8ToClr((native->ProductID));
			///产品类型
			rspdata->ProductClass = native->ProductClass;
			///交割年份
			rspdata->DeliveryYear = native->DeliveryYear;
			///交割月
			rspdata->DeliveryMonth = native->DeliveryMonth;
			///市价单最大下单量
			rspdata->MaxMarketOrderVolume = native->MaxMarketOrderVolume;
			///市价单最小下单量
			rspdata->MinMarketOrderVolume = native->MinMarketOrderVolume;
			///限价单最大下单量
			rspdata->MaxLimitOrderVolume = native->MaxLimitOrderVolume;
			///限价单最小下单量
			rspdata->MinLimitOrderVolume = native->MinLimitOrderVolume;
			///合约数量乘数
			rspdata->VolumeMultiple = native->VolumeMultiple;
			///最小变动价位
			rspdata->PriceTick = native->PriceTick;
			///创建日
			rspdata->CreateDate = U8ToClr((native->CreateDate));
			///上市日
			rspdata->OpenDate = U8ToClr((native->OpenDate));
			///到期日
			rspdata->ExpireDate = U8ToClr((native->ExpireDate));
			///开始交割日
			rspdata->StartDelivDate = U8ToClr((native->StartDelivDate));
			///结束交割日
			rspdata->EndDelivDate = U8ToClr((native->EndDelivDate));
			///合约生命周期状态
			rspdata->InstLifePhase = native->InstLifePhase;
			///当前是否交易
			rspdata->IsTrading = native->IsTrading;
			///持仓类型
			rspdata->PositionType = native->PositionType;
			///持仓日期类型
			rspdata->PositionDateType = native->PositionDateType;
			///多头保证金率
			rspdata->LongMarginRatio = native->LongMarginRatio;
			///空头保证金率
			rspdata->ShortMarginRatio = native->ShortMarginRatio;
			///是否使用大额单边保证金算法
			rspdata->MaxMarginSideAlgorithm = native->MaxMarginSideAlgorithm;
			///基础商品代码
			rspdata->UnderlyingInstrID = U8ToClr((native->UnderlyingInstrID));
			///执行价
			rspdata->StrikePrice = native->StrikePrice;
			///期权类型
			rspdata->OptionsType = native->OptionsType;
			///合约基础商品乘数
			rspdata->UnderlyingMultiple = native->UnderlyingMultiple;
			///组合类型
			rspdata->CombinationType = native->CombinationType;
			return rspdata;
		}
		///合约代码
		String^ InstrumentID;
		///交易所代码
		String^ ExchangeID;
		///合约名称
		String^ InstrumentName;
		///合约在交易所的代码
		String^ ExchangeInstID;
		///产品代码
		String^ ProductID;
		///产品类型
		char ProductClass;
		///交割年份
		int DeliveryYear;
		///交割月
		int DeliveryMonth;
		///市价单最大下单量
		int  MaxMarketOrderVolume;
		///市价单最小下单量
		int MinMarketOrderVolume;
		///限价单最大下单量
		int MaxLimitOrderVolume;
		///限价单最小下单量
		int MinLimitOrderVolume;
		///合约数量乘数
		int VolumeMultiple;
		///最小变动价位
		double PriceTick;
		///创建日
		String^ CreateDate;
		///上市日
		String^ OpenDate;
		///到期日
		String^ ExpireDate;
		///开始交割日
		String^ StartDelivDate;
		///结束交割日
		String^ EndDelivDate;
		///合约生命周期状态
		char InstLifePhase;
		///当前是否交易
		int IsTrading;
		///持仓类型
		char PositionType;
		///持仓日期类型
		char PositionDateType;
		///多头保证金率
		double LongMarginRatio;
		///空头保证金率
		double ShortMarginRatio;
		///是否使用大额单边保证金算法
		char MaxMarginSideAlgorithm;
		///基础商品代码
		String^ UnderlyingInstrID;
		///执行价
		double StrikePrice;
		///期权类型
		char OptionsType;
		///合约基础商品乘数
		double UnderlyingMultiple;
		///组合类型
		char CombinationType;
	};
	public ref class QrySettlementInfoResponseData
	{
	public:
		static QrySettlementInfoResponseData^ FromNative(CThostFtdcSettlementInfoField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew QrySettlementInfoResponseData;
			///交易日
			rspdata->TradingDay = U8ToClr((native->TradingDay));
			///结算编号
			rspdata->SettlementID = native->SettlementID;
			///经纪公司代码
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///投资者代码
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///序号
			rspdata->SequenceNo = native->SequenceNo;
			///消息正文
			rspdata->Content = U8ToClr((native->Content));
			///投资者帐号
			rspdata->AccountID = U8ToClr((native->AccountID));
			///币种代码
			rspdata->CurrencyID = U8ToClr((native->CurrencyID));
			return rspdata;
		}
		///交易日
		String^ TradingDay;
		///结算编号
		int SettlementID;
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///序号
		int SequenceNo;
		///消息正文
		String^ Content;
		///投资者帐号
		String^ AccountID;
		///币种代码
		String^ CurrencyID;
	};
	public ref class QrySettlementInfoConfirmResponseData
	{
	public:
		static QrySettlementInfoConfirmResponseData^ FromNative(CThostFtdcSettlementInfoConfirmField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew QrySettlementInfoConfirmResponseData;
			///经纪公司代码
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///投资者代码
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///确认日期
			rspdata->ConfirmDate = U8ToClr((native->ConfirmDate));
			///确认时间
			rspdata->ConfirmTime = U8ToClr((native->ConfirmTime));
			///结算编号
			rspdata->SettlementID = native->SettlementID;
			///投资者帐号
			rspdata->AccountID = U8ToClr((native->AccountID));
			///币种代码
			rspdata->CurrencyID = U8ToClr((native->CurrencyID));
			return rspdata;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///确认日期
		String^ ConfirmDate;
		///确认时间
		String^ ConfirmTime;
		///结算编号
		int SettlementID;
		///投资者帐号
		String^ AccountID;
		///币种代码
		String^ CurrencyID;
	};
	public ref class SettlementInfoConfirmResponseData
	{
	public:
		static SettlementInfoConfirmResponseData^ FromNative(CThostFtdcSettlementInfoConfirmField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew SettlementInfoConfirmResponseData;
			///经纪公司代码
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///投资者代码
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///确认日期
			rspdata->ConfirmDate = U8ToClr((native->ConfirmDate));
			///确认时间
			rspdata->ConfirmTime = U8ToClr((native->ConfirmTime));
			///结算编号
			rspdata->SettlementID = native->SettlementID;
			///投资者帐号
			rspdata->AccountID = U8ToClr((native->AccountID));
			///币种代码
			rspdata->CurrencyID = U8ToClr((native->CurrencyID));
			return rspdata;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者代码
		String^ InvestorID;
		///确认日期
		String^ ConfirmDate;
		///确认时间
		String^ ConfirmTime;
		///结算编号
		int SettlementID;
		///投资者帐号
		String^ AccountID;
		///币种代码
		String^ CurrencyID;
	};
	public ref class NoticeResponseData
	{
	public:
		static NoticeResponseData^ FromNative(CThostFtdcNoticeField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew NoticeResponseData;
			///经纪公司代码
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///消息正文
			rspdata->Content = U8ToClr((native->Content));
			///经纪公司通知内容序列号
			rspdata->SequenceLabel = U8ToClr((native->SequenceLabel));
			return rspdata;
		}
		///经纪公司代码
		String^ BrokerID;
		///消息正文
		String^ Content;
		///经纪公司通知内容序列号
		String^ SequenceLabel;
	};
	public ref class TradingNoticeResponseData
	{
	public:
		static TradingNoticeResponseData^ FromNative(CThostFtdcTradingNoticeField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew TradingNoticeResponseData;
			///经纪公司代码
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///投资者范围
			rspdata->InvestorRange = native->InvestorRange;
			///投资者代码
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///序列系列号
			rspdata->SequenceSeries = native->SequenceSeries;
			///用户代码
			rspdata->UserID = U8ToClr((native->UserID));
			///发送时间
			rspdata->SendTime = U8ToClr((native->SendTime));
			///序列号
			rspdata->SequenceNo = native->SequenceNo;
			///消息正文
			rspdata->FieldContent = U8ToClr((native->FieldContent));
			///投资单元代码
			rspdata->InvestUnitID = U8ToClr((native->InvestUnitID));
			return rspdata;
		}
		///经纪公司代码
		String^ BrokerID;
		///投资者范围
		char InvestorRange;
		///投资者代码
		String^ InvestorID;
		///序列系列号
		short SequenceSeries;
		///用户代码
		String^ UserID;
		///发送时间
		String^ SendTime;
		///序列号
		int SequenceNo;
		///消息正文
		String^ FieldContent;
		///投资单元代码
		String^ InvestUnitID;
	};

	public ref class RspSubMarketResponseData
	{
	public:
		static RspSubMarketResponseData^ FromNative(CThostFtdcSpecificInstrumentField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew RspSubMarketResponseData;
			rspdata->InstrumentID = U8ToClr((native->InstrumentID));
			return rspdata;
		}
		///合约代码
		String^ InstrumentID;
	};

	public ref class RtnDepthMarketResponseData
	{
	public:
		static RtnDepthMarketResponseData^ FromNative(CThostFtdcDepthMarketDataField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew RtnDepthMarketResponseData;
			rspdata->TradingDay = U8ToClr((native->TradingDay));
			///合约代码
			rspdata->InstrumentID = U8ToClr((native->InstrumentID));
			///交易所代码
			rspdata->ExchangeID = U8ToClr((native->ExchangeID));
			///合约在交易所的代码
			rspdata->ExchangeInstID = U8ToClr((native->ExchangeInstID));
			///最新价
			rspdata->LastPrice= native->LastPrice;
			///上次结算价
			rspdata->PreSettlementPrice= native->PreSettlementPrice;
			///昨收盘
			rspdata->PreClosePrice= native->PreClosePrice;
			///昨持仓量
			rspdata->PreOpenInterest= native->PreOpenInterest;
			///今开盘
			rspdata->OpenPrice= native->OpenPrice;
			///最高价
			rspdata->HighestPrice= native->HighestPrice;
			///最低价
			rspdata->LowestPrice= native->LowestPrice;
			///数量
			rspdata->Volume= native->Volume;
			///成交金额
			rspdata->Turnover= native->Turnover;
			///持仓量
			rspdata->OpenInterest= native->OpenInterest;
			///今收盘
			rspdata->ClosePrice= native->ClosePrice;
			///本次结算价
			rspdata->SettlementPrice= native->SettlementPrice;
			///涨停板价
			rspdata->UpperLimitPrice= native->UpperLimitPrice;
			///跌停板价
			rspdata->LowerLimitPrice= native->LowerLimitPrice;
			///昨虚实度
			rspdata->PreDelta= native->PreDelta;
			///今虚实度
			rspdata->CurrDelta= native->CurrDelta;
			///最后修改时间
			rspdata->UpdateTime = U8ToClr((native->UpdateTime));
			///最后修改毫秒
			rspdata->UpdateMillisec= native->UpdateMillisec;
			///申买价一
			rspdata->BidPrice1 = native->BidPrice1;
			///申买量一
			rspdata->BidVolume1= native->BidVolume1;
			///申卖价一
			rspdata->AskPrice1 = native->AskPrice1;
			///申卖量一
			rspdata->AskVolume1= native->AskVolume1;
			///申买价二
			rspdata->BidPrice2 = native->BidPrice2;
			///申买量二
			rspdata->BidVolume2= native->BidVolume2;
			///申卖价二
			rspdata->AskPrice2= native->AskPrice2;
			///申卖量二
			rspdata->AskVolume2= native->AskVolume2;
			///申买价三
			rspdata->BidPrice3= native->BidPrice3;
			///申买量三
			rspdata->BidVolume3= native->BidVolume3;
			///申卖价三
			rspdata->AskPrice3= native->AskPrice3;
			///申卖量三
			rspdata->AskVolume3= native->AskVolume3;
			///申买价四
			rspdata->BidPrice4= native->BidPrice4;
			///申买量四
			rspdata->BidVolume4= native->BidVolume4;
			///申卖价四
			rspdata->AskPrice4= native->AskPrice4;
			///申卖量四
			rspdata->AskVolume4= native->AskVolume4;
			///申买价五
			rspdata->BidPrice5= native->BidPrice5;
			///申买量五
			rspdata->BidVolume5= native->BidVolume5;
			///申卖价五
			rspdata->AskPrice5= native->AskPrice5;
			///申卖量五
			rspdata->AskVolume5= native->AskVolume5;
			///当日均价
			rspdata->AveragePrice= native->AveragePrice;
			///业务日期
			rspdata->ActionDay = U8ToClr((native->ActionDay));
			return rspdata;
		}
		///交易日
		String^	TradingDay;
		///合约代码
		String^	InstrumentID;
		///交易所代码
		String^	ExchangeID;
		///合约在交易所的代码
		String^	ExchangeInstID;
		///最新价
		double	LastPrice;
		///上次结算价
		double	PreSettlementPrice;
		///昨收盘
		double	PreClosePrice;
		///昨持仓量
		double	PreOpenInterest;
		///今开盘
		double	OpenPrice;
		///最高价
		double	HighestPrice;
		///最低价
		double	LowestPrice;
		///数量
		int	Volume;
		///成交金额
		double	Turnover;
		///持仓量
		double	OpenInterest;
		///今收盘
		double	ClosePrice;
		///本次结算价
		double	SettlementPrice;
		///涨停板价
		double	UpperLimitPrice;
		///跌停板价
		double	LowerLimitPrice;
		///昨虚实度
		double	PreDelta;
		///今虚实度
		double	CurrDelta;
		///最后修改时间
		String^	UpdateTime;
		///最后修改毫秒
		int	UpdateMillisec;
		///申买价一
		double	BidPrice1;
		///申买量一
		int	BidVolume1;
		///申卖价一
		double	AskPrice1;
		///申卖量一
		int	AskVolume1;
		///申买价二
		double	BidPrice2;
		///申买量二
		int	BidVolume2;
		///申卖价二
		double	AskPrice2;
		///申卖量二
		int	AskVolume2;
		///申买价三
		double	BidPrice3;
		///申买量三
		int	BidVolume3;
		///申卖价三
		double	AskPrice3;
		///申卖量三
		int	AskVolume3;
		///申买价四
		double	BidPrice4;
		///申买量四
		int	BidVolume4;
		///申卖价四
		double	AskPrice4;
		///申卖量四
		int	AskVolume4;
		///申买价五
		double 	BidPrice5;
		///申买量五
		int	BidVolume5;
		///申卖价五
		double	AskPrice5;
		///申卖量五
		int	AskVolume5;
		///当日均价
		double	AveragePrice;
		///业务日期
		String^	ActionDay;
	};

	public ref class OnRtnForQuoteResponseData
	{
	public:
		static OnRtnForQuoteResponseData^ FromNative(CThostFtdcForQuoteRspField * native)
		{
			if (native == nullptr)
			{
				return nullptr;
			}
			auto rspdata = gcnew OnRtnForQuoteResponseData;
			rspdata->TradingDay = U8ToClr((native->TradingDay));
			rspdata->InstrumentID = U8ToClr((native->InstrumentID));
			rspdata->ForQuoteSysID = U8ToClr((native->ForQuoteSysID));
			rspdata->ForQuoteTime = U8ToClr((native->ForQuoteTime));
			rspdata->ExchangeID = U8ToClr((native->ExchangeID));
			return rspdata;
		}
		///交易日
		String^	TradingDay;
		///合约代码
		String^	InstrumentID;
		///询价编号
		String^	ForQuoteSysID;
		///询价时间
		String^	ForQuoteTime;
		///业务日期
		String^	ActionDay;
		///交易所代码
		String^	ExchangeID;
	};
}