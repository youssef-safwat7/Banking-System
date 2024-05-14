#pragma once
#include<Windows.h>
#include"MainForm.h"
#include"Taller.h"
#include"customer.h"
#include <exception>


using namespace System;
using namespace System::Windows::Forms;

namespace BankingSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace std;
	using namespace BankingSystem;

	/// <summary>
	/// Summary for registrationForm
	/// </summary>
	public ref class registrationForm : public System::Windows::Forms::Form
	{
	public:
		registrationForm(Taller^ taller_)
		{
			InitializeComponent();
			taller = taller_;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~registrationForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:




	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ tbPassword;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ tbAgeReg;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ tbAddress;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ tbPhoneNumber;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tbEmail;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tbName;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tbAccountBalance;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ button1;


	protected:














	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbAgeReg = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tbAddress = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbPhoneNumber = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbEmail = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbAccountBalance = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(511, 523);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(255, 68);
			this->button5->TabIndex = 37;
			this->button5->Text = L"Create";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &registrationForm::button5_Click);
			// 
			// tbPassword
			// 
			this->tbPassword->Location = System::Drawing::Point(874, 388);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(196, 22);
			this->tbPassword->TabIndex = 36;
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(740, 384);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(1113, 47);
			this->label6->TabIndex = 35;
			this->label6->Text = L"Password";
			// 
			// tbAgeReg
			// 
			this->tbAgeReg->Location = System::Drawing::Point(354, 384);
			this->tbAgeReg->Name = L"tbAgeReg";
			this->tbAgeReg->Size = System::Drawing::Size(196, 22);
			this->tbAgeReg->TabIndex = 34;
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(206, 380);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(1113, 47);
			this->label7->TabIndex = 33;
			this->label7->Text = L"Age";
			// 
			// tbAddress
			// 
			this->tbAddress->Location = System::Drawing::Point(874, 277);
			this->tbAddress->Name = L"tbAddress";
			this->tbAddress->Size = System::Drawing::Size(196, 22);
			this->tbAddress->TabIndex = 32;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(740, 273);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(1113, 47);
			this->label4->TabIndex = 31;
			this->label4->Text = L"Address";
			// 
			// tbPhoneNumber
			// 
			this->tbPhoneNumber->Location = System::Drawing::Point(354, 277);
			this->tbPhoneNumber->Name = L"tbPhoneNumber";
			this->tbPhoneNumber->Size = System::Drawing::Size(196, 22);
			this->tbPhoneNumber->TabIndex = 30;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(206, 277);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(1113, 47);
			this->label5->TabIndex = 29;
			this->label5->Text = L"Phon Number";
			this->label5->Click += gcnew System::EventHandler(this, &registrationForm::label5_Click_1);
			// 
			// tbEmail
			// 
			this->tbEmail->Location = System::Drawing::Point(874, 184);
			this->tbEmail->Name = L"tbEmail";
			this->tbEmail->Size = System::Drawing::Size(196, 22);
			this->tbEmail->TabIndex = 28;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(740, 180);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(1113, 47);
			this->label3->TabIndex = 27;
			this->label3->Text = L"Email";
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(354, 188);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(196, 22);
			this->tbName->TabIndex = 26;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(206, 184);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(1113, 47);
			this->label2->TabIndex = 25;
			this->label2->Text = L"Name";
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1172, 52);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Create New Account";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbAccountBalance
			// 
			this->tbAccountBalance->Location = System::Drawing::Point(639, 446);
			this->tbAccountBalance->Name = L"tbAccountBalance";
			this->tbAccountBalance->Size = System::Drawing::Size(196, 22);
			this->tbAccountBalance->TabIndex = 38;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(425, 443);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(175, 25);
			this->label8->TabIndex = 39;
			this->label8->Text = L"Account Balance";
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(12, 531);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(166, 53);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Log Out";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &registrationForm::button1_Click);
			// 
			// registrationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)), static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->ClientSize = System::Drawing::Size(1196, 627);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->tbAccountBalance);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->tbAgeReg);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->tbAddress);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->tbPhoneNumber);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->tbEmail);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"registrationForm";
			this->Text = L"registrationForm";
			this->Load += gcnew System::EventHandler(this, &registrationForm::registrationForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public: Taller^ taller = nullptr;
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
;

private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {

	
}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {

	}

		

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ email = this->tbEmail->Text;
		String^ password = this->tbPassword->Text;
		String^ name = this->tbName->Text;
		String^ address = this->tbAddress->Text;
		String^ phoneNumber = this->tbPhoneNumber->Text;
		float accountBalance; 
		int age; 

		if (!Int32::TryParse(this->tbAgeReg->Text, age)) {
			MessageBox::Show("Please enter a valid age.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (!float::TryParse(this->tbAccountBalance->Text, accountBalance)) {
			MessageBox::Show("Please enter a valid Account Balance.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (email->Length == 0 ||  password->Length==0 || name->Length == 0 || address->Length == 0 || phoneNumber->Length == 0 || age <= 0 || accountBalance < 0) {
			MessageBox::Show("Please Fill All Required Filled.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		taller->AddCustomer(0, name, email, password, age, phoneNumber, address, accountBalance);

		
	}


	
	private: System::Void registrationForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();

	System::Diagnostics::Process::Start(Application::ExecutablePath);
}
private: System::Void label5_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
};
}
