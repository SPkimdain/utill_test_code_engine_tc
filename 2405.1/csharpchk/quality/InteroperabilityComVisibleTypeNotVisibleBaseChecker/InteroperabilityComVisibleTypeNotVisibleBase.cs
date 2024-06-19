using System;
using System.Runtime.InteropServices;

[assembly: ComVisible(false)]
namespace InteroperabilityLibrary
{
    [ComVisible(false)]
    public class BaseClass
    {
        public void SomeMethod(int valueOne) {}
    }

    // This class violates the rule.
    [ComVisible(true)]// @violation
    public class DerivedClass : BaseClass
    {
        public void AnotherMethod(int valueOne, int valueTwo) {}
    }
}