#pragma once
//#include"TallerForm.h"

#include <Windows.h>
#include <string>
#include <vcclr.h>

using namespace System;
using namespace System::Data::SqlClient;
using namespace System::Windows::Forms;
public ref class Taller
{
private:
	String^ name;
	String^ email;
	String^ phoneNumber;
	String^ password;
public:
	Taller(String^ name, String^ email, String^ phoneNumber, String^ password) :name(name), email(email), phoneNumber(phoneNumber), password(password) {

	}
	void AddCustomer(int id, String^ name, String^ email, String^ password, int age, String^ phoneNumber, String^ address, float accountBalance) {
		Customer^ customer = gcnew Customer(0, name, email, password, age, phoneNumber, address, accountBalance);

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
					MessageBox::Show("Account Created Successfully.\n The Account Number is: " + customer->GetId(), "New Account Added", MessageBoxButtons::OK);
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

	}
    bool withdraw(Customer^ customer, float amount) {
		if (customer->withdraw(amount)) {
			return true;
		}
		else {

			return false;

		}
    }
	float GetCustomerAccountBalance(Customer^ customer) {
		return customer->GetAccountBalance();
	}
    bool deposit(Customer^ customer, float amount) {
 
		 
			if (customer->deposit(amount)) {
				return true;
			}
			else {
				
				return false;

			}
		
    }

    bool transfer(Customer^ sender, Customer^ receiver, float amount) {
		
			if (sender->transfer(receiver, amount)) {
				return true;
			}
			else {
				MessageBox::Show("Not Valid Amount", "Transfer failed ");
				return false;
			}

		
	
    
    }
    void DeleteCustomer(int id) {
		try
		{
			String^ connString = "Data Source=Youssef;Initial Catalog=BankingSystem;Integrated Security=True;Encrypt=True;TrustServerCertificate=True;Connection Timeout=60";

			SqlConnection sqlConn(connString);
			sqlConn.Open();


			String^ sqlQuery = "DELETE FROM customers WHERE id = @id;";
			SqlCommand command(sqlQuery, % sqlConn);

			command.Parameters->AddWithValue("@id", id);
			int rowsAffected = command.ExecuteNonQuery();

			if (rowsAffected > 0)
			{
				MessageBox::Show(" Customer deleted successfully ");

			}
			else
			{
				MessageBox::Show("Customer with ID " + id + " does not exist.");
			}
			sqlQuery = "DELETE FROM transactions WHERE id = @id;";
			SqlCommand transCommand(sqlQuery, % sqlConn);

			transCommand.Parameters->AddWithValue("@id", id);
			int rowsAffected_trans = transCommand.ExecuteNonQuery();
			while (rowsAffected_trans > 0)
			{

				rowsAffected_trans = command.ExecuteNonQuery();
			}
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
};

