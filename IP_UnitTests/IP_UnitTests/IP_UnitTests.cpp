#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

string fun(double a, double b, double c, double d, double e, double f);
namespace IPUnitTests
{
	TEST_CLASS(NoneSlove) // 0
	{
	public:
		TEST_METHOD(NoneSloves1)
		{
			string resoult;
			string funResoult;
			resoult = "0";
			funResoult = fun(0, 0, 0, 1, 1, 0);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}

		TEST_METHOD(NoneSloves2)
		{
			string resoult;
			string funResoult;
			resoult = "0";
			funResoult = fun(0, 1, 0, 1, 0, 1);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}
		TEST_METHOD(NoneSloves3)
		{
			string resoult;
			string funResoult;
			resoult = "0";
			funResoult = fun(0, 0, 0, 1, 1, 1);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}

		TEST_METHOD(NoneSloves4)
		{
			string resoult;
			string funResoult;
			resoult = "0";
			funResoult = fun(0, 0, 0, 0, 1, 1);
			Assert res;
			res.AreEqual(resoult, funResoult);
		}

	};

	TEST_CLASS(InfSloveK) {		// 1 y=kx+n
public:

	TEST_METHOD(InfSlovesBandE)
	{
		string resoult;
		string funResoult;
		resoult = "1 " + to_string(double(-1)) + " " + to_string(double(1));
		funResoult = fun(0, 0, 1, 1, 0, 1);
		Assert res;
		res.AreEqual(resoult, funResoult);
	}

	TEST_METHOD(InfSlovesAandE)
	{
		string resoult;
		string funResoult;
		resoult = "1 " + to_string(double(-1)) + " " + to_string(double(0));
		funResoult = fun(0, 1, 1, 1, 0, 0);
		Assert res;
		res.AreEqual(resoult, funResoult);
	}
	TEST_METHOD(InfSlovesDandF)
	{
		string resoult;
		string funResoult;
		resoult = "1 " + to_string(double(-1)) + " " + to_string(double(1));
		funResoult = fun(1, 1, 0, 0, 1, 0);
		Assert res;
		res.AreEqual(resoult, funResoult);
	}

	TEST_METHOD(InfSlovesCandF)
	{
		string resoult;
		string funResoult;
		resoult = "1 " + to_string(double(-1)) + " " + to_string(double(0));
		funResoult = fun(1, 1, 0, 1, 0, 0);
		Assert res;
		res.AreEqual(resoult, funResoult);
	}
	TEST_METHOD(InfSlovesABCD)
	{
		string resoult;
		string funResoult;
		resoult = "1 " + to_string(double(-1)) + " " + to_string(double(0));
		funResoult = fun(1, 1, 1, 1, 0, 0);
		Assert res;
		res.AreEqual(resoult, funResoult);
	}

	TEST_METHOD(InfSlovesABCD2)
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
	TEST_METHOD(OnlyOneWay12)
	{
		string resoult;
		string funResoult;
		resoult = "2 " + to_string(double(1)) + " -" + to_string(double(0));
		funResoult = fun(0, 1, 1, 0, 0, 1);
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
	TEST_METHOD(OnlyOneWay22)
	{
		string resoult;
		string funResoult;
		resoult = "2 -" + to_string(double(0)) + " " + to_string(double(1));
		funResoult = fun(0, 1, 1, 0, 1, 0);
		Assert res;
		res.AreEqual(resoult, funResoult);

	}
	};

	TEST_CLASS(InfSloveX) {		//	3 x0
public:
	TEST_METHOD(InfSlovesBandD)
	{
		string resoult;
		string funResoult;
		resoult = "3 " + to_string(double(1));
		funResoult = fun(1, 0, 1, 0, 1, 1);
		Assert res;
		res.AreEqual(resoult, funResoult);
	}

	TEST_METHOD(InfSlovesBandD2)
	{
		string resoult;
		string funResoult;
		resoult = "3 " + to_string(double(0));
		funResoult = fun(1, 0, 1, 0, 0, 0);
		Assert res;
		res.AreEqual(resoult, funResoult);
	}

	TEST_METHOD(InfSlovesBandD3)
	{
		string resoult;
		string funResoult;
		resoult = "3 " + to_string(double(1));
		funResoult = fun(1, 0, 0, 0, 1, 0);
		Assert res;
		res.AreEqual(resoult, funResoult);
	}

	TEST_METHOD(InfSlovesBandD4)
	{
		string resoult;
		string funResoult;
		resoult = "3 " + to_string(double(1));
		funResoult = fun(0, 0, 1, 0, 0, 1);
		Assert res;
		res.AreEqual(resoult, funResoult);
	}

	TEST_METHOD(InfSlovesA)
	{
		string resoult;
		string funResoult;
		resoult = "3 " + to_string(double(0));
		funResoult = fun(1, 0, 0, 0, 0, 0);
		Assert res;
		res.AreEqual(resoult, funResoult);
	}

	TEST_METHOD(InfSlovesC)
	{
		string resoult;
		string funResoult;
		resoult = "3 " + to_string(double(0));
		funResoult = fun(0, 0, 1, 0, 0, 0);
		Assert res;
		res.AreEqual(resoult, funResoult);
	}

	};
	TEST_CLASS(InfSloveY) {		// 4 y0
public:
	TEST_METHOD(InfSlovesAandC)
	{
		string resoult;
		string funResoult;
		resoult = "4 " + to_string(double(1));
		funResoult = fun(0, 1, 0, 1, 1, 1);
		Assert res;
		res.AreEqual(resoult, funResoult);
	}

	TEST_METHOD(InfSlovesAandC2)
	{
		string resoult;
		string funResoult;
		resoult = "4 " + to_string(double(0));
		funResoult = fun(0, 1, 0, 1, 0, 0);
		Assert res;
		res.AreEqual(resoult, funResoult);
	}

	TEST_METHOD(InfSlovesAandC3)
	{
		string resoult;
		string funResoult;
		resoult = "4 " + to_string(double(1));
		funResoult = fun(0, 1, 0, 0, 1, 0);
		Assert res;
		res.AreEqual(resoult, funResoult);
	}

	TEST_METHOD(InfSlovesAandC4)
	{
		string resoult;
		string funResoult;
		resoult = "4 " + to_string(double(1));
		funResoult = fun(0, 0, 0, 1, 0, 1);
		Assert res;
		res.AreEqual(resoult, funResoult);
	}

	TEST_METHOD(InfSlovesD)
	{
		string resoult;
		string funResoult;
		resoult = "4 " + to_string(double(0));
		funResoult = fun(0, 0, 0, 1, 0, 0);
		Assert res;
		res.AreEqual(resoult, funResoult);
	}

	TEST_METHOD(InfSlovesB)
	{
		string resoult;
		string funResoult;
		resoult = "4 " + to_string(double(0));
		funResoult = fun(0, 1, 0, 0, 0, 0);
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
