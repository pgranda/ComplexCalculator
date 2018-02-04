#include "MainForm.h"
#include <regex>

using namespace System;
using namespace System::Windows::Forms;
using namespace ComplexCalculatorGUI;

MainForm::MainForm()
{
	InitializeComponent();
}

MainForm::~MainForm()
{
	if (components)
	{
		delete components;
	}
}

/**
Function which after inserting number and clicking two arguments function button
Inserts function identifier and opens parenthesis
Sets the given number as first argument and inserts arguments separator - ","

@param function the function identifier
*/
void ComplexCalculatorGUI::MainForm::StringHandlerTwoArgsFunction(std::string function)
{
	std::regex digit("[[:digit:]]");
	std::string convertedLabelText = msclr::interop::marshal_as<std::string>(label->Text);

	std::string lastSymbol(1, convertedLabelText[label->Text->Length - 1]);
	if (!std::regex_match(lastSymbol, digit))
	{
		return;
	}

	for (int i = (int)convertedLabelText.length() - 1; i >= 0; i--)
	{
		std::string symbol(1, convertedLabelText[i]);
		if ((!std::regex_match(symbol, digit) && symbol != ".") || i == 0)
		{
			convertedLabelText.insert(i > 0 ? i + 1 : i, function);
			convertedLabelText.insert(convertedLabelText.length(), ",");

			label->Text = msclr::interop::marshal_as<String^>(convertedLabelText);
			openedParAmount++;
			return;
		}
	}
}

/**
Function which after inserting number and clicking single argument function button
Inserts function identifier and opens and closes parenthesis
Sets the given number as an argument

@param function the function identifier
*/
void ComplexCalculatorGUI::MainForm::StringHandlerSingleArgsFunction(std::string function)
{
	std::regex digit("[[:digit:]]");
	std::string convertedLabelText = msclr::interop::marshal_as<std::string>(label->Text);

	std::string lastSymbol(1, convertedLabelText[label->Text->Length - 1]);
	if (!std::regex_match(lastSymbol, digit))
	{
		return;
	}

	for (int i = (int)convertedLabelText.length() - 1; i >= 0; i--)
	{
		std::string symbol(1, convertedLabelText[i]);
		if ((!std::regex_match(symbol, digit) && symbol != ".") || i == 0)
		{
			convertedLabelText.insert(i > 0 ? i + 1 : i, function);
			convertedLabelText.insert(convertedLabelText.length(), ")");

			label->Text = msclr::interop::marshal_as<String^>(convertedLabelText);
			return;
		}
	}
}

/**
Action function linked to the buttons
After clicking the button, text from it is inserted into the equation label box

@param sender of the click event
@param e events argument
*/
System::Void MainForm::button_Click(System::Object^  sender, System::EventArgs^  e)
{
	Button^ button = safe_cast<Button^>(sender);
	HandleButtonClick(button->Text);
}

/**
Function which adds text from the clicked button to the label containing the equation

@param buttonText the text from the button that has been clicked
*/
System::Void MainForm::HandleButtonClick(String^ buttonText)
{
	if (!Validate(label->Text, buttonText))
	{
		return;
	}

	std::regex integer("[[:digit:]]");

	//Check if text is equal to zero, if true and digit was provided then remove 0.
	std::regex zero("[0]");
	std::regex error("ERROR");
	std::string convertedText = msclr::interop::marshal_as<std::string>(label->Text);
	std::string convertedButtonText = msclr::interop::marshal_as<std::string>(buttonText);
	//If the label text is a "starting zero" and user inserted a digit or parenthesis then we clear the label text
	if (std::regex_match(convertedText, zero))
	{
		if (std::regex_match(convertedButtonText, integer) || convertedButtonText == "(")
		{
			label->Text = "";
		}
	}
	//If the label text is an error, then we clear the label text
	if (std::regex_match(convertedText, error))
	{
		label->Text = "";
	}
	//Add text from clicked button to the label
	label->Text += buttonText;

	//Handle parenthesis counters if open or close parenthesis has been clicked
	if (convertedButtonText == "(")
	{
		openedParAmount++;
	}
	else if (convertedButtonText == ")")
	{
		closedParAmount++;
	}
}

