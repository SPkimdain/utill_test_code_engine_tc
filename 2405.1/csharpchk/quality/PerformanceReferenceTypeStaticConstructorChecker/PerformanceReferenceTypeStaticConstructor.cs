using System;
using System.Reflection;
using System.Resources;

namespace PerformanceLibrary
{
   public class StaticConstructor
   {
      static int someInteger;
      static string resourceString;

      static StaticConstructor() // @violation
      {
         someInteger = 3;
         ResourceManager stringManager =
            new ResourceManager("strings", Assembly.GetExecutingAssembly());
         resourceString = stringManager.GetString("string");
      }
   }

   public class NoStaticConstructor
   {
      static int someInteger = 3;
      static string resourceString = InitializeResourceString();

      static string InitializeResourceString()
      {
         ResourceManager stringManager =
            new ResourceManager("strings", Assembly.GetExecutingAssembly());
         return stringManager.GetString("string");
      }
   }
}