#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\rogalik\source\repos\BOSE\BOSE\BOSE.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		TEST_METHOD(calculate1_getNegative15and2_Negative29returned) {
			double x = -15;
			int n = 2;
			double expected = -29;

			double actual = calculate1(x, n);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(calculate2_get7and4_12returned)
		{
			double x = 7;
			int n = 4;
			double expected = 12.5;

			double actual = calculate2(x, n);

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(checkValidParams_get10_exceptionNotThrown) {
			int n = 10;
			try {
				checkValidParams(n);
				Assert::IsTrue(true);
			}
			catch(invalid_argument){
				Assert::Fail();
			}
		}
		TEST_METHOD(checkValidParams_getNegative10_exceptionThrown) {
			int n = -10;

			try {
				checkValidParams(n);
				Assert::Fail;
			}
			catch(invalid_argument){
				Assert::IsTrue(true);
			}
		}
	};
}
