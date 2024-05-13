#pragma once
#include"MainForm.h"
#include"customer.h"
#include "TallerForm.h"
#include<string>
namespace BankingSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for CustomerForm
	/// </summary>
	public ref class CustomerForm : public System::Windows::Forms::Form
	{
	public:
		Customer^ customer;

		CustomerForm(Customer^ _customer)
		{
			customer = _customer;
			InitializeComponent();
			loadInfo();
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CustomerForm()
		{

			try
			{
				String^ connString = "Data Source=Youssef;Initial Catalog=BankingSystem;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
				SqlConnection^ sqlConn = gcnew SqlConnection(connString);
				sqlConn->Open();

				// Update Customer information
				SqlCommand^ updateUserCommand;

				String^ updateUserQuery = "UPDATE customers SET accountBalance = @accountBalance WHERE id = @id;";
				updateUserCommand = gcnew SqlCommand(updateUserQuery, sqlConn);
				updateUserCommand->Parameters->AddWithValue("@accountBalance", customer->GetAccountBalance());
				updateUserCommand->Parameters->AddWithValue("@id", customer->GetId());
				updateUserCommand->ExecuteNonQuery();


				// Insert transactions
				SqlCommand^ insertTransactionCommand;

				while (customer->transactions->Count > 0)
				{
					Transaction^ transaction = customer->transactions->Pop();
					String^ insertTransactionQuery = "INSERT INTO transactions (id, sender, receiver, amount, type) VALUES (@id, @sender, @receiver, @amount, @type)";
					insertTransactionCommand = gcnew SqlCommand(insertTransactionQuery, sqlConn);
					insertTransactionCommand->Parameters->AddWithValue("@id", transaction->id);
					insertTransactionCommand->Parameters->AddWithValue("@sender", transaction->sender);
					insertTransactionCommand->Parameters->AddWithValue("@receiver", transaction->receiver);
					insertTransactionCommand->Parameters->AddWithValue("@amount", transaction->amount);
					insertTransactionCommand->Parameters->AddWithValue("@type", transaction->type);
					insertTransactionCommand->ExecuteNonQuery();
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
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ tbAmountWithdraw;
	protected:
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::TextBox^ tbAmountSend;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ tbAmountDeposit;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tbTo;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Receiver;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Sender;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Amount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Type;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ phoneNumber;
	private: System::Windows::Forms::Label^ accountNumber;
	private: System::Windows::Forms::Label^ email;
	private: System::Windows::Forms::Label^ address;
	private: System::Windows::Forms::Label^ accountBalance;
	private: System::Windows::Forms::Label^ name;

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
			this->tbAmountWithdraw = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->tbAmountSend = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbAmountDeposit = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbTo = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Receiver = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Sender = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Amount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->phoneNumber = (gcnew System::Windows::Forms::Label());
			this->accountNumber = (gcnew System::Windows::Forms::Label());
			this->email = (gcnew System::Windows::Forms::Label());
			this->address = (gcnew System::Windows::Forms::Label());
			this->accountBalance = (gcnew System::Windows::Forms::Label());
			this->name = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tbAmountWithdraw
			// 
			this->tbAmountWithdraw->Location = System::Drawing::Point(139, 41);
			this->tbAmountWithdraw->Name = L"tbAmountWithdraw";
			this->tbAmountWithdraw->Size = System::Drawing::Size(233, 30);
			this->tbAmountWithdraw->TabIndex = 28;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(18, 44);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(93, 25);
			this->label7->TabIndex = 27;
			this->label7->Text = L"Amount:";
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
			this->button7->Location = System::Drawing::Point(403, 70);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(168, 53);
			this->button7->TabIndex = 26;
			this->button7->Text = L"Withdraw";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &CustomerForm::button7_Click);
			// 
			// tbAmountSend
			// 
			this->tbAmountSend->Location = System::Drawing::Point(114, 94);
			this->tbAmountSend->Name = L"tbAmountSend";
			this->tbAmountSend->Size = System::Drawing::Size(230, 30);
			this->tbAmountSend->TabIndex = 53;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 94);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(93, 25);
			this->label4->TabIndex = 52;
			this->label4->Text = L"Amount:";
			// 
			// tbAmountDeposit
			// 
			this->tbAmountDeposit->Location = System::Drawing::Point(166, 29);
			this->tbAmountDeposit->Name = L"tbAmountDeposit";
			this->tbAmountDeposit->Size = System::Drawing::Size(241, 30);
			this->tbAmountDeposit->TabIndex = 20;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(18, 34);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(93, 25);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Amount:";
			// 
			// tbTo
			// 
			this->tbTo->Location = System::Drawing::Point(114, 34);
			this->tbTo->Name = L"tbTo";
			this->tbTo->Size = System::Drawing::Size(231, 30);
			this->tbTo->TabIndex = 51;
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
			this->button2->Location = System::Drawing::Point(403, 48);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(168, 60);
			this->button2->TabIndex = 50;
			this->button2->Text = L"Send";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &CustomerForm::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(18, 34);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 25);
			this->label3->TabIndex = 49;
			this->label3->Text = L"To:";
			// 
			// Receiver
			// 
			this->Receiver->HeaderText = L"Receiver ID";
			this->Receiver->MinimumWidth = 6;
			this->Receiver->Name = L"Receiver";
			this->Receiver->ReadOnly = true;
			// 
			// Sender
			// 
			this->Sender->HeaderText = L"Sender ID";
			this->Sender->MinimumWidth = 6;
			this->Sender->Name = L"Sender";
			this->Sender->ReadOnly = true;
			// 
			// Amount
			// 
			this->Amount->HeaderText = L"Transaction Amount";
			this->Amount->MinimumWidth = 6;
			this->Amount->Name = L"Amount";
			this->Amount->ReadOnly = true;
			// 
			// Type
			// 
			this->Type->HeaderText = L"Transaction Type";
			this->Type->MinimumWidth = 10;
			this->Type->Name = L"Type";
			this->Type->ReadOnly = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tbAmountSend);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->tbTo);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(12, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(601, 159);
			this->groupBox1->TabIndex = 67;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Send";
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
			this->dataGridView1->Location = System::Drawing::Point(18, 443);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1286, 190);
			this->dataGridView1->TabIndex = 66;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->tbAmountWithdraw);
			this->groupBox3->Controls->Add(this->label7);
			this->groupBox3->Controls->Add(this->button7);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->Location = System::Drawing::Point(12, 167);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(601, 126);
			this->groupBox3->TabIndex = 65;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Withdraw";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->tbAmountDeposit);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(12, 303);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(601, 126);
			this->groupBox2->TabIndex = 64;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Deposit";
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
			this->button4->Location = System::Drawing::Point(403, 65);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(168, 53);
			this->button4->TabIndex = 18;
			this->button4->Text = L"Deposit";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &CustomerForm::button4_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button1);
			this->groupBox4->Controls->Add(this->phoneNumber);
			this->groupBox4->Controls->Add(this->accountNumber);
			this->groupBox4->Controls->Add(this->email);
			this->groupBox4->Controls->Add(this->address);
			this->groupBox4->Controls->Add(this->accountBalance);
			this->groupBox4->Controls->Add(this->name);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox4->Location = System::Drawing::Point(628, 10);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(682, 427);
			this->groupBox4->TabIndex = 68;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Account Informations";
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
			this->button1->Location = System::Drawing::Point(462, 341);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(180, 60);
			this->button1->TabIndex = 59;
			this->button1->Text = L"Log Out";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &CustomerForm::button1_Click);
			// 
			// phoneNumber
			// 
			this->phoneNumber->AutoSize = true;
			this->phoneNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phoneNumber->Location = System::Drawing::Point(354, 255);
			this->phoneNumber->Name = L"phoneNumber";
			this->phoneNumber->Size = System::Drawing::Size(149, 25);
			this->phoneNumber->TabIndex = 58;
			this->phoneNumber->Text = L"Phone Number:";
			// 
			// accountNumber
			// 
			this->accountNumber->AutoSize = true;
			this->accountNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->accountNumber->Location = System::Drawing::Point(354, 40);
			this->accountNumber->Name = L"accountNumber";
			this->accountNumber->Size = System::Drawing::Size(164, 25);
			this->accountNumber->TabIndex = 57;
			this->accountNumber->Text = L"Account Number:";
			// 
			// email
			// 
			this->email->AutoSize = true;
			this->email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->email->Location = System::Drawing::Point(30, 142);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(66, 25);
			this->email->TabIndex = 56;
			this->email->Text = L"Email:";
			// 
			// address
			// 
			this->address->AutoSize = true;
			this->address->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->address->Location = System::Drawing::Point(354, 142);
			this->address->Name = L"address";
			this->address->Size = System::Drawing::Size(91, 25);
			this->address->TabIndex = 55;
			this->address->Text = L"Address:";
			// 
			// accountBalance
			// 
			this->accountBalance->AutoSize = true;
			this->accountBalance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->accountBalance->Location = System::Drawing::Point(30, 255);
			this->accountBalance->Name = L"accountBalance";
			this->accountBalance->Size = System::Drawing::Size(166, 25);
			this->accountBalance->TabIndex = 54;
			this->accountBalance->Text = L"Account Balance:";
			// 
			// name
			// 
			this->name->AutoSize = true;
			this->name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name->Location = System::Drawing::Point(30, 40);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(70, 25);
			this->name->TabIndex = 53;
			this->name->Text = L"Name:";
			// 
			// CustomerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)), static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->ClientSize = System::Drawing::Size(1322, 635);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox4);
			this->Name = L"CustomerForm";
			this->Text = L"CustomerForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion



	public: void lastTransactions() {

		String^ connString = "Data Source=Youssef;Initial Catalog=BankingSystem;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
		SqlConnection sqlConn(connString);
		sqlConn.Open();

		// Populate users
		String^ sqlQuery_trans = "SELECT * FROM transactions WHERE id=@id";
		SqlCommand command(sqlQuery_trans, % sqlConn);
		command.Parameters->AddWithValue("@id", customer->GetId());

		SqlDataReader^ reader_trans = command.ExecuteReader();

		if (reader_trans->Read())
		{
			int num_id = reader_trans->GetInt32(0);

			customer->transactions->Push(gcnew Transaction(reader_trans->GetInt32(0), reader_trans->IsDBNull(4) ? 0.0f : Convert::ToSingle(reader_trans->GetValue(4)),
				reader_trans->GetString(1), reader_trans->GetInt32(2), reader_trans->GetInt32(3)));

		}

		reader_trans->Close();
		sqlConn.Close();

		//loadTransactions = false;
	



		  int count = 10; // Make sure to set this to a value or parse it from Customer input

		  List<Transaction^>^ lastTransactions = gcnew List<Transaction^>();

		  // Retrieve the last 'count' transactions
		  int remaining = count; // Ensure 'count' is assigned a value
		  for each (Transaction ^ transaction in customer->transactions) {
			  lastTransactions->Add(transaction);
			  remaining--;
			  if (remaining == 0) {
				  break;
			  }
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

public: void loadInfo() {
	accountNumber->Text = customer->GetId().ToString();

		name->Text = "Name: "+ customer->GetName();
		accountBalance->Text = "Account Balance"+customer->GetAccountBalance().ToString();
		address->Text = "Address: "+customer->GetAddress();
		phoneNumber->Text ="Phone Number"+ customer->GetPhoneNumber();
		email->Text = "Email: "+customer->GetEmail();
		//lastTransactions();


}
private: System::Void groupBox4_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();

	// Start a new instance of the application
	System::Diagnostics::Process::Start(Application::ExecutablePath);
}
	public:   BankingSystem::TallerForm form;
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int from;
	int to;
	float amount;
	Int32::TryParse(this->tbTo->Text, to);
	float::TryParse(this->tbAmountSend->Text, amount);
	form.accebter = gcnew Customer;

	// Withdraw from -> deposit to
	// withdraw
	if (form.customers->TryGetValue(to, form.accebter)) {
		if (customer->transfer(form.accebter, amount)) {
			MessageBox::Show("Your Account "  + " Balance Now is: " + customer->GetAccountBalance(), "Sending Successful");

		}
		else {
			MessageBox::Show("Not Valid Amount", "Send failed ");

		}

	}
	else {
		MessageBox::Show("Cann't Find This Account", "Account Not Found");
	}
	lastTransactions();

}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {

		float amount;
		float::TryParse(this->tbAmountWithdraw->Text, amount);


		if (customer->withdraw(amount)) {
			MessageBox::Show("Your Account Balance now is: " + customer->GetAccountBalance(), "Withdrawal Successful");

		}
		else {
			MessageBox::Show("The Amount is grater than Your account balance.\nYour Account Balance is:" + customer->GetAccountBalance(), "Withdrawal failed ");

		}
		lastTransactions();
	}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	float amount;
	float::TryParse(this->tbAmountDeposit->Text, amount);

	
		if (customer->deposit(amount)) {
			MessageBox::Show("Your Account Balance Now is: " + customer->GetAccountBalance(), "Deposit Successful");

		}
		else {
			MessageBox::Show("Not Valid Amount", "Withdrawal failed ");

		}
		lastTransactions();
}
};
}
