#ifndef _EQUATIONPARSER_H_
#define _EQUATIONPARSER_H_

#include <vector>
#include "Operation.h"
#include "Direction.h"
#include "Functions.h"

class EquationParser
{
public:
	EquationParser();
	void AddOperator(std::string name, int priority, Direction direction, float(*func)(float, float));
	float Parse(std::string equation);
	void SetError(bool error);
	bool GetError();
	std::vector<std::string>ConvertToRPN(std::string equation);

private:
	std::vector<Operation> operations;
	bool error; //Auxiliary value - true if error occurred during Parsing

	bool IsOperation(std::string character, Operation* operation);
};

#endif