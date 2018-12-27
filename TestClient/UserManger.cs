using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestClient
{
    public class UserManger
    {
        private UserManger()
        {
        }
        public static int RequestId =0;
        private static Object lockobject = new object();
        private static UserManger _current = null;
        public static UserManger Current
        {
            get
            {
                if (_current == null)
                {
                    lock (lockobject)
                    {
                        if (_current == null)
                        {
                            _current = new UserManger();

                        }
                    }
                }
                return _current;
            }
        }
        public string Username { get;  set; } = string.Empty;
        public string Userpwd { get;  set; } = string.Empty;

        public string BlockId { get;  set; } = string.Empty;
        //private string Userpwd { get; set; } = string.Empty;
        //private string Userpwd { get; set; } = string.Empty;
        //private string Userpwd { get; set; } = string.Empty;

    }
}
