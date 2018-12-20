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
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///��Լ����
		String^ InstrumentID;
		///����������
		String^ ExchangeID;
		///�������
		String^ OrderSysID;
		///��ʼʱ��
		String^ InsertTimeStart;
		///����ʱ��
		String^ InsertTimeEnd;
		///Ͷ�ʵ�Ԫ����
		String^ InvestUnitID;
	};
	//��ѯ������������Ϊ--> RtnOrderResponseData
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
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///���ִ���
		String^ CurrencyID;
		///ҵ������
		String^ BizType;
		///Ͷ�����ʺ�
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
		///���͹�˾����
		String^ BrokerID;
		///Ͷ�����ʺ�
		String^ AccountID;
		///�ϴ���Ѻ���
		double PreMortgage;
		///�ϴ����ö��
		double  PreCredit;
		///�ϴδ���
		double  PreDeposit;
		///�ϴν���׼����
		double  PreBalance;
		///�ϴ�ռ�õı�֤��
		double  PreMargin;
		///��Ϣ����
		double  InterestBase;
		///��Ϣ����
		double  Interest;
		///�����
		double  Deposit;
		///������
		double  Withdraw;
		///����ı�֤��
		double  FrozenMargin;
		///������ʽ�
		double  FrozenCash;
		///�����������
		double  FrozenCommission;
		///��ǰ��֤���ܶ�
		double  CurrMargin;
		///�ʽ���
		double  CashIn;
		///������
		double  Commission;
		///ƽ��ӯ��
		double  CloseProfit;
		///�ֲ�ӯ��
		double  PositionProfit;
		///�ڻ�����׼����
		double  Balance;
		///�����ʽ�
		double  Available;
		///��ȡ�ʽ�
		double  WithdrawQuota;
		///����׼����
		double  Reserve;
		///������
		String^ TradingDay;
		///������
		int SettlementID;
		///���ö��
		double Credit;
		///��Ѻ���
		double Mortgage;
		///��������֤��
		double ExchangeMargin;
		///Ͷ���߽��֤��
		double DeliveryMargin;
		///���������֤��
		double ExchangeDeliveryMargin;
		///�����ڻ�����׼����
		double ReserveBalance;
		///���ִ���
		String^ CurrencyID;
		///�ϴλ���������
		double  PreFundMortgageIn;
		///�ϴλ����ʳ����
		double  PreFundMortgageOut;
		///����������
		double  FundMortgageIn;
		///�����ʳ����
		double  FundMortgageOut;
		///������Ѻ���
		double  FundMortgageAvailable;
		///����Ѻ���ҽ��
		double  MortgageableFund;
		///�����Ʒռ�ñ�֤��
		double  SpecProductMargin;
		///�����Ʒ���ᱣ֤��
		double  SpecProductFrozenMargin;
		///�����Ʒ������
		double  SpecProductCommission;
		///�����Ʒ����������
		double  SpecProductFrozenCommission;
		///�����Ʒ�ֲ�ӯ��
		double  SpecProductPositionProfit;
		///�����Ʒƽ��ӯ��
		double  SpecProductCloseProfit;
		///���ݳֲ�ӯ���㷨����������Ʒ�ֲ�ӯ��
		double  SpecProductPositionProfitByAlg;
		///�����Ʒ��������֤��
		double  SpecProductExchangeMargin;
		///ҵ������
		char BizType;
		///��ʱ���㶳����
		double FrozenSwap;
		///ʣ�໻����
		double RemainSwap;
	};
	//����¼������
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
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///�û�����
		String^	UserID;
		///��Լ����
		String^ InstrumentID;
		///��������
		String^ OrderRef;
		///�����۸�����
		char OrderPriceType;
		///��������
		char Direction;
		///��Ͽ�ƽ��־
		char CombOffsetFlag;
		///���Ͷ���ױ���־
		char CombHedgeFlag;
		///�۸�
		double LimitPrice;
		///����
		Int32 VolumeTotalOriginal;
		///��Ч������
		char TimeCondition;
		///GTD����
		String^ GTDDate;
		///�ɽ�������
		char VolumeCondition;
		///��С�ɽ���
		Int32 MinVolume;
		///��������
		char ContingentCondition;
		///ֹ���
		Int32 StopPrice;
		///ǿƽԭ��
		char ForceCloseReason;
		///�Զ������־
		Int32 IsAutoSuspend;
		///ҵ��Ԫ
		String^	BusinessUnit;
		///������
		Int32	RequestID;
		///�û�ǿ����־
		Int32	UserForceClose;
		///��������־
		Int32	IsSwapOrder;
		///����������
		String^	ExchangeID;
		///Ͷ�ʵ�Ԫ����
		String^	InvestUnitID;
		///�ʽ��˺�
		String^	AccountID;
		///���ִ���
		String^	CurrencyID;
		///���ױ���
		String^	ClientID;
		///IP��ַ
		String^	IPAddress;
		///Mac��ַ
		String^	MacAddress;
	};
	//����¼��������Ӧ����ִ��ReqOrderInsert�����ֶ���д����֮���CTP������ͨ���˽ӿڷ���
	//OnRsnativeInsert��OnErrRtnOrderInsert����
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
		///���͹�˾����
		String^	BrokerID;
		///Ͷ���ߴ���
		String^	InvestorID;
		///��Լ����
		String^	InstrumentID;
		///��������
		String^	OrderRef;
		///�û�����
		String^	UserID;
		///�����۸�����
		char	OrderPriceType;
		///��������
		char	Direction;
		///��Ͽ�ƽ��־
		String^	CombOffsetFlag;
		///���Ͷ���ױ���־
		String^	CombHedgeFlag;
		///�۸�
		double	LimitPrice;
		///����
		int	VolumeTotalOriginal;
		///��Ч������
		char	TimeCondition;
		///GTD����
		String^	GTDDate;
		///�ɽ�������
		char	VolumeCondition;
		///��С�ɽ���
		int	MinVolume;
		///��������
		char	ContingentCondition;
		///ֹ���
		double	StopPrice;
		///ǿƽԭ��
		char	ForceCloseReason;
		///�Զ������־
		int	IsAutoSuspend;
		///ҵ��Ԫ
		String^	BusinessUnit;
		///������
		int	RequestID;
		///�û�ǿ����־
		int	UserForceClose;
		///��������־
		int	IsSwapOrder;
		///����������
		String^	ExchangeID;
		///Ͷ�ʵ�Ԫ����
		String^	InvestUnitID;
		///�ʽ��˺�
		String^	AccountID;
		///���ִ���
		String^	CurrencyID;
		///���ױ���
		String^	ClientID;
		///IP��ַ
		String^	IPAddress;
		///Mac��ַ
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
			///���͹�˾����
			rspdata->BrokerID = U8ToClr(native->BrokerID);
			///Ͷ���ߴ���
			rspdata->InvestorID = U8ToClr(native->InvestorID);
			///��Լ����
			rspdata->InstrumentID = U8ToClr(native->InstrumentID);
			///��������
			rspdata->OrderRef = U8ToClr(native->OrderRef);
			///�û�����
			rspdata->UserID = U8ToClr(native->UserID);
			///�����۸�����
			rspdata->OrderPriceType = native->OrderPriceType;
			///��������
			rspdata->Direction = native->Direction;
			///��Ͽ�ƽ��־
			rspdata->CombOffsetFlag = U8ToClr(native->CombOffsetFlag);
			///���Ͷ���ױ���־
			rspdata->CombHedgeFlag = U8ToClr(native->CombHedgeFlag);
			///�۸�
			rspdata->LimitPrice = native->LimitPrice;
			///����
			rspdata->VolumeTotalOriginal = native->VolumeTotalOriginal;
			///��Ч������
			rspdata->TimeCondition = native->TimeCondition;
			///GTD����
			rspdata->GTDDate = U8ToClr(native->GTDDate);
			///�ɽ�������
			rspdata->VolumeCondition = native->VolumeCondition;
			///��С�ɽ���
			rspdata->MinVolume = native->MinVolume;
			///��������
			rspdata->ContingentCondition = native->ContingentCondition;
			///ֹ���
			rspdata->StopPrice = native->StopPrice;
			///ǿƽԭ��
			rspdata->ForceCloseReason = native->ForceCloseReason;
			///�Զ������־
			rspdata->IsAutoSuspend = native->IsAutoSuspend;
			///ҵ��Ԫ
			rspdata->BusinessUnit = U8ToClr(native->BusinessUnit);
			///������
			rspdata->RequestID = native->RequestID;
			///���ر������
			rspdata->OrderLocalID = U8ToClr(native->OrderLocalID);
			///����������
			rspdata->ExchangeID = U8ToClr(native->ExchangeID);
			///��Ա����
			rspdata->ParticipantID = U8ToClr(native->ParticipantID);
			///�ͻ�����
			rspdata->ClientID = U8ToClr(native->ClientID);
			///��Լ�ڽ������Ĵ���
			rspdata->ExchangeInstID = U8ToClr(native->ExchangeInstID);
			///����������Ա����
			rspdata->TraderID = U8ToClr(native->TraderID);
			///��װ���
			rspdata->InstallID = native->InstallID;
			///�����ύ״̬
			rspdata->OrderSubmitStatus = native->OrderSubmitStatus;
			///������ʾ���
			rspdata->NotifySequence = native->NotifySequence;
			///������
			rspdata->TradingDay = U8ToClr(native->TradingDay);
			///������
			rspdata->SettlementID = native->SettlementID;
			///�������
			rspdata->OrderSysID = U8ToClr(native->OrderSysID);
			///������Դ
			rspdata->OrderSource = native->OrderSource;
			///��������
			rspdata->OrderType = native->OrderType;
			///��ɽ�����
			rspdata->VolumeTraded = native->VolumeTraded;
			///ʣ������
			rspdata->VolumeTotal = native->VolumeTotal;
			///��������
			rspdata->InsertDate = U8ToClr(native->InsertDate);
			///ί��ʱ��
			rspdata->InsertTime = U8ToClr(native->InsertTime);
			///����ʱ��
			rspdata->ActiveTime = U8ToClr(native->ActiveTime);
			///����ʱ��
			rspdata->SuspendTime = U8ToClr(native->SuspendTime);
			///����޸�ʱ��
			rspdata->UpdateTime = U8ToClr(native->UpdateTime);
			///����ʱ��
			rspdata->CancelTime = U8ToClr(native->CancelTime);
			///����޸Ľ���������Ա����
			rspdata->ActiveTraderID = U8ToClr(native->ActiveTraderID);
			///�����Ա���
			rspdata->ClearingPartID = U8ToClr(native->ClearingPartID);
			///���
			rspdata->SequenceNo = native->SequenceNo;
			///ǰ�ñ��
			rspdata->FrontID = native->FrontID;
			///�Ự���
			rspdata->SessionID = native->SessionID;
			///�û��˲�Ʒ��Ϣ
			rspdata->UserProductInfo = U8ToClr(native->UserProductInfo);
			///״̬��Ϣ
			rspdata->StatusMsg = AnsiToClr(native->StatusMsg);
			///�û�ǿ����־
			rspdata->UserForceClose = native->UserForceClose;
			///�����û�����
			rspdata->ActiveUserID = U8ToClr(native->ActiveUserID);
			///���͹�˾�������
			rspdata->BrokerOrderSeq = native->BrokerOrderSeq;
			///��ر���
			rspdata->RelativeOrderSysID = U8ToClr(native->RelativeOrderSysID);
			///֣�����ɽ�����
			rspdata->ZCETotalTradedVolume = native->ZCETotalTradedVolume;
			///��������־
			rspdata->IsSwapOrder = native->IsSwapOrder;
			///Ӫҵ�����
			rspdata->BranchID = U8ToClr(native->BranchID);
			///Ͷ�ʵ�Ԫ����
			rspdata->InvestUnitID = U8ToClr(native->InvestUnitID);
			///�ʽ��˺�
			rspdata->AccountID = U8ToClr(native->AccountID);
			///���ִ���
			rspdata->CurrencyID = U8ToClr(native->CurrencyID);
			///IP��ַ
			rspdata->IPAddress = U8ToClr(native->IPAddress);
			///����״̬ �ܹؼ�
			rspdata->OrderStatus = native->OrderStatus;
			///Mac��ַ
			rspdata->MacAddress = U8ToClr(native->MacAddress);
			return rspdata;
		}
		///���͹�˾����
		String^	BrokerID;
		///Ͷ���ߴ���
		String^	InvestorID;
		///��Լ����
		String^	InstrumentID;
		///��������
		String^	OrderRef;
		///�û�����
		String^	UserID;
		///�����۸�����
		char	OrderPriceType;
		///��������
		char	Direction;
		///��Ͽ�ƽ��־
		String^	CombOffsetFlag;
		///���Ͷ���ױ���־
		String^	CombHedgeFlag;
		///�۸�
		double	LimitPrice;
		///����
		int	VolumeTotalOriginal;
		///��Ч������
		char	TimeCondition;
		///GTD����
		String^	GTDDate;
		///�ɽ�������
		char	VolumeCondition;
		///��С�ɽ���
		int	MinVolume;
		///��������
		char	ContingentCondition;
		///ֹ���
		double	StopPrice;
		///ǿƽԭ��
		char	ForceCloseReason;
		///�Զ������־
		int	IsAutoSuspend;
		///ҵ��Ԫ
		String^	BusinessUnit;
		///������
		int	RequestID;
		///���ر������
		String^	OrderLocalID;
		///����������
		String^	ExchangeID;
		///��Ա����
		String^	ParticipantID;
		///�ͻ�����
		String^	ClientID;
		///��Լ�ڽ������Ĵ���
		String^	ExchangeInstID;
		///����������Ա����
		String^	TraderID;
		///��װ���
		int	InstallID;
		///�����ύ״̬
		char	OrderSubmitStatus;
		///������ʾ���
		int	NotifySequence;
		///������
		String^	TradingDay;
		///������
		int	SettlementID;
		///�������
		String^	OrderSysID;
		///������Դ
		char	OrderSource;
		///����״̬
		char	OrderStatus;
		///��������
		char	OrderType;
		///��ɽ�����
		int	VolumeTraded;
		///ʣ������
		int	VolumeTotal;
		///��������
		String^	InsertDate;
		///ί��ʱ��
		String^	InsertTime;
		///����ʱ��
		String^	ActiveTime;
		///����ʱ��
		String^	SuspendTime;
		///����޸�ʱ��
		String^	UpdateTime;
		///����ʱ��
		String^	CancelTime;
		///����޸Ľ���������Ա����
		String^	ActiveTraderID;
		///�����Ա���
		String^	ClearingPartID;
		///���
		int	SequenceNo;
		///ǰ�ñ��
		int	FrontID;
		///�Ự���
		int	SessionID;
		///�û��˲�Ʒ��Ϣ
		String^	UserProductInfo;
		///״̬��Ϣ
		String^	StatusMsg;
		///�û�ǿ����־
		int	UserForceClose;
		///�����û�����
		String^	ActiveUserID;
		///���͹�˾�������
		int	BrokerOrderSeq;
		///��ر���
		String^	RelativeOrderSysID;
		///֣�����ɽ�����
		int	ZCETotalTradedVolume;
		///��������־
		int	IsSwapOrder;
		///Ӫҵ�����
		String^	BranchID;
		///Ͷ�ʵ�Ԫ����
		String^	InvestUnitID;
		///�ʽ��˺�
		String^	AccountID;
		///���ִ���
		String^	CurrencyID;
		///IP��ַ
		String^	IPAddress;
		///Mac��ַ
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
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///��Լ����
		String^ InstrumentID;
		///��������
		String^ OrderRef;
		///�û�����
		String^ UserID;
		///����������
		String^ ExchangeID;
		///�ɽ����
		String^ TradeID;
		///��������
		char Direction;
		///�������
		String^ OrderSysID;
		///��Ա����
		String^ ParticipantID;
		///�ͻ�����
		String^ ClientID;
		///���׽�ɫ
		char TradingRole;
		///��Լ�ڽ������Ĵ���
		String^ ExchangeInstID;
		///��ƽ��־
		char OffsetFlag;
		///Ͷ���ױ���־
		char HedgeFlag;
		///�۸�
		double Price;
		///����
		Int32 Volume;
		///�ɽ�ʱ��
		String^ TradeDate;
		///�ɽ�ʱ��
		String^ TradeTime;
		///�ɽ�����
		char TradeType;
		///�ɽ�����Դ
		char PriceSource;
		///����������Ա����
		String^ TraderID;
		///���ر������
		String^ OrderLocalID;
		///�����Ա���
		String^ ClearingPartID;
		///ҵ��Ԫ
		String^ BusinessUnit;
		///���
		Int32 SequenceNo;
		///������
		String^ TradingDay;
		///������
		Int32 SettlementID;
		///���͹�˾�������
		Int32 BrokerOrderSeq;
		///�ɽ���Դ
		char TradeSource;
		///Ͷ�ʵ�Ԫ����
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
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^  InvestorID;
		///��Լ����
		String^  InstrumentID;
		///����������
		String^  ExchangeID;
		///Ͷ�ʵ�Ԫ����
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
		///��Լ����
		String^	InstrumentID;
		///���͹�˾����
		String^	BrokerID;
		///Ͷ���ߴ���
		String^	InvestorID;
		///�ֲֶ�շ���
		char	PosiDirection;
		///Ͷ���ױ���־
		char	HedgeFlag;
		///�ֲ�����
		char	PositionDate;
		///���ճֲ�
		int	YdPosition;
		///���ճֲ�
		int	Position;
		///��ͷ����
		int	LongFrozen;
		///��ͷ����
		int	ShortFrozen;
		///���ֶ�����
		double	LongFrozenAmount;
		///���ֶ�����
		double	ShortFrozenAmount;
		///������
		int	OpenVolume;
		///ƽ����
		int	CloseVolume;
		///���ֽ��
		double	OpenAmount;
		///ƽ�ֽ��
		double	CloseAmount;
		///�ֲֳɱ�
		double	PositionCost;
		///�ϴ�ռ�õı�֤��
		double	PreMargin;
		///ռ�õı�֤��
		double	UseMargin;
		///����ı�֤��
		double	FrozenMargin;
		///������ʽ�
		double	FrozenCash;
		///�����������
		double	FrozenCommission;
		///�ʽ���
		double	CashIn;
		///������
		double	Commission;
		///ƽ��ӯ��
		double	CloseProfit;
		///�ֲ�ӯ��
		double	PositionProfit;
		///�ϴν����
		double	PreSettlementPrice;
		///���ν����
		double	SettlementPrice;
		///������
		String^	TradingDay;
		///������
		int	SettlementID;
		///���ֳɱ�
		double	OpenCost;
		///��������֤��
		double	ExchangeMargin;
		///��ϳɽ��γɵĳֲ�
		int	CombPosition;
		///��϶�ͷ����
		int	CombLongFrozen;
		///��Ͽ�ͷ����
		int	CombShortFrozen;
		///���ն���ƽ��ӯ��
		double	CloseProfitByDate;
		///��ʶԳ�ƽ��ӯ��
		double	CloseProfitByTrade;
		///���ճֲ�
		int	TodayPosition;
		///��֤����
		double	MarginRateByMoney;
		///��֤����(������)
		double	MarginRateByVolume;
		///ִ�ж���
		int	StrikeFrozen;
		///ִ�ж�����
		double	StrikeFrozenAmount;
		///����ִ�ж���
		int	AbandonFrozen;
		///����������
		String^	ExchangeID;
		///ִ�ж�������
		int	YdStrikeFrozen;
		///Ͷ�ʵ�Ԫ����
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
		String^	ErrorMsg = "���ؿս��";
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
		///���͹�˾����
		String^ BrokerID;
		///Ͷ�����ʺ�
		String^ AccountID;
		///���б���
		String^ BankID;
		///���ִ���
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
		///ƽ̨��ˮ��
		int PlateSerial;
		///���׷�������
		String^ TradeDate;
		///��������
		String^ TradingDay;
		///����ʱ��
		String^ TradeTime;
		///���״���
		String^ TradeCode;
		///�Ự���
		int SessionID;
		///���б���
		String^ BankID;
		///���з�֧��������
		String^ BankBranchID;
		///�����ʺ�����
		char BankAccType;
		///�����ʺ�
		String^ BankAccount;
		///������ˮ��
		String^ BankSerial;
		///�ڻ���˾����
		String^ BrokerID;
		///���̷�֧��������
		String^ BrokerBranchID;
		///�ڻ���˾�ʺ�����
		char FutureAccType;
		///Ͷ�����ʺ�
		String^ AccountID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///�ڻ���˾��ˮ��
		int FutureSerial;
		///֤������
		char IdCardType;
		///֤������
		String^ IdentifiedCardNo;
		///���ִ���
		String^ CurrencyID;
		///���׽��
		double TradeAmount;
		///Ӧ�տͻ�����
		double CustFee;
		///Ӧ���ڻ���˾����
		double BrokerFee;
		///��Ч��־
		char AvailabilityFlag;
		///����Ա
		String^ OperatorCode;
		///�������ʺ�
		String^ BankNewAccount;
		///�������
		int ErrorID;
		///������Ϣ
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
		///���͹�˾����
		String^ BrokerID;
		///Ͷ�����ʺ�
		String^ AccountID;
		///���б���
		String^ BankID;
		///���з�֧��������
		String^ BankBranchID;
		///���ִ���
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
		///���͹�˾����
		String^ BrokerID;
		///���д���
		String^ BankID;
		///���з����Ĵ���
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
		///ҵ������
		String^ TradeCode;
		///���д���
		String^ BankID;
		///���з�֧��������
		String^ BankBranchID;
		///���̴���
		String^ BrokerID;
		///���̷�֧��������
		String^ BrokerBranchID;
		///��������
		String^ TradeDate;
		///����ʱ��
		String^ TradeTime;
		///������ˮ��
		String^ BankSerial;
		///����ϵͳ���� 
		String^ TradingDay;
		///����ƽ̨��Ϣ��ˮ��
		Int32 PlateSerial;
		///����Ƭ��־
		char LastFragment;
		///�Ự��
		Int32 SessionID;
		///�ͻ�����
		String^ CustomerName;
		///֤������
		char IdCardType;
		///֤������
		String^ IdentifiedCardNo;
		///�ͻ�����
		char CustType;
		///�����ʺ�
		String^ BankAccount;
		///��������
		String^ BankPassWord;
		///Ͷ�����ʺ�
		String^ AccountID;
		///�ڻ�����
		String^ Password;
		///��װ���
		Int32 InstallID;
		///�ڻ���˾��ˮ��
		Int32 FutureSerial;
		///�û���ʶ
		String^ UserID;
		///��֤�ͻ�֤�������־
		char VerifyCertNoFlag;
		///���ִ���
		String^ CurrencyID;
		///ת�ʽ��
		double TradeAmount;
		///�ڻ���ȡ���
		double FutureFetchAmount;
		///����֧����־
		char FeePayFlag;
		///Ӧ�տͻ�����
		double CustFee;
		///Ӧ���ڻ���˾����
		double BrokerFee;
		///���ͷ������շ�����Ϣ
		String^ Message;
		///ժҪ
		String^ Digest;
		///�����ʺ�����
		char BankAccType;
		///������־
		String^ DeviceID;
		///�ڻ���λ�ʺ�����
		char BankSecuAccType;
		///�ڻ���˾���б���
		String^ BrokerIDByBank;
		///�ڻ���λ�ʺ�
		String^ BankSecuAcc;
		///���������־
		char BankPwdFlag;
		///�ڻ��ʽ�����˶Ա�־
		char SecuPwdFlag;
		///���׹�Ա
		String^ OperNo;
		///������
		Int32 RequestID;
		///����ID
		Int32 TID;
		///ת�˽���״̬
		char TransferStatus;
		///���ͻ�����
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
		///ҵ������
		String^ TradeCode;
		///���д���
		String^ BankID;
		///���з�֧��������
		String^ BankBranchID;
		///���̴���
		String^ BrokerID;
		///���̷�֧��������
		String^ BrokerBranchID;
		///��������
		String^ TradeDate;
		///����ʱ��
		String^ TradeTime;
		///������ˮ��
		String^ BankSerial;
		///����ϵͳ���� 
		String^ TradingDay;
		///����ƽ̨��Ϣ��ˮ��
		Int32 PlateSerial;
		///����Ƭ��־
		char LastFragment;
		///�Ự��
		Int32 SessionID;
		///�ͻ�����
		String^ CustomerName;
		///֤������
		char IdCardType;
		///֤������
		String^ IdentifiedCardNo;
		///�ͻ�����
		char CustType;
		///�����ʺ�
		String^ BankAccount;
		///��������
		String^ BankPassWord;
		///Ͷ�����ʺ�
		String^ AccountID;
		///�ڻ�����
		String^ Password;
		///��װ���
		Int32 InstallID;
		///�ڻ���˾��ˮ��
		Int32 FutureSerial;
		///�û���ʶ
		String^ UserID;
		///��֤�ͻ�֤�������־
		char VerifyCertNoFlag;
		///���ִ���
		String^ CurrencyID;
		///ת�ʽ��
		double TradeAmount;
		///�ڻ���ȡ���
		double FutureFetchAmount;
		///����֧����־
		char FeePayFlag;
		///Ӧ�տͻ�����
		double CustFee;
		///Ӧ���ڻ���˾����
		double BrokerFee;
		///���ͷ������շ�����Ϣ
		String^ Message;
		///ժҪ
		String^ Digest;
		///�����ʺ�����
		char BankAccType;
		///������־
		String^ DeviceID;
		///�ڻ���λ�ʺ�����
		char BankSecuAccType;
		///�ڻ���˾���б���
		String^ BrokerIDByBank;
		///�ڻ���λ�ʺ�
		String^ BankSecuAcc;
		///���������־
		char BankPwdFlag;
		///�ڻ��ʽ�����˶Ա�־
		char SecuPwdFlag;
		///���׹�Ա
		String^ OperNo;
		///������
		Int32 RequestID;
		///����ID
		Int32 TID;
		///ת�˽���״̬
		char TransferStatus;
		///���ͻ�����
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
		///���͹�˾����
		String^ BrokerID;
		///Ͷ�����ʺ�
		String^ AccountID;
		///ԭ���Ŀ���
		String^ OldPassword;
		///�µĿ���
		String^ NewPassword;
		///���ִ���
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
		///ҵ������
		String^ TradeCode;
		///���д���
		String^ BankID;
		///���з�֧��������
		String^ BankBranchID;
		///���̴���
		String^ BrokerID;
		///���̷�֧��������
		String^ BrokerBranchID;
		///��������
		String^ TradeDate;
		///����ʱ��
		String^ TradeTime;
		///������ˮ��
		String^ BankSerial;
		///����ϵͳ���� 
		String^ TradingDay;
		///����ƽ̨��Ϣ��ˮ��
		Int32 PlateSerial;
		///����Ƭ��־
		char LastFragment;
		///�Ự��
		Int32 SessionID;
		///�ͻ�����
		String^ CustomerName;
		///֤������
		char IdCardType;
		///֤������
		String^ IdentifiedCardNo;
		///�ͻ�����
		char CustType;
		///�����ʺ�
		String^ BankAccount;
		///��������
		String^ BankPassWord;
		///Ͷ�����ʺ�
		String^ AccountID;
		///�ڻ�����
		String^ Password;
		///�ڻ���˾��ˮ��
		Int32 FutureSerial;
		///��װ���
		Int32 InstallID;
		///�û���ʶ
		String^ UserID;
		///��֤�ͻ�֤�������־
		char VerifyCertNoFlag;
		///���ִ���
		String^ CurrencyID;
		///ժҪ
		String^ Digest;
		///�����ʺ�����
		char BankAccType;
		///������־
		String^ DeviceID;
		///�ڻ���λ�ʺ�����
		char BankSecuAccType;
		///�ڻ���˾���б���
		String^ BrokerIDByBank;
		///�ڻ���λ�ʺ�
		String^ BankSecuAcc;
		///���������־
		char BankPwdFlag;
		///�ڻ��ʽ�����˶Ա�־
		char SecuPwdFlag;
		///���׹�Ա
		String^ OperNo;
		///������
		Int32 RequestID;
		///����ID
		Int32 TID;
		///���ͻ�����
		String^ LongCustomerName;
	};
	public ref class UserPasswordUpdateRequestData
	{
	public:
		CThostFtdcUserPasswordUpdateField  ToNative()
		{
			CThostFtdcUserPasswordUpdateField  native = { 0 };
			///���͹�˾����
			copy_string_to_array(BrokerID, native.BrokerID);
			///�û�����
			copy_string_to_array(UserID, native.UserID);
			///ԭ���Ŀ���
			copy_string_to_array(OldPassword, native.OldPassword);
			///�µĿ���
			copy_string_to_array(NewPassword, native.NewPassword);
			return native;
		}
		///���͹�˾����
		String^ BrokerID;
		///�û�����
		String^ UserID;
		///ԭ���Ŀ���
		String^ OldPassword;
		///�µĿ���
		String^ NewPassword;
	};
	public ref class QueryMaxOrderVolumeRequestData
	{
	public:
		CThostFtdcQueryMaxOrderVolumeField  ToNative()
		{
			CThostFtdcQueryMaxOrderVolumeField  native = { 0 };
			///���͹�˾����
			copy_string_to_array(BrokerID, native.BrokerID);
			///Ͷ���ߴ���
			copy_string_to_array(InvestorID, native.InvestorID);
			///��Լ����
			copy_string_to_array(InstrumentID, native.InstrumentID);
			///��������
			native.Direction = Direction;
			///��ƽ��־
			native.OffsetFlag = OffsetFlag;
			///Ͷ���ױ���־
			native.HedgeFlag = HedgeFlag;
			///�������������
			native.MaxVolume = MaxVolume;
			///����������
			copy_string_to_array(ExchangeID, native.ExchangeID);
			///Ͷ�ʵ�Ԫ����
			copy_string_to_array(InvestUnitID, native.InvestUnitID);
			return native;
		}
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///��Լ����
		String^ InstrumentID;
		///��������
		char Direction;
		///��ƽ��־
		char OffsetFlag;
		///Ͷ���ױ���־
		char HedgeFlag;
		///�������������
		Int32 MaxVolume;
		///����������
		String^ ExchangeID;
		///Ͷ�ʵ�Ԫ����
		String^ InvestUnitID;
	};
	public ref class TradeRequestData
	{
	public:
		CThostFtdcQryTradeField  ToNative()
		{
			CThostFtdcQryTradeField  native = { 0 };
			///���͹�˾����
			copy_string_to_array(BrokerID, native.BrokerID);
			///Ͷ���ߴ���
			copy_string_to_array(InvestorID, native.InvestorID);
			///��Լ����
			copy_string_to_array(InstrumentID, native.InstrumentID);
			///����������
			copy_string_to_array(ExchangeID, native.ExchangeID);
			///�ɽ����
			copy_string_to_array(TradeID, native.TradeID);
			///��ʼʱ��
			copy_string_to_array(TradeTimeStart, native.TradeTimeStart);
			///����ʱ��
			copy_string_to_array(TradeTimeEnd, native.TradeTimeEnd);
			///Ͷ�ʵ�Ԫ����
			copy_string_to_array(InvestUnitID, native.InvestUnitID);
			return native;
		}
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///��Լ����
		String^ InstrumentID;
		///����������
		String^ ExchangeID;
		///�ɽ����
		String^ TradeID;
		///��ʼʱ��
		String^ TradeTimeStart;
		///����ʱ��
		String^ TradeTimeEnd;
		///Ͷ�ʵ�Ԫ����
		String^ InvestUnitID;
	};
	public ref class InvestorPositionDetailRequestData
	{
	public:
		CThostFtdcQryInvestorPositionDetailField  ToNative()
		{
			CThostFtdcQryInvestorPositionDetailField  native = { 0 };
			///���͹�˾����
			copy_string_to_array(BrokerID, native.BrokerID);
			///Ͷ���ߴ���
			copy_string_to_array(InvestorID, native.InvestorID);
			///��Լ����
			copy_string_to_array(InstrumentID, native.InstrumentID);
			///����������
			copy_string_to_array(ExchangeID, native.ExchangeID);
			///Ͷ�ʵ�Ԫ����
			copy_string_to_array(InvestUnitID, native.InvestUnitID);
			return native;
		}
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///��Լ����
		String^ InstrumentID;
		///����������
		String^ ExchangeID;
		///Ͷ�ʵ�Ԫ����
		String^ InvestUnitID;
	};
	public ref class InvestorRequestData
	{
	public:
		CThostFtdcQryInvestorField  ToNative()
		{
			CThostFtdcQryInvestorField  native = { 0 };
			///���͹�˾����
			copy_string_to_array(BrokerID, native.BrokerID);
			///Ͷ���ߴ���
			copy_string_to_array(InvestorID, native.InvestorID);
			return native;
		}
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
	};
	public ref class TradingCodeRequestData
	{
	public:
		CThostFtdcQryTradingCodeField  ToNative()
		{
			CThostFtdcQryTradingCodeField  native = { 0 };
			///���͹�˾����
			copy_string_to_array(BrokerID, native.BrokerID);
			///Ͷ���ߴ���
			copy_string_to_array(InvestorID, native.InvestorID);
			///����������
			copy_string_to_array(ExchangeID, native.ExchangeID);
			///�ͻ�����
			copy_string_to_array(ClientID, native.ClientID);
			///���ױ�������
			native.ClientIDType = ClientIDType;
			///Ͷ�ʵ�Ԫ����
			copy_string_to_array(InvestUnitID, native.InvestUnitID);
			return native;
		}
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///����������
		String^ ExchangeID;
		///�ͻ�����
		String^ ClientID;
		///���ױ�������
		char ClientIDType;
		///Ͷ�ʵ�Ԫ����
		String^ InvestUnitID;
	};
	public ref class InstrumentMarginRateRequestData
	{
	public:
		CThostFtdcQryInstrumentMarginRateField  ToNative()
		{
			CThostFtdcQryInstrumentMarginRateField  native = { 0 };
			///���͹�˾����
			copy_string_to_array(BrokerID, native.BrokerID);
			///Ͷ���ߴ���
			copy_string_to_array(InvestorID, native.InvestorID);
			///��Լ����
			copy_string_to_array(InstrumentID, native.InstrumentID);
			///Ͷ���ױ���־
			native.HedgeFlag = HedgeFlag;
			///����������
			copy_string_to_array(ExchangeID, native.ExchangeID);
			///Ͷ�ʵ�Ԫ����
			copy_string_to_array(InvestUnitID, native.InvestUnitID);
			return native;
		}
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///��Լ����
		String^ InstrumentID;
		///Ͷ���ױ���־
		char HedgeFlag;
		///����������
		String^ ExchangeID;
		///Ͷ�ʵ�Ԫ����
		String^ InvestUnitID;
	};
	public ref class InstrumentCommissionRateRequestData
	{
	public:
		CThostFtdcQryInstrumentCommissionRateField  ToNative()
		{
			CThostFtdcQryInstrumentCommissionRateField  native = { 0 };
			///���͹�˾����
			copy_string_to_array(BrokerID, native.BrokerID);
			///Ͷ���ߴ���
			copy_string_to_array(InvestorID, native.InvestorID);
			///��Լ����
			copy_string_to_array(InstrumentID, native.InstrumentID);
			///����������
			copy_string_to_array(ExchangeID, native.ExchangeID);
			///Ͷ�ʵ�Ԫ����
			copy_string_to_array(InvestUnitID, native.InvestUnitID);
			return native;
		}
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///��Լ����
		String^ InstrumentID;
		///����������
		String^ ExchangeID;
		///Ͷ�ʵ�Ԫ����
		String^ InvestUnitID;
	};
	public ref class InstrumentRequestData
	{
	public:
		CThostFtdcQryInstrumentField  ToNative()
		{
			CThostFtdcQryInstrumentField  native = { 0 };
			///��Լ����
			copy_string_to_array(InstrumentID, native.InstrumentID);
			///����������
			copy_string_to_array(ExchangeID, native.ExchangeID);
			///��Լ�ڽ������Ĵ���
			copy_string_to_array(ExchangeInstID, native.ExchangeInstID);
			///��Ʒ����
			copy_string_to_array(ProductID, native.ProductID);
			return native;
		}
		///��Լ����
		String^ InstrumentID;
		///����������
		String^ ExchangeID;
		///��Լ�ڽ������Ĵ���
		String^ ExchangeInstID;
		///��Ʒ����
		String^ ProductID;
	};
	public ref class QrySettlementInfoRequestData
	{
	public:
		CThostFtdcQrySettlementInfoField  ToNative()
		{
			CThostFtdcQrySettlementInfoField  native = { 0 };
			///���͹�˾����
			copy_string_to_array(BrokerID, native.BrokerID);
			///Ͷ���ߴ���
			copy_string_to_array(InvestorID, native.InvestorID);
			///������
			copy_string_to_array(TradingDay, native.TradingDay);
			///Ͷ�����ʺ�
			copy_string_to_array(AccountID, native.AccountID);
			///���ִ���
			copy_string_to_array(CurrencyID, native.CurrencyID);
			return native;
		}
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///������
		String^ TradingDay;
		///Ͷ�����ʺ�
		String^ AccountID;
		///���ִ���
		String^ CurrencyID;
	};
	public ref class QrySettlementInfoConfirmRequestData
	{
	public:
		CThostFtdcQrySettlementInfoConfirmField  ToNative()
		{
			CThostFtdcQrySettlementInfoConfirmField  native = { 0 };
			///���͹�˾����
			copy_string_to_array(BrokerID, native.BrokerID);
			///Ͷ���ߴ���
			copy_string_to_array(InvestorID, native.InvestorID);
			///Ͷ�����ʺ�
			copy_string_to_array(AccountID, native.AccountID);
			///���ִ���
			copy_string_to_array(CurrencyID, native.CurrencyID);
			return native;
		}
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///Ͷ�����ʺ�
		String^ AccountID;
		///���ִ���
		String^ CurrencyID;
	};
	public ref class SettlementInfoConfirmRequestData
	{
	public:
		CThostFtdcSettlementInfoConfirmField  ToNative()
		{
			CThostFtdcSettlementInfoConfirmField  native = { 0 };
			///���͹�˾����
			copy_string_to_array(BrokerID, native.BrokerID);
			///Ͷ���ߴ���
			copy_string_to_array(InvestorID, native.InvestorID);
			///ȷ������
			copy_string_to_array(ConfirmDate, native.ConfirmDate);
			///ȷ��ʱ��
			copy_string_to_array(ConfirmTime, native.ConfirmTime);
			///������
			native.SettlementID = SettlementID;
			///Ͷ�����ʺ�
			copy_string_to_array(AccountID, native.AccountID);
			///���ִ���
			copy_string_to_array(CurrencyID, native.CurrencyID);
			return native;
		}
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///ȷ������
		String^ ConfirmDate;
		///ȷ��ʱ��
		String^ ConfirmTime;
		///������
		Int32 SettlementID;
		///Ͷ�����ʺ�
		String^ AccountID;
		///���ִ���
		String^ CurrencyID;
	};
	public ref class NoticeRequestData
	{
	public:
		CThostFtdcQryNoticeField  ToNative()
		{
			CThostFtdcQryNoticeField  native = { 0 };
			///���͹�˾����
			copy_string_to_array(BrokerID, native.BrokerID);
			return native;
		}
		///���͹�˾����
		String^ BrokerID;
	};
	public ref class TradingNoticeRequestData
	{
	public:
		CThostFtdcQryTradingNoticeField  ToNative()
		{
			CThostFtdcQryTradingNoticeField  native = { 0 };
			///���͹�˾����
			copy_string_to_array(BrokerID, native.BrokerID);
			///Ͷ���ߴ���
			copy_string_to_array(InvestorID, native.InvestorID);
			///Ͷ�ʵ�Ԫ����
			copy_string_to_array(InvestUnitID, native.InvestUnitID);
			return native;
		}
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///Ͷ�ʵ�Ԫ����
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
		///��������
		String^ TradeDay;
		///���б���
		String^ BankID;
		///���з�֧��������
		String^ BankBranchID;
		///�����ʺ�
		String^ BankAccount;
		///�ڻ���˾����
		String^ BrokerID;
		///�ڻ���˾��֧��������
		String^ BrokerBranchID;
		///Ͷ�����ʺ�
		String^ AccountID;
		///֤������
		char IdCardType;
		///֤������
		String^ IdentifiedCardNo;
		///�ͻ�����
		String^ CustomerName;
		///���ִ���
		String^ CurrencyID;
		///���������
		char OpenOrDestroy;
		///ǩԼ����
		String^ RegDate;
		///��Լ����
		String^ OutDate;
		///����ID
		int TID;
		///�ͻ�����
		char CustType;
		///�����ʺ�����
		char BankAccType;
		///���ͻ�����
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
		///���͹�˾����
		String^ BrokerID;
		///���д���
		String^ BankID;
		///���з����Ĵ���
		String^ BankBrchID;
		///��������
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
		///ҵ������
		String^ TradeCode;
		///���д���
		String^ BankID;
		///���з�֧��������
		String^ BankBranchID;
		///���̴���
		String^ BrokerID;
		///���̷�֧��������
		String^ BrokerBranchID;
		///��������
		String^ TradeDate;
		///����ʱ��
		String^ TradeTime;
		///������ˮ��
		String^ BankSerial;
		///����ϵͳ���� 
		String^ TradingDay;
		///����ƽ̨��Ϣ��ˮ��
		int PlateSerial;
		///����Ƭ��־
		char LastFragment;
		///�Ự��
		int SessionID;
		///�ͻ�����
		String^ CustomerName;
		///֤������
		char IdCardType;
		///֤������
		String^ IdentifiedCardNo;
		///�ͻ�����
		char CustType;
		///�����ʺ�
		String^ BankAccount;
		///��������
		String^ BankPassWord;
		///Ͷ�����ʺ�
		String^ AccountID;
		///�ڻ�����
		String^ Password;
		///��װ���
		int InstallID;
		///�ڻ���˾��ˮ��
		int FutureSerial;
		///�û���ʶ
		String^ UserID;
		///��֤�ͻ�֤�������־
		char VerifyCertNoFlag;
		///���ִ���
		String^ CurrencyID;
		///ת�ʽ��
		double TradeAmount;
		///�ڻ���ȡ���
		double FutureFetchAmount;
		///����֧����־
		double FeePayFlag;
		///Ӧ�տͻ�����
		double CustFee;
		///Ӧ���ڻ���˾����
		double BrokerFee;
		///���ͷ������շ�����Ϣ
		String^ Message;
		///ժҪ
		String^ Digest;
		///�����ʺ�����
		double BankAccType;
		///������־
		String^ DeviceID;
		///�ڻ���λ�ʺ�����
		char BankSecuAccType;
		///�ڻ���˾���б���
		String^ BrokerIDByBank;
		///�ڻ���λ�ʺ�
		String^ BankSecuAcc;
		///���������־
		char BankPwdFlag;
		///�ڻ��ʽ�����˶Ա�־
		char SecuPwdFlag;
		///���׹�Ա
		String^ OperNo;
		///������
		int RequestID;
		///����ID
		int TID;
		///ת�˽���״̬
		char TransferStatus;
		///���ͻ�����
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
		///ҵ������
		String^ TradeCode;
		///���д���
		String^ BankID;
		///���з�֧��������
		String^ BankBranchID;
		///���̴���
		String^ BrokerID;
		///���̷�֧��������
		String^ BrokerBranchID;
		///��������
		String^ TradeDate;
		///����ʱ��
		String^ TradeTime;
		///������ˮ��
		String^ BankSerial;
		///����ϵͳ���� 
		String^ TradingDay;
		///����ƽ̨��Ϣ��ˮ��
		int PlateSerial;
		///����Ƭ��־
		char LastFragment;
		///�Ự��
		int SessionID;
		///�ͻ�����
		String^ CustomerName;
		///֤������
		char IdCardType;
		///֤������
		String^ IdentifiedCardNo;
		///�ͻ�����
		char CustType;
		///�����ʺ�
		String^ BankAccount;
		///��������
		String^ BankPassWord;
		///Ͷ�����ʺ�
		String^ AccountID;
		///�ڻ�����
		String^ Password;
		///��װ���
		int InstallID;
		///�ڻ���˾��ˮ��
		int FutureSerial;
		///�û���ʶ
		String^ UserID;
		///��֤�ͻ�֤�������־
		char VerifyCertNoFlag;
		///���ִ���
		String^ CurrencyID;
		///ת�ʽ��
		double TradeAmount;
		///�ڻ���ȡ���
		double FutureFetchAmount;
		///����֧����־
		double FeePayFlag;
		///Ӧ�տͻ�����
		double CustFee;
		///Ӧ���ڻ���˾����
		double BrokerFee;
		///���ͷ������շ�����Ϣ
		String^ Message;
		///ժҪ
		String^ Digest;
		///�����ʺ�����
		double BankAccType;
		///������־
		String^ DeviceID;
		///�ڻ���λ�ʺ�����
		char BankSecuAccType;
		///�ڻ���˾���б���
		String^ BrokerIDByBank;
		///�ڻ���λ�ʺ�
		String^ BankSecuAcc;
		///���������־
		char BankPwdFlag;
		///�ڻ��ʽ�����˶Ա�־
		char SecuPwdFlag;
		///���׹�Ա
		String^ OperNo;
		///������
		int RequestID;
		///����ID
		int TID;
		///ת�˽���״̬
		char TransferStatus;
		///�������
		int ErrorID;
		///������Ϣ
		String^ ErrorMsg;
		///���ͻ�����
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
		///ҵ������
		String^ TradeCode;
		///���д���
		String^ BankID;
		///���з�֧��������
		String^ BankBranchID;
		///���̴���
		String^ BrokerID;
		///���̷�֧��������
		String^ BrokerBranchID;
		///��������
		String^ TradeDate;
		///����ʱ��
		String^ TradeTime;
		///������ˮ��
		String^ BankSerial;
		///����ϵͳ���� 
		String^ TradingDay;
		///����ƽ̨��Ϣ��ˮ��
		int PlateSerial;
		///����Ƭ��־
		char LastFragment;
		///�Ự��
		int SessionID;
		///�ͻ�����
		String^ CustomerName;
		///֤������
		char IdCardType;
		///֤������
		String^ IdentifiedCardNo;
		///�ͻ�����
		char CustType;
		///�����ʺ�
		String^ BankAccount;
		///��������
		String^ BankPassWord;
		///Ͷ�����ʺ�
		String^ AccountID;
		///�ڻ�����
		String^ Password;
		///��װ���
		int InstallID;
		///�ڻ���˾��ˮ��
		int FutureSerial;
		///�û���ʶ
		String^ UserID;
		///��֤�ͻ�֤�������־
		char VerifyCertNoFlag;
		///���ִ���
		String^ CurrencyID;
		///ת�ʽ��
		double TradeAmount;
		///�ڻ���ȡ���
		double FutureFetchAmount;
		///����֧����־
		double FeePayFlag;
		///Ӧ�տͻ�����
		double CustFee;
		///Ӧ���ڻ���˾����
		double BrokerFee;
		///���ͷ������շ�����Ϣ
		String^ Message;
		///ժҪ
		String^ Digest;
		///�����ʺ�����
		double BankAccType;
		///������־
		String^ DeviceID;
		///�ڻ���λ�ʺ�����
		char BankSecuAccType;
		///�ڻ���˾���б���
		String^ BrokerIDByBank;
		///�ڻ���λ�ʺ�
		String^ BankSecuAcc;
		///���������־
		char BankPwdFlag;
		///�ڻ��ʽ�����˶Ա�־
		char SecuPwdFlag;
		///���׹�Ա
		String^ OperNo;
		///������
		int RequestID;
		///����ID
		int TID;
		///ת�˽���״̬
		char TransferStatus;
		///���ͻ�����
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
		///ҵ������
		String^ TradeCode;
		///���д���
		String^ BankID;
		///���з�֧��������
		String^ BankBranchID;
		///���̴���
		String^ BrokerID;
		///���̷�֧��������
		String^ BrokerBranchID;
		///��������
		String^ TradeDate;
		///����ʱ��
		String^ TradeTime;
		///������ˮ��
		String^ BankSerial;
		///����ϵͳ���� 
		String^ TradingDay;
		///����ƽ̨��Ϣ��ˮ��
		int PlateSerial;
		///����Ƭ��־
		char LastFragment;
		///�Ự��
		int SessionID;
		///�ͻ�����
		String^ CustomerName;
		///֤������
		char IdCardType;
		///֤������
		String^ IdentifiedCardNo;
		///�ͻ�����
		char CustType;
		///�����ʺ�
		String^ BankAccount;
		///��������
		String^ BankPassWord;
		///Ͷ�����ʺ�
		String^ AccountID;
		///�ڻ�����
		String^ Password;
		///��װ���
		int InstallID;
		///�ڻ���˾��ˮ��
		int FutureSerial;
		///�û���ʶ
		String^ UserID;
		///��֤�ͻ�֤�������־
		char VerifyCertNoFlag;
		///���ִ���
		String^ CurrencyID;
		///ת�ʽ��
		double TradeAmount;
		///�ڻ���ȡ���
		double FutureFetchAmount;
		///����֧����־
		double FeePayFlag;
		///Ӧ�տͻ�����
		double CustFee;
		///Ӧ���ڻ���˾����
		double BrokerFee;
		///���ͷ������շ�����Ϣ
		String^ Message;
		///ժҪ
		String^ Digest;
		///�����ʺ�����
		double BankAccType;
		///������־
		String^ DeviceID;
		///�ڻ���λ�ʺ�����
		char BankSecuAccType;
		///�ڻ���˾���б���
		String^ BrokerIDByBank;
		///�ڻ���λ�ʺ�
		String^ BankSecuAcc;
		///���������־
		char BankPwdFlag;
		///�ڻ��ʽ�����˶Ա�־
		char SecuPwdFlag;
		///���׹�Ա
		String^ OperNo;
		///������
		int RequestID;
		///����ID
		int TID;
		///ת�˽���״̬
		char TransferStatus;
		///�������
		int ErrorID;
		///������Ϣ
		String^ ErrorMsg;
		///���ͻ�����
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
		///���͹�˾����
		String^ BrokerID;
		///Ͷ�����ʺ�
		String^ AccountID;
		///ԭ���Ŀ���
		String^ OldPassword;
		///�µĿ���
		String^ NewPassword;
		///���ִ���
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
		///ҵ������
		String^ TradeCode;
		///���д���
		String^ BankID;
		///���з�֧��������
		String^ BankBranchID;
		///���̴���
		String^ BrokerID;
		///���̷�֧��������
		String^ BrokerBranchID;
		///��������
		String^ TradeDate;
		///����ʱ��
		String^ TradeTime;
		///������ˮ��
		String^ BankSerial;
		///����ϵͳ���� 
		String^ TradingDay;
		///����ƽ̨��Ϣ��ˮ��
		int PlateSerial;
		///����Ƭ��־
		char LastFragment;
		///�Ự��
		int SessionID;
		///�ͻ�����
		String^ CustomerName;
		///֤������
		char IdCardType;
		///֤������
		String^ IdentifiedCardNo;
		///�ͻ�����
		char CustType;
		///�����ʺ�
		String^ BankAccount;
		///��������
		String^ BankPassWord;
		///Ͷ�����ʺ�
		String^ AccountID;
		///�ڻ�����
		String^ Password;
		///�ڻ���˾��ˮ��
		int FutureSerial;
		///��װ���
		int InstallID;
		///�û���ʶ
		String^ UserID;
		///��֤�ͻ�֤�������־
		char VerifyCertNoFlag;
		///���ִ���
		String^ CurrencyID;
		///ժҪ
		String^ Digest;
		///�����ʺ�����
		double BankAccType;
		///������־
		String^ DeviceID;
		///�ڻ���λ�ʺ�����
		char BankSecuAccType;
		///�ڻ���˾���б���
		String^ BrokerIDByBank;
		///�ڻ���λ�ʺ�
		String^ BankSecuAcc;
		///���������־
		char BankPwdFlag;
		///�ڻ��ʽ�����˶Ա�־
		char SecuPwdFlag;
		///���׹�Ա
		String^ OperNo;
		///������
		int RequestID;
		///����ID
		int TID;
		///���ͻ�����
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
		///ҵ������
		String^ TradeCode;
		///���д���
		String^ BankID;
		///���з�֧��������
		String^ BankBranchID;
		///���̴���
		String^ BrokerID;
		///���̷�֧��������
		String^ BrokerBranchID;
		///��������
		String^ TradeDate;
		///����ʱ��
		String^ TradeTime;
		///������ˮ��
		String^ BankSerial;
		///����ϵͳ���� 
		String^ TradingDay;
		///����ƽ̨��Ϣ��ˮ��
		int PlateSerial;
		///����Ƭ��־
		char LastFragment;
		///�Ự��
		int SessionID;
		///�ͻ�����
		String^ CustomerName;
		///֤������
		char IdCardType;
		///֤������
		String^ IdentifiedCardNo;
		///�ͻ�����
		char CustType;
		///�����ʺ�
		String^ BankAccount;
		///��������
		String^ BankPassWord;
		///Ͷ�����ʺ�
		String^ AccountID;
		///�ڻ�����
		String^ Password;
		///�ڻ���˾��ˮ��
		int FutureSerial;
		///��װ���
		int InstallID;
		///�û���ʶ
		String^ UserID;
		///��֤�ͻ�֤�������־
		char VerifyCertNoFlag;
		///���ִ���
		String^ CurrencyID;
		///ժҪ
		String^ Digest;
		///�����ʺ�����
		char BankAccType;
		///������־
		String^ DeviceID;
		///�ڻ���λ�ʺ�����
		char BankSecuAccType;
		///�ڻ���˾���б���
		String^ BrokerIDByBank;
		///�ڻ���λ�ʺ�
		String^ BankSecuAcc;
		///���������־
		char BankPwdFlag;
		///�ڻ��ʽ�����˶Ա�־
		char SecuPwdFlag;
		///���׹�Ա
		String^ OperNo;
		///������
		int RequestID;
		///����ID
		int TID;
		///���п��ý��
		double BankUseAmount;
		///���п�ȡ���
		double BankFetchAmount;
		///�������
		int ErrorID;
		///������Ϣ
		String^ ErrorMsg;
		///���ͻ�����
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
			///���͹�˾����
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///�û�����
			rspdata->UserID = U8ToClr((native->UserID));
			///ԭ���Ŀ���
			rspdata->OldPassword = U8ToClr((native->OldPassword));
			///�µĿ���
			rspdata->NewPassword = U8ToClr((native->NewPassword));
			return rspdata;
		}
		///���͹�˾����
		String^ BrokerID;
		///�û�����
		String^ UserID;
		///ԭ���Ŀ���
		String^ OldPassword;
		///�µĿ���
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
			///���͹�˾����
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///Ͷ���ߴ���
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///��Լ����
			rspdata->InstrumentID = U8ToClr((native->InstrumentID));
			///��������
			rspdata->Direction = native->Direction;
			///��ƽ��־
			rspdata->OffsetFlag = native->OffsetFlag;
			///Ͷ���ױ���־
			rspdata->HedgeFlag = native->HedgeFlag;
			///�������������
			rspdata->MaxVolume = native->MaxVolume;
			///����������
			rspdata->ExchangeID = U8ToClr((native->ExchangeID));
			///Ͷ�ʵ�Ԫ����
			rspdata->InvestUnitID = U8ToClr((native->InvestUnitID));
			return rspdata;
		}
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///��Լ����
		String^ InstrumentID;
		///��������
		char Direction;
		///��ƽ��־
		char OffsetFlag;
		///Ͷ���ױ���־
		char HedgeFlag;
		///�������������
		char MaxVolume;
		///����������
		String^ ExchangeID;
		///Ͷ�ʵ�Ԫ����
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
			///���͹�˾����
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///Ͷ���ߴ���
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///��Լ����
			rspdata->InstrumentID = U8ToClr((native->InstrumentID));
			///��������
			rspdata->OrderRef = U8ToClr((native->OrderRef));
			///�û�����
			rspdata->UserID = U8ToClr((native->UserID));
			///����������
			rspdata->ExchangeID = U8ToClr((native->ExchangeID));
			///�ɽ����
			rspdata->TradeID = U8ToClr((native->TradeID));
			///��������
			rspdata->Direction = native->Direction;
			///�������
			rspdata->OrderSysID = U8ToClr((native->OrderSysID));
			///��Ա����
			rspdata->ParticipantID = U8ToClr((native->ParticipantID));
			///�ͻ�����
			rspdata->ClientID = U8ToClr((native->ClientID));
			///���׽�ɫ
			rspdata->TradingRole = native->TradingRole;
			///��Լ�ڽ������Ĵ���
			rspdata->ExchangeInstID = U8ToClr((native->ExchangeInstID));
			///��ƽ��־
			rspdata->OffsetFlag = native->OffsetFlag;
			///Ͷ���ױ���־
			rspdata->HedgeFlag = native->HedgeFlag;
			///�۸�
			rspdata->Price = native->Price;
			///����
			rspdata->Volume = native->Volume;
			///�ɽ�ʱ��
			rspdata->TradeDate = U8ToClr((native->TradeDate));
			///�ɽ�ʱ��
			rspdata->TradeTime = U8ToClr((native->TradeTime));
			///�ɽ�����
			rspdata->TradeType = native->TradeType;
			///�ɽ�����Դ
			rspdata->PriceSource = native->PriceSource;
			///����������Ա����
			rspdata->TraderID = U8ToClr((native->TraderID));
			///���ر������
			rspdata->OrderLocalID = U8ToClr((native->OrderLocalID));
			///�����Ա���
			rspdata->ClearingPartID = U8ToClr((native->ClearingPartID));
			///ҵ��Ԫ
			rspdata->BusinessUnit = U8ToClr((native->BusinessUnit));
			///���
			rspdata->SequenceNo = native->SequenceNo;
			///������
			rspdata->TradingDay = U8ToClr((native->TradingDay));
			///������
			rspdata->SettlementID = native->SettlementID;
			///���͹�˾�������
			rspdata->BrokerOrderSeq = native->BrokerOrderSeq;
			///�ɽ���Դ
			rspdata->TradeSource = native->TradeSource;
			///Ͷ�ʵ�Ԫ����
			rspdata->InvestUnitID = U8ToClr((native->InvestUnitID));
			return rspdata;
		}
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///��Լ����
		String^ InstrumentID;
		///��������
		String^ OrderRef;
		///�û�����
		String^ UserID;
		///����������
		String^ ExchangeID;
		///�ɽ����
		String^ TradeID;
		///��������
		char Direction;
		///�������
		String^ OrderSysID;
		///��Ա����
		String^ ParticipantID;
		///�ͻ�����
		String^ ClientID;
		///���׽�ɫ
		char TradingRole;
		///��Լ�ڽ������Ĵ���
		String^ ExchangeInstID;
		///��ƽ��־
		char OffsetFlag;
		///Ͷ���ױ���־
		char HedgeFlag;
		///�۸�
		double Price;
		///����
		int Volume;
		///�ɽ�ʱ��
		String^ TradeDate;
		///�ɽ�ʱ��
		String^ TradeTime;
		///�ɽ�����
		char TradeType;
		///�ɽ�����Դ
		char PriceSource;
		///����������Ա����
		String^ TraderID;
		///���ر������
		String^ OrderLocalID;
		///�����Ա���
		String^ ClearingPartID;
		///ҵ��Ԫ
		String^ BusinessUnit;
		///���
		int SequenceNo;
		///������
		String^ TradingDay;
		///������
		int SettlementID;
		///���͹�˾�������
		int BrokerOrderSeq;
		///�ɽ���Դ
		int TradeSource;
		///Ͷ�ʵ�Ԫ����
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
			///��Լ����
			rspdata->InstrumentID = U8ToClr((native->InstrumentID));
			///���͹�˾����
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///Ͷ���ߴ���
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///Ͷ���ױ���־
			rspdata->HedgeFlag = native->HedgeFlag;
			///����
			rspdata->Direction = native->Direction;
			///��������
			rspdata->OpenDate = U8ToClr((native->OpenDate));
			///�ɽ����
			rspdata->TradeID = U8ToClr((native->TradeID));
			///����
			rspdata->Volume = native->Volume;
			///���ּ�
			rspdata->OpenPrice = native->OpenPrice;
			///������
			rspdata->TradingDay = U8ToClr((native->TradingDay));
			///������
			rspdata->SettlementID = native->SettlementID;
			///�ɽ�����
			rspdata->TradeType = native->TradeType;
			///��Ϻ�Լ����
			rspdata->CombInstrumentID = U8ToClr((native->CombInstrumentID));
			///����������
			rspdata->ExchangeID = U8ToClr((native->ExchangeID));
			///���ն���ƽ��ӯ��
			rspdata->CloseProfitByDate = native->CloseProfitByDate;
			///��ʶԳ�ƽ��ӯ��
			rspdata->CloseProfitByTrade = native->CloseProfitByTrade;
			///���ն��гֲ�ӯ��
			rspdata->PositionProfitByDate = native->PositionProfitByDate;
			///��ʶԳ�ֲ�ӯ��
			rspdata->PositionProfitByTrade = native->PositionProfitByTrade;
			///Ͷ���߱�֤��
			rspdata->Margin = native->Margin;
			///��������֤��
			rspdata->ExchMargin = native->ExchMargin;
			///��֤����
			rspdata->MarginRateByMoney = native->MarginRateByMoney;
			///��֤����(������)
			rspdata->MarginRateByVolume = native->MarginRateByVolume;
			///������
			rspdata->LastSettlementPrice = native->LastSettlementPrice;
			///�����
			rspdata->SettlementPrice = native->SettlementPrice;
			///ƽ����
			rspdata->CloseVolume = native->CloseVolume;
			///ƽ�ֽ��
			rspdata->CloseAmount = native->CloseAmount;
			///Ͷ�ʵ�Ԫ����
			rspdata->InvestUnitID = U8ToClr((native->InvestUnitID));
			return rspdata;
		}
		///��Լ����
		String^ InstrumentID;
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///Ͷ���ױ���־
		char HedgeFlag;
		///����
		char Direction;
		///��������
		String^ OpenDate;
		///�ɽ����
		String^ TradeID;
		///����
		int Volume;
		///���ּ�
		double OpenPrice;
		///������
		String^ TradingDay;
		///������
		int SettlementID;
		///�ɽ�����
		char TradeType;
		///��Ϻ�Լ����
		String^ CombInstrumentID;
		///����������
		String^ ExchangeID;
		///���ն���ƽ��ӯ��
		double CloseProfitByDate;
		///��ʶԳ�ƽ��ӯ��
		double CloseProfitByTrade;
		///���ն��гֲ�ӯ��
		double PositionProfitByDate;
		///��ʶԳ�ֲ�ӯ��
		double PositionProfitByTrade;
		///Ͷ���߱�֤��
		double Margin;
		///��������֤��
		double ExchMargin;
		///��֤����
		double MarginRateByMoney;
		///��֤����(������)
		double MarginRateByVolume;
		///������
		double LastSettlementPrice;
		///�����
		double SettlementPrice;
		///ƽ����
		int CloseVolume;
		///ƽ�ֽ��
		double CloseAmount;
		///Ͷ�ʵ�Ԫ����
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
			///Ͷ���ߴ���
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///���͹�˾����
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///Ͷ���߷������
			rspdata->InvestorGroupID = U8ToClr((native->InvestorGroupID));
			///Ͷ��������
			rspdata->InvestorName = U8ToClr((native->InvestorName));
			///֤������
			rspdata->IdentifiedCardType = native->IdentifiedCardType;
			///֤������
			rspdata->IdentifiedCardNo = U8ToClr((native->IdentifiedCardNo));
			///�Ƿ��Ծ
			rspdata->IsActive = native->IsActive;
			///��ϵ�绰
			rspdata->Telephone = U8ToClr((native->Telephone));
			///ͨѶ��ַ
			rspdata->Address = U8ToClr((native->Address));
			///��������
			rspdata->OpenDate = U8ToClr((native->OpenDate));
			///�ֻ�
			rspdata->Mobile = U8ToClr((native->Mobile));
			///��������ģ�����
			rspdata->CommModelID = U8ToClr((native->CommModelID));
			///��֤����ģ�����
			rspdata->MarginModelID = U8ToClr((native->MarginModelID));
			return rspdata;
		}
		///Ͷ���ߴ���
		String^ InvestorID;
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���߷������
		String^ InvestorGroupID;
		///Ͷ��������
		String^ InvestorName;
		///֤������
		char IdentifiedCardType;
		///֤������
		String^ IdentifiedCardNo;
		///�Ƿ��Ծ
		int IsActive;
		///��ϵ�绰
		String^ Telephone;
		///ͨѶ��ַ
		String^ Address;
		///��������
		String^ OpenDate;
		///�ֻ�
		String^ Mobile;
		///��������ģ�����
		String^ CommModelID;
		///��֤����ģ�����
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
			///Ͷ���ߴ���
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///���͹�˾����
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///����������
			rspdata->ExchangeID = U8ToClr((native->ExchangeID));
			///�ͻ�����
			rspdata->ClientID = U8ToClr((native->ClientID));
			///�Ƿ��Ծ
			rspdata->IsActive = native->IsActive;
			///���ױ�������
			rspdata->ClientIDType = native->ClientIDType;
			///Ӫҵ�����
			rspdata->BranchID = U8ToClr((native->BranchID));
			///ҵ������
			rspdata->BizType = native->BizType;
			///Ͷ�ʵ�Ԫ����
			rspdata->InvestUnitID = U8ToClr((native->InvestUnitID));
			return rspdata;
		}
		///Ͷ���ߴ���
		String^ InvestorID;
		///���͹�˾����
		String^ BrokerID;
		///����������
		String^ ExchangeID;
		///�ͻ�����
		String^ ClientID;
		///�Ƿ��Ծ
		int IsActive;
		///���ױ�������
		char ClientIDType;
		///Ӫҵ�����
		String^ BranchID;
		///ҵ������
		char BizType;
		///Ͷ�ʵ�Ԫ����
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
			///��Լ����
			rspdata->InstrumentID = U8ToClr((native->InstrumentID));
			///Ͷ���߷�Χ
			rspdata->InvestorRange = native->InvestorRange;
			///���͹�˾����
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///Ͷ���ߴ���
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///Ͷ���ױ���־
			rspdata->HedgeFlag = native->HedgeFlag;
			///��ͷ��֤����
			rspdata->LongMarginRatioByMoney = native->LongMarginRatioByMoney;
			///��ͷ��֤���
			rspdata->LongMarginRatioByVolume = native->LongMarginRatioByVolume;
			///��ͷ��֤����
			rspdata->ShortMarginRatioByMoney =native->ShortMarginRatioByMoney;
			///��ͷ��֤���
			rspdata->ShortMarginRatioByVolume = native->ShortMarginRatioByVolume;
			///�Ƿ���Խ�������ȡ
			rspdata->IsRelative = native->IsRelative;
			///����������
			rspdata->ExchangeID = U8ToClr((native->ExchangeID));
			///Ͷ�ʵ�Ԫ����
			rspdata->InvestUnitID = U8ToClr((native->InvestUnitID));
			return rspdata;
		}
		///��Լ����
		String^ InstrumentID;
		///Ͷ���߷�Χ
		char InvestorRange;
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///Ͷ���ױ���־
		char HedgeFlag;
		///��ͷ��֤����
		double LongMarginRatioByMoney;
		///��ͷ��֤���
		double LongMarginRatioByVolume;
		///��ͷ��֤����
		double ShortMarginRatioByMoney;
		///��ͷ��֤���
		double ShortMarginRatioByVolume;
		///�Ƿ���Խ�������ȡ
		int IsRelative;
		///����������
		String^ ExchangeID;
		///Ͷ�ʵ�Ԫ����
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
			///��Լ����
			rspdata->InstrumentID = U8ToClr((native->InstrumentID));
			///Ͷ���߷�Χ
			rspdata->InvestorRange = native->InvestorRange;
			///���͹�˾����
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///Ͷ���ߴ���
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///������������
			rspdata->OpenRatioByMoney = native->OpenRatioByMoney;
			///����������
			rspdata->OpenRatioByVolume = native->OpenRatioByVolume;
			///ƽ����������
			rspdata->CloseRatioByMoney = native->CloseRatioByMoney;
			///ƽ��������
			rspdata->CloseRatioByVolume = native->CloseRatioByVolume;
			///ƽ����������
			rspdata->CloseTodayRatioByMoney = native->CloseTodayRatioByMoney;
			///ƽ��������
			rspdata->CloseTodayRatioByVolume = native->CloseTodayRatioByVolume;
			///����������
			rspdata->ExchangeID = U8ToClr((native->ExchangeID));
			///ҵ������
			rspdata->BizType = native->BizType;
			///Ͷ�ʵ�Ԫ����
			rspdata->InvestUnitID = U8ToClr((native->InvestUnitID));
			return rspdata;
		}
		///��Լ����
		String^ InstrumentID;
		///Ͷ���߷�Χ
		char InvestorRange;
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///������������
		double OpenRatioByMoney;
		///����������
		double OpenRatioByVolume;
		///ƽ����������
		double CloseRatioByMoney;
		///ƽ��������
		double CloseRatioByVolume;
		///ƽ����������
		double CloseTodayRatioByMoney;
		///ƽ��������
		double CloseTodayRatioByVolume;
		///����������
		String^ ExchangeID;
		///ҵ������
		char BizType;
		///Ͷ�ʵ�Ԫ����
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
			///��Լ����
			rspdata->InstrumentID = U8ToClr((native->InstrumentID));
			///����������
			rspdata->ExchangeID = U8ToClr((native->ExchangeID));
			///��Լ����
			rspdata->InstrumentName = U8ToClr((native->InstrumentName));
			///��Լ�ڽ������Ĵ���
			rspdata->ExchangeInstID = U8ToClr((native->ExchangeInstID));
			///��Ʒ����
			rspdata->ProductID = U8ToClr((native->ProductID));
			///��Ʒ����
			rspdata->ProductClass = native->ProductClass;
			///�������
			rspdata->DeliveryYear = native->DeliveryYear;
			///������
			rspdata->DeliveryMonth = native->DeliveryMonth;
			///�м۵�����µ���
			rspdata->MaxMarketOrderVolume = native->MaxMarketOrderVolume;
			///�м۵���С�µ���
			rspdata->MinMarketOrderVolume = native->MinMarketOrderVolume;
			///�޼۵�����µ���
			rspdata->MaxLimitOrderVolume = native->MaxLimitOrderVolume;
			///�޼۵���С�µ���
			rspdata->MinLimitOrderVolume = native->MinLimitOrderVolume;
			///��Լ��������
			rspdata->VolumeMultiple = native->VolumeMultiple;
			///��С�䶯��λ
			rspdata->PriceTick = native->PriceTick;
			///������
			rspdata->CreateDate = U8ToClr((native->CreateDate));
			///������
			rspdata->OpenDate = U8ToClr((native->OpenDate));
			///������
			rspdata->ExpireDate = U8ToClr((native->ExpireDate));
			///��ʼ������
			rspdata->StartDelivDate = U8ToClr((native->StartDelivDate));
			///����������
			rspdata->EndDelivDate = U8ToClr((native->EndDelivDate));
			///��Լ��������״̬
			rspdata->InstLifePhase = native->InstLifePhase;
			///��ǰ�Ƿ���
			rspdata->IsTrading = native->IsTrading;
			///�ֲ�����
			rspdata->PositionType = native->PositionType;
			///�ֲ���������
			rspdata->PositionDateType = native->PositionDateType;
			///��ͷ��֤����
			rspdata->LongMarginRatio = native->LongMarginRatio;
			///��ͷ��֤����
			rspdata->ShortMarginRatio = native->ShortMarginRatio;
			///�Ƿ�ʹ�ô��߱�֤���㷨
			rspdata->MaxMarginSideAlgorithm = native->MaxMarginSideAlgorithm;
			///������Ʒ����
			rspdata->UnderlyingInstrID = U8ToClr((native->UnderlyingInstrID));
			///ִ�м�
			rspdata->StrikePrice = native->StrikePrice;
			///��Ȩ����
			rspdata->OptionsType = native->OptionsType;
			///��Լ������Ʒ����
			rspdata->UnderlyingMultiple = native->UnderlyingMultiple;
			///�������
			rspdata->CombinationType = native->CombinationType;
			return rspdata;
		}
		///��Լ����
		String^ InstrumentID;
		///����������
		String^ ExchangeID;
		///��Լ����
		String^ InstrumentName;
		///��Լ�ڽ������Ĵ���
		String^ ExchangeInstID;
		///��Ʒ����
		String^ ProductID;
		///��Ʒ����
		char ProductClass;
		///�������
		int DeliveryYear;
		///������
		int DeliveryMonth;
		///�м۵�����µ���
		int  MaxMarketOrderVolume;
		///�м۵���С�µ���
		int MinMarketOrderVolume;
		///�޼۵�����µ���
		int MaxLimitOrderVolume;
		///�޼۵���С�µ���
		int MinLimitOrderVolume;
		///��Լ��������
		int VolumeMultiple;
		///��С�䶯��λ
		double PriceTick;
		///������
		String^ CreateDate;
		///������
		String^ OpenDate;
		///������
		String^ ExpireDate;
		///��ʼ������
		String^ StartDelivDate;
		///����������
		String^ EndDelivDate;
		///��Լ��������״̬
		char InstLifePhase;
		///��ǰ�Ƿ���
		int IsTrading;
		///�ֲ�����
		char PositionType;
		///�ֲ���������
		char PositionDateType;
		///��ͷ��֤����
		double LongMarginRatio;
		///��ͷ��֤����
		double ShortMarginRatio;
		///�Ƿ�ʹ�ô��߱�֤���㷨
		char MaxMarginSideAlgorithm;
		///������Ʒ����
		String^ UnderlyingInstrID;
		///ִ�м�
		double StrikePrice;
		///��Ȩ����
		char OptionsType;
		///��Լ������Ʒ����
		double UnderlyingMultiple;
		///�������
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
			///������
			rspdata->TradingDay = U8ToClr((native->TradingDay));
			///������
			rspdata->SettlementID = native->SettlementID;
			///���͹�˾����
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///Ͷ���ߴ���
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///���
			rspdata->SequenceNo = native->SequenceNo;
			///��Ϣ����
			rspdata->Content = U8ToClr((native->Content));
			///Ͷ�����ʺ�
			rspdata->AccountID = U8ToClr((native->AccountID));
			///���ִ���
			rspdata->CurrencyID = U8ToClr((native->CurrencyID));
			return rspdata;
		}
		///������
		String^ TradingDay;
		///������
		int SettlementID;
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///���
		int SequenceNo;
		///��Ϣ����
		String^ Content;
		///Ͷ�����ʺ�
		String^ AccountID;
		///���ִ���
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
			///���͹�˾����
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///Ͷ���ߴ���
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///ȷ������
			rspdata->ConfirmDate = U8ToClr((native->ConfirmDate));
			///ȷ��ʱ��
			rspdata->ConfirmTime = U8ToClr((native->ConfirmTime));
			///������
			rspdata->SettlementID = native->SettlementID;
			///Ͷ�����ʺ�
			rspdata->AccountID = U8ToClr((native->AccountID));
			///���ִ���
			rspdata->CurrencyID = U8ToClr((native->CurrencyID));
			return rspdata;
		}
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///ȷ������
		String^ ConfirmDate;
		///ȷ��ʱ��
		String^ ConfirmTime;
		///������
		int SettlementID;
		///Ͷ�����ʺ�
		String^ AccountID;
		///���ִ���
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
			///���͹�˾����
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///Ͷ���ߴ���
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///ȷ������
			rspdata->ConfirmDate = U8ToClr((native->ConfirmDate));
			///ȷ��ʱ��
			rspdata->ConfirmTime = U8ToClr((native->ConfirmTime));
			///������
			rspdata->SettlementID = native->SettlementID;
			///Ͷ�����ʺ�
			rspdata->AccountID = U8ToClr((native->AccountID));
			///���ִ���
			rspdata->CurrencyID = U8ToClr((native->CurrencyID));
			return rspdata;
		}
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���ߴ���
		String^ InvestorID;
		///ȷ������
		String^ ConfirmDate;
		///ȷ��ʱ��
		String^ ConfirmTime;
		///������
		int SettlementID;
		///Ͷ�����ʺ�
		String^ AccountID;
		///���ִ���
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
			///���͹�˾����
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///��Ϣ����
			rspdata->Content = U8ToClr((native->Content));
			///���͹�˾֪ͨ�������к�
			rspdata->SequenceLabel = U8ToClr((native->SequenceLabel));
			return rspdata;
		}
		///���͹�˾����
		String^ BrokerID;
		///��Ϣ����
		String^ Content;
		///���͹�˾֪ͨ�������к�
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
			///���͹�˾����
			rspdata->BrokerID = U8ToClr((native->BrokerID));
			///Ͷ���߷�Χ
			rspdata->InvestorRange = native->InvestorRange;
			///Ͷ���ߴ���
			rspdata->InvestorID = U8ToClr((native->InvestorID));
			///����ϵ�к�
			rspdata->SequenceSeries = native->SequenceSeries;
			///�û�����
			rspdata->UserID = U8ToClr((native->UserID));
			///����ʱ��
			rspdata->SendTime = U8ToClr((native->SendTime));
			///���к�
			rspdata->SequenceNo = native->SequenceNo;
			///��Ϣ����
			rspdata->FieldContent = U8ToClr((native->FieldContent));
			///Ͷ�ʵ�Ԫ����
			rspdata->InvestUnitID = U8ToClr((native->InvestUnitID));
			return rspdata;
		}
		///���͹�˾����
		String^ BrokerID;
		///Ͷ���߷�Χ
		char InvestorRange;
		///Ͷ���ߴ���
		String^ InvestorID;
		///����ϵ�к�
		short SequenceSeries;
		///�û�����
		String^ UserID;
		///����ʱ��
		String^ SendTime;
		///���к�
		int SequenceNo;
		///��Ϣ����
		String^ FieldContent;
		///Ͷ�ʵ�Ԫ����
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
		///��Լ����
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
			///��Լ����
			rspdata->InstrumentID = U8ToClr((native->InstrumentID));
			///����������
			rspdata->ExchangeID = U8ToClr((native->ExchangeID));
			///��Լ�ڽ������Ĵ���
			rspdata->ExchangeInstID = U8ToClr((native->ExchangeInstID));
			///���¼�
			rspdata->LastPrice= native->LastPrice;
			///�ϴν����
			rspdata->PreSettlementPrice= native->PreSettlementPrice;
			///������
			rspdata->PreClosePrice= native->PreClosePrice;
			///��ֲ���
			rspdata->PreOpenInterest= native->PreOpenInterest;
			///����
			rspdata->OpenPrice= native->OpenPrice;
			///��߼�
			rspdata->HighestPrice= native->HighestPrice;
			///��ͼ�
			rspdata->LowestPrice= native->LowestPrice;
			///����
			rspdata->Volume= native->Volume;
			///�ɽ����
			rspdata->Turnover= native->Turnover;
			///�ֲ���
			rspdata->OpenInterest= native->OpenInterest;
			///������
			rspdata->ClosePrice= native->ClosePrice;
			///���ν����
			rspdata->SettlementPrice= native->SettlementPrice;
			///��ͣ���
			rspdata->UpperLimitPrice= native->UpperLimitPrice;
			///��ͣ���
			rspdata->LowerLimitPrice= native->LowerLimitPrice;
			///����ʵ��
			rspdata->PreDelta= native->PreDelta;
			///����ʵ��
			rspdata->CurrDelta= native->CurrDelta;
			///����޸�ʱ��
			rspdata->UpdateTime = U8ToClr((native->UpdateTime));
			///����޸ĺ���
			rspdata->UpdateMillisec= native->UpdateMillisec;
			///�����һ
			rspdata->BidPrice1 = native->BidPrice1;
			///������һ
			rspdata->BidVolume1= native->BidVolume1;
			///������һ
			rspdata->AskPrice1 = native->AskPrice1;
			///������һ
			rspdata->AskVolume1= native->AskVolume1;
			///����۶�
			rspdata->BidPrice2 = native->BidPrice2;
			///��������
			rspdata->BidVolume2= native->BidVolume2;
			///�����۶�
			rspdata->AskPrice2= native->AskPrice2;
			///��������
			rspdata->AskVolume2= native->AskVolume2;
			///�������
			rspdata->BidPrice3= native->BidPrice3;
			///��������
			rspdata->BidVolume3= native->BidVolume3;
			///��������
			rspdata->AskPrice3= native->AskPrice3;
			///��������
			rspdata->AskVolume3= native->AskVolume3;
			///�������
			rspdata->BidPrice4= native->BidPrice4;
			///��������
			rspdata->BidVolume4= native->BidVolume4;
			///��������
			rspdata->AskPrice4= native->AskPrice4;
			///��������
			rspdata->AskVolume4= native->AskVolume4;
			///�������
			rspdata->BidPrice5= native->BidPrice5;
			///��������
			rspdata->BidVolume5= native->BidVolume5;
			///��������
			rspdata->AskPrice5= native->AskPrice5;
			///��������
			rspdata->AskVolume5= native->AskVolume5;
			///���վ���
			rspdata->AveragePrice= native->AveragePrice;
			///ҵ������
			rspdata->ActionDay = U8ToClr((native->ActionDay));
			return rspdata;
		}
		///������
		String^	TradingDay;
		///��Լ����
		String^	InstrumentID;
		///����������
		String^	ExchangeID;
		///��Լ�ڽ������Ĵ���
		String^	ExchangeInstID;
		///���¼�
		double	LastPrice;
		///�ϴν����
		double	PreSettlementPrice;
		///������
		double	PreClosePrice;
		///��ֲ���
		double	PreOpenInterest;
		///����
		double	OpenPrice;
		///��߼�
		double	HighestPrice;
		///��ͼ�
		double	LowestPrice;
		///����
		int	Volume;
		///�ɽ����
		double	Turnover;
		///�ֲ���
		double	OpenInterest;
		///������
		double	ClosePrice;
		///���ν����
		double	SettlementPrice;
		///��ͣ���
		double	UpperLimitPrice;
		///��ͣ���
		double	LowerLimitPrice;
		///����ʵ��
		double	PreDelta;
		///����ʵ��
		double	CurrDelta;
		///����޸�ʱ��
		String^	UpdateTime;
		///����޸ĺ���
		int	UpdateMillisec;
		///�����һ
		double	BidPrice1;
		///������һ
		int	BidVolume1;
		///������һ
		double	AskPrice1;
		///������һ
		int	AskVolume1;
		///����۶�
		double	BidPrice2;
		///��������
		int	BidVolume2;
		///�����۶�
		double	AskPrice2;
		///��������
		int	AskVolume2;
		///�������
		double	BidPrice3;
		///��������
		int	BidVolume3;
		///��������
		double	AskPrice3;
		///��������
		int	AskVolume3;
		///�������
		double	BidPrice4;
		///��������
		int	BidVolume4;
		///��������
		double	AskPrice4;
		///��������
		int	AskVolume4;
		///�������
		double 	BidPrice5;
		///��������
		int	BidVolume5;
		///��������
		double	AskPrice5;
		///��������
		int	AskVolume5;
		///���վ���
		double	AveragePrice;
		///ҵ������
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
		///������
		String^	TradingDay;
		///��Լ����
		String^	InstrumentID;
		///ѯ�۱��
		String^	ForQuoteSysID;
		///ѯ��ʱ��
		String^	ForQuoteTime;
		///ҵ������
		String^	ActionDay;
		///����������
		String^	ExchangeID;
	};
}