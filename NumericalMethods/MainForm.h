#pragma once

namespace NumericalMethods {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: static int N = 3;

	private: System::Windows::Forms::TextBox^ a11;
	private: System::Windows::Forms::TextBox^ a12;
	private: System::Windows::Forms::TextBox^ a13;

	private: System::Windows::Forms::TextBox^ b14;

	private: System::Windows::Forms::TextBox^ a21;
	private: System::Windows::Forms::TextBox^ a22;
	private: System::Windows::Forms::TextBox^ a23;

	private: System::Windows::Forms::TextBox^ b24;

	private: System::Windows::Forms::TextBox^ a31;
	private: System::Windows::Forms::TextBox^ a33;
	private: System::Windows::Forms::TextBox^ a32;

	private: System::Windows::Forms::TextBox^ b34;

	private: System::Windows::Forms::TextBox^ x1;
	private: System::Windows::Forms::TextBox^ x2;
	private: System::Windows::Forms::TextBox^ x3;

	private: System::Windows::Forms::Label^ x11;
	private: System::Windows::Forms::Label^ x12;
	private: System::Windows::Forms::Label^ x13;
	private: System::Windows::Forms::Label^ x21;
	private: System::Windows::Forms::Label^ x22;
	private: System::Windows::Forms::Label^ x23;
	private: System::Windows::Forms::Label^ x31;
	private: System::Windows::Forms::Label^ x32;
	private: System::Windows::Forms::Label^ x33;
	private: System::Windows::Forms::Label^ x1s;
	private: System::Windows::Forms::Label^ x2s;
	private: System::Windows::Forms::Label^ x3s;

	private: System::Windows::Forms::GroupBox^ solution;
	private: System::Windows::Forms::Button^ solveButton;

