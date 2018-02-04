//#include <regex>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <sstream>
#include "EquationParser.h"
#include "Direction.h"

namespace ComplexCalculatorGUI
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//Windows Form class which represents the Graphical User Interface of the calculator
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm();
		static Boolean AreRadiansChecked;

	protected:
		~MainForm();
	private:
		String^ memoryString;
		int openedParAmount = 0;
		int closedParAmount = 0;

	private: System::Windows::Forms::Label^  label;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button0;
	private: System::Windows::Forms::Button^  buttonClosePar;
	private: System::Windows::Forms::Button^  buttonOpenPar;
	private: System::Windows::Forms::Button^  buttonComma;
	private: System::Windows::Forms::Button^  buttonEquals;
	private: System::Windows::Forms::Button^  buttonAdd;
	private: System::Windows::Forms::Button^  buttonMultiply;
	private: System::Windows::Forms::Button^  buttonDivide;
	private: System::Windows::Forms::Button^  buttonErase;
	private: System::Windows::Forms::Button^  buttonClear;
	private: System::Windows::Forms::Button^  buttonClearEntry;

	private: System::Windows::Forms::Button^  buttonPower;
	private: System::Windows::Forms::Button^  buttonRoot;

	private: System::Windows::Forms::Button^  buttonInverse;
	private: System::Windows::Forms::Button^  buttonMemory;
	private: System::Windows::Forms::Button^  buttonSubstract;
	private: System::Windows::Forms::Button^  buttonPlusMinus;
	private: System::Windows::Forms::Button^  buttonMemoryPlus;
	private: System::Windows::Forms::Button^  buttonMemoryMinus;
	private: System::Windows::Forms::Label^  lblMemory;
	private: System::Windows::Forms::Button^  buttonSin;
	private: System::Windows::Forms::Button^  buttonCos;
	private: System::Windows::Forms::Button^  buttonTan;
	private: System::Windows::Forms::GroupBox^  gbDigits;
	private: System::Windows::Forms::GroupBox^  gbOperators;


	private: System::Windows::Forms::GroupBox^  gbTrygonometric;

	private: System::Windows::Forms::GroupBox^  gbMemory;
	private: System::Windows::Forms::GroupBox^  gbRemoval;
	private: System::Windows::Forms::GroupBox^  gbPar;



	private: System::Windows::Forms::GroupBox^  gbFunctions;
	private: System::Windows::Forms::Button^  buttonATan;
	private: System::Windows::Forms::Button^  buttonACos;
	private: System::Windows::Forms::Button^  buttonASin;
	private: System::Windows::Forms::Button^  buttonLog;
	private: System::Windows::Forms::RadioButton^  radioRadians;
	private: System::Windows::Forms::RadioButton^  radioDegrees;
	private: System::Windows::Forms::Button^  buttonLn;

	private: void StringHandlerSingleArgsFunction(std::string function);
	private: void StringHandlerTwoArgsFunction(std::string function);
	private: void HandleButtonClick(String^ buttonText);
	private: void Calculate(String^ buttonText);

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button0 = (gcnew System::Windows::Forms::Button());
			this->buttonClosePar = (gcnew System::Windows::Forms::Button());
			this->buttonOpenPar = (gcnew System::Windows::Forms::Button());
			this->buttonComma = (gcnew System::Windows::Forms::Button());
			this->buttonEquals = (gcnew System::Windows::Forms::Button());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonMultiply = (gcnew System::Windows::Forms::Button());
			this->buttonDivide = (gcnew System::Windows::Forms::Button());
			this->buttonErase = (gcnew System::Windows::Forms::Button());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->buttonClearEntry = (gcnew System::Windows::Forms::Button());
			this->buttonPower = (gcnew System::Windows::Forms::Button());
			this->buttonRoot = (gcnew System::Windows::Forms::Button());
			this->buttonInverse = (gcnew System::Windows::Forms::Button());
			this->buttonMemory = (gcnew System::Windows::Forms::Button());
			this->buttonSubstract = (gcnew System::Windows::Forms::Button());
			this->buttonPlusMinus = (gcnew System::Windows::Forms::Button());
			this->buttonMemoryPlus = (gcnew System::Windows::Forms::Button());
			this->buttonMemoryMinus = (gcnew System::Windows::Forms::Button());
			this->lblMemory = (gcnew System::Windows::Forms::Label());
			this->buttonSin = (gcnew System::Windows::Forms::Button());
			this->buttonCos = (gcnew System::Windows::Forms::Button());
			this->buttonTan = (gcnew System::Windows::Forms::Button());
			this->gbDigits = (gcnew System::Windows::Forms::GroupBox());
			this->gbOperators = (gcnew System::Windows::Forms::GroupBox());
			this->gbTrygonometric = (gcnew System::Windows::Forms::GroupBox());
			this->radioRadians = (gcnew System::Windows::Forms::RadioButton());
			this->radioDegrees = (gcnew System::Windows::Forms::RadioButton());
			this->buttonATan = (gcnew System::Windows::Forms::Button());
			this->buttonASin = (gcnew System::Windows::Forms::Button());
			this->buttonACos = (gcnew System::Windows::Forms::Button());
			this->gbMemory = (gcnew System::Windows::Forms::GroupBox());
			this->gbRemoval = (gcnew System::Windows::Forms::GroupBox());
			this->gbPar = (gcnew System::Windows::Forms::GroupBox());
			this->gbFunctions = (gcnew System::Windows::Forms::GroupBox());
			this->buttonLog = (gcnew System::Windows::Forms::Button());
			this->buttonLn = (gcnew System::Windows::Forms::Button());
			this->gbDigits->SuspendLayout();
			this->gbOperators->SuspendLayout();
			this->gbTrygonometric->SuspendLayout();
			this->gbMemory->SuspendLayout();
			this->gbRemoval->SuspendLayout();
			this->gbPar->SuspendLayout();
			this->gbFunctions->SuspendLayout();
			this->SuspendLayout();
			// 
			// label
			// 
			this->label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label->Font = (gcnew System::Drawing::Font(L"Consolas", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label->Location = System::Drawing::Point(23, 40);
			this->label->Margin = System::Windows::Forms::Padding(0);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(518, 60);
			this->label->TabIndex = 0;
			this->label->Text = L"0";
			this->label->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button7->Location = System::Drawing::Point(9, 19);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(60, 60);
			this->button7->TabIndex = 1;
			this->button7->Text = L"7";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MainForm::button_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button8->Location = System::Drawing::Point(75, 19);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(60, 60);
			this->button8->TabIndex = 2;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MainForm::button_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button9->Location = System::Drawing::Point(141, 19);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(60, 60);
			this->button9->TabIndex = 3;
			this->button9->Text = L"9";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MainForm::button_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button4->Location = System::Drawing::Point(9, 85);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(60, 60);
			this->button4->TabIndex = 4;
			this->button4->Text = L"4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button5->Location = System::Drawing::Point(75, 85);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(60, 60);
			this->button5->TabIndex = 5;
			this->button5->Text = L"5";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button6->Location = System::Drawing::Point(141, 85);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(60, 60);
			this->button6->TabIndex = 6;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MainForm::button_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button1->Location = System::Drawing::Point(9, 151);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(60, 60);
			this->button1->TabIndex = 7;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button2->Location = System::Drawing::Point(75, 151);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(60, 60);
			this->button2->TabIndex = 8;
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button3->Location = System::Drawing::Point(141, 151);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(60, 60);
			this->button3->TabIndex = 9;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button_Click);
			// 
			// button0
			// 
			this->button0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button0->Location = System::Drawing::Point(75, 217);
			this->button0->Name = L"button0";
			this->button0->Size = System::Drawing::Size(60, 60);
			this->button0->TabIndex = 10;
			this->button0->Text = L"0";
			this->button0->UseVisualStyleBackColor = true;
			this->button0->Click += gcnew System::EventHandler(this, &MainForm::button_Click);
			// 
			// buttonClosePar
			// 
			this->buttonClosePar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonClosePar->Location = System::Drawing::Point(75, 16);
			this->buttonClosePar->Name = L"buttonClosePar";
			this->buttonClosePar->Size = System::Drawing::Size(60, 60);
			this->buttonClosePar->TabIndex = 11;
			this->buttonClosePar->Text = L")";
			this->buttonClosePar->UseVisualStyleBackColor = true;
			this->buttonClosePar->Click += gcnew System::EventHandler(this, &MainForm::button_Click);
			// 
			// buttonOpenPar
			// 
			this->buttonOpenPar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonOpenPar->Location = System::Drawing::Point(9, 16);
			this->buttonOpenPar->Name = L"buttonOpenPar";
			this->buttonOpenPar->Size = System::Drawing::Size(60, 60);
			this->buttonOpenPar->TabIndex = 12;
			this->buttonOpenPar->Text = L"(";
			this->buttonOpenPar->UseVisualStyleBackColor = true;
			this->buttonOpenPar->Click += gcnew System::EventHandler(this, &MainForm::button_Click);
			// 
			// buttonComma
			// 
			this->buttonComma->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonComma->Location = System::Drawing::Point(141, 16);
			this->buttonComma->Name = L"buttonComma";
			this->buttonComma->Size = System::Drawing::Size(60, 60);
			this->buttonComma->TabIndex = 13;
			this->buttonComma->Text = L".";
			this->buttonComma->UseVisualStyleBackColor = true;
			this->buttonComma->Click += gcnew System::EventHandler(this, &MainForm::button_Click);
			// 
			// buttonEquals
			// 
			this->buttonEquals->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonEquals->Location = System::Drawing::Point(9, 397);
			this->buttonEquals->Name = L"buttonEquals";
			this->buttonEquals->Size = System::Drawing::Size(60, 60);
			this->buttonEquals->TabIndex = 14;
			this->buttonEquals->Text = L"=";
			this->buttonEquals->UseVisualStyleBackColor = true;
			this->buttonEquals->Click += gcnew System::EventHandler(this, &MainForm::buttonEquals_Click);
			// 
			// buttonAdd
			// 
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonAdd->Location = System::Drawing::Point(9, 217);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(60, 60);
			this->buttonAdd->TabIndex = 15;
			this->buttonAdd->Text = L"+";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &MainForm::button_Click);
			// 
			// buttonMultiply
			// 
			this->buttonMultiply->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonMultiply->Location = System::Drawing::Point(9, 151);
			this->buttonMultiply->Name = L"buttonMultiply";
			this->buttonMultiply->Size = System::Drawing::Size(60, 60);
			this->buttonMultiply->TabIndex = 16;
			this->buttonMultiply->Text = L"*";
			this->buttonMultiply->UseVisualStyleBackColor = true;
			this->buttonMultiply->Click += gcnew System::EventHandler(this, &MainForm::button_Click);
			// 
			// buttonDivide
			// 
			this->buttonDivide->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonDivide->Location = System::Drawing::Point(9, 85);
			this->buttonDivide->Name = L"buttonDivide";
			this->buttonDivide->Size = System::Drawing::Size(60, 60);
			this->buttonDivide->TabIndex = 17;
			this->buttonDivide->Text = L"/";
			this->buttonDivide->UseVisualStyleBackColor = true;
			this->buttonDivide->Click += gcnew System::EventHandler(this, &MainForm::button_Click);
			// 
			// buttonErase
			// 
			this->buttonErase->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonErase->Location = System::Drawing::Point(141, 19);
			this->buttonErase->Name = L"buttonErase";
			this->buttonErase->Size = System::Drawing::Size(60, 60);
			this->buttonErase->TabIndex = 18;
			this->buttonErase->Text = L"<-";
			this->buttonErase->UseVisualStyleBackColor = true;
			this->buttonErase->Click += gcnew System::EventHandler(this, &MainForm::buttonErase_Click);
			// 
			// buttonClear
			// 
			this->buttonClear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonClear->Location = System::Drawing::Point(75, 19);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(60, 60);
			this->buttonClear->TabIndex = 19;
			this->buttonClear->Text = L"C";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &MainForm::buttonClear_Click);
			// 
			// buttonClearEntry
			// 
			this->buttonClearEntry->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonClearEntry->Location = System::Drawing::Point(9, 19);
			this->buttonClearEntry->Name = L"buttonClearEntry";
			this->buttonClearEntry->Size = System::Drawing::Size(60, 60);
			this->buttonClearEntry->TabIndex = 20;
			this->buttonClearEntry->Text = L"CE";
			this->buttonClearEntry->UseVisualStyleBackColor = true;
			this->buttonClearEntry->Click += gcnew System::EventHandler(this, &MainForm::buttonClearEntry_Click);
			// 
			// buttonPower
			// 
			this->buttonPower->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonPower->Location = System::Drawing::Point(9, 19);
			this->buttonPower->Name = L"buttonPower";
			this->buttonPower->Size = System::Drawing::Size(60, 60);
			this->buttonPower->TabIndex = 21;
			this->buttonPower->Text = L"pow";
			this->buttonPower->UseVisualStyleBackColor = true;
			this->buttonPower->Click += gcnew System::EventHandler(this, &MainForm::buttonPower_Click);
			// 
			// buttonRoot
			// 
			this->buttonRoot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonRoot->Location = System::Drawing::Point(75, 19);
			this->buttonRoot->Name = L"buttonRoot";
			this->buttonRoot->Size = System::Drawing::Size(60, 60);
			this->buttonRoot->TabIndex = 22;
			this->buttonRoot->Text = L"root";
			this->buttonRoot->UseVisualStyleBackColor = true;
			this->buttonRoot->Click += gcnew System::EventHandler(this, &MainForm::buttonRoot_Click);
			// 
			// buttonInverse
			// 
			this->buttonInverse->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonInverse->Location = System::Drawing::Point(141, 19);
			this->buttonInverse->Name = L"buttonInverse";
			this->buttonInverse->Size = System::Drawing::Size(60, 60);
			this->buttonInverse->TabIndex = 23;
			this->buttonInverse->Text = L"inv";
			this->buttonInverse->UseVisualStyleBackColor = true;
			this->buttonInverse->Click += gcnew System::EventHandler(this, &MainForm::buttonInverse_Click);
			// 
			// buttonMemory
			// 
			this->buttonMemory->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonMemory->Location = System::Drawing::Point(9, 19);
			this->buttonMemory->Name = L"buttonMemory";
			this->buttonMemory->Size = System::Drawing::Size(60, 60);
			this->buttonMemory->TabIndex = 24;
			this->buttonMemory->Text = L"M";
			this->buttonMemory->UseVisualStyleBackColor = true;
			this->buttonMemory->Click += gcnew System::EventHandler(this, &MainForm::buttonMemory_Click);
			// 
			// buttonSubstract
			// 
			this->buttonSubstract->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonSubstract->Location = System::Drawing::Point(9, 283);
			this->buttonSubstract->Name = L"buttonSubstract";
			this->buttonSubstract->Size = System::Drawing::Size(60, 60);
			this->buttonSubstract->TabIndex = 25;
			this->buttonSubstract->Text = L"-";
			this->buttonSubstract->UseVisualStyleBackColor = true;
			this->buttonSubstract->Click += gcnew System::EventHandler(this, &MainForm::button_Click);
			// 
			// buttonPlusMinus
			// 
			this->buttonPlusMinus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonPlusMinus->Location = System::Drawing::Point(9, 19);
			this->buttonPlusMinus->Name = L"buttonPlusMinus";
			this->buttonPlusMinus->Size = System::Drawing::Size(60, 60);
			this->buttonPlusMinus->TabIndex = 26;
			this->buttonPlusMinus->Text = L"+/-";
			this->buttonPlusMinus->UseVisualStyleBackColor = true;
			this->buttonPlusMinus->Click += gcnew System::EventHandler(this, &MainForm::buttonPlusMinus_Click);
			// 
			// buttonMemoryPlus
			// 
			this->buttonMemoryPlus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonMemoryPlus->Location = System::Drawing::Point(75, 19);
			this->buttonMemoryPlus->Name = L"buttonMemoryPlus";
			this->buttonMemoryPlus->Size = System::Drawing::Size(60, 60);
			this->buttonMemoryPlus->TabIndex = 27;
			this->buttonMemoryPlus->Text = L"M+";
			this->buttonMemoryPlus->UseVisualStyleBackColor = true;
			this->buttonMemoryPlus->Click += gcnew System::EventHandler(this, &MainForm::buttonMemoryPlus_Click);
			// 
			// buttonMemoryMinus
			// 
			this->buttonMemoryMinus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonMemoryMinus->Location = System::Drawing::Point(141, 19);
			this->buttonMemoryMinus->Name = L"buttonMemoryMinus";
			this->buttonMemoryMinus->Size = System::Drawing::Size(60, 60);
			this->buttonMemoryMinus->TabIndex = 28;
			this->buttonMemoryMinus->Text = L"M-";
			this->buttonMemoryMinus->UseVisualStyleBackColor = true;
			this->buttonMemoryMinus->Click += gcnew System::EventHandler(this, &MainForm::buttonMemoryMinus_Click);
			// 
			// lblMemory
			// 
			this->lblMemory->AutoSize = true;
			this->lblMemory->Location = System::Drawing::Point(106, 36);
			this->lblMemory->Name = L"lblMemory";
			this->lblMemory->Size = System::Drawing::Size(0, 13);
			this->lblMemory->TabIndex = 29;
			// 
			// buttonSin
			// 
			this->buttonSin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonSin->Location = System::Drawing::Point(10, 19);
			this->buttonSin->Name = L"buttonSin";
			this->buttonSin->Size = System::Drawing::Size(60, 60);
			this->buttonSin->TabIndex = 30;
			this->buttonSin->Text = L"sin";
			this->buttonSin->UseVisualStyleBackColor = true;
			this->buttonSin->Click += gcnew System::EventHandler(this, &MainForm::buttonSin_Click);
			// 
			// buttonCos
			// 
			this->buttonCos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonCos->Location = System::Drawing::Point(75, 19);
			this->buttonCos->Name = L"buttonCos";
			this->buttonCos->Size = System::Drawing::Size(60, 60);
			this->buttonCos->TabIndex = 31;
			this->buttonCos->Text = L"cos";
			this->buttonCos->UseVisualStyleBackColor = true;
			this->buttonCos->Click += gcnew System::EventHandler(this, &MainForm::buttonCos_Click);
			// 
			// buttonTan
			// 
			this->buttonTan->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonTan->Location = System::Drawing::Point(141, 19);
			this->buttonTan->Name = L"buttonTan";
			this->buttonTan->Size = System::Drawing::Size(60, 60);
			this->buttonTan->TabIndex = 32;
			this->buttonTan->Text = L"tan";
			this->buttonTan->UseVisualStyleBackColor = true;
			this->buttonTan->Click += gcnew System::EventHandler(this, &MainForm::buttonTan_Click);
			// 
			// gbDigits
			// 
			this->gbDigits->Controls->Add(this->button7);
			this->gbDigits->Controls->Add(this->button8);
			this->gbDigits->Controls->Add(this->button9);
			this->gbDigits->Controls->Add(this->button4);
			this->gbDigits->Controls->Add(this->button5);
			this->gbDigits->Controls->Add(this->button6);
			this->gbDigits->Controls->Add(this->button1);
			this->gbDigits->Controls->Add(this->button2);
			this->gbDigits->Controls->Add(this->button3);
			this->gbDigits->Controls->Add(this->button0);
			this->gbDigits->Location = System::Drawing::Point(242, 212);
			this->gbDigits->Name = L"gbDigits";
			this->gbDigits->Size = System::Drawing::Size(212, 285);
			this->gbDigits->TabIndex = 33;
			this->gbDigits->TabStop = false;
			this->gbDigits->Text = L"digits";
			// 
			// gbOperators
			// 
			this->gbOperators->Controls->Add(this->buttonDivide);
			this->gbOperators->Controls->Add(this->buttonMultiply);
			this->gbOperators->Controls->Add(this->buttonAdd);
			this->gbOperators->Controls->Add(this->buttonSubstract);
			this->gbOperators->Controls->Add(this->buttonEquals);
			this->gbOperators->Controls->Add(this->buttonPlusMinus);
			this->gbOperators->Location = System::Drawing::Point(463, 118);
			this->gbOperators->Name = L"gbOperators";
			this->gbOperators->Size = System::Drawing::Size(78, 466);
			this->gbOperators->TabIndex = 34;
			this->gbOperators->TabStop = false;
			this->gbOperators->Text = L"operators";
			// 
			// gbTrygonometric
			// 
			this->gbTrygonometric->Controls->Add(this->radioRadians);
			this->gbTrygonometric->Controls->Add(this->radioDegrees);
			this->gbTrygonometric->Controls->Add(this->buttonATan);
			this->gbTrygonometric->Controls->Add(this->buttonASin);
			this->gbTrygonometric->Controls->Add(this->buttonACos);
			this->gbTrygonometric->Controls->Add(this->buttonSin);
			this->gbTrygonometric->Controls->Add(this->buttonCos);
			this->gbTrygonometric->Controls->Add(this->buttonTan);
			this->gbTrygonometric->Location = System::Drawing::Point(23, 374);
			this->gbTrygonometric->Name = L"gbTrygonometric";
			this->gbTrygonometric->Size = System::Drawing::Size(210, 201);
			this->gbTrygonometric->TabIndex = 35;
			this->gbTrygonometric->TabStop = false;
			this->gbTrygonometric->Text = L"trigonometric";
			// 
			// radioRadians
			// 
			this->radioRadians->AutoSize = true;
			this->radioRadians->Checked = true;
			this->radioRadians->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->radioRadians->Location = System::Drawing::Point(115, 152);
			this->radioRadians->Name = L"radioRadians";
			this->radioRadians->Size = System::Drawing::Size(86, 24);
			this->radioRadians->TabIndex = 40;
			this->radioRadians->TabStop = true;
			this->radioRadians->Text = L"Radians";
			this->radioRadians->UseVisualStyleBackColor = true;
			this->radioRadians->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioRadians_CheckedChanged);
			// 
			// radioDegrees
			// 
			this->radioDegrees->AutoSize = true;
			this->radioDegrees->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->radioDegrees->Location = System::Drawing::Point(10, 152);
			this->radioDegrees->Name = L"radioDegrees";
			this->radioDegrees->Size = System::Drawing::Size(88, 24);
			this->radioDegrees->TabIndex = 39;
			this->radioDegrees->Text = L"Degrees";
			this->radioDegrees->UseVisualStyleBackColor = true;
			this->radioDegrees->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioDegrees_CheckedChanged);
			// 
			// buttonATan
			// 
			this->buttonATan->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonATan->Location = System::Drawing::Point(141, 85);
			this->buttonATan->Name = L"buttonATan";
			this->buttonATan->Size = System::Drawing::Size(60, 60);
			this->buttonATan->TabIndex = 34;
			this->buttonATan->Text = L"atan";
			this->buttonATan->UseVisualStyleBackColor = true;
			this->buttonATan->Click += gcnew System::EventHandler(this, &MainForm::buttonATan_Click);
			// 
			// buttonASin
			// 
			this->buttonASin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonASin->Location = System::Drawing::Point(9, 85);
			this->buttonASin->Name = L"buttonASin";
			this->buttonASin->Size = System::Drawing::Size(60, 60);
			this->buttonASin->TabIndex = 38;
			this->buttonASin->Text = L"asin";
			this->buttonASin->UseVisualStyleBackColor = true;
			this->buttonASin->Click += gcnew System::EventHandler(this, &MainForm::buttonASin_Click);
			// 
			// buttonACos
			// 
			this->buttonACos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonACos->Location = System::Drawing::Point(75, 85);
			this->buttonACos->Name = L"buttonACos";
			this->buttonACos->Size = System::Drawing::Size(60, 60);
			this->buttonACos->TabIndex = 33;
			this->buttonACos->Text = L"acos";
			this->buttonACos->UseVisualStyleBackColor = true;
			this->buttonACos->Click += gcnew System::EventHandler(this, &MainForm::buttonACos_Click);
			// 
			// gbMemory
			// 
			this->gbMemory->Controls->Add(this->buttonMemory);
			this->gbMemory->Controls->Add(this->buttonMemoryPlus);
			this->gbMemory->Controls->Add(this->buttonMemoryMinus);
			this->gbMemory->Location = System::Drawing::Point(23, 118);
			this->gbMemory->Name = L"gbMemory";
			this->gbMemory->Size = System::Drawing::Size(210, 90);
			this->gbMemory->TabIndex = 33;
			this->gbMemory->TabStop = false;
			this->gbMemory->Text = L"memory";
			// 
			// gbRemoval
			// 
			this->gbRemoval->Controls->Add(this->buttonClearEntry);
			this->gbRemoval->Controls->Add(this->buttonClear);
			this->gbRemoval->Controls->Add(this->buttonErase);
			this->gbRemoval->Location = System::Drawing::Point(242, 118);
			this->gbRemoval->Name = L"gbRemoval";
			this->gbRemoval->Size = System::Drawing::Size(212, 90);
			this->gbRemoval->TabIndex = 34;
			this->gbRemoval->TabStop = false;
			this->gbRemoval->Text = L"removal";
			// 
			// gbPar
			// 
			this->gbPar->Controls->Add(this->buttonOpenPar);
			this->gbPar->Controls->Add(this->buttonClosePar);
			this->gbPar->Controls->Add(this->buttonComma);
			this->gbPar->Location = System::Drawing::Point(242, 499);
			this->gbPar->Name = L"gbPar";
			this->gbPar->Size = System::Drawing::Size(212, 85);
			this->gbPar->TabIndex = 36;
			this->gbPar->TabStop = false;
			// 
			// gbFunctions
			// 
			this->gbFunctions->Controls->Add(this->buttonLog);
			this->gbFunctions->Controls->Add(this->buttonLn);
			this->gbFunctions->Controls->Add(this->buttonPower);
			this->gbFunctions->Controls->Add(this->buttonRoot);
			this->gbFunctions->Controls->Add(this->buttonInverse);
			this->gbFunctions->Location = System::Drawing::Point(23, 212);
			this->gbFunctions->Name = L"gbFunctions";
			this->gbFunctions->Size = System::Drawing::Size(210, 156);
			this->gbFunctions->TabIndex = 37;
			this->gbFunctions->TabStop = false;
			this->gbFunctions->Text = L"functions";
			// 
			// buttonLog
			// 
			this->buttonLog->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonLog->Location = System::Drawing::Point(75, 85);
			this->buttonLog->Name = L"buttonLog";
			this->buttonLog->Size = System::Drawing::Size(60, 60);
			this->buttonLog->TabIndex = 40;
			this->buttonLog->Text = L"log";
			this->buttonLog->UseVisualStyleBackColor = true;
			this->buttonLog->Click += gcnew System::EventHandler(this, &MainForm::buttonLog_Click);
			// 
			// buttonLn
			// 
			this->buttonLn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->buttonLn->Location = System::Drawing::Point(10, 85);
			this->buttonLn->Name = L"buttonLn";
			this->buttonLn->Size = System::Drawing::Size(60, 60);
			this->buttonLn->TabIndex = 39;
			this->buttonLn->Text = L"ln";
			this->buttonLn->UseVisualStyleBackColor = true;
			this->buttonLn->Click += gcnew System::EventHandler(this, &MainForm::buttonLn_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(562, 593);
			this->Controls->Add(this->gbFunctions);
			this->Controls->Add(this->gbPar);
			this->Controls->Add(this->gbRemoval);
			this->Controls->Add(this->gbMemory);
			this->Controls->Add(this->gbTrygonometric);
			this->Controls->Add(this->gbOperators);
			this->Controls->Add(this->gbDigits);
			this->Controls->Add(this->lblMemory);
			this->Controls->Add(this->label);
			this->DoubleBuffered = true;
			this->KeyPreview = true;
			this->Name = L"MainForm";
			this->Text = L"Complex Calculator";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->gbDigits->ResumeLayout(false);
			this->gbOperators->ResumeLayout(false);
			this->gbTrygonometric->ResumeLayout(false);
			this->gbTrygonometric->PerformLayout();
			this->gbMemory->ResumeLayout(false);
			this->gbRemoval->ResumeLayout(false);
			this->gbPar->ResumeLayout(false);
			this->gbFunctions->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonErase_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonClear_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Boolean Validate(String^ text, String^ button);

	private: System::Void buttonEquals_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonPlusMinus_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonPower_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonMemory_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonMemoryPlus_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonMemoryMinus_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonRoot_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonInverse_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonSin_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonCos_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonTan_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonClearEntry_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonASin_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonACos_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonATan_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonLn_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonLog_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);

	private: System::Void radioRadians_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::Void radioDegrees_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	};
}
