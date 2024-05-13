#pragma once
#include<Windows.h>
#include"MainForm.h"

#include"customer.h"
#include <exception>
//#include"TallerForm.h"

//ref class TallerForm;

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
		registrationForm(void)
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
		~registrationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Button^ button8;

	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ tbPassword;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ tbAge;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbAge = (gcnew System::Windows::Forms::TextBox());
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
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
				static_cast<System::Int32>(static_cast<System::Byte>(107)));
			this->panel1->Controls->Add(this->button8);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(1, -28);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(185, 651);
			this->panel1->TabIndex = 23;
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
			this->button8->Location = System::Drawing::Point(7, 274);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(166, 74);
			this->button8->TabIndex = 10;
			this->button8->Text = L"Main Dashboard";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &registrationForm::button8_Click);
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
			this->button1->Location = System::Drawing::Point(7, 584);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(166, 53);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Log Out";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &registrationForm::button1_Click);
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
			this->button5->Location = System::Drawing::Point(512, 491);
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
			// tbAge
			// 
			this->tbAge->Location = System::Drawing::Point(354, 384);
			this->tbAge->Name = L"tbAge";
			this->tbAge->Size = System::Drawing::Size(196, 22);
			this->tbAge->TabIndex = 34;
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
			this->label1->Location = System::Drawing::Point(192, 72);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1010, 52);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Create New Account";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// registrationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)), static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->ClientSize = System::Drawing::Size(1196, 627);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->tbAge);
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
			this->Controls->Add(this->panel1);
			this->Name = L"registrationForm";
			this->Text = L"registrationForm";
			this->Load += gcnew System::EventHandler(this, &registrationForm::registrationForm_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}

 //ref class TallerForm;

private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	// Hide and close the current form
	this->Hide();
	this->Close();

	// Create an instance of TallerForm
	//TallerForm^ tallerForm = gcnew TallerForm();

	// Show the TallerForm
	//tallerForm->Show();
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
		int age = 0; // Initialize age to 0

		// Try parsing age
		if (!Int32::TryParse(this->tbAge->Text, age)) {
			// Age parsing failed, handle the error
			MessageBox::Show("Please enter a valid age.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		Int32::TryParse(this->tbAge->Text, age);
		if (email->Length == 0 ||  password->Length==0 || name->Length == 0 || address->Length == 0 || phoneNumber->Length == 0 || age<= 0) {
			MessageBox::Show("Please Fill All Required Filled.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		Customer^ customer = gcnew Customer(0,name,email,password,age,phoneNumber,address,0);
	


		int customerId = -1; // Default value in case user ID retrieval fails

		// Connection string to connect to the database
		String^ connString = "Data Source=Youssef;Initial Catalog=BankingSystem;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);

		try {
			sqlConn->Open(); // Open the database connection

			// Check if the email already exists
			SqlCommand^ checkEmailCommand = gcnew SqlCommand("SELECT COUNT(*) FROM customers WHERE email = @email");
			checkEmailCommand->Connection = sqlConn;
			checkEmailCommand->Parameters->AddWithValue("@email", email);
			int existingEmailCount = Convert::ToInt32(checkEmailCommand->ExecuteScalar());

			if (existingEmailCount > 0) {
				MessageBox::Show("This Email Already Exists", "Email Not Valid", MessageBoxButtons::OK);

				// Email already exists, handle the error (you can throw an exception or return an error code)
				return; // Custom error code indicating duplicate email
			}

			// Add new user information
			SqlCommand^ addUserCommand = gcnew SqlCommand();
			addUserCommand->Connection = sqlConn;

			String^ addUserQuery = "INSERT INTO customers (name, email, password, age, phoneNumber, address, accountBalance) "
				"VALUES (@name, @email, @password, @age, @phoneNumber, @address, @accountBalance); "
				"SELECT SCOPE_IDENTITY();";

			addUserCommand->CommandText = addUserQuery;
			addUserCommand->Parameters->AddWithValue("@name", customer->GetName());
			addUserCommand->Parameters->AddWithValue("@email", customer->GetEmail());
			addUserCommand->Parameters->AddWithValue("@password", customer->GetPassword());
			addUserCommand->Parameters->AddWithValue("@age", customer->GetAge());
			addUserCommand->Parameters->AddWithValue("@phoneNumber", customer->GetPhoneNumber());
			addUserCommand->Parameters->AddWithValue("@address", customer->GetAddress());
			addUserCommand->Parameters->AddWithValue("@accountBalance", customer->GetAccountBalance());

			customerId = Convert::ToInt32(addUserCommand->ExecuteScalar());

			if (customerId != -1) {
				// Here, you can directly add the user to a dictionary
				Dictionary<int, Customer^>^ customers = gcnew Dictionary<int, Customer^>();

				if (!customers->ContainsKey(customerId)) {
					customers->Add(customerId, customer);
					customer->SetId(customerId);
					MessageBox::Show("Account Created Successfully.", "New Account Added", MessageBoxButtons::OK);
					return;

				}
				else {
					// Handle the case where the key already exists
					MessageBox::Show("An account with the same ID already exists.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			else {
				// Handle the case where userId is not retrieved successfully
				MessageBox::Show("Failed to retrieve customer ID from the database.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			sqlConn->Close(); // Close the database connection
		}
		catch (SqlException^ ex) {
			// SQL Exception occurred, handle it (you can log the error or throw it)
			Console::WriteLine("SQL Exception: " + ex->Message);
			// Custom error code indicating SQL exception
		}

		// No need to check if TallerForm is instantiated successfully
		// Just return after processing
		return;

	}


	
	private: System::Void registrationForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Close the current instance of the application
	Application::Exit();

	// Start a new instance of the application
	System::Diagnostics::Process::Start(Application::ExecutablePath);
}
};
}
