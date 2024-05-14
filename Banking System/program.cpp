#include "MainForm.h"
#include "TallerForm.h"
#include "customer.h" 
#include "CustomerForm.h" 
#include"Admin.h"
#include"Taller.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]

int main(cli::array<System::String^>^ args) 
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    BankingSystem::MainForm form;

    form.ShowDialog();
    Customer^ customer = form.customer;
    Taller^ taller = form.taller;
    Admin^ admin = form.admin;

    if (taller != nullptr && form.role == "Taller") {
        BankingSystem::TallerForm tallerForm(taller); 
        tallerForm.ShowDialog();
     
    }
    else if (admin != nullptr && form.role == "Admin") {
        BankingSystem::AdminForm adminForm(admin); 
        adminForm.ShowDialog();
    }
    else if (customer != nullptr && form.role == "Customer") {
        BankingSystem::CustomerForm customerForm(customer); 
        customerForm.ShowDialog();
    }

    return 0; 
}

