using System;

    // Violates rule: DeclareTypesInNamespaces.
    public class Test       // @violation
    {
       public override string ToString()
       {
          return "Test does not live in a namespace!";
       }
    }

    namespace GoodSpace
    {
       public class Test
       {
          public override string ToString()
          {
             return "Test lives in a namespace!";
          }
       }
    }