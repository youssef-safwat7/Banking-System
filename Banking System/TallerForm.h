#pragma once
//ref class TallerForm;
#include <windows.h>
#include"registrationForm.h"
#include "MainForm.h"
//#include "MangeForm.h"
//#include"Taller.h"
#include"customer.h"
#include"Taller.h"

#include <map>
#using <System.dll>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>
#include <iostream>
//#include"ViewInfo.h"
// Define SQL Server connection parameters

using namespace System;
using namespace System::Collections::Generic;
namespace BankingSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace std;


	public ref class TallerForm : public System::Windows::Forms::Form
	{
	public:
		TallerForm(Taller^ taller_)
		{
			InitializeComponent();
			taller = taller_;

			try
			{
				dataGridView1->Visible = true; // Initially hide the DataGridView



				String^ connString = "Data Source=Youssef;Initial Catalog=BankingSystem;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";

				// Using a using statement to ensure proper resource management
				{
					SqlConnection sqlConn(connString);
					sqlConn.Open();

					// Populate users
					String^ sqlQuery = "SELECT * FROM customers";
					SqlCommand command(sqlQuery, % sqlConn);
					SqlDataReader^ reader = command.ExecuteReader();

					while (reader->Read())
					{
						customer = gcnew Customer(reader->GetInt32(0), reader->GetString(1), reader->GetString(2), reader->GetString(3), reader->GetInt32(4), reader->GetString(5), reader->GetString(6),
							reader->IsDBNull(7) ? 0.0f : Convert::ToSingle(reader->GetValue(7)));

						customers->Add(customer->GetId(), customer);

					}

					reader->Close(); // Close the reader when done
					sqlConn.Close();
					// Populate transactions
				 // Close the reader when done
				} // SqlConnection is automatically closed when it goes out of scope

				// Dispose of objects to release resources
			}
			catch (SqlException^ ex)
			{
				// Handle SQL exceptions
				MessageBox::Show("Error: " + ex->Message);
			}
			catch (Exception^ ex)
			{
				// Handle other exceptions
				MessageBox::Show("Error: " + ex->Message);
			}
		}
		TallerForm()
		{
			InitializeComponent();
			

			try
			{
				dataGridView1->Visible = true; // Initially hide the DataGridView



				String^ connString = "Data Source=Youssef;Initial Catalog=BankingSystem;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";

				// Using a using statement to ensure proper resource management
				{
					SqlConnection sqlConn(connString);
					sqlConn.Open();

					// Populate users
					String^ sqlQuery = "SELECT * FROM customers";
					SqlCommand command(sqlQuery, % sqlConn);
					SqlDataReader^ reader = command.ExecuteReader();

					while (reader->Read())
					{
						customer = gcnew Customer(reader->GetInt32(0), reader->GetString(1), reader->GetString(2), reader->GetString(3), reader->GetInt32(4), reader->GetString(5), reader->GetString(6),
							reader->IsDBNull(7) ? 0.0f : Convert::ToSingle(reader->GetValue(7)));

						customers->Add(customer->GetId(), customer);

					}

					reader->Close(); // Close the reader when done
					sqlConn.Close();
					// Populate transactions
				 // Close the reader when done
				} // SqlConnection is automatically closed when it goes out of scope

				// Dispose of objects to release resources
			}
			catch (SqlException^ ex)
			{
				// Handle SQL exceptions
				MessageBox::Show("Error: " + ex->Message);
			}
			catch (Exception^ ex)
			{
				// Handle other exceptions
				MessageBox::Show("Error: " + ex->Message);
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TallerForm()
		{
			try
			{
				String^ connString = "Data Source=Youssef;Initial Catalog=BankingSystem;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
				SqlConnection^ sqlConn = gcnew SqlConnection(connString);
				sqlConn->Open();

				// Update Customer information
				SqlCommand^ updateUserCommand;
				for each (Customer ^ customer in customers->Values)
				{
					String^ updateUserQuery = "UPDATE customers SET accountBalance = @accountBalance WHERE id = @id;";
					updateUserCommand = gcnew SqlCommand(updateUserQuery, sqlConn);
					updateUserCommand->Parameters->AddWithValue("@accountBalance", customer->GetAccountBalance());
					updateUserCommand->Parameters->AddWithValue("@id", customer->GetId());
					updateUserCommand->ExecuteNonQuery();
				}

				// Insert transactions
				SqlCommand^ insertTransactionCommand;
				for each (Customer ^ customer in customers->Values)
				{
					while (customer->transactions->GetSize() > 0)
					{
						Transaction^ transaction = customer->transactions->pop();
						String^ insertTransactionQuery = "INSERT INTO transactions (id, sender, receiver, amount, type) VALUES (@id, @sender, @receiver, @amount, @type)";
						insertTransactionCommand = gcnew SqlCommand(insertTransactionQuery, sqlConn);
						insertTransactionCommand->Parameters->AddWithValue("@id", transaction->id);
						insertTransactionCommand->Parameters->AddWithValue("@sender", transaction->sender);
						insertTransactionCommand->Parameters->AddWithValue("@receiver", transaction->receiver);
						insertTransactionCommand->Parameters->AddWithValue("@amount", transaction->amount);
						insertTransactionCommand->Parameters->AddWithValue("@type", transaction->type);
						insertTransactionCommand->ExecuteNonQuery();
					}
				}

				sqlConn->Close();
			}
			catch (SqlException^ ex)
			{
				MessageBox::Show("SQL Error: " + ex->Message);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error: " + ex->Message);
			}

		}

	private: System::Windows::Forms::GroupBox^ groupBox4;
	protected:



	private: System::Windows::Forms::GroupBox^ groupBox3;








	private: System::Windows::Forms::GroupBox^ groupBox2;


















	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Button^ button6;













	private: System::Windows::Forms::Button^ logOut;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ bCheck;
	private: System::Windows::Forms::TextBox^ tbAccountNumCheck;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ tbAmountDeposit;
	private: System::Windows::Forms::TextBox^ tbAccountNumDeposit;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ tbAmountWithdraw;
	private: System::Windows::Forms::TextBox^ tbAccountNumWithdraw;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ tbAmountTransfer;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ tbTo;
	private: System::Windows::Forms::TextBox^ tbFrom;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;




	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::TextBox^ tbAccountNumDelete;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Amount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Sender;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Receiver;





















	protected:




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
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->bCheck = (gcnew System::Windows::Forms::Button());
			this->tbAccountNumCheck = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->tbAmountWithdraw = (gcnew System::Windows::Forms::TextBox());
			this->tbAccountNumWithdraw = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->tbAmountDeposit = (gcnew System::Windows::Forms::TextBox());
			this->tbAccountNumDeposit = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->logOut = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Amount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Sender = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Receiver = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tbAmountTransfer = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbTo = (gcnew System::Windows::Forms::TextBox());
			this->tbFrom = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->tbAccountNumDelete = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->bCheck);
			this->groupBox4->Controls->Add(this->tbAccountNumCheck);
			this->groupBox4->Controls->Add(this->label10);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox4->Location = System::Drawing::Point(199, 438);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(590, 200);
			this->groupBox4->TabIndex = 19;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Check Account Balance";
			// 
			// bCheck
			// 
			this->bCheck->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->bCheck->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->bCheck->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bCheck->Location = System::Drawing::Point(366, 100);
			this->bCheck->Name = L"bCheck";
			this->bCheck->Size = System::Drawing::Size(187, 56);
			this->bCheck->TabIndex = 19;
			this->bCheck->Text = L"Check";
			this->bCheck->UseVisualStyleBackColor = false;
			this->bCheck->Click += gcnew System::EventHandler(this, &TallerForm::bCheck_Click_1);
			// 
			// tbAccountNumCheck
			// 
			this->tbAccountNumCheck->Location = System::Drawing::Point(233, 45);
			this->tbAccountNumCheck->Name = L"tbAccountNumCheck";
			this->tbAccountNumCheck->Size = System::Drawing::Size(241, 30);
			this->tbAccountNumCheck->TabIndex = 18;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(38, 45);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(179, 25);
			this->label10->TabIndex = 17;
			this->label10->Text = L"Account Number:";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tbAmountWithdraw);
			this->groupBox3->Controls->Add(this->tbAccountNumWithdraw);
			this->groupBox3->Controls->Add(this->label7);
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Controls->Add(this->button7);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->Location = System::Drawing::Point(822, 218);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(681, 227);
			this->groupBox3->TabIndex = 18;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Withdraw";
			// 
			// tbAmountWithdraw
			// 
			this->tbAmountWithdraw->Location = System::Drawing::Point(218, 96);
			this->tbAmountWithdraw->Name = L"tbAmountWithdraw";
			this->tbAmountWithdraw->Size = System::Drawing::Size(233, 30);
			this->tbAmountWithdraw->TabIndex = 22;
			// 
			// tbAccountNumWithdraw
			// 
			this->tbAccountNumWithdraw->Location = System::Drawing::Point(218, 39);
			this->tbAccountNumWithdraw->Name = L"tbAccountNumWithdraw";
			this->tbAccountNumWithdraw->Size = System::Drawing::Size(233, 30);
			this->tbAccountNumWithdraw->TabIndex = 21;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(23, 101);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(93, 25);
			this->label7->TabIndex = 20;
			this->label7->Text = L"Amount:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(23, 39);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(179, 25);
			this->label8->TabIndex = 19;
			this->label8->Text = L"Account Number:";
			// 
			// button7
			// 
			this->button7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(351, 145);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(187, 53);
			this->button7->TabIndex = 18;
			this->button7->Text = L"Withdraw";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &TallerForm::button7_Click_1);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tbAmountDeposit);
			this->groupBox2->Controls->Add(this->tbAccountNumDeposit);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(193, 205);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(601, 227);
			this->groupBox2->TabIndex = 17;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Deposit";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &TallerForm::groupBox2_Enter);
			// 
			// tbAmountDeposit
			// 
			this->tbAmountDeposit->Location = System::Drawing::Point(238, 91);
			this->tbAmountDeposit->Name = L"tbAmountDeposit";
			this->tbAmountDeposit->Size = System::Drawing::Size(241, 30);
			this->tbAmountDeposit->TabIndex = 17;
			// 
			// tbAccountNumDeposit
			// 
			this->tbAccountNumDeposit->Location = System::Drawing::Point(238, 34);
			this->tbAccountNumDeposit->Name = L"tbAccountNumDeposit";
			this->tbAccountNumDeposit->Size = System::Drawing::Size(241, 30);
			this->tbAccountNumDeposit->TabIndex = 16;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(43, 96);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(93, 25);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Amount:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(43, 34);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(179, 25);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Account Number:";
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
			this->button4->Location = System::Drawing::Point(371, 140);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(187, 53);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Deposit";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &TallerForm::button4_Click_2);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
				static_cast<System::Int32>(static_cast<System::Byte>(107)));
			this->panel1->Controls->Add(this->logOut);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Location = System::Drawing::Point(2, -2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(185, 651);
			this->panel1->TabIndex = 20;
			// 
			// logOut
			// 
			this->logOut->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->logOut->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(97)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->logOut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->logOut->Location = System::Drawing::Point(7, 568);
			this->logOut->Name = L"logOut";
			this->logOut->Size = System::Drawing::Size(166, 53);
			this->logOut->TabIndex = 11;
			this->logOut->Text = L"Log Out";
			this->logOut->UseVisualStyleBackColor = false;
			this->logOut->Click += gcnew System::EventHandler(this, &TallerForm::logOut_Click_1);
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
			this->button6->Location = System::Drawing::Point(7, 151);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(166, 63);
			this->button6->TabIndex = 9;
			this->button6->Text = L"Create New Account";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &TallerForm::button6_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(233)), static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->dataGridView1->ColumnHeadersHeight = 29;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Type, this->Amount,
					this->Sender, this->Receiver
			});
			this->dataGridView1->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->dataGridView1->Location = System::Drawing::Point(822, 459);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(681, 190);
			this->dataGridView1->TabIndex = 26;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &TallerForm::dataGridView1_CellContentClick_1);
			// 
			// Type
			// 
			this->Type->HeaderText = L"Transaction Type";
			this->Type->MinimumWidth = 10;
			this->Type->Name = L"Type";
			this->Type->ReadOnly = true;
			// 
			// Amount
			// 
			this->Amount->HeaderText = L"Transaction Amount";
			this->Amount->MinimumWidth = 6;
			this->Amount->Name = L"Amount";
			this->Amount->ReadOnly = true;
			// 
			// Sender
			// 
			this->Sender->HeaderText = L"Sender ID";
			this->Sender->MinimumWidth = 6;
			this->Sender->Name = L"Sender";
			this->Sender->ReadOnly = true;
			// 
			// Receiver
			// 
			this->Receiver->HeaderText = L"Receiver ID";
			this->Receiver->MinimumWidth = 6;
			this->Receiver->Name = L"Receiver";
			this->Receiver->ReadOnly = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tbAmountTransfer);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->tbTo);
			this->groupBox1->Controls->Add(this->tbFrom);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(822, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(681, 200);
			this->groupBox1->TabIndex = 27;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Transfer";
			// 
			// tbAmountTransfer
			// 
			this->tbAmountTransfer->Location = System::Drawing::Point(444, 46);
			this->tbAmountTransfer->Name = L"tbAmountTransfer";
			this->tbAmountTransfer->Size = System::Drawing::Size(230, 30);
			this->tbAmountTransfer->TabIndex = 48;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(352, 46);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(86, 25);
			this->label4->TabIndex = 47;
			this->label4->Text = L"Amount";
			// 
			// tbTo
			// 
			this->tbTo->Location = System::Drawing::Point(100, 109);
			this->tbTo->Name = L"tbTo";
			this->tbTo->Size = System::Drawing::Size(231, 30);
			this->tbTo->TabIndex = 46;
			// 
			// tbFrom
			// 
			this->tbFrom->Location = System::Drawing::Point(100, 49);
			this->tbFrom->Name = L"tbFrom";
			this->tbFrom->Size = System::Drawing::Size(231, 30);
			this->tbFrom->TabIndex = 45;
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
			this->button2->Location = System::Drawing::Point(444, 94);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(204, 60);
			this->button2->TabIndex = 44;
			this->button2->Text = L"Transfer";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &TallerForm::button2_Click_1);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 109);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 25);
			this->label3->TabIndex = 43;
			this->label3->Text = L"To:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 25);
			this->label2->TabIndex = 42;
			this->label2->Text = L"From:";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->button9);
			this->groupBox5->Controls->Add(this->tbAccountNumDelete);
			this->groupBox5->Controls->Add(this->label1);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox5->Location = System::Drawing::Point(199, 12);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(542, 170);
			this->groupBox5->TabIndex = 56;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Delete Account";
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
			this->button9->Location = System::Drawing::Point(323, 108);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(187, 56);
			this->button9->TabIndex = 16;
			this->button9->Text = L"Delete";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &TallerForm::button9_Click_1);
			// 
			// tbAccountNumDelete
			// 
			this->tbAccountNumDelete->Location = System::Drawing::Point(190, 53);
			this->tbAccountNumDelete->Name = L"tbAccountNumDelete";
			this->tbAccountNumDelete->Size = System::Drawing::Size(241, 30);
			this->tbAccountNumDelete->TabIndex = 14;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(-5, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(179, 25);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Account Number:";
			// 
			// TallerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)), static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->ClientSize = System::Drawing::Size(1515, 656);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Name = L"TallerForm";
			this->Text = L"TallerForm";
			this->Load += gcnew System::EventHandler(this, &TallerForm::TallerForm_Load);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	public:	  Taller^ taller = nullptr;
	public: Customer^ customer = nullptr;
	public:	  Customer^ accebter = nullptr;





		  static Dictionary<int, Customer^>^ customers = gcnew Dictionary<int, Customer^>();



	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void groupBox4_Enter(System::Object^ sender, System::EventArgs^ e) {
	}

	private:System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->Close();
		BankingSystem::registrationForm regForm(taller);
		regForm.ShowDialog();

	}



	private: System::Void TallerForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void logOut_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void logOut_Click_1(System::Object^ sender, System::EventArgs^ e) {
		// Close the current instance of the application
		Application::Exit();

		// Start a new instance of the application
		System::Diagnostics::Process::Start(Application::ExecutablePath);
	}
	private: System::Void tbAccountNumCheck_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void bCheck_Click(System::Object^ sender, System::EventArgs^ e) {





	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {


	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	public: bool loadTransactions = true;
	public: void lastTransactions(int accountNumber) {
		if (loadTransactions) {
			String^ connString = "Data Source=Youssef;Initial Catalog=BankingSystem;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			// Populate users
			String^ sqlQuery_trans = "SELECT * FROM transactions";
			SqlCommand command(sqlQuery_trans, % sqlConn);
			SqlDataReader^ reader_trans = command.ExecuteReader();

			while (reader_trans->Read())
			{
				int num_id = reader_trans->GetInt32(0);
				if (customers->TryGetValue(num_id, customer))
				{
					customer->transactions->push(gcnew Transaction(reader_trans->GetInt32(0), reader_trans->IsDBNull(1) ? 0.0f : Convert::ToSingle(reader_trans->GetValue(1)),
						reader_trans->GetString(2), reader_trans->GetInt32(3), reader_trans->GetInt32(4)));
				}
			}

			reader_trans->Close();
			sqlConn.Close();

			loadTransactions = false;
		}

		if (customers->TryGetValue(accountNumber, customer)) {



			int count = 10; // Make sure to set this to a value or parse it from Customer input

			List<Transaction^>^ lastTransactions = gcnew List<Transaction^>();

			// Retrieve the last 'count' transactions
			int remaining = count; // Ensure 'count' is assigned a value
			int index = 0;

			if (!customer->transactions->isEmpty()) {

				Node<Transaction^>^ current = customer->transactions->topNode(); // Start at the top of the stack

				while (current != nullptr) {
					Transaction^ transaction = current->data;
					lastTransactions->Add(transaction);
					remaining--;
					index++;
					if (remaining == 0) {
						break;
					}
					current = current->next; // Move to the next node in the stack
				}
				// Clear existing data in the DataGridView
				dataGridView1->AllowUserToAddRows = false;

				while (dataGridView1->Rows->Count > 0) {
					dataGridView1->Rows->RemoveAt(0);
				}

				// Populate the DataGridView with the last transactions in reverse order
				for (int i = 0; i < lastTransactions->Count; i++) {
					Transaction^ transaction = lastTransactions[i];
					dataGridView1->Rows->Add(transaction->type, transaction->amount, transaction->sender, transaction->receiver);
				}

			}
		}

	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void bCheck_Click_1(System::Object^ sender, System::EventArgs^ e) {

		//Check 
		int accountNumber;
		if (Int32::TryParse(this->tbAccountNumCheck->Text, accountNumber)) {



			if (customers->TryGetValue(accountNumber, customer)) {

				MessageBox::Show("Account Balance is: " + (taller->GetCustomerAccountBalance(customer)), "Checking Account Balance");
				lastTransactions(accountNumber);


			}
			else {
				MessageBox::Show("Cann't Find This Account", "Account Not Found");

			}





		}


	}
	private: System::Void button4_Click_2(System::Object^ sender, System::EventArgs^ e) {
		// Deposit
		int accountNumber;
		float amount;
		Int32::TryParse(this->tbAccountNumDeposit->Text, accountNumber);
		float::TryParse(this->tbAmountDeposit->Text, amount);

		if (customers->TryGetValue(accountNumber, customer)) {
			if (taller->deposit(customer,amount) ){
				MessageBox::Show("Account Balance now is: " + customer->GetAccountBalance(), "Deposit Successful");

			}
			else {
				MessageBox::Show("Not Valid Amount", "Withdrawal failed ");

			}
		}
		else {
			MessageBox::Show("Cann't Find This Account", "Account Not Found");


		}
		lastTransactions(accountNumber);


	}
	private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
		//Transfer
		int from;
		int to;
		float amount;
		Int32::TryParse(this->tbFrom->Text, from);
		Int32::TryParse(this->tbTo->Text, to);
		float::TryParse(this->tbAmountTransfer->Text, amount);
		accebter = gcnew Customer;

		
		if (customers->TryGetValue(from, customer) && customers->TryGetValue(to, accebter)) {
			if (taller->transfer(customer, accebter, amount) ){
				MessageBox::Show("Account Numeber " + from + " Balance now is: " + customer->GetAccountBalance() + "\nAccount Numeber " + to + " Balance now is: " + accebter->GetAccountBalance(), "Transfer Successful");

			}
		}
		
		else {
			MessageBox::Show("Cann't Find This Account", "Account Not Found");
		}
		

		lastTransactions(from);


	}
	private: System::Void button7_Click_1(System::Object^ sender, System::EventArgs^ e) {
		//withdraw
		int accountNumber;
		float amount;
		Int32::TryParse(this->tbAccountNumWithdraw->Text, accountNumber);
		float::TryParse(this->tbAmountWithdraw->Text, amount);

		if (customers->TryGetValue(accountNumber, customer)) {
			if (taller->withdraw(customer,amount)) {
				MessageBox::Show("Account Balance now is: " + (taller->GetCustomerAccountBalance(customer)), "Withdrawal Successful");

			}
			else {
				MessageBox::Show("The Amount is grater than the account balance.\nThe Account Balance is:" + (taller->GetCustomerAccountBalance(customer)), "Withdrawal failed ");

			}
		}
		else {
			MessageBox::Show("Cann't Find This Account", "Account Not Found");

		}
		lastTransactions(accountNumber);

	}
	private: System::Void button9_Click_1(System::Object^ sender, System::EventArgs^ e) {
		int id;
		bool parseSuccess = Int32::TryParse(this->tbAccountNumDelete->Text, id);

		if (parseSuccess)
		{
			taller->DeleteCustomer(id);
			customers->Remove(id);
		}
		else
		{
			// Parsing of ID failed
			MessageBox::Show("Invalid ID format.");
		}
		while (dataGridView1->Rows->Count > 0) {
			dataGridView1->Rows->RemoveAt(0);
		}
	}
	private: System::Void dataGridView1_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	};
};