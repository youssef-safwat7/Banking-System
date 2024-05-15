#pragma once

//#include"TallerForm.h"

#include <Windows.h>
#include <string>
#include <vcclr.h>
#include"customer.h"
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
	Taller(String^ name, String^ email, String^ phoneNumber, String^ password);

	void AddCustomer(int id, String^ name, String^ email, String^ password, int age, String^ phoneNumber, String^ address, float accountBalance);
	bool withdraw(Customer^ customer, float amount);
	float GetCustomerAccountBalance(Customer^ customer);
	bool deposit(Customer^ customer, float amount);
	bool transfer(Customer^ sender, Customer^ receiver, float amount);
	void DeleteCustomer(int id);
};