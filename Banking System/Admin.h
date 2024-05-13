#pragma once
#include<string>
using namespace System;
using namespace std;

public ref class Admin
{
private:
	String^ name;
	String^ email;
	String^ password;
public:
	Admin(String^ name, String^ email, String^ password):name(name),email(email),password(password){
	}
};