/**
Function to Delete/Erase one symbol after erase button click

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonErase_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (label->Text == "0")
	{
		return;
	}
	if (label->Text->Substring(label->Text->Length > 1 ? label->Text->Length - 2 : 0, 1) == ")")
	{
		closedParAmount--;
	}
	else if (label->Text->Substring(label->Text->Length > 1 ? label->Text->Length - 2 : 0, 1) == "(")
	{
		openedParAmount--;
	}

	label->Text = label->Text->Substring(0, label->Text->Length - 1);

	if (label->Text->Length == 0)
	{
		label->Text = "0";
	}
}

/**
Function to Clear whole label after clear button click

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonClear_Click(System::Object^  sender, System::EventArgs^  e)
{
	closedParAmount = 0;
	openedParAmount = 0;
	label->Text = "0";
}

/**
Action on PlusMinus button click.
Function which allows us to change sign after inputing digit,
from positive to negative and from negative to positive.

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonPlusMinus_Click(System::Object^  sender, System::EventArgs^  e)
{
	std::regex digit("[[:digit:]]");
	std::regex dot("[.]");
	std::string convertedLabelText = msclr::interop::marshal_as<std::string>(label->Text);
	for (int i = (int)convertedLabelText.length() - 1; i >= 0; i--)
	{
		std::string symbol(1, convertedLabelText[i]);
		if (!(std::regex_match(symbol, digit) || std::regex_match(symbol, dot)) && i > 0)
		{
			std::string previousSymbol(1, convertedLabelText[i - 1]);
			if (std::regex_match(previousSymbol, digit))
			{
				convertedLabelText.insert(i + 1, "-");
			}
			else
			{
				convertedLabelText.erase(i, 1);
			}
			label->Text = msclr::interop::marshal_as<String^>(convertedLabelText);
			return;
		}
		else if (i == 0)
		{
			if (symbol != "-")
			{
				convertedLabelText.insert(i, "-");
			}
			else
			{
				convertedLabelText.erase(i, 1);
			}
			label->Text = msclr::interop::marshal_as<String^>(convertedLabelText);
		}
	}
}

/**
On Power button Click Event which changes string x to pow(x,

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonPower_Click(System::Object^  sender, System::EventArgs^  e)
{
	StringHandlerTwoArgsFunction("pow(");
}

/**
On Root button Click Event which changes string x to root(x,

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonRoot_Click(System::Object^  sender, System::EventArgs^  e)
{
	StringHandlerTwoArgsFunction("root(");
}

/**
On Inverse button Click Event which changes string x to inv(x)

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonInverse_Click(System::Object^  sender, System::EventArgs^  e)
{
	StringHandlerSingleArgsFunction("inv(");
}

/**
On Natural Logarithm button Click Event which changes string x to ln(x)

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonLn_Click(System::Object^  sender, System::EventArgs^  e)
{
	StringHandlerSingleArgsFunction("ln(");
}

/**
On Decimal Logarithm button Click Event which changes string x to log(x)

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonLog_Click(System::Object^  sender, System::EventArgs^  e)
{
	StringHandlerSingleArgsFunction("log(");
}

/**
On Sin button Click Event which changes string x to sin(x)

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonSin_Click(System::Object^  sender, System::EventArgs^  e)
{
	StringHandlerSingleArgsFunction("sin(");
}

/**
On Cos button Click Event which changes string x to cos(x)

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonCos_Click(System::Object^  sender, System::EventArgs^  e)
{
	StringHandlerSingleArgsFunction("cos(");
}

/**
On Tan button Click Event which changes string x to tan(x)

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonTan_Click(System::Object^  sender, System::EventArgs^  e)
{
	StringHandlerSingleArgsFunction("tan(");
}

/**
On Asin button Click Event which changes string x to asin(x)

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonASin_Click(System::Object^  sender, System::EventArgs^  e)
{
	StringHandlerSingleArgsFunction("asin(");
}

/**
On Acos button Click Event which changes string x to acos(x)

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonACos_Click(System::Object^  sender, System::EventArgs^  e)
{
	StringHandlerSingleArgsFunction("acos(");
}

/**
On Atan button Click Event which changes string x to atan(x)

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonATan_Click(System::Object^  sender, System::EventArgs^  e)
{
	StringHandlerSingleArgsFunction("atan(");
}

/**
On Radians radio button Click Event which changes the value AreRadiansChecked flag to true

@param sender of the click event
@param e events argument
*/
System::Void MainForm::radioRadians_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	TrigonometricUnitHelper::getInstance().AreRadiansChecked = true;
}

