#include "stdafx.h"
#include "CppUnitTest.h"
#include "EquationParser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComplexCalculatorTests
{
	//Class which purpose is to test correctness of converting the equation to Reverse Polish Notation
	//This class tests only the conversion of pre-defined operators
	TEST_CLASS(ConvertToRPN_Operators_Tests)
	{
	public:

		TEST_METHOD(ConvertToRPN_PositivesTest)
		{
			EquationParser equationParser;

			std::string equation = "2+2";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "2","2","+" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_FloatPositivesTest)
		{
			EquationParser equationParser;

			std::string equation = "2.5+2.5";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "2.5","2.5","+" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_NegativesTest)
		{
			EquationParser equationParser;

			std::string equation = "(0-2)+(0-2)";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "0","2","-","0","2","-","+" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_FloatNegativesTest)
		{
			EquationParser equationParser;

			std::string equation = "(0-2.5)+(0-2.5)";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "0","2.5","-","0","2.5","-","+" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_NegativeAndPositiveTest)
		{
			EquationParser equationParser;

			std::string equation = "(0-2)+2";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "0","2","-","2","+" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_FloatNegativeAndFloatPositiveTest)
		{
			EquationParser equationParser;

			std::string equation = "(0-2.5)+2.5";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "0","2.5","-","2.5","+" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_PositiveAndNegativeTest)
		{
			EquationParser equationParser;

			std::string equation = "2+(0-2)";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "2","0","2","-","+" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_FloatPositiveAndFloatNegativeTest)
		{
			EquationParser equationParser;

			std::string equation = "2.5+(0-2.5)";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "2.5","0","2.5","-","+" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_PositiveAndZeroTest)
		{
			EquationParser equationParser;

			std::string equation = "2+0";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "2","0","+" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_FloatPositiveAndZeroTest)
		{
			EquationParser equationParser;

			std::string equation = "2.5+0";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "2.5","0","+" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_ZeroAndPositiveTest)
		{
			EquationParser equationParser;

			std::string equation = "0+2";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "0","2","+" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_ZeroAndFloatPositiveTest)
		{
			EquationParser equationParser;

			std::string equation = "0+2.5";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "0","2.5","+" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_NegativeAndZeroTest)
		{
			EquationParser equationParser;

			std::string equation = "(0-2)+0";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "0","2","-","0","+" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_FloatNegativeAndZeroTest)
		{
			EquationParser equationParser;

			std::string equation = "(0-2.5)+0";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "0","2.5","-","0","+" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_ZeroAndNegativeTest)
		{
			EquationParser equationParser;

			std::string equation = "0+(0-2)";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "0","0","2","-","+" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_ZeroAndFloatNegativeTest)
		{
			EquationParser equationParser;

			std::string equation = "0+(0-2.5)";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "0","0","2.5","-","+" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}
	};
}