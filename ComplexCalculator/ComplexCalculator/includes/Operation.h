#ifndef _OPERATION_H_
#define _OPERATION_H_
#include <iostream>
#include <string>
#include "Direction.h"

class Operation
{
public:
	Operation();
	Operation(std::string name, int priority, Direction direction, float(*func)(float, float));
	std::string GetName();
	int GetPriority();
	Direction GetDirection();
	float(*func)(float, float);

private:
	std::string name;
	int priority;
	Direction direction;
};

#endif
