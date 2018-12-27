using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Reflection;
using Ctp.Core;

namespace TestClient
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>

    public partial class MainWindow : Window
    {
        Trader trader = null;
        Quoter quoter = null;
        string user = "";
        string pwd = "";
        static int request_id = -1;
        public MainWindow()
        {
            InitializeComponent();
            Loaded += (sender, d) =>
              {
                  InitTrader();
                  InitQuoter();
              };
            btn_login.Click += (sender, e) =>
              {
                  user = user_txt.Text.Trim().ToString();
                  pwd = user_pwd.Text.Trim().ToString();

                  var login_param = new UserLoginRequestData()
                  {
                      TradingDay = "20181214",
                      BrokerID = "7070",
                      UserID = user,
                      Password = pwd,
                      UserProductInfo = "test",
                      InterfaceProductInfo = "test",
                      ProtocolInfo = "test",
                      MacAddress = "FC-AA-14-BC-6D-18",
                      OneTimePassword = "",
                      ClientIPAddress = "192.168.0.1",
                      LoginRemark = "test",
                  };
                  trader.RequestLogin(login_param, request_id++);
              };
        }
        public void InitTrader()
        {
            if (trader == null)
            {
                trader = new Trader();
            }
            trader.FrontConnected += () =>
            {
                Dispatcher.BeginInvoke(new Action(() =>
                {
                    lab_error_msg.Content = "交易初始化成功....";
                }));
            };

            trader.UserLoginResponse += (e) =>
            {
                Dispatcher.BeginInvoke(new Action(() =>
                {
                    if (e.ResponseInfo.ErrorID == 0)
                    {
                        TradeWindow window = new TradeWindow(trader)
                        {
                            WindowStartupLocation = WindowStartupLocation.CenterScreen,
                        };
                        UserManger.Current.Username = e.LoginResonseData.UserID;
                        UserManger.Current.Userpwd = pwd;
                        UserManger.Current.BlockId = e.LoginResonseData.BrokerID;
                        window.Show();
                        this.Hide();
                    }
                    else
                    {
                        Dispatcher.BeginInvoke(new Action(() =>
                            {
                                lab_error_msg.Content = e.ResponseInfo.ErrorID + "  " + e.ResponseInfo.ErrorMsg;
                            }));
                    }
                }));
            };

           // trader.RegisterFront("tcp://47.97.122.147:41205");

            trader.RegisterFront("tcp://116.236.239.136:41205"); 
            trader.SubscribePrivateTopic(SubscriptionMode.Quick);
            trader.SubscribePublicTopic(SubscriptionMode.Quick);
            trader.Init();
        }


        public void InitQuoter()
        {
            if (quoter == null)
            {
                quoter = new Quoter();
            }
        }
        private void btn_login_Click(object sender, RoutedEventArgs e)
        {

        }
    }
}
