#pragma once

#include <Windows.h>
#include <string>
#include <vcclr.h>

using namespace System;
using namespace System::Data::SqlClient;
using namespace System::Windows::Forms;

public ref class Admin
{
private:
    String^ name;
    String^ email;
    String^ password;

public:
    Admin(String^ name, String^ email, String^ password)
        : name(name), email(email), password(password) {}

    void AddTaller(String^ name, String^ email, String^ password, String^ phoneNumber)
    {
        try
        {
            String^ connString = "Data Source=Youssef;Initial Catalog=BankingSystem;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
            SqlConnection^ sqlConn = gcnew SqlConnection(connString);
            SqlCommand^ cmd = gcnew SqlCommand("INSERT INTO tallers (name, email, password, phoneNumber) VALUES (@name, @email, @password, @phoneNumber)",
                sqlConn);

            cmd->Parameters->AddWithValue("@name", name);
            cmd->Parameters->AddWithValue("@email", email);
            cmd->Parameters->AddWithValue("@password", password);
            cmd->Parameters->AddWithValue("@phoneNumber", phoneNumber);

            sqlConn->Open();
            int rowsAffected = cmd->ExecuteNonQuery();

            if (rowsAffected > 0)
            {
                MessageBox::Show("Account Created Successfully.", "New Account Added", MessageBoxButtons::OK);
            }
            else
            {
                MessageBox::Show("Failed to add new account.");
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

    void DeleteTaller(String^ email)
    {
        try
        {
            String^ connString = "Data Source=Youssef;Initial Catalog=BankingSystem;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
            SqlConnection^ sqlConn = gcnew SqlConnection(connString);
            SqlCommand^ cmd = gcnew SqlCommand("DELETE FROM tallers WHERE email = @email",
                sqlConn);

            cmd->Parameters->AddWithValue("@email", email);

            sqlConn->Open();
            int rowsAffected = cmd->ExecuteNonQuery();

            if (rowsAffected > 0)
            {
                MessageBox::Show("Taller deleted successfully");
            }
            else
            {
                MessageBox::Show("Taller with Email " + email + " does not exist.");
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
