using System;

namespace DesignLibrary
{
   public enum TraceLevel
   {
      Off     = 0,
      Error   = 1,
      Warning = 2,
      Info    = 3,
      Verbose = 4
   }

   public enum TraceLevelMissingZeroValue    // @violation
   {
      Error   = 1,
      Warning = 2,
      Info    = 3,
      Verbose = 4
   }

   [Flags]
   public enum TraceOptions
   {
      None         =    0,
      CallStack    = 0x01,
      LogicalStack = 0x02,
      DateTime     = 0x04,
      Timestamp    = 0x08,
   }

   [Flags]
   public enum BadTraceOptions1              // @violation
   {
      CallStack    =    0,
      LogicalStack = 0x01,
      DateTime     = 0x02,
      Timestamp    = 0x04,
   }

   [FlagsAttribute]
   public enum BadTraceOptions2              // @violation
   {
      CallStack    =    0,
      LogicalStack = 0x01,
      DateTime     = 0x02,
      Timestamp    = 0x04,
   }

   [FlagsAttribute]
   public enum BadTraceOptions3              // @violation
   {
      CallStack1    =    0,
      CallStack2    =    0,
      LogicalStack = 0x01,
      DateTime     = 0x02,
      Timestamp    = 0x04,
   }

   class UseBadTraceOptions
   {
      static void Main()
      {
         // Set the flags.
         BadTraceOptions badOptions =
            BadTraceOptions.LogicalStack | BadTraceOptions.Timestamp;

         // Check whether CallStack is set.
         if((badOptions & BadTraceOptions.CallStack) ==
             BadTraceOptions.CallStack)
         {
            // This 'if' statement is always true.
         }
      }
   }
}