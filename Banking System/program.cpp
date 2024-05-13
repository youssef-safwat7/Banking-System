#include "MainForm.h"
#include "TallerForm.h"
//#include "registrationForm.h"
#include "customer.h" 
#include "CustomerForm.h" // Include the customer header file to access the customer class
#include"Admin.h"
#include"Taller.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]

int main(cli::array<System::String^>^ args) // Change 'void' to 'int' for the main function
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    BankingSystem::MainForm form;

    form.ShowDialog();
    Customer^ customer = form.customer;
    Taller^ taller = form.taller;
    Admin^ admin = form.admin;

    if (taller != nullptr && form.role == "Taller") {
        BankingSystem::TallerForm tallerForm; 
        tallerForm.ShowDialog();
      /*  BankingSystem::registrationForm regForm; 
        regForm.ShowDialog();*/
    }
    else if (admin != nullptr && form.role == "Admin") {
        BankingSystem::AdminForm adminForm; // Change 'AdminForm' to 'adminForm'
        adminForm.ShowDialog();
    }
    else if (customer != nullptr && form.role == "Customer") {
        BankingSystem::CustomerForm customerForm(customer); // Change 'AdminForm' to 'adminForm'
        customerForm.ShowDialog();
    }

    return 0; // Add a return statement to indicate successful execution
}

