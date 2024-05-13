#pragma once
#include <windows.h>
//#include"registrationForm.h"
//#include"TallerForm.h"
#include"AdminForm.h"
#include"customer.h"
#include"Admin.h"
#include"Taller.h"
#include <string>
using namespace std;

namespace BankingSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ L;








	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tbPassword;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ tbEmail;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ cbRole;






	protected:

	protected:

	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->L = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbEmail = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cbRole = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// L
			// 
			this->L->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->L->AutoSize = true;
			this->L->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 31.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L->Location = System::Drawing::Point(370, 62);
			this->L->Name = L"L";
			this->L->Size = System::Drawing::Size(185, 61);
			this->L->TabIndex = 1;
			this->L->Text = L"Log in:";
			this->L->Click += gcnew System::EventHandler(this, &MainForm::L_Click);
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(536, 482);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(255, 62);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Log In";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.ErrorImage")));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(5, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(359, 583);
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(375, 390);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(146, 32);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Password";
			// 
			// tbPassword
			// 
			this->tbPassword->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbPassword->Location = System::Drawing::Point(540, 400);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(333, 22);
			this->tbPassword->TabIndex = 12;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(375, 295);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 32);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Email";
			// 
			// tbEmail
			// 
			this->tbEmail->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbEmail->Location = System::Drawing::Point(540, 305);
			this->tbEmail->Name = L"tbEmail";
			this->tbEmail->Size = System::Drawing::Size(333, 22);
			this->tbEmail->TabIndex = 10;
			this->tbEmail->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(376, 216);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 25);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Log in as:";
			// 
			// cbRole
			// 
			this->cbRole->FormattingEnabled = true;
			this->cbRole->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Customer", L"Taller", L"Admin" });
			this->cbRole->Location = System::Drawing::Point(540, 217);
			this->cbRole->Name = L"cbRole";
			this->cbRole->Size = System::Drawing::Size(182, 24);
			this->cbRole->TabIndex = 16;
			this->cbRole->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::cbRole_SelectedIndexChanged);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)), static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->ClientSize = System::Drawing::Size(885, 587);
			this->Controls->Add(this->cbRole);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tbEmail);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->L);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public: Customer^ customer;
		public: Taller^ taller;
		public: Admin^ admin;
		public: String^ role;

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void L_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		
	}
		  
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ email = this->tbEmail->Text;
	String^ password = this->tbPassword->Text;
	role = this->cbRole->Text;
	if (email->Length == 0 || password->Length == 0) {
		MessageBox::Show("Please Enter The Email and Passowd","Email or Passwored is Empty");
		return;
	}
	
	try
	{
		String^ connString = "Data Source=Youssef;Initial Catalog=BankingSystem;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
		SqlConnection sqlConn(connString);
		sqlConn.Open();
		String^ sqlQuery = "";

		if (role == "Admin") {
			 sqlQuery = "SELECT * FROM admins WHERE email=@email AND password=@password";
			 SqlCommand command(sqlQuery, % sqlConn);
			 command.Parameters->AddWithValue("@email", email);
			 command.Parameters->AddWithValue("@password", password);

			 SqlDataReader^ reader = command.ExecuteReader();
			 if (reader->Read()) {
				  admin = gcnew Admin(reader->GetString(1), reader->GetString(2), reader->GetString(3));
			
				 this->Close();
			 }
			 else {
				 MessageBox::Show("Please Enter The Email and Passowd", "Email or Passwored Error");
				 return;
			 }

			 reader->Close(); // Close the reader when done
		}
		else if(role == "Customer")
		{
			 sqlQuery = "SELECT * FROM customers WHERE email=@email AND password=@password";
			 SqlCommand command(sqlQuery, % sqlConn);
			 command.Parameters->AddWithValue("@email", email);
			 command.Parameters->AddWithValue("@password", password);

			 SqlDataReader^ reader = command.ExecuteReader();
			 if (reader->Read()) {
				 customer = gcnew Customer(reader->GetInt32(0), reader->GetString(1),reader->GetString(2),
					 reader->GetString(3), reader->GetInt32(4), reader->GetString(5), reader->GetString(6),
					 reader->IsDBNull(7) ? 0.0f : Convert::ToSingle(reader->GetValue(7)));
				


				 this->Close();
			 }
			 else {
				 MessageBox::Show("Please Enter The Email and Passowd", "Email or Passwored Error");
				 return;
			 }

			 reader->Close(); // Close the reader when done

		}
		else if (role == "Taller")
		{
			 sqlQuery = "SELECT * FROM tallers WHERE email=@email AND password=@password";
			 SqlCommand command(sqlQuery, % sqlConn);
			 command.Parameters->AddWithValue("@email", email);
			 command.Parameters->AddWithValue("@password", password);

			 SqlDataReader^ reader = command.ExecuteReader();
			 if (reader->Read()) {
				 taller = gcnew Taller(reader->GetString(1), reader->GetString(2), reader->GetString(3), reader->GetString(4));
				

				 this->Close();
			 }
			 else {
				 MessageBox::Show("Please Enter The Email and Passowd", "Email or Passwored Error");
				 return;
			 }

			 reader->Close(); // Close the reader when done

		}
		else{
			MessageBox::Show("Please Slect Your Corect Role", "Incorect Role");
			return;
		}
		//String^ sqlQuery = "SELECT * FROM customers WHERE email=@email AND password=@password";


		// Dispose of objects to release resources
		
	}
	catch (SqlException^ ex)
	{
		MessageBox::Show("Failed to connect to database: " + ex->Message, "Database Error");
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("An error occurred: " + ex->Message, "Error");
	}
}

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void cbRole_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

}
};
}