	protected:

	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->a11 = (gcnew System::Windows::Forms::TextBox());
			this->a13 = (gcnew System::Windows::Forms::TextBox());
			this->a12 = (gcnew System::Windows::Forms::TextBox());
			this->b14 = (gcnew System::Windows::Forms::TextBox());
			this->a21 = (gcnew System::Windows::Forms::TextBox());
			this->a22 = (gcnew System::Windows::Forms::TextBox());
			this->a23 = (gcnew System::Windows::Forms::TextBox());
			this->b24 = (gcnew System::Windows::Forms::TextBox());
			this->a31 = (gcnew System::Windows::Forms::TextBox());
			this->a32 = (gcnew System::Windows::Forms::TextBox());
			this->a33 = (gcnew System::Windows::Forms::TextBox());
			this->b34 = (gcnew System::Windows::Forms::TextBox());
			this->x1 = (gcnew System::Windows::Forms::TextBox());
			this->x2 = (gcnew System::Windows::Forms::TextBox());
			this->x3 = (gcnew System::Windows::Forms::TextBox());
			this->x11 = (gcnew System::Windows::Forms::Label());
			this->x12 = (gcnew System::Windows::Forms::Label());
			this->x21 = (gcnew System::Windows::Forms::Label());
			this->x31 = (gcnew System::Windows::Forms::Label());
			this->x22 = (gcnew System::Windows::Forms::Label());
			this->x32 = (gcnew System::Windows::Forms::Label());
			this->x13 = (gcnew System::Windows::Forms::Label());
			this->x23 = (gcnew System::Windows::Forms::Label());
			this->x33 = (gcnew System::Windows::Forms::Label());
			this->x1s = (gcnew System::Windows::Forms::Label());
			this->x2s = (gcnew System::Windows::Forms::Label());
			this->x3s = (gcnew System::Windows::Forms::Label());
			this->solution = (gcnew System::Windows::Forms::GroupBox());
			this->solveButton = (gcnew System::Windows::Forms::Button());
			this->solution->SuspendLayout();
			this->SuspendLayout();
			// 
			// a11
			// 
			this->a11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->a11->Font = (gcnew System::Drawing::Font(L"Courier New", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->a11->Location = System::Drawing::Point(48, 44);
			this->a11->Name = L"a11";
			this->a11->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->a11->Size = System::Drawing::Size(70, 34);
			this->a11->TabIndex = 0;
			this->a11->Tag = L"";
			this->a11->Text = L"0";
			this->a11->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// a13
			// 
			this->a13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->a13->Font = (gcnew System::Drawing::Font(L"Courier New", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->a13->Location = System::Drawing::Point(410, 44);
			this->a13->Name = L"a13";
			this->a13->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->a13->Size = System::Drawing::Size(70, 34);
			this->a13->TabIndex = 2;
			this->a13->Tag = L"";
			this->a13->Text = L"0";
			this->a13->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// a12
			// 
			this->a12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->a12->Font = (gcnew System::Drawing::Font(L"Courier New", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->a12->Location = System::Drawing::Point(229, 44);
			this->a12->Name = L"a12";
			this->a12->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->a12->Size = System::Drawing::Size(70, 34);
			this->a12->TabIndex = 1;
			this->a12->Tag = L"";
			this->a12->Text = L"0";
			this->a12->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// b14
			// 
			this->b14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->b14->Font = (gcnew System::Drawing::Font(L"Courier New", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->b14->Location = System::Drawing::Point(591, 44);
			this->b14->Name = L"b14";
			this->b14->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->b14->Size = System::Drawing::Size(70, 34);
			this->b14->TabIndex = 3;
			this->b14->Tag = L"";
			this->b14->Text = L"0";
			this->b14->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// a21
			// 
			this->a21->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->a21->Font = (gcnew System::Drawing::Font(L"Courier New", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->a21->Location = System::Drawing::Point(48, 107);
			this->a21->Name = L"a21";
			this->a21->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->a21->Size = System::Drawing::Size(70, 34);
			this->a21->TabIndex = 4;
			this->a21->Tag = L"";
			this->a21->Text = L"0";
			this->a21->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// a22
			// 
			this->a22->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->a22->Font = (gcnew System::Drawing::Font(L"Courier New", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->a22->Location = System::Drawing::Point(229, 107);
			this->a22->Name = L"a22";
			this->a22->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->a22->Size = System::Drawing::Size(70, 34);
			this->a22->TabIndex = 5;
			this->a22->Tag = L"";
			this->a22->Text = L"0";
			this->a22->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// a23
			// 
			this->a23->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->a23->Font = (gcnew System::Drawing::Font(L"Courier New", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->a23->Location = System::Drawing::Point(410, 107);
			this->a23->Name = L"a23";
			this->a23->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->a23->Size = System::Drawing::Size(70, 34);
			this->a23->TabIndex = 6;
			this->a23->Tag = L"";
			this->a23->Text = L"0";
			this->a23->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// b24
			// 
			this->b24->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->b24->Font = (gcnew System::Drawing::Font(L"Courier New", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->b24->Location = System::Drawing::Point(591, 107);
			this->b24->Name = L"b24";
			this->b24->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->b24->Size = System::Drawing::Size(70, 34);
			this->b24->TabIndex = 7;
			this->b24->Tag = L"";
			this->b24->Text = L"0";
			this->b24->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// a31
			// 
			this->a31->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->a31->Font = (gcnew System::Drawing::Font(L"Courier New", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->a31->Location = System::Drawing::Point(48, 169);
			this->a31->Name = L"a31";
			this->a31->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->a31->Size = System::Drawing::Size(70, 34);
			this->a31->TabIndex = 8;
			this->a31->Tag = L"";
			this->a31->Text = L"0";
			this->a31->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// a32
			// 
			this->a32->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->a32->Font = (gcnew System::Drawing::Font(L"Courier New", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->a32->Location = System::Drawing::Point(229, 169);
			this->a32->Name = L"a32";
			this->a32->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->a32->Size = System::Drawing::Size(70, 34);
			this->a32->TabIndex = 9;
			this->a32->Tag = L"";
			this->a32->Text = L"0";
			this->a32->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// a33
			// 
			this->a33->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->a33->Font = (gcnew System::Drawing::Font(L"Courier New", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->a33->Location = System::Drawing::Point(410, 169);
			this->a33->Name = L"a33";
			this->a33->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->a33->Size = System::Drawing::Size(70, 34);
			this->a33->TabIndex = 10;
			this->a33->Tag = L"";
			this->a33->Text = L"0";
			this->a33->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// b34
			// 
			this->b34->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->b34->Font = (gcnew System::Drawing::Font(L"Courier New", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->b34->Location = System::Drawing::Point(591, 169);
			this->b34->Name = L"b34";
			this->b34->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->b34->Size = System::Drawing::Size(70, 34);
			this->b34->TabIndex = 11;
			this->b34->Tag = L"";
			this->b34->Text = L"0";
			this->b34->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// x1
			// 
			this->x1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->x1->Enabled = false;
			this->x1->Font = (gcnew System::Drawing::Font(L"Courier New", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->x1->Location = System::Drawing::Point(131, 60);
			this->x1->Name = L"x1";
			this->x1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->x1->Size = System::Drawing::Size(90, 34);
			this->x1->TabIndex = 13;
			this->x1->Tag = L"";
			this->x1->Text = L"0";
			this->x1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// x2
			// 
			this->x2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->x2->Enabled = false;
			this->x2->Font = (gcnew System::Drawing::Font(L"Courier New", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->x2->Location = System::Drawing::Point(131, 108);
			this->x2->Name = L"x2";
			this->x2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->x2->Size = System::Drawing::Size(90, 34);
			this->x2->TabIndex = 11;
			this->x2->Tag = L"";
			this->x2->Text = L"0";
			this->x2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// x3
			// 
			this->x3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->x3->Enabled = false;
			this->x3->Font = (gcnew System::Drawing::Font(L"Courier New", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->x3->Location = System::Drawing::Point(131, 155);
			this->x3->Name = L"x3";
			this->x3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->x3->Size = System::Drawing::Size(90, 34);
			this->x3->TabIndex = 12;
			this->x3->Tag = L"";
			this->x3->Text = L"0";
			this->x3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// x11
			// 
			this->x11->AutoSize = true;
			this->x11->Font = (gcnew System::Drawing::Font(L"Courier New", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->x11->ForeColor = System::Drawing::Color::Black;
			this->x11->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->x11->Location = System::Drawing::Point(124, 47);
			this->x11->Name = L"x11";
			this->x11->Size = System::Drawing::Size(99, 31);
			this->x11->TabIndex = 14;
			this->x11->Text = L"x1 + ";
			this->x11->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// x12
			// 
			this->x12->AutoSize = true;
			this->x12->Font = (gcnew System::Drawing::Font(L"Courier New", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->x12->ForeColor = System::Drawing::Color::Black;
			this->x12->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->x12->Location = System::Drawing::Point(305, 47);
			this->x12->Name = L"x12";
			this->x12->Size = System::Drawing::Size(99, 31);
			this->x12->TabIndex = 15;
			this->x12->Text = L"x2 + ";
			this->x12->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// x21
			// 
			this->x21->AutoSize = true;
			this->x21->Font = (gcnew System::Drawing::Font(L"Courier New", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->x21->ForeColor = System::Drawing::Color::Black;
			this->x21->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->x21->Location = System::Drawing::Point(124, 110);
			this->x21->Name = L"x21";
			this->x21->Size = System::Drawing::Size(99, 31);
			this->x21->TabIndex = 19;
			this->x21->Text = L"x1 + ";
			this->x21->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// x31
			// 
			this->x31->AutoSize = true;
			this->x31->Font = (gcnew System::Drawing::Font(L"Courier New", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->x31->ForeColor = System::Drawing::Color::Black;
			this->x31->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->x31->Location = System::Drawing::Point(124, 172);
			this->x31->Name = L"x31";
			this->x31->Size = System::Drawing::Size(99, 31);
			this->x31->TabIndex = 20;
			this->x31->Text = L"x1 + ";
			this->x31->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// x22
			// 
			this->x22->AutoSize = true;
			this->x22->Font = (gcnew System::Drawing::Font(L"Courier New", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->x22->ForeColor = System::Drawing::Color::Black;
			this->x22->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->x22->Location = System::Drawing::Point(305, 110);
			this->x22->Name = L"x22";
			this->x22->Size = System::Drawing::Size(99, 31);
			this->x22->TabIndex = 21;
			this->x22->Text = L"x2 + ";
			this->x22->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// x32
			// 
			this->x32->AutoSize = true;
			this->x32->Font = (gcnew System::Drawing::Font(L"Courier New", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->x32->ForeColor = System::Drawing::Color::Black;
			this->x32->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->x32->Location = System::Drawing::Point(305, 172);
			this->x32->Name = L"x32";
			this->x32->Size = System::Drawing::Size(99, 31);
			this->x32->TabIndex = 22;
			this->x32->Text = L"x2 + ";
			this->x32->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// x13
			// 
			this->x13->AutoSize = true;
			this->x13->Font = (gcnew System::Drawing::Font(L"Courier New", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->x13->ForeColor = System::Drawing::Color::Black;
			this->x13->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->x13->Location = System::Drawing::Point(486, 47);
			this->x13->Name = L"x13";
			this->x13->Size = System::Drawing::Size(99, 31);
			this->x13->TabIndex = 23;
			this->x13->Text = L"x3 = ";
			this->x13->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// x23
			// 
			this->x23->AutoSize = true;
			this->x23->Font = (gcnew System::Drawing::Font(L"Courier New", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->x23->ForeColor = System::Drawing::Color::Black;
			this->x23->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->x23->Location = System::Drawing::Point(486, 110);
			this->x23->Name = L"x23";
			this->x23->Size = System::Drawing::Size(99, 31);
			this->x23->TabIndex = 24;
			this->x23->Text = L"x3 = ";
			this->x23->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// x33
			// 
			this->x33->AutoSize = true;
			this->x33->Font = (gcnew System::Drawing::Font(L"Courier New", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->x33->ForeColor = System::Drawing::Color::Black;
			this->x33->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->x33->Location = System::Drawing::Point(486, 172);
			this->x33->Name = L"x33";
			this->x33->Size = System::Drawing::Size(99, 31);
			this->x33->TabIndex = 25;
			this->x33->Text = L"x3 = ";
			this->x33->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// x1s
			// 
			this->x1s->AutoSize = true;
			this->x1s->Font = (gcnew System::Drawing::Font(L"Courier New", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->x1s->ForeColor = System::Drawing::Color::Black;
			this->x1s->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->x1s->Location = System::Drawing::Point(26, 63);
			this->x1s->Name = L"x1s";
			this->x1s->Size = System::Drawing::Size(99, 31);
			this->x1s->TabIndex = 27;
			this->x1s->Text = L"x1 = ";
			this->x1s->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// x2s
			// 
			this->x2s->AutoSize = true;
			this->x2s->Font = (gcnew System::Drawing::Font(L"Courier New", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->x2s->ForeColor = System::Drawing::Color::Black;
			this->x2s->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->x2s->Location = System::Drawing::Point(26, 111);
			this->x2s->Name = L"x2s";
			this->x2s->Size = System::Drawing::Size(99, 31);
			this->x2s->TabIndex = 28;
			this->x2s->Text = L"x2 = ";
			this->x2s->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// x3s
			// 
			this->x3s->AutoSize = true;
			this->x3s->Font = (gcnew System::Drawing::Font(L"Courier New", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->x3s->ForeColor = System::Drawing::Color::Black;
			this->x3s->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->x3s->Location = System::Drawing::Point(26, 158);
			this->x3s->Name = L"x3s";
			this->x3s->Size = System::Drawing::Size(99, 31);
			this->x3s->TabIndex = 29;
			this->x3s->Text = L"x3 = ";
			this->x3s->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// solution
			// 
			this->solution->Controls->Add(this->x1);
			this->solution->Controls->Add(this->x3s);
			this->solution->Controls->Add(this->x2);
			this->solution->Controls->Add(this->x2s);
			this->solution->Controls->Add(this->x3);
			this->solution->Controls->Add(this->x1s);
			this->solution->Font = (gcnew System::Drawing::Font(L"Courier New", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->solution->Location = System::Drawing::Point(373, 236);
			this->solution->Name = L"solution";
			this->solution->Size = System::Drawing::Size(251, 214);
			this->solution->TabIndex = 30;
			this->solution->TabStop = false;
			this->solution->Text = L"Solution";
			// 
			// solveButton
			// 
			this->solveButton->Font = (gcnew System::Drawing::Font(L"Courier New", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->solveButton->Location = System::Drawing::Point(48, 330);
			this->solveButton->Name = L"solveButton";
			this->solveButton->Size = System::Drawing::Size(251, 60);
			this->solveButton->TabIndex = 31;
			this->solveButton->Text = L"Solve";
			this->solveButton->UseVisualStyleBackColor = true;
			this->solveButton->Click += gcnew System::EventHandler(this, &MainForm::solveButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkSalmon;
			this->ClientSize = System::Drawing::Size(708, 490);
			this->Controls->Add(this->solveButton);
			this->Controls->Add(this->solution);
			this->Controls->Add(this->x33);
			this->Controls->Add(this->x23);
			this->Controls->Add(this->x13);
			this->Controls->Add(this->x32);
			this->Controls->Add(this->x22);
			this->Controls->Add(this->x31);
			this->Controls->Add(this->x21);
			this->Controls->Add(this->x12);
			this->Controls->Add(this->x11);
			this->Controls->Add(this->a12);
			this->Controls->Add(this->a13);
			this->Controls->Add(this->b14);
			this->Controls->Add(this->a21);
			this->Controls->Add(this->a22);
			this->Controls->Add(this->a23);
			this->Controls->Add(this->b24);
			this->Controls->Add(this->a31);
			this->Controls->Add(this->a32);
			this->Controls->Add(this->a33);
			this->Controls->Add(this->b34);
			this->Controls->Add(this->a11);
			this->MinimumSize = System::Drawing::Size(726, 537);
			this->Name = L"MainForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"Gauss Method";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->solution->ResumeLayout(false);
			this->solution->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {}

	private: System::Void solveButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		array<TextBox^>^ textBoxes = gcnew array<TextBox^> {a11, a12, a13, b14,
															a21, a22, a23, b24,
															a31, a32, a33, b34};
		array<array<double>^>^ matrix;
		array<double>^ x = gcnew array<double>(N);

		if (!checkAndAssignToMatrix(textBoxes, matrix) || !checkDeterminant(matrix, N))
			return;

		partialPivot(matrix, N);
		backSubstitute(matrix, N, x);

		System::Diagnostics::Debug::WriteLine(System::String::Format("x1 = {0}", x[0]));
		System::Diagnostics::Debug::WriteLine(System::String::Format("x2 = {0}", x[1]));
		System::Diagnostics::Debug::WriteLine(System::String::Format("x3 = {0}", x[2]));

		x1->Text = roundToSignificantFigures(x[0], 3).ToString();
		x2->Text = roundToSignificantFigures(x[1], 3).ToString();
		x3->Text = roundToSignificantFigures(x[2], 3).ToString();
	}

	private: System::Boolean checkAndAssignToMatrix(array<TextBox^>^ textBoxes, array<array<double>^>^% matrix)
	{
		matrix = gcnew array<array<double>^>(N);	// Initialization of the matrix of dimension [N][N+1]
		for (int i = 0; i < N; i++)
			matrix[i] = gcnew array<double>(N + 1);

		int textBoxIndex = 0; // Index for sorting text fields
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N + 1; j++)
			{
				if (textBoxIndex < textBoxes->Length)
				{
					double value;
					if (Double::TryParse(textBoxes[textBoxIndex]->Text, value))
					{
						matrix[i][j] = value; // Writing the converted value into the matrix
						textBoxIndex++;	// Go to the next text field
					}
					else
					{
						MessageBox::Show("One or more values ​​entered are not double numbers", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
						return false;	// Exit from the method in case of an error
					}
				}
			}
		}
		return true;
	}

	private: System::Void partialPivot(array<array<double>^>^ A, int n)	// Foward elimination of Gauss method
	{
		for (int i = 0; i < n; i++) // Iterate through each column
		{
			int pivotRow = i;
			for (int j = i + 1; j < n; j++)	// Find the row with the maximum absolute value in the current column
			{
				if (Math::Abs(A[j][i]) > Math::Abs(A[pivotRow][i]))
					pivotRow = j;
			}
			
			if (pivotRow != i)	// Swap the current row with the pivot row if needed
			{
				for (int j = i; j <= n; j++) 
				{
					double temp = A[i][j];
					A[i][j] = A[pivotRow][j];
					A[pivotRow][j] = temp;
				}
			}
			
			for (int j = i + 1; j < n; j++)	// Eliminate the current column in all subsequent rows
			{
				double factor = A[j][i] / A[i][i];
				for (int k = i; k <= n; k++)
					A[j][k] -= factor * A[i][k];
			}
		}
	}

	private: System::Void backSubstitute(array<array<double>^>^ A, int n, array<double>^ x)	// Back Substitution of Gauss method
	{
		for (int i = n - 1; i >= 0; i--)	// Iterate from the last row up
		{
			double sum = 0.0;
			for (int j = i + 1; j < n; j++)	// Sum up all the values already found and multiply by their coefficients in the current row
				sum += A[i][j] * x[j];
			
			x[i] = (A[i][n] - sum) / A[i][i];	// Subtract the sum from the augmented part and divide by the pivot element
		}
	}

	private: System::Double calculateDeterminant(array<array<double>^>^ matrix, int n)
	{
		double det = 0;
		if (n == 1)
			return matrix[0][0]; // For a 1x1 matrix, the determinant is its only element

		array<array<double>^>^ temp = gcnew array<array<double>^>(n); // Temporary matrix for submatrices
		for (int i = 0; i < n; ++i)
			temp[i] = gcnew array<double>(n);

		int sign = 1; // The sign for each term of the determinant

		for (int f = 0; f < n; f++) // Sort by the first row
		{ 
			int p = 0; // A row of the temporary matrix
			for (int x = 1; x < n; x++)	// Exclude the first row of the original matrix
			{
				int q = 0; // A column of the temporal matrix
				for (int y = 0; y < n; y++)	// Exclude column f of the original matrix
				{ 
					if (y == f)	// Skip column f
						continue; 
					temp[p][q] = matrix[x][y];
					q++;
				}
				p++;
			}
			det += sign * matrix[0][f] * calculateDeterminant(temp, n - 1); // Recursive call for a submatrix
			sign = -sign; // Change of sign
		}

		return det;
	}

	private: System::Boolean checkDeterminant(array<array<double>^>^ matrix, int n) {
		double determinant = calculateDeterminant(matrix, n);

		if (determinant == 0 || Math::Abs(determinant) < 1e-6)	// Check whether the determinant = 0 or approaches 0
		{
			MessageBox::Show("There is no solution or the system is unstable", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return false;
		}
		return true;
	}

	private: System::Double roundToSignificantFigures(double num, int n) 
	{
		if (num == 0.0)	// If the number is zero, return zero
			return 0.0;

		double d = Math::Ceiling(Math::Log10(Math::Abs(num)));	// Calculate the order of magnitude of the number using its logarithm
																// Ceiling is used to round up to the nearest whole number
		int power = n - (int)d;	// Calculate the power to shift the number to the right of the decimal point
								// Needed to round the number to n significant figures

		double magnitude = Math::Pow(10, power); // Calculate the magnitude for the shifting process
		double shifted = Math::Round(num * magnitude); // Shift the number to the right of the decimal point, round it,
														// and then shift it back to its original position
		return shifted / magnitude;	// Return the rounded number, shifted back to its original position
	}
	};
}
