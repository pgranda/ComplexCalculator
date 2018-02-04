#include "Functions.h"

//Function which returns the sum of 2 arguments
float Functions::Add(float arg1, float arg2)
{
	return arg1 + arg2;
}

//Function which returns the difference of 2 arguments
float Functions::Substract(float arg1, float arg2)
{
	return arg1 - arg2;
}

//Function which returns the product of 2 arguments
float Functions::Multiply(float arg1, float arg2)
{
	return arg1 * arg2;
}

//Function which returns the ratio/fraction of 2 arguments
float Functions::Divide(float arg1, float arg2)
{
	return arg1 / arg2;
}

//Function which returns the power of 2 arguments - base and exponent
float Functions::Power(float arg1, float arg2)
{
	return pow(arg1, arg2);
}

//Function which returns the root of 2 arguments - radicand and degree
float Functions::Root(float arg1, float arg2)
{
	return pow(arg1, 1.f / arg2);
}

//Function which returns the inverse of an argument
float Functions::Inverse(float arg1, float arg2)
{
	return 1 / arg1;
}

//Function which returns the result of natural logarithm
float Functions::Ln(float arg1, float arg2)
{
	return log(arg1);
}

//Function which returns the result of logarithm of base 10
float Functions::Log(float arg1, float arg2)
{
	return log10(arg1);
}

//Function which returns the sin of argument
float Functions::Sin(float arg1, float arg2)
{
	if (!TrigonometricUnitHelper::getInstance().AreRadiansChecked)
	{
		arg1 = arg1 * M_PI / 180.f;
	}
	return sin(arg1);
}

//Function which returns the cos of argument
float Functions::Cos(float arg1, float arg2)
{
	if (!TrigonometricUnitHelper::getInstance().AreRadiansChecked)
	{
		arg1 = arg1 * M_PI / 180.f;
	}
	return cos(arg1);
}

//Function which returns the tan of argument
float Functions::Tan(float arg1, float arg2)
{
	if (!TrigonometricUnitHelper::getInstance().AreRadiansChecked)
	{
		arg1 = arg1 * M_PI / 180.f;
	}
	return tan(arg1);
}

//Function which returns the arcsin of argument
float Functions::ASin(float arg1, float arg2)
{
	if (!TrigonometricUnitHelper::getInstance().AreRadiansChecked)
	{
		arg1 = arg1 * M_PI / 180.f;
	}
	return asin(arg1);
}

//Function which returns the arccos of argument
float Functions::ACos(float arg1, float arg2)
{
	if (!TrigonometricUnitHelper::getInstance().AreRadiansChecked)
	{
		arg1 = arg1 * M_PI / 180.f;
	}
	return acos(arg1);
}

//Function which returns the arctan of argument
float Functions::ATan(float arg1, float arg2)
{
	if (!TrigonometricUnitHelper::getInstance().AreRadiansChecked)
	{
		arg1 = arg1 * M_PI / 180.f;
	}
	return atan(arg1);
}

Functions::Functions()
{

}