#pragma once
#include <Windows.h>
#include <exception>
#include "MainForm.h" // Include the header file for MainForm
#include <string>

namespace BankingSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	// Forward declaration of MainForm
	ref class MainForm;

	/// <summary>
	/// Summary for AdminForm
	/// </summary>
	public ref class AdminForm : public System::Windows::Forms::Form
	{
	public:
		AdminForm(void)
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
		~AdminForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::TextBox^ tbEmailDelete;
	protected:


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::TextBox^ tbPhoneNumber;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ tbPassword;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ tbEmail;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tbName;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;












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
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->tbEmailDelete = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tbPhoneNumber = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbEmail = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox5->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->button9);
			this->groupBox5->Controls->Add(this->tbEmailDelete);
			this->groupBox5->Controls->Add(this->label3);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox5->Location = System::Drawing::Point(12, 368);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(729, 170);
			this->groupBox5->TabIndex = 57;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Delete Taller Account";
			// 
			// button9
			// 
			this->button9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(482, 108);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(187, 56);
			this->button9->TabIndex = 17;
			this->button9->Text = L"Delete";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &AdminForm::button9_Click);
			// 
			// tbEmailDelete
			// 
			this->tbEmailDelete->Location = System::Drawing::Point(190, 53);
			this->tbEmailDelete->Name = L"tbEmailDelete";
			this->tbEmailDelete->Size = System::Drawing::Size(241, 30);
			this->tbEmailDelete->TabIndex = 14;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(16, 56);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 25);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Email:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tbPhoneNumber);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->tbPassword);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->tbEmail);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->tbName);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1224, 350);
			this->groupBox1->TabIndex = 56;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Add New Taller";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &AdminForm::groupBox1_Enter);
			// 
			// tbPhoneNumber
			// 
			this->tbPhoneNumber->Location = System::Drawing::Point(907, 95);
			this->tbPhoneNumber->Name = L"tbPhoneNumber";
			this->tbPhoneNumber->Size = System::Drawing::Size(241, 30);
			this->tbPhoneNumber->TabIndex = 36;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(712, 95);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(162, 25);
			this->label7->TabIndex = 35;
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
			this->button2->Location = System::Drawing::Point(482, 254);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(187, 56);
			this->button2->TabIndex = 34;
			this->button2->Text = L"Add";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &AdminForm::button2_Click);
			// 
			// tbPassword
			// 
			this->tbPassword->Location = System::Drawing::Point(907, 164);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->Size = System::Drawing::Size(241, 30);
			this->tbPassword->TabIndex = 33;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(712, 164);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(113, 25);
			this->label6->TabIndex = 32;
			this->label6->Text = L"Password:";
			// 
			// tbEmail
			// 
			this->tbEmail->Location = System::Drawing::Point(211, 164);
			this->tbEmail->Name = L"tbEmail";
			this->tbEmail->Size = System::Drawing::Size(241, 30);
			this->tbEmail->TabIndex = 31;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(16, 164);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 25);
			this->label5->TabIndex = 30;
			this->label5->Text = L"Email:";
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(211, 95);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(241, 30);
			this->tbName->TabIndex = 29;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(16, 95);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(75, 25);
			this->label4->TabIndex = 28;
			this->label4->Text = L"Name:";
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
			this->button1->Location = System::Drawing::Point(1017, 476);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(187, 56);
			this->button1->TabIndex = 58;
			this->button1->Text = L"Log Out";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &AdminForm::button1_Click);
			// 
			// AdminForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)), static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->ClientSize = System::Drawing::Size(1248, 546);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox1);
			this->Name = L"AdminForm";
			this->Text = L"AdminForm";
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ email = tbEmail->Text;
		String^ password = tbPassword->Text;
		String^ name = tbName->Text;
		String^ phoneNumber = tbPhoneNumber->Text;

		try
		{
			// Connection string to connect to the database
			String^ connString = "Data Source=Youssef;Initial Catalog=BankingSystem;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";

			// Establishing connection
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			// SQL command to insert a new user
			String^ addUserQuery = "INSERT INTO tallers (name, email, password, phoneNumber) "
				"VALUES (@name, @email, @password, @phoneNumber);";

			// Creating SQL command object and assigning connection
			SqlCommand^ addUserCommand = gcnew SqlCommand(addUserQuery, % sqlConn);

			// Adding parameters with explicit data types
			addUserCommand->Parameters->Add("@name", name);
			addUserCommand->Parameters->Add("@email", email);
			addUserCommand->Parameters->Add("@password", password);
			addUserCommand->Parameters->Add("@phoneNumber", phoneNumber);

			// Executing the command
			int rowsAffected = addUserCommand->ExecuteNonQuery();

			if (rowsAffected > 0)
			{
				// Displaying success message if insertion is successful
				MessageBox::Show("Account Created Successfully.", "New Account Added", MessageBoxButtons::OK);
			}
			else
			{
				MessageBox::Show("Failed to add new account.");
			}
		}
		catch (SqlException^ ex)
		{
			// Handling SQL exceptions
			MessageBox::Show("SQL Error: " + ex->Message);
		}
		catch (Exception^ ex)
		{
			// Handling other exceptions
			MessageBox::Show("Error: " + ex->Message);
		}
	}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ email = tbEmailDelete->Text;
	
		try
		{
			String^ connString = "Data Source=Youssef;Initial Catalog=BankingSystem;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";

			SqlConnection sqlConn(connString);
			sqlConn.Open();

			// Populate users
			String^ sqlQuery = "DELETE FROM tallers WHERE email = @email;";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@email", email);
			int rowsAffected = command.ExecuteNonQuery();

			if (rowsAffected > 0)
			{
				// User deleted successfully
				MessageBox::Show(" Taller deleted successfully ");

			}
			else
			{
				// User with the provided ID does not exist
				MessageBox::Show("Taller with Email " + email + " does not exist.");
			}
		}
		catch (SqlException^ ex)
		{
			// Handle SQL exceptions
			MessageBox::Show("SQL Error: " + ex->Message);
		}
		catch (Exception^ ex)
		{
			// Handle other exceptions
			MessageBox::Show("Error: " + ex->Message);
		}
	

}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Close the current instance of the application
	Application::Exit();
	// Start a new instance of the application
	System::Diagnostics::Process::Start(Application::ExecutablePath);
}
};
}
