#pragma once
#include<string>
using namespace System;
using namespace std;

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
};

