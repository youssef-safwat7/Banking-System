#pragma once
#include <string>
#include "Stack.h"
#using <System.dll>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data::SqlClient;

public ref class Transaction {
public:
    int sender;
    int receiver;
    float amount;
    int id;
    String^ type;
    Transaction(int id, float amount, String^ type, int sender, int receiver);
};

public ref class Customer {
private:
    int age;
    int id;
    float accountBalance;
    String^ email;
    String^ phoneNumber;
    String^ password;
    String^ name;
    String^ address;

public:
    stack<Transaction^>^ transactions;

    Customer(int id, String^ name, String^ email, String^ password, int age, String^ phoneNumber, String^ address, float accountBalance);
    Customer();

    int GetAge();
    void SetAge(int value);

    int GetId();
    void SetId(int value);

    float GetAccountBalance();
    void SetAccountBalance(float value);

    String^ GetEmail();
    void SetEmail(String^ value);

    String^ GetPhoneNumber();
    void SetPhoneNumber(String^ value);

    String^ GetPassword();
    void SetPassword(String^ value);

    String^ GetName();
    void SetName(String^ value);

    String^ GetAddress();
    void SetAddress(String^ value);

    bool withdraw(float amount);

    bool deposit(float amount);

    bool transfer(Customer^ receiver, float amount);
};
