#include "Operation.h"
#include "Direction.h"

Operation::Operation()
{

}

Operation::Operation(std::string name, int priority, Direction direction, float(*func)(float, float))
{
	this->name = name;
	this->priority = priority;
	this->direction = direction;
	this->func = func;
}

std::string Operation::GetName()
{
	return name;
}

int Operation::GetPriority()
{
	return priority;
}

Direction Operation::GetDirection()
{
	return direction;
}
