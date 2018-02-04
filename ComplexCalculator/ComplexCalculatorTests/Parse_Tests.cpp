#define _USE_MATH_DEFINES

#include <math.h>
#include "stdafx.h"
#include "CppUnitTest.h"
#include "EquationParser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComplexCalculatorTests
{
	//Class which purpose is to test correctness of the calculated result
	//At the very beginning the given equation is converted to RPN - conversion is covered in other Unit Tests
	//After that the process of calculation the final result is performed
	//Final result is being displayed to the user
	TEST_CLASS(Parse_Tests)
	{
	public:

		TEST_METHOD(Parse_Operators_PositivesTest)
		{
			EquationParser equationParser;
			std::string equation = "2+2";
			float result = equationParser.Parse(equation);
			float expectedResult = 4.f;

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_Operators_FloatPositivesTest)
		{
			EquationParser equationParser;
			std::string equation = "2.25+2.5";
			float result = equationParser.Parse(equation);
			float expectedResult = 4.75;

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_Operators_NegativesTest)
		{
			EquationParser equationParser;
			std::string equation = "(0-2)+(0-2)";
			float result = equationParser.Parse(equation);
			float expectedResult = -4.f;

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_Operators_FloatNegativesTest)
		{
			EquationParser equationParser;
			std::string equation = "(0-2.25)+(0-2.5)";
			float result = equationParser.Parse(equation);
			float expectedResult = -4.75f;

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_Operators_NegativeAndPositiveTest)
		{
			EquationParser equationParser;
			std::string equation = "(0-2)+2";
			float result = equationParser.Parse(equation);
			float expectedResult = 0.0f;

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_Operators_FloatNegativeAndFloatPositiveTest)
		{
			EquationParser equationParser;
			std::string equation = "(0-2.25)+2.5";
			float result = equationParser.Parse(equation);
			float expectedResult = 0.25f;

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_Operators_PositiveAndNegativeTest)
		{
			EquationParser equationParser;
			std::string equation = "2+(0-2)";
			float result = equationParser.Parse(equation);
			float expectedResult = 0.0f;

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_Operators_FloatPositiveAndFloatNegativeTest)
		{
			EquationParser equationParser;
			std::string equation = "2.5+(0-2.25)";
			float result = equationParser.Parse(equation);
			float expectedResult = 0.25f;

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_Operators_PositiveAndZeroTest)
		{
			EquationParser equationParser;
			std::string equation = "2+0";
			float result = equationParser.Parse(equation);
			float expectedResult = 2.f;

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_Operators_FloatPositiveAndZeroTest)
		{
			EquationParser equationParser;
			std::string equation = "2.25+0";
			float result = equationParser.Parse(equation);
			float expectedResult = 2.25f;

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_Operators_ZeroAndPositiveTest)
		{
			EquationParser equationParser;
			std::string equation = "0+2";
			float result = equationParser.Parse(equation);
			float expectedResult = 2.f;

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_Operators_ZeroAndFloatPositiveTest)
		{
			EquationParser equationParser;
			std::string equation = "0+2.25";
			float result = equationParser.Parse(equation);
			float expectedResult = 2.25f;

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_Operators_NegativeAndZeroTest)
		{
			EquationParser equationParser;
			std::string equation = "(0-2)+0";
			float result = equationParser.Parse(equation);
			float expectedResult = -2.f;

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_Operators_FloatNegativeAndZeroTest)
		{
			EquationParser equationParser;
			std::string equation = "(0-2.25)+0";
			float result = equationParser.Parse(equation);
			float expectedResult = -2.25f;

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_Operators_ZeroAndNegativeTest)
		{
			EquationParser equationParser;
			std::string equation = "0+(0-2)";
			float result = equationParser.Parse(equation);
			float expectedResult = -2.f;

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_Operators_ZeroAndFloatNegativeTest)
		{
			EquationParser equationParser;
			std::string equation = "0+(0-2.25)";
			float result = equationParser.Parse(equation);
			float expectedResult = -2.25f;

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_OneArgFunctionPositiveArgTest)
		{
			EquationParser equationParser;

			std::string equation = "sin(90)";
			float result = equationParser.Parse(equation);
			float expectedResult = 1.f;

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_OneArgFunctionNegativeArgTest)
		{
			EquationParser equationParser;

			std::string equation = "sin((0-90))";
			float result = equationParser.Parse(equation);
			float expectedResult = -1.f;

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_OneArgFunctionPositiveFloatArgTest)
		{
			EquationParser equationParser;
			std::string equation = "sin(90.5)";
			float result = equationParser.Parse(equation);
			float expectedResult = sin(90.5*M_PI / 180.f);

			Assert::AreEqual(GetFloatPrecision(result, 6), GetFloatPrecision(expectedResult, 6));
		}

		TEST_METHOD(Parse_OneArgFunctionNegativeFloatArgTest)
		{
			EquationParser equationParser;
			std::string equation = "sin((0-90.5))";
			float result = equationParser.Parse(equation);
			float expectedResult = sin(-90.5*M_PI / 180.f);

			Assert::AreEqual(GetFloatPrecision(result, 6), GetFloatPrecision(expectedResult, 6));
		}

		TEST_METHOD(Parse_TwoArgFunctionPositiveArgsTest)
		{
			EquationParser equationParser;
			std::string equation = "pow(4,2)";
			float result = equationParser.Parse(equation);
			float expectedResult = pow(4, 2);

			Assert::AreEqual(result, expectedResult);
		}

		TEST_METHOD(Parse_TwoArgFunctionPositiveAndNegativeArgsTest)
		{
			EquationParser equationParser;
			std::string equation = "pow(4,(0-2))";
			float result = equationParser.Parse(equation);
			float expectedResult = pow(4, -2);

			Assert::AreEqual(GetFloatPrecision(result, 6), GetFloatPrecision(expectedResult, 6));
		}

		TEST_METHOD(Parse_TwoArgFunctionNegativeArgsTest)
		{
			EquationParser equationParser;
			std::string equation = "pow((0-4),(0-2))";
			float result = equationParser.Parse(equation);
			float expectedResult = pow(-4, -2);

			Assert::AreEqual(GetFloatPrecision(result, 6), GetFloatPrecision(expectedResult, 6));
		}

		TEST_METHOD(Parse_TwoArgFunctionNegativeAndPositiveArgsTest)
		{
			EquationParser equationParser;
			std::string equation = "pow((0-4),2)";
			float result = equationParser.Parse(equation);
			float expectedResult = pow(-4, 2);

			Assert::AreEqual(GetFloatPrecision(result, 6), GetFloatPrecision(expectedResult, 6));
		}

		TEST_METHOD(Parse_TwoArgFunctionPositiveFloatArgsTest)
		{
			EquationParser equationParser;
			std::string equation = "pow(4.5,2.5)";
			float result = equationParser.Parse(equation);
			float expectedResult = pow(4.5, 2.5);

			Assert::AreEqual(GetFloatPrecision(result, 6), GetFloatPrecision(expectedResult, 6));
		}

		TEST_METHOD(Parse_TwoArgFunctionPositiveAndNegativeFloatArgsTest)
		{
			EquationParser equationParser;
			std::string equation = "pow(4.5,(0-2.5))";
			float result = equationParser.Parse(equation);
			float expectedResult = pow(4.5, -2.5);

			Assert::AreEqual(GetFloatPrecision(result, 6), GetFloatPrecision(expectedResult, 6));
		}

		TEST_METHOD(Parse_TwoArgFunctionNegativeFloatArgsTest)
		{
			EquationParser equationParser;
			std::string equation = "pow((0-4.5),(0-2.5))";
			float result = equationParser.Parse(equation);
			float expectedResult = 0;

			Assert::AreEqual(GetFloatPrecision(result, 6), GetFloatPrecision(expectedResult, 6));
			Assert::IsTrue(equationParser.GetError());
		}

		TEST_METHOD(Parse_TwoArgFunctionNegativeAndPositiveFloatArgsTest)
		{
			EquationParser equationParser;
			std::string equation = "pow((0-4.5),2.5)";
			float result = equationParser.Parse(equation);
			float expectedResult = 0;

			Assert::AreEqual(GetFloatPrecision(result, 6), GetFloatPrecision(expectedResult, 6));
			Assert::IsTrue(equationParser.GetError());
		}

		float GetFloatPrecision(float value, int precision)
		{
			return ((int)(value * (int)pow(10, precision) + .5) / (float)pow(10, precision));
		}
	};
}