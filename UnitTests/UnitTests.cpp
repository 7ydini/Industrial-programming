#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

string fun(double a, double b, double c, double d, double e, double f);
namespace UnitTests
{
	TEST_CLASS(NoneSlove)
	{
	public:
		TEST_METHOD(NoneSloves) // 0
		{
			string resoult;
			string funResoult;
			resoult = "0";
			funResoult = fun(0, 0, 0, 1, 1, 0);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}
	};

	TEST_CLASS(InfSloveK) {		// 1 y=kx+n
	public:

		TEST_METHOD(InfSlovesK1)
		{
			string resoult;
			string funResoult;
			resoult = "1 " + to_string(double(-1)) + " " + to_string(double(1));
			funResoult = fun(0, 0, 1, 1, 0, 1);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}

		TEST_METHOD(InfSlovesK2)
		{
			string resoult;
			string funResoult;
			resoult = "1 " + to_string(double(-1)) + " " + to_string(double(0));
			funResoult = fun(0, 1, 1, 1, 0, 0);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}
		TEST_METHOD(InfSlovesK3)
		{
			string resoult;
			string funResoult;
			resoult = "1 " + to_string(double(-1)) + " " + to_string(double(1));
			funResoult = fun(1, 1, 0, 0, 1, 0);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}
	
		TEST_METHOD(InfSlovesK4)
		{
			string resoult;
			string funResoult;
			resoult = "1 " + to_string(double(-1)) + " " + to_string(double(0));
			funResoult = fun(1, 1, 0, 1, 0, 0);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}
		TEST_METHOD(InfSlovesK5)
		{
			string resoult;
			string funResoult;
			resoult = "1 " + to_string(double(-1)) + " " + to_string(double(0));
			funResoult = fun(1, 1, 1, 1, 0, 0);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}

		TEST_METHOD(InfSlovesK6)
		{
			string resoult;
			string funResoult;
			resoult = "1 " + to_string(double(-1)) + " " + to_string(double(1));
			funResoult = fun(1, 1, 1, 1, 1, 1);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}

	};

	TEST_CLASS(OnlyOneWay) {	//	2 x0 y0
	public:
		TEST_METHOD(OnlyOneWay1)
	{
			string resoult;
			string funResoult;
			resoult = "2 " + to_string(double(1)) + " " + to_string(double(0));
			funResoult = fun(1, 0, 0, 1, 1, 0);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}
		TEST_METHOD(OnlyOneWay2)
		{
			string resoult;
			string funResoult;
			resoult = "2 " + to_string(double(0)) + " " + to_string(double(1));
			funResoult = fun(1, 0, 0, 1, 0, 1);
			Assert res;
			res.AreEqual(resoult, funResoult);

		}
	};

	TEST_CLASS(InfSloveX) {		//	3 x0
	public:
		TEST_METHOD(InfSlovesX1)
		{
			string resoult;
			string funResoult;
			resoult = "3 " + to_string(double(1));
			funResoult = fun(1, 0, 1, 0, 1, 1);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}

		TEST_METHOD(InfSlovesX2)
		{
			string resoult;
			string funResoult;
			resoult = "3 " + to_string(double(0));
			funResoult = fun(1, 0, 1, 0, 0, 0);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}

		TEST_METHOD(InfSlovesX3)
		{
			string resoult;
			string funResoult;
			resoult = "3 " + to_string(double(1));
			funResoult = fun(1, 0, 0, 0, 1, 0);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}

		TEST_METHOD(InfSlovesX4)
		{
			string resoult;
			string funResoult;
			resoult = "3 " + to_string(double(1));
			funResoult = fun(0, 0, 1, 0, 0, 1);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}
	};
	TEST_CLASS(InfSloveY) {		// 4 y0
	public:
		TEST_METHOD(InfSlovesY)
		{
			string resoult;
			string funResoult;
			resoult = "4 " + to_string(double(1));
			funResoult = fun(0, 1, 0, 1, 1, 1);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}

		TEST_METHOD(InfSlovesY2)
		{
			string resoult;
			string funResoult;
			resoult = "4 " + to_string(double(0));
			funResoult = fun(0, 1, 0, 1, 0, 0);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}

		TEST_METHOD(InfSlovesY3)
		{
			string resoult;
			string funResoult;
			resoult = "4 " + to_string(double(1));
			funResoult = fun(0, 1, 0, 0, 1, 0);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}

		TEST_METHOD(InfSlovesY4)
		{
			string resoult;
			string funResoult;
			resoult = "4 " + to_string(double(1));
			funResoult = fun(0, 0, 0, 1, 0, 1);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}
	};

	TEST_CLASS(AllNumbersZero)	// 5
	{
	public:
		TEST_METHOD(AllNumbersZero1)
		{
			string resoult;
			string funResoult;
			resoult = "5";
			funResoult = fun(0, 0, 0, 0, 0, 0);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}
	};
	
}
