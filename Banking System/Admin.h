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
    Admin(String^ name, String^ email, String^ password);

    void AddTaller(String^ name, String^ email, String^ password, String^ phoneNumber);

    void DeleteTaller(String^ email);
};
