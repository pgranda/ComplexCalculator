#include "EquationParser.h"
#include <regex>
#include <algorithm>

EquationParser::EquationParser()
{
	//By default we have no errors
	error = false;

	//All operators and functions have to be added to parser
	AddOperator("+", 1, Direction::left, Functions::Add);
	AddOperator("-", 1, Direction::left, Functions::Substract);
	AddOperator("*", 2, Direction::left, Functions::Multiply);
	AddOperator("/", 2, Direction::left, Functions::Divide);
	AddOperator("pow", 3, Direction::right, Functions::Power);
	AddOperator("root", 3, Direction::right, Functions::Root);
	AddOperator("inv", 3, Direction::right, Functions::Inverse);
	AddOperator("ln", 3, Direction::right, Functions::Ln);
	AddOperator("log", 3, Direction::right, Functions::Log);
	AddOperator("sin", 3, Direction::right, Functions::Sin);
	AddOperator("cos", 3, Direction::right, Functions::Cos);
	AddOperator("tan", 3, Direction::right, Functions::Tan);
	AddOperator("asin", 3, Direction::right, Functions::ASin);
	AddOperator("acos", 3, Direction::right, Functions::ACos);
	AddOperator("atan", 3, Direction::right, Functions::ATan);
}

//Function which creates an operator anytime it is called with passed arguments and then adds it to the operations vector
void EquationParser::AddOperator(std::string name, int priority, Direction direction, float(*func)(float, float))
{
	Operation operation = Operation(name, priority, direction, func);
	operations.push_back(operation);
}

//Function which is a Setter for error
void EquationParser::SetError(bool error)
{
	this->error = error;
}

//Functions which is a Getter for error
bool EquationParser::GetError()
{
	return error;
}

//Functions which checks if operator with name equals to character was defined
bool EquationParser::IsOperation(std::string character, Operation* operation)
{
	Operation temporaryOperator = Operation("", -1, (Direction)-1, 0);
	*operation = temporaryOperator;

	bool isOperator = false;
	for (int i = 0; i < (int)operations.size(); i++)
	{
		if (operations[i].GetName() == character)
		{
			isOperator = true;
			*operation = operations[i];
			break;
		}
	}
	return isOperator;
}

//Function which gets the equation in converted RPN form, interpreters it, perform calculations and returns the result
float EquationParser::Parse(std::string equation)
{
	std::vector<std::string>convertedEquation = ConvertToRPN(equation);
	std::vector<std::string>stack;
	std::vector<std::string>singleArgumentFunctions = { "sin","cos","tan","asin","acos","atan","ln","log","inv" };

	for (int i = 0; i < (int)convertedEquation.size(); i++)
	{
		std::string symbol = convertedEquation[i];
		Operation operation;
		double dupa = atof(symbol.c_str());
		//Check if symbol is a number
		if (atof(symbol.c_str()) > 0 || symbol == "0")
		{
			stack.push_back(symbol);
		}
		//Check if symbol is an operator
		else if (IsOperation(symbol, &operation))
		{
			std::string firstNumber = stack[stack.size() - 1];
			stack.pop_back();

			float result;
			//Execute function for single argument operator
			if (std::find(singleArgumentFunctions.begin(), singleArgumentFunctions.end(), symbol) != singleArgumentFunctions.end())
			{
				result = (*operation.func)((float)atof(firstNumber.c_str()), 0.f);
			}
			//Execute function for double argument operator
			else
			{
				//If equation was not correct, for example "2+" and user clicked "="
				if (stack.size() == 0)
				{
					error = true;
					return 0;
				}
				std::string secondNumber = stack[stack.size() - 1];
				stack.pop_back();
				result = (*operation.func)((float)atof(secondNumber.c_str()), (float)atof(firstNumber.c_str()));
			}


			//Check if error during calculation occurred
			if (result == INFINITY || result != result)
			{
				error = true;
				return 0;
			}
			//Convert number to string

			std::string semiResult = std::to_string(result);
			stack.push_back(semiResult);
		}
	}
	if (stack.size() == 0)
	{
		error = true;
		return 0;
	}
	std::string result = stack[0];
	//Convert string to number
	return (float)atof(result.c_str());
}

//Function which converts provided string equation to Reverse Polish Notation equation
std::vector<std::string> EquationParser::ConvertToRPN(std::string equation)
{
	std::vector<std::string> result;
	std::vector<std::string> stack;

	int equationLength = (int)equation.size();
	std::string firstCharacter;
	std::string secondCharacter;
	std::regex integer("[[:digit:]]");
	std::regex letter("[a-zA-Z]");

	//Iterate through whole equation
	for (int i = 0; i < equationLength; i++)
	{
		//Read current character equal to i from equation
		firstCharacter = equation[i];
		//If read character is a number
		if (std::regex_match(firstCharacter, integer))
		{
			//Read next character in iteration
			secondCharacter = equation[++i];
			//Assign first character to auxiliary variable digit
			std::string digit = firstCharacter;
			//Check if every next character is a part of the same number
			while (std::regex_match(secondCharacter, integer) || secondCharacter == ".")
			{
				//Assign next character to variable digit
				digit += secondCharacter;
				//Check if its the end of the equation
				if (i + 1 >= equationLength)
				{
					i++;
					break;
				}
				//Assign the very next character to the second character
				secondCharacter = equation[++i];
				continue;
			}
			i--;
			//Push whole read number to the result vector array
			result.push_back(digit);
		}
		//Check for function
		else if (std::regex_match(firstCharacter, letter))
		{
			secondCharacter = equation[++i];
			std::string function = firstCharacter;

			while (std::regex_match(secondCharacter, letter))
			{
				function += secondCharacter;
				if (i + 1 >= equationLength)
				{
					i++;
					break;
				}

				secondCharacter = equation[++i];
				continue;
			}
			i--;
			stack.push_back(function);
		}
		//Check for function arguments separator
		else if (firstCharacter == ",")
		{
			while (stack[stack.size() - 1] != "(")
			{
				result.push_back(stack[stack.size() - 1]);
				stack.pop_back();
			}
		}
		//Check for opening the parenthesis
		else if (firstCharacter == "(")
		{
			stack.push_back(firstCharacter);
		}
		//Check for closing the parenthesis
		else if (firstCharacter == ")")
		{
			while (stack[stack.size() - 1] != "(")
			{
				result.push_back(stack[stack.size() - 1]);
				stack.pop_back();
			}
			stack.pop_back();
		}
		//If everything else fails, it means our character is an operator
		else
		{
			Operation currentOperator;
			//Getting defined operator with name equal to firstCharacter
			if (!IsOperation(firstCharacter, &currentOperator))
			{
				break;
			}

			//If no operator on stack
			if (stack.size() <= 0)
			{
				stack.push_back(firstCharacter);
				continue;
			}

			Operation Operation;
			//Getting operator with name equal to the last name on stack
			while (IsOperation(stack[stack.size() - 1], &Operation))
			{
				//Checking the order of operations by comparing priorities according to the directions
				if ((currentOperator.GetDirection() == (Direction)0 && currentOperator.GetPriority() <= Operation.GetPriority())
					|| (currentOperator.GetDirection() == (Direction)1 && currentOperator.GetPriority() < Operation.GetPriority()))
				{
					result.push_back(stack[stack.size() - 1]);
					stack.pop_back();
				}
				else
				{
					break;
				}
				if (stack.size() <= 0)
				{
					break;
				}
			}
			stack.push_back(firstCharacter);
		}
	}
	while (stack.size() > 0)
	{
		result.push_back(stack[stack.size() - 1]);
		stack.pop_back();
	}
	return result;
}