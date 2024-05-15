#include"Admin.h"

Admin::Admin(String^ name, String^ email, String^ password)
    : name(name), email(email), password(password) {}

void Admin::AddTaller(String^ name, String^ email, String^ password, String^ phoneNumber)
{
    try
    {
        String^ connString = "Data Source=Youssef;Initial Catalog=BankingSystem;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
        SqlConnection^ sqlConn = gcnew SqlConnection(connString);
        SqlCommand^ cmd = gcnew SqlCommand("INSERT INTO tallers (name, email, password, phoneNumber) VALUES (@name, @email, @password, @phoneNumber)",
            sqlConn);
        if (name->Length == 0 || email->Length == 0 || password->Length == 0 || phoneNumber->Length == 0) {
            MessageBox::Show("Please Fill All Required Filled.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }
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

void Admin::DeleteTaller(String^ email)
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