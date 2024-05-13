#pragma once
#include <exception>
#include"registrationForm.h"
#include"TallerForm.h"
#include"MainForm.h"
#include"registrationForm.h"

namespace BankingSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MangeForm
	/// </summary>
	public ref class MangeForm : public System::Windows::Forms::Form
	{
	public:
		MangeForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MangeForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:












	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ panel1;




	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ tbAccountNumEdit;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ tbPasswordEdit;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ tbEmailEdit;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tbNameEdit;


	private: System::Windows::Forms::Label^ label4;




	private: System::Windows::Forms::TextBox^ tbPhonNumEdit;

	private: System::Windows::Forms::Label^ label7;


	protected:



















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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tbPhonNumEdit = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tbPasswordEdit = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbEmailEdit = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbNameEdit = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbAccountNumEdit = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(188, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1010, 52);
			this->label1->TabIndex = 39;
			this->label1->Text = L"Mange Account";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button8
			// 
			this->button8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(3, 311);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(166, 53);
			this->button8->TabIndex = 10;
			this->button8->Text = L"Transaction";
			this->button8->UseVisualStyleBackColor = false;
			// 
			// button6
			// 
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(7, 50);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(166, 63);
			this->button6->TabIndex = 9;
			this->button6->Text = L"Create New Account";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MangeForm::button6_Click);
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
			this->button1->Location = System::Drawing::Point(7, 560);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(166, 53);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Log Out";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(3, 171);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(166, 65);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Mange Account";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
				static_cast<System::Int32>(static_cast<System::Byte>(107)));
			this->panel1->Controls->Add(this->button8);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Location = System::Drawing::Point(3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(185, 651);
			this->panel1->TabIndex = 38;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tbPhonNumEdit);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->tbPasswordEdit);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->tbEmailEdit);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->tbNameEdit);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->tbAccountNumEdit);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(194, 120);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1029, 350);
			this->groupBox1->TabIndex = 54;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Edit Account";
			// 
			// tbPhonNumEdit
			// 
			this->tbPhonNumEdit->Location = System::Drawing::Point(667, 138);
			this->tbPhonNumEdit->Name = L"tbPhonNumEdit";
			this->tbPhonNumEdit->Size = System::Drawing::Size(241, 30);
			this->tbPhonNumEdit->TabIndex = 27;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(472, 138);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(162, 25);
			this->label7->TabIndex = 26;
			this->label7->Text = L"Phone Number:";
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(398, 278);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(187, 56);
			this->button2->TabIndex = 25;
			this->button2->Text = L"Applay";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MangeForm::button2_Click);
			// 
			// tbPasswordEdit
			// 
			this->tbPasswordEdit->Location = System::Drawing::Point(667, 207);
			this->tbPasswordEdit->Name = L"tbPasswordEdit";
			this->tbPasswordEdit->Size = System::Drawing::Size(241, 30);
			this->tbPasswordEdit->TabIndex = 23;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(472, 207);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(113, 25);
			this->label6->TabIndex = 22;
			this->label6->Text = L"Password:";
			// 
			// tbEmailEdit
			// 
			this->tbEmailEdit->Location = System::Drawing::Point(190, 207);
			this->tbEmailEdit->Name = L"tbEmailEdit";
			this->tbEmailEdit->Size = System::Drawing::Size(241, 30);
			this->tbEmailEdit->TabIndex = 21;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(-5, 207);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 25);
			this->label5->TabIndex = 20;
			this->label5->Text = L"Email:";
			// 
			// tbNameEdit
			// 
			this->tbNameEdit->Location = System::Drawing::Point(190, 138);
			this->tbNameEdit->Name = L"tbNameEdit";
			this->tbNameEdit->Size = System::Drawing::Size(241, 30);
			this->tbNameEdit->TabIndex = 19;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(-5, 138);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(75, 25);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Name:";
			// 
			// tbAccountNumEdit
			// 
			this->tbAccountNumEdit->Location = System::Drawing::Point(447, 53);
			this->tbAccountNumEdit->Name = L"tbAccountNumEdit";
			this->tbAccountNumEdit->Size = System::Drawing::Size(241, 30);
			this->tbAccountNumEdit->TabIndex = 14;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(252, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(179, 25);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Account Number:";
			// 
			// MangeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1225, 658);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Name = L"MangeForm";
			this->Text = L"MangeForm";
			this->Load += gcnew System::EventHandler(this, &MangeForm::MangeForm_Load);
			this->panel1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MangeForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {


}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	//int id; 
	//Int32::TryParse(this->tbAccountNumEdit->Text, id);
	//User^ user = gcnew User;
	//TallerForm^ tallerForm = gcnew TallerForm();
	//tallerForm->customers->TryGetValue(id, user);
	//String^ email = this->tbEmailEdit->Text;
	//String^ password = this->tbPasswordEdit->Text;
	//String^ name = this->tbNameEdit->Text;
	//String^ address = this->tbAddressEdit->Text;
	//String^ phoneNumber = this->tbPhoneNumEdit->Text;
	//int age;
	//Int32::TryParse(this->tbAgeEdit->Text, age);
	//user->accountType = "Customer";
	//user->address = address;
	//user->age = age;
	//user->email = email;
	//user->name = name;
	//user->password = password;
	//user->phoneNumber = phoneNumber;
}
};
}