/**
On Radians radio button Click Event which changes the value AreRadiansChecked flag to false

@param sender of the click event
@param e events argument
*/
System::Void MainForm::radioDegrees_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	TrigonometricUnitHelper::getInstance().AreRadiansChecked = false;
}

/**
On Memory button Click Event which inserts the string stored in memory only when current string is ended with an operator

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonMemory_Click(System::Object^  sender, System::EventArgs^  e)
{
	std::string convertedText = msclr::interop::marshal_as<std::string>(label->Text);
	if (convertedText.back() != '+' && convertedText.back() != '-' && convertedText.back() != '*' && convertedText.back() != '/')
	{
		return;
	}

	label->Text = label->Text + memoryString;
}

/**
On Memory Plus button Click Event which adds the string to the memory variable

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonMemoryPlus_Click(System::Object^  sender, System::EventArgs^  e)
{
	memoryString = label->Text;
	lblMemory->Text = memoryString;
}

/**
On Memory Minus button Click Event which deletes the string that was stored in memory

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonMemoryMinus_Click(System::Object^  sender, System::EventArgs^  e)
{
	memoryString = "";
	lblMemory->Text = memoryString;
}

/**
On Clear Entry button Click Event which erases last entered number

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonClearEntry_Click(System::Object^  sender, System::EventArgs^  e)
{
	std::regex digit("[[:digit:]]");
	std::string convertedLabelText = msclr::interop::marshal_as<std::string>(label->Text);
	for (int i = (int)convertedLabelText.length() - 1; i >= 0; i--)
	{
		std::string symbol(1, convertedLabelText[i]);
		if ((!std::regex_match(symbol, digit) && symbol != ".") || i == 0)
		{
			int indexToRemove = i + 1;
			if (i != 0)
			{
				std::string previousSymbol(1, convertedLabelText[i - 1]);
				if (!std::regex_match(previousSymbol, digit) && symbol != ".")
				{
					indexToRemove--;
				}
				convertedLabelText.erase(indexToRemove, convertedLabelText.length() - indexToRemove);
			}
			else
			{
				indexToRemove = 0;
				convertedLabelText = "0";
			}

			label->Text = msclr::interop::marshal_as<String^>(convertedLabelText);
			return;
		}
	}
}

/**
Validation function which prevents errors when inputing values

@param text of current equation
@param button text from the clicked button
*/
System::Boolean MainForm::Validate(String^ text, String^ button)
{
	std::regex digit("[[:digit:]]");
	std::regex operators("[+-/*]");
	std::string convertedLabelText = msclr::interop::marshal_as<std::string>(text);
	std::string convertedButtonText = msclr::interop::marshal_as<std::string>(button);
	std::string symbol(1, convertedLabelText[convertedLabelText.length() - 1]);

	int textLength = (int)convertedLabelText.length();

	//Check for dot
	if (symbol == "." && !std::regex_match(convertedButtonText, digit))
	{
		return false;
	}

	//Check if dot can be placed
	if (convertedButtonText == "." && !std::regex_match(symbol, digit))
	{
		return false;
	}

	//Check for multiple operators precedence
	if (std::regex_match(symbol, operators) && std::regex_match(convertedButtonText, operators))
	{
		return false;
	}

	//Check for amount of digits in single number
	if (std::regex_match(convertedButtonText, digit) || convertedButtonText == ".")
	{
		for (int i = textLength - 1; i >= 0; i--)
		{
			std::string character(1, convertedLabelText[i]);
			if ((!std::regex_match(character, digit) && character != ".") || i == 0)
			{
				if (textLength - i >= 32)
				{
					return false;
				}
				break;
			}
		}
	}

	//Check for multiple dots in single number
	if (convertedButtonText == ".")
	{
		for (int i = textLength - 1; i >= 0; i--)
		{
			std::string character(1, convertedLabelText[i]);
			if ((!std::regex_match(character, digit) && character == "."))
			{
				return false;
			}
			else if (std::regex_match(character, operators))
			{
				break;
			}
		}
	}

	//Check for parenthesis opening
	if (convertedButtonText == "(")
	{
		if (!(textLength == 1 && convertedLabelText[0] == '0'))
		{
			std::string character(1, convertedLabelText[textLength - 1]);
			if (std::regex_match(character, digit))
			{
				return false;
			}
		}
	}

	//Check for parenthesis closing
	if (convertedButtonText == ")")
	{
		std::string lastCharacter(1, convertedLabelText[(int)convertedLabelText.length() - 1]);
		if (!std::regex_match(lastCharacter, digit) && lastCharacter != ")")
		{
			return false;
		}

		if (openedParAmount <= closedParAmount)
		{
			return false;
		}
	}

	return true;
}

