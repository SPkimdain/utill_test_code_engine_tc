using System;
using System.Text;
using System.Security.Cryptography;
using System.Configuration;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            String password = "password";
            Encrypt(password);
        }

        public static string Encrypt(string toEncrypt)
        {
            byte[] keyArray;
            // key size should be 16 byte in current setting(128 bit)
            string key = "1234567890123456"; 

            byte[] toEncryptArray = UTF8Encoding.UTF8.GetBytes(toEncrypt);
            keyArray = UTF8Encoding.UTF8.GetBytes(key);

            AesCryptoServiceProvider aes = new AesCryptoServiceProvider();
            aes.Key = keyArray; // @violation
            aes.Padding = PaddingMode.PKCS7;

            Random rnd = new Random();
            Byte[] b = new Byte[16];
            rnd.NextBytes(b);
            aes.Key = b;

            ICryptoTransform cTransform = aes.CreateEncryptor();
            byte[] resultArray = cTransform.TransformFinalBlock
                    (toEncryptArray, 0, toEncryptArray.Length);
            aes.Clear();
            return Convert.ToBase64String(resultArray, 0, resultArray.Length);
        }
    }
}