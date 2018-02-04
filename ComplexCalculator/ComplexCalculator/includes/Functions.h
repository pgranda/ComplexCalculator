#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#define _USE_MATH_DEFINES

#include <math.h>
#include "TrigonometricUnitHelper.h"

class Functions
{
public:
	//Function which returns the sum of 2 arguments
	static float Add(float arg1, float arg2);

	//Function which returns the difference of 2 arguments
	static float Substract(float arg1, float arg2);

	//Function which returns the product of 2 arguments
	static float Multiply(float arg1, float arg2);

	//Function which returns the ratio/fraction of 2 arguments
	static float Divide(float arg1, float arg2);

	//Function which returns the power of 2 arguments - base and exponent
	static float Power(float arg1, float arg2);

	//Function which returns the root of 2 arguments - radicand and degree
	static float Root(float arg1, float arg2);

	//Function which returns the inverse of an argument
	static float Inverse(float arg1, float arg2);

	//Function which returns the result of natural logarithm
	static float Ln(float arg1, float arg2);

	//Function which returns the result of logarithm of base 10
	static float Log(float arg1, float arg2);

	//Function which returns the sin of argument
	static float Sin(float arg1, float arg2);

	//Function which returns the cos of argument
	static float Cos(float arg1, float arg2);

	//Function which returns the tan of argument
	static float Tan(float arg1, float arg2);

	//Function which returns the arcsin of argument
	static float ASin(float arg1, float arg2);

	//Function which returns the arccos of argument
	static float ACos(float arg1, float arg2);

	//Function which returns the arctan of argument
	static float ATan(float arg1, float arg2);

private:
	//Disallow creating an instance of this object
	Functions();
};

#endif