#include "stdafx.h"
#include "CppUnitTest.h"
#include "EquationParser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComplexCalculatorTests
{
	//Class which purpose is to test correctness of converting the equation to Reverse Polish Notation
	//This class tests only the conversion of pre-defined functions one and two argumentative
	TEST_CLASS(ConvertToRPN_Functions_Tests)
	{
	public:

		TEST_METHOD(ConvertToRPN_OneArgFunctionPositiveArgTest)
		{
			EquationParser equationParser;

			std::string equation = "sin(90)";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "90", "sin" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_OneArgFunctionNegativeArgTest)
		{
			EquationParser equationParser;

			std::string equation = "sin((0-90))";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "0","90","-","sin" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_OneArgFunctionPositiveFloatArgTest)
		{
			EquationParser equationParser;

			std::string equation = "sin(90.5)";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "90.5", "sin" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_OneArgFunctionNegativeFloatArgTest)
		{
			EquationParser equationParser;

			std::string equation = "sin((0-90.5))";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "0","90.5","-","sin" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_TwoArgFunctionPositiveArgsTest)
		{
			EquationParser equationParser;

			std::string equation = "pow(4,2)";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "4","2","pow" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_TwoArgFunctionPositiveAndNegativeArgsTest)
		{
			EquationParser equationParser;

			std::string equation = "pow(4,-2)";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "4","2","-","pow" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_TwoArgFunctionNegativeArgsTest)
		{
			EquationParser equationParser;

			std::string equation = "pow(-4,-2)";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "4","-","2","-","pow" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_TwoArgFunctionNegativeAndPositiveArgsTest)
		{
			EquationParser equationParser;

			std::string equation = "pow(-4,2)";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "4","-","2","pow" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_TwoArgFunctionPositiveFloatArgsTest)
		{
			EquationParser equationParser;

			std::string equation = "pow(4.5,2.5)";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "4.5","2.5","pow" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_TwoArgFunctionPositiveAndNegativeFloatArgsTest)
		{
			EquationParser equationParser;

			std::string equation = "pow(4.5,-2.5)";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "4.5","2.5","-","pow" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_TwoArgFunctionNegativeFloatArgsTest)
		{
			EquationParser equationParser;

			std::string equation = "pow(-4.5,-2.5)";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "4.5","-","2.5","-","pow" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}

		TEST_METHOD(ConvertToRPN_TwoArgFunctionNegativeAndPositiveFloatArgsTest)
		{
			EquationParser equationParser;

			std::string equation = "pow(-4.5,2.5)";
			std::vector<std::string> result = equationParser.ConvertToRPN(equation);
			std::vector<std::string> expectedResult = { "4.5","-","2.5","pow" };
			bool is_equal = false;
			if (result.size() == expectedResult.size())
				is_equal = std::equal(result.begin(), result.end(), expectedResult.begin());
			Assert::IsTrue(is_equal);
		}
	};
}