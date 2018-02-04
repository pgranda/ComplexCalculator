#define _USE_MATH_DEFINES

#include <math.h>
#include "stdafx.h"
#include "CppUnitTest.h"
#include "EquationParser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComplexCalculatorTests
{
	//Class which purpose is to test correctness of functions linked to the operators
	//These functions are added to equationParser and give it possibility to perform calculations
	TEST_CLASS(Functions_Tests)
	{
	public:

		//Add tests

		TEST_METHOD(Functions_Add_PositivesTest)
		{
			float result = Functions::Add(2, 2);
			float expectedResult = 4.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Add_FloatPositivesTest)
		{
			float result = Functions::Add(2.5, 2.5);
			float expectedResult = 5.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Add_NegativesTest)
		{
			float result = Functions::Add(-2, -2);
			float expectedResult = -4.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Add_FloatNegativesTest)
		{
			float result = Functions::Add(-2.5, -2.5);
			float expectedResult = -5.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Add_NegativeAndPositiveTest)
		{
			float result = Functions::Add(-2, 2);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Add_FloatNegativeAndFloatPositiveTest)
		{
			float result = Functions::Add(-2.5, 2.5);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Add_PositiveAndNegativeTest)
		{
			float result = Functions::Add(2, -2);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Add_FloatPositiveAndFloatNegativeTest)
		{
			float result = Functions::Add(2.5, -2.5);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Add_PositiveAndZeroTest)
		{
			float result = Functions::Add(2, 0);
			float expectedResult = 2.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Add_FloatPositiveAndZeroTest)
		{
			float result = Functions::Add(2.5, 0);
			float expectedResult = 2.5f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Add_ZeroAndPositiveTest)
		{
			float result = Functions::Add(0, 2);
			float expectedResult = 2.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Add_ZeroAndFloatPositiveTest)
		{
			float result = Functions::Add(0, 2.5);
			float expectedResult = 2.5f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Add_NegativeAndZeroTest)
		{
			float result = Functions::Add(-2, 0);
			float expectedResult = -2.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Add_FloatNegativeAndZeroTest)
		{
			float result = Functions::Add(-2.5, 0);
			float expectedResult = -2.5f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Add_ZeroAndNegativeTest)
		{
			float result = Functions::Add(0, -2);
			float expectedResult = -2.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Add_ZeroAndFloatNegativeTest)
		{
			float result = Functions::Add(0, -2.5);
			float expectedResult = -2.5f;
			Assert::AreEqual(result, expectedResult);
		}

		//Subtract tests

		TEST_METHOD(Functions_Sub_PositivesTest)
		{
			float result = Functions::Substract(2, 2);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Sub_FloatPositivesTest)
		{
			float result = Functions::Substract(2.5, 2.5);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Sub_NegativesTest)
		{
			float result = Functions::Substract(-2, -2);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Sub_FloatNegativesTest)
		{
			float result = Functions::Substract(-2.5, -2.5);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Sub_NegativeAndPositiveTest)
		{
			float result = Functions::Substract(-2, 2);
			float expectedResult = -4.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Sub_FloatNegativeAndFloatPositiveTest)
		{
			float result = Functions::Substract(-2.5, 2.5);
			float expectedResult = -5.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Sub_PositiveAndNegativeTest)
		{
			float result = Functions::Substract(2, -2);
			float expectedResult = 4.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Sub_FloatPositiveAndFloatNegativeTest)
		{
			float result = Functions::Substract(2.5, -2.5);
			float expectedResult = 5.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Sub_PositiveAndZeroTest)
		{
			float result = Functions::Substract(2, 0);
			float expectedResult = 2.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Sub_FloatPositiveAndZeroTest)
		{
			float result = Functions::Substract(2.5, 0);
			float expectedResult = 2.5f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Sub_ZeroAndPositiveTest)
		{
			float result = Functions::Substract(0, 2);
			float expectedResult = -2.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Sub_ZeroAndFloatPositiveTest)
		{
			float result = Functions::Substract(0, 2.5);
			float expectedResult = -2.5f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Sub_NegativeAndZeroTest)
		{
			float result = Functions::Substract(-2, 0);
			float expectedResult = -2.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Sub_FloatNegativeAndZeroTest)
		{
			float result = Functions::Substract(-2.5, 0);
			float expectedResult = -2.5f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Sub_ZeroAndNegativeTest)
		{
			float result = Functions::Substract(0, -2);
			float expectedResult = 2.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Sub_ZeroAndFloatNegativeTest)
		{
			float result = Functions::Substract(0, -2.5);
			float expectedResult = 2.5f;
			Assert::AreEqual(result, expectedResult);
		}


		//Multiply tests

		TEST_METHOD(Functions_Multi_PositivesTest)
		{
			float result = Functions::Multiply(2, 2);
			float expectedResult = 4.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Multi_FloatPositivesTest)
		{
			float result = Functions::Multiply(2.5, 2.5);
			float expectedResult = 6.25;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Multi_NegativesTest)
		{
			float result = Functions::Multiply(-2, -2);
			float expectedResult = 4.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Multi_FloatNegativesTest)
		{
			float result = Functions::Multiply(-2.5, -2.5);
			float expectedResult = 6.25;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Multi_NegativeAndPositiveTest)
		{
			float result = Functions::Multiply(-2, 2);
			float expectedResult = -4.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Multi_FloatNegativeAndFloatPositiveTest)
		{
			float result = Functions::Multiply(-2.5, 2.5);
			float expectedResult = -6.25;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Multi_PositiveAndNegativeTest)
		{
			float result = Functions::Multiply(2, -2);
			float expectedResult = -4.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Multi_FloatPositiveAndFloatNegativeTest)
		{
			float result = Functions::Multiply(2.5, -2.5);
			float expectedResult = -6.25;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Multi_PositiveAndZeroTest)
		{
			float result = Functions::Multiply(2, 0);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Multi_FloatPositiveAndZeroTest)
		{
			float result = Functions::Multiply(2.5, 0);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Multi_ZeroAndPositiveTest)
		{
			float result = Functions::Multiply(0, 2);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Multi_ZeroAndFloatPositiveTest)
		{
			float result = Functions::Multiply(0, 2.5);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Multi_NegativeAndZeroTest)
		{
			float result = Functions::Multiply(-2, 0);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Multi_FloatNegativeAndZeroTest)
		{
			float result = Functions::Multiply(-2.5, 0);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Multi_ZeroAndNegativeTest)
		{
			float result = Functions::Multiply(0, -2);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Multi_ZeroAndFloatNegativeTest)
		{
			float result = Functions::Multiply(0, -2.5);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}


		//Divide tests

		TEST_METHOD(Functions_Div_PositivesTest)
		{
			float result = Functions::Divide(2, 2);
			float expectedResult = 1.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Div_FloatPositivesTest)
		{
			float result = Functions::Divide(2.5, 2.5);
			float expectedResult = 1.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Div_NegativesTest)
		{
			float result = Functions::Divide(-2, -2);
			float expectedResult = 1.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Div_FloatNegativesTest)
		{
			float result = Functions::Divide(-2.5, -2.5);
			float expectedResult = 1.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Div_NegativeAndPositiveTest)
		{
			float result = Functions::Divide(-2, 2);
			float expectedResult = -1.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Div_FloatNegativeAndFloatPositiveTest)
		{
			float result = Functions::Divide(-2.5, 2.5);
			float expectedResult = -1.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Div_PositiveAndNegativeTest)
		{
			float result = Functions::Divide(2, -2);
			float expectedResult = -1.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Div_FloatPositiveAndFloatNegativeTest)
		{
			float result = Functions::Divide(2.5, -2.5);
			float expectedResult = -1.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Div_PositiveAndZeroTest)
		{
			float result = Functions::Divide(2, 0);
			float expectedResult = INFINITY;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Div_FloatPositiveAndZeroTest)
		{
			float result = Functions::Divide(2.5, 0);
			float expectedResult = INFINITY;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Div_ZeroAndPositiveTest)
		{
			float result = Functions::Divide(0, 2);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Div_ZeroAndFloatPositiveTest)
		{
			float result = Functions::Divide(0, 2.5);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Div_NegativeAndZeroTest)
		{
			float result = Functions::Divide(-2, 0);
			float expectedResult = -INFINITY;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Div_FloatNegativeAndZeroTest)
		{
			float result = Functions::Divide(-2.5, 0);
			float expectedResult = -INFINITY;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Div_ZeroAndNegativeTest)
		{
			float result = Functions::Divide(0, -2);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Div_ZeroAndFloatNegativeTest)
		{
			float result = Functions::Divide(0, -2.5);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}


		//Sin tests

		TEST_METHOD(Functions_Sin_PositiveTest)
		{
			float result = Functions::Sin(90, 0);
			float expectedResult = 1.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Sin_NegativeTest)
		{
			float result = Functions::Sin(-90, 0);
			float expectedResult = -1.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Sin_ZeroTest)
		{
			float result = Functions::Sin(0, 0);
			float expectedResult = 0.f;
			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Functions_Sin_FloatPositiveTest)
		{
			float result = Functions::Sin(90.5, 0);
			float expectedResult = 0.999962f;
			Assert::AreEqual(GetFloatPrecision(result, 6), GetFloatPrecision(expectedResult, 6));
		}

		TEST_METHOD(Functions_Sin_FloatNegativeTest)
		{
			float result = Functions::Sin(-90.5, 0);
			float expectedResult = -0.999962f;
			Assert::AreEqual(GetFloatPrecision(result, 6), GetFloatPrecision(expectedResult, 6));
		}


		//Cos tests

		TEST_METHOD(Functions_Cos_PositiveTest)
		{
			float result = Functions::Cos(90, 0);
			float expectedResult = 0.f;
			Assert::AreEqual(GetFloatPrecision(result, 6), expectedResult);
		}

		TEST_METHOD(Functions_Cos_NegativeTest)
		{
			float result = Functions::Cos(-90, 0);
			float expectedResult = 0.f;
			Assert::AreEqual(GetFloatPrecision(result, 6), expectedResult);
		}

		TEST_METHOD(Functions_Cos_ZeroTest)
		{
			float result = Functions::Cos(0, 0);
			float expectedResult = 1.f;
			Assert::AreEqual(GetFloatPrecision(result, 6), expectedResult);
		}

		TEST_METHOD(Functions_Cos_FloatPositiveTest)
		{
			float result = Functions::Cos(180.5, 0);
			float expectedResult = -0.999961f;
			Assert::AreEqual(GetFloatPrecision(result, 6), expectedResult);
		}

		TEST_METHOD(Functions_Cos_FloatNegativeTest)
		{
			float result = Functions::Cos(-180.5, 0);
			float expectedResult = -0.999961f;
			Assert::AreEqual(GetFloatPrecision(result, 6), expectedResult);
		}

		float GetFloatPrecision(float value, int precision)
		{
			return ((int)(value * (int)pow(10, precision) + .5) / (float)pow(10, precision));
		}
	};
}