/**
On Equals button Click Event which executes the result calculation process

@param sender of the click event
@param e events argument
*/
System::Void MainForm::buttonEquals_Click(System::Object^  sender, System::EventArgs^  e)
{
	Button^ button = safe_cast<Button^>(sender);
	Calculate(button->Text);
}

/**
Function which executes the logic of final result calculation

@param text from the button
*/
System::Void MainForm::Calculate(String^ buttonText)
{
	EquationParser equationParser;

	std::string convertedText = msclr::interop::marshal_as<std::string>(label->Text);

	//Unary minus
	std::regex digit("[[:digit:]]");
	for (int i = (int)convertedText.length() - 1; i >= 0; i--)
	{
		std::string symbol(1, convertedText[i]);
		if (symbol == "-")
		{
			std::string previousSymbol = "";
			if (i > 0)
			{
				previousSymbol = std::string(1, convertedText[i - 1]);
			}

			std::regex operators("[+-/*]");
			int tempIndex = 0;
			for (int j = i + 1; j <= (int)convertedText.length() - 1; j++)
			{
				std::string newSymbol(1, convertedText[j]);
				if (std::regex_match(newSymbol, operators) && newSymbol != ".")
				{
					tempIndex = j;
					break;
				}
				else if (j == (int)convertedText.length() - 1)
				{
					tempIndex = j + 1;
					break;
				}
			}
			if (!std::regex_match(previousSymbol, digit))
			{
				convertedText.insert(tempIndex, ")");
				convertedText.insert(i, "(0");
			}
		}
	}
	float result = equationParser.Parse(convertedText);
	if (equationParser.GetError())
	{
		label->Text = "ERROR";
		equationParser.SetError(false);
		return;
	}

	std::string stringResult = msclr::interop::marshal_as<std::string>(result.ToString());
	std::replace(stringResult.begin(), stringResult.end(), ',', '.');
	label->Text = msclr::interop::marshal_as<String^>(stringResult);
}

/**
Function which handles the input from the keyboard

@param sender of the click event
@param e key events argument
*/
System::Void MainForm::MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	Keys tmp = e->KeyCode;
	if (e->Modifiers == Keys::Shift && e->KeyCode == Keys::D9)
	{
		HandleButtonClick("(");
	}
	else if (e->Modifiers == Keys::Shift && e->KeyCode == Keys::D0)
	{
		HandleButtonClick(")");
	}
	else if (e->Modifiers == Keys::Shift && e->KeyCode == Keys::Oemplus)
	{
		Calculate("=");
	}
	else if ((e->KeyCode >= Keys::NumPad0) && (e->KeyCode <= Keys::NumPad9))
	{
		HandleButtonClick((e->KeyValue - 96).ToString());
	}
	else if ((e->KeyCode >= Keys::D0) && (e->KeyCode <= Keys::D9))
	{
		HandleButtonClick((e->KeyValue - 48).ToString());
	}
	else if (e->KeyCode == Keys::Add)
	{
		HandleButtonClick("+");
	}
	else if (e->KeyCode == Keys::Subtract)
	{
		HandleButtonClick("-");
	}
	else if (e->KeyCode == Keys::Multiply)
	{
		HandleButtonClick("*");
	}
	else if (e->KeyCode == Keys::Divide)
	{
		HandleButtonClick("/");
	}
	else if (e->KeyCode == Keys::Decimal || e->KeyCode == Keys::Oemcomma)
	{
		HandleButtonClick(".");
	}
	else if (e->KeyCode == Keys::OemOpenBrackets)
	{
		HandleButtonClick("(");
	}
}

int main()
{
	MainForm form;
	Application::Run(%form);
}

