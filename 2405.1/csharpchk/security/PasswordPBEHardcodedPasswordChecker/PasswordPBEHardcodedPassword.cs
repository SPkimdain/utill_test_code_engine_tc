using System;
using System.Text;
using System.Security.Cryptography;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            String password = "password";
            String s_salt = "!!@!@!@!@!#!@";

            byte[] password_b = Encoding.Default.GetBytes(password);
            byte[] password_bb = Encoding.Default.GetBytes(s_salt);

            Rfc2898DeriveBytes rdb8_1 = new Rfc2898DeriveBytes("", 10001);
            Rfc2898DeriveBytes rdb8_2 = new Rfc2898DeriveBytes(password, password_bb); // @violation
            Rfc2898DeriveBytes rdb16 = new Rfc2898DeriveBytes(password, Encoding.Default.GetBytes(s_salt), 10001); // @violation
            Rfc2898DeriveBytes rdb32_1 = new Rfc2898DeriveBytes("password", Encoding.Default.GetBytes(s_salt), 10001); // @violation
            Rfc2898DeriveBytes rdb32_2 = new Rfc2898DeriveBytes(password_b, Encoding.Default.GetBytes(s_salt), 10001); // @violation
        }
    }
}