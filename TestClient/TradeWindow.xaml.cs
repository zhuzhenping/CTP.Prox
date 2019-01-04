using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using Ctp.Core;

namespace TestClient
{
    /// <summary>
    /// 测试客户端，测试银证转账的话需要实盘账户，例子里提供的都是有误的信息
    /// </summary>
    public partial class TradeWindow : Window
    {
        Trader trader = null;
        List<Dictionary<String, String>> chicangdic = new List<Dictionary<string, string>>();
        List<Dictionary<String, String>> baodandic = new List<Dictionary<string, string>>();

        List<Dictionary<String, String>> chengjiaodic = new List<Dictionary<string, string>>();
        List<Dictionary<String, String>> chedandic = new List<Dictionary<string, string>>();
        public TradeWindow(Trader _trader)
        {
            InitializeComponent();
            trader = _trader;
            //下单
            buybtn.GroupName = "group1";
            shellbtn.GroupName = "group1";
            pingcangbtn.GroupName = "group2";
            kaicangbtn.GroupName = "group2";
            pingjingbtn.GroupName = "group2";
            this.Closed += (sender, e) =>
              {
                  Application.Current.Shutdown();
              };
            xiadanBtn.Click += (sender, e) =>
              {
                  sbyte s = new sbyte();
                  if (pingcangbtn.IsChecked == true)
                  {
                      s = (sbyte)'1';
                  }
                  if (kaicangbtn.IsChecked == true)
                  {
                      s = (sbyte)'0';
                  }
                  if (pingjingbtn.IsChecked == true)
                  {
                      s = (sbyte)'3';
                  }
                  var xiadan_req = new OrderInsertRequestData()
                  {
                      BrokerID = "9999",
                      InvestorID = UserManger.Current.Username,
                      ExchangeID = "SHFE",
                      InstrumentID = codebtn.Text.Trim(),
                      UserID = UserManger.Current.Username,
                      OrderPriceType = (sbyte)'2',
                      Direction = (buybtn.IsChecked == true) ? (sbyte)'0' : (sbyte)'1',     //买
                      CombOffsetFlag = s,//开
                      CombHedgeFlag = (sbyte)'1',
                      LimitPrice = Convert.ToDouble(pricebtn.Text.Trim()),
                      VolumeTotalOriginal = Convert.ToInt32(countbtn.Text.Trim()),
                      TimeCondition = (sbyte)'3',///当日有效
                      VolumeCondition = (sbyte)'1',  ///任何数量
                      MinVolume = 1,
                      ContingentCondition = (sbyte)'1',  // '4'预埋单 ，1立即
                      StopPrice = 0,
                      ForceCloseReason = (sbyte)'0',
                      IsAutoSuspend = 0,
                  };
                  trader.ReqOrderInsert(xiadan_req, UserManger.RequestId++);
              };

            trader.OnRspOrderInsert += (e) =>
            {
                MessageBox.Show(e.ResponseInfo.ErrorMsg.ToString());
            };
            trader.OnErrRtnOrderInsert += (e) =>
            {
                MessageBox.Show(e.ResponseInfo.ErrorMsg.ToString());
            };
            trader.OnRtnOrder += (e) =>
            {
                //MessageBox.Show(e.RtnOrderResData.StatusMsg.ToString());
            };
            trader.OnRtnTrade += (e) =>
            {
                MessageBox.Show("交易成功");
            };

            //查询报单
            baodanQry.Click += (sender, e) =>
              {
                  var req_parmas = new QryOrderRequestData()
                  {
                      BrokerID = UserManger.Current.BlockId,
                      InvestorID = UserManger.Current.Username,
                      ExchangeID = "SHFE",
                  };
                  trader.ReqQryOrder(req_parmas, UserManger.RequestId++);
              };
            trader.OnRspQryOrder += (e) =>
              {
                  if (e.QryOrderResData == null)
                  {
                      return;
                  }
                  Dictionary<String, String> dic = new Dictionary<string, string>()
                  {
                      {"代码", e.QryOrderResData.InstrumentID },
                         {"报单编号", e.QryOrderResData.OrderSysID},
                      {"经纪公司代码", e.QryOrderResData.BrokerID},
                     {"报单引用", e.QryOrderResData.OrderRef},
                  {"营业部编号", e.QryOrderResData.BranchID},
                   {"投资单元代码", e.QryOrderResData.InvestUnitID},
                  {"资金账号",  e.QryOrderResData.AccountID},
                  {"币种代码", e.QryOrderResData.CurrencyID},
                  {"IP地址", e.QryOrderResData.IPAddress},
                  {"Mac地址", e.QryOrderResData.MacAddress},
                };
                  baodandic.Add(dic);

                  if (Convert.ToDouble(e.QryOrderResData.OrderSubmitStatus) == 51)
                  {
                      if (Convert.ToDouble(e.QryOrderResData.OrderStatus) == 51)
                      {
                          chedandic.Add(dic);
                      }
                  }
                  if (Convert.ToDouble(e.QryOrderResData.OrderSubmitStatus) == 48)
                  {
                      if (Convert.ToDouble(e.QryOrderResData.OrderStatus) == 48)
                      {
                          chengjiaodic.Add(dic);
                      }
                  }

                  Dispatcher.BeginInvoke(new Action(() =>
                  {
                      qryGrid.AutoGenerateColumns = false;
                      if (qryGrid.ItemsSource == null)
                      {
                          if (baodandic.Count != 0)
                          {
                              var first = baodandic.First();
                              foreach (var node in first)
                              {
                                  qryGrid.Columns.Add(new DataGridTextColumn { Header = node.Key, Binding = new Binding(string.Format("[{0}]", node.Key)) });
                              }
                              qryGrid.ItemsSource = baodandic;
                          }
                      }

                      chedanGrid.AutoGenerateColumns = false;
                      if (chedanGrid.ItemsSource == null)
                      {
                          if (chedandic.Count != 0)
                          {
                              var first = chedandic.First();
                              foreach (var node in first)
                              {
                                  chedanGrid.Columns.Add(new DataGridTextColumn { Header = node.Key, Binding = new Binding(string.Format("[{0}]", node.Key)) });
                              }
                              chedanGrid.ItemsSource = chedandic;
                          }
                      }

                      cjGrid.AutoGenerateColumns = false;
                      if (cjGrid.ItemsSource == null)
                      {
                          if (chengjiaodic.Count != 0)
                          {
                              var first = chengjiaodic.First();
                              foreach (var node in first)
                              {
                                  cjGrid.Columns.Add(new DataGridTextColumn { Header = node.Key, Binding = new Binding(string.Format("[{0}]", node.Key)) });
                              }
                              cjGrid.ItemsSource = chengjiaodic;
                          }
                      }
                  }));
              };
            //持仓
            chicangbtn.Click += (sender, e) =>
            {
                var req_parmas = new InvestorPositionRequestData()
                {
                    BrokerID = UserManger.Current.BlockId,
                    InvestorID = UserManger.Current.Username,
                };
                trader.ReqQryInvestorPosition(req_parmas, UserManger.RequestId++);
            };
            trader.OnRspQryInvestorPosition += (data, info, id, last) =>
            {
                string str = "多";
                if (Convert.ToDouble(data.PosiDirection) == 49.0)
                {
                    str = "净";
                }
                else
                {
                    str = (Convert.ToDouble(data.PosiDirection) == 50.0) ? "多" : "空";
                }
                Dictionary<String, String> dic = new Dictionary<string, string>()
                {
                      {   "代码", data.InstrumentID }, 
                };
                chicangdic.Add(dic);
                Dispatcher.BeginInvoke(new Action(() =>
                {
                    chicanggrid.AutoGenerateColumns = false;
                    if (chicanggrid.ItemsSource == null)
                    {
                        var first = chicangdic.First();
                        foreach (var node in first)
                        {
                            chicanggrid.Columns.Add(new DataGridTextColumn { Header = node.Key, Binding = new Binding(string.Format("[{0}]", node.Key)) });
                        }
                        chicanggrid.ItemsSource = chicangdic;
                    }
                }));
            };

            //撤单
            chedanBtn.Click += (semder, e) =>
              {
                  int x = chedanGrid.SelectedIndex;
                  string str = (chedanGrid.Columns[0].GetCellContent(chedanGrid.Items[x]) as TextBlock).Text;
                  string str2 = (chedanGrid.Columns[1].GetCellContent(chedanGrid.Items[x]) as TextBlock).Text;
                  MessageBox.Show("是否要撤单:  " + str + "编号为：" + str2);
                  var req_parmas = new OrderActionRequestData()
                  {
                      BrokerID = UserManger.Current.BlockId,
                      InvestorID = UserManger.Current.Username,
                      UserID = UserManger.Current.Username,
                      ExchangeID = "SHFE",

                      OrderSysID = str2,
                      InstrumentID = str,
                      ActionFlag = (sbyte)'0',
                  };
                  trader.ReqOrderAction(req_parmas, UserManger.RequestId++);
              };
            trader.OnRspOrderAction += (data, info, id, last) =>
              {

              };



            //资金
            zijinQry.Click += (sender, e) =>
              {
                  var req_parmas = new QryAccountRequestData()
                  {
                      BrokerID = UserManger.Current.BlockId,
                      InvestorID = UserManger.Current.Username,
                      CurrencyID = "CNY",
                      BizType = "",
                      AccountID = "",
                  };

                  trader.ReqQryTradingAccount(req_parmas, UserManger.RequestId++);
              };
            trader.OnRspQryTradingAccount += (e) =>
              {
                  List<Dictionary<String, String>> fields = new List<Dictionary<String, String>>
                  {
                     new Dictionary<String,String>() {
                         //{   "可用资金", e.QryAccountResData.Available },
                         //{   "可取资金", e.QryAccountResData.WithdrawQuota },
                         //{   "手续费", e.QryAccountResData.Commission },
                         //{   "平仓盈亏", e.QryAccountResData.CloseProfit },
                         //{   "持仓盈亏", e.QryAccountResData.PositionProfit },
                         //{   "利息基数", e.QryAccountResData.InterestBase },
                         //{   "利息收入", e.QryAccountResData.Interest },
                         //{   "入金金额", e.QryAccountResData.Deposit },
                         //{   "出金金额", e.QryAccountResData.Withdraw },
                         //{   "资金差额", e.QryAccountResData.CashIn },
                         //{   "冻结的保证金", e.QryAccountResData.FrozenMargin },
                         //{   "冻结的资金", e.QryAccountResData.FrozenCash },
                         //{   "冻结的手续费", e.QryAccountResData.FrozenCommission },
                         //{   "当前保证金总额", e.QryAccountResData.CurrMargin },
                     },
                  };
                  Dispatcher.BeginInvoke(new Action(() =>
                  {
                      zijinGrid.AutoGenerateColumns = false;
                      var first = fields.First();
                      foreach (var node in first)
                      {
                          zijinGrid.Columns.Add(new DataGridTextColumn { Header = node.Key, Binding = new Binding(string.Format("[{0}]", node.Key)) });
                      }
                      zijinGrid.ItemsSource = fields;
                  }));
              };

            #region 测试
            //转账流水
            zhuanzhangliushuiBtn.Click += (sender, e) =>
              {
                  var req_parmas = new QryTransferSerialRequestData()
                  {
                      BrokerID = "7070",
                      AccountID = "8100915",
                      CurrencyID = "CNY",
                      BankID = text.Text.Trim(),
                  };
                  trader.ReqQryTransferSerial(req_parmas, UserManger.RequestId++);
              };
            trader.OnRspQryTransferSerial += (data, info, id, i) =>
              {
                  MessageBox.Show(info.ErrorID + "  " + info.ErrorMsg.ToString());
              };



            //查询银期签约关系
            yinqiqianyueBtn.Click += (sender, e) =>
            {
                var req_parmas = new AccountregisterRequestData()
                {
                    BrokerID = "7070",
                    AccountID = "8100915",
                    CurrencyID = "CNY",
                    // BankID = "2",//nonghang  //不需要遍历，这个不传的话，签约了几个就返回几个
                };
                trader.ReqAccountregister(req_parmas, UserManger.RequestId++);
            };
            trader.OnRspQryAccountregister += (data, info, id, i) =>
            {
                MessageBox.Show(info.ErrorID + "  " + info.ErrorMsg.ToString());
            };




            //查询签约银行
            qianyuebankBtn.Click += (sender, e) =>
            {
                var req_parmas = new ContractBankRequestData()
                {
                    BrokerID = "7070",
                };
                trader.ReqContractBank(req_parmas, UserManger.RequestId++);
            };
            trader.OnRspQryContractBank += (data, info, id, i) =>
            {
                MessageBox.Show(info.ErrorID + "  " + info.ErrorMsg.ToString());
            };



            //银行资金转期货
            bankzijinzhuanqihuoBtn.Click += (sender, e) =>
            {
                var req_parmas = new FromBankToFutureByFutureRequestData()
                {
                    TradeCode = "202001",///业务功能码
                    BankID = "2",
                    BankBranchID = "0000",///期商代码
                    BrokerID = "7070",
                    LastFragment = (sbyte)'0',///最后分片标志 '0'=是最后分片
                    IdCardType = (sbyte)'1',///证件类型
                    CustType = (sbyte)'0',///客户类型
                    BankAccount = "6228480318330377184",
                    AccountID = "8100915",///投资者帐号
                    Password = "123456",///期货密码--资金密码
                    BankPassWord = "975268",
                    InstallID = 1,///安装编号
                    FutureSerial = 0,///期货公司流水号
                    VerifyCertNoFlag = (sbyte)'1',///验证客户证件号码标志
                    CurrencyID = "CNY",///币种代码 
                    TradeAmount = 0.0,///转帐金额
                    CustFee = 0,///应收客户费用
                    BrokerFee = 0,///应收期货公司费用
                    SecuPwdFlag = (sbyte)'1',///期货资金密码核对标志
                    RequestID = 0,///请求编号
                    TID = 0,///交易ID
                };
                trader.ReqFromBankToFutureByFuture(req_parmas, UserManger.RequestId++);
            };
            trader.OnRspQryFromBankToFutureByFuture += (data, info, id, i) =>
            {
                MessageBox.Show(info.ErrorID + "  " + info.ErrorMsg.ToString());
            };
            trader.OnRtnFromBankToFutureByFuture += (data) =>
            {
                MessageBox.Show("OnRtnFromBankToFutureByFuture成功");
            };



            //期货资金转银行
            qihuozijinzhuanbankBtn.Click += (sender, e) =>
            {
                var req_parmas = new FromFutureToBankByFutureRequestData()
                {
                    TradeCode = "202002",///业务功能码
                    BankID = "2",
                    BankBranchID = "0000",///期商代码
                    BrokerID = "7070",
                    LastFragment = (sbyte)'0',///最后分片标志 '0'=是最后分片
                    IdCardType = (sbyte)'1',///证件类型
                    IdentifiedCardNo = "33020319950410245X",///证件号码
                   //BankAccount = "6228480318330377184",///银行帐号
                    BankPassWord = "975268",
                    AccountID = "8100915",///投资者帐号
                    Password = "123456",///期货密码
                    InstallID = 1,///安装编号
                    CustType = (sbyte)'0',
                    VerifyCertNoFlag = (sbyte)'1', //验证客户证件号码标志
                    CurrencyID = "CNY",///币种代码
                    TradeAmount = 0.0,///转帐金额
                    FutureFetchAmount = 0,///期货可取金额
                    CustFee = 0,///应收客户费用
                    BrokerFee = 0,///应收期货公司费用
                    RequestID = 0,///请求编号
                    TID = 0,///交易ID
                };
                trader.ReqFromFutureToBankByFuture(req_parmas, UserManger.RequestId++);
            };
            trader.OnRspQryFromFutureToBankByFuture += (data, info, id, i) =>
            {
                MessageBox.Show(info.ErrorID + "  " + info.ErrorMsg.ToString());
            };
            trader.OnRtnFromFutureToBankByFuture += (data) =>
            {
                MessageBox.Show("OnRtnFromFutureToBankByFuture成功了");
            };



            //!!!重点 ！！修改密码
            passwordBtn.Click += (sender, e) =>
            {
                var req_parmas = new TradingAccountPasswordUpdateRequestData()
                {
                    BrokerID = "7070",
                    AccountID = "8100915",
                    OldPassword = "410244",
                    NewPassword = "123456",
                    CurrencyID = "CNY",
                };
                trader.ReqTradingAccountPasswordUpdate(req_parmas, UserManger.RequestId++);
            };
            trader.OnRspQryTradingAccountPasswordUpdate += (data, info, id, i) =>
            {
                MessageBox.Show(info.ErrorID + "  " + info.ErrorMsg.ToString());
            };


            //查询银行余额
            chaxunyinghangyueBtn.Click += (sender, e) =>
            {
                var req_parmas = new QueryBankAccountMoneyByFutureRequestData()
                {
                    TradeCode = "204002",
                    BankID = "2",
                    BankBranchID = "0000",
                    BrokerID = "7070",
                    CurrencyID = "CNY",
                    Password = "410245",
                    BankPassWord = "975268",
                    AccountID = "8100915",
                    VerifyCertNoFlag = (sbyte)'1',
                    IdentifiedCardNo = "33020319950410245X",
                    BankAccount = "6228480318330377184",
                };
                trader.ReqQueryBankAccountMoneyByFuture(req_parmas, UserManger.RequestId++);
            };
            trader.OnRspQryQueryBankAccountMoneyByFuture += (data, info, id, i) =>
            {
                MessageBox.Show(info.ErrorID + "  " + info.ErrorMsg.ToString());
            };
            trader.OnRtnNotifyQueryAccountField += (e) => //成功信息回报
            {
                MessageBox.Show(e.ErrorMsg.ToString());
                MessageBox.Show("银行可取金额：" + e.BankFetchAmount.ToString());
                MessageBox.Show("银行可用金额：" + e.BankUseAmount.ToString());
            };
            #endregion 测试
        }
    }
}
