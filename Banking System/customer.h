#pragma once
#include <string>
#include <stack>
#using <System.dll>

#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>
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
     Transaction(int id, float amount, String^ type, int sender , int receiver ) :id(id), amount(amount), type(type), sender(sender), receiver(receiver) {

     }
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
    Stack<Transaction^>^ transactions;

    Customer(int id ,String^ name, String^ email, String^ password,int age, String^ phoneNumber, String^ address,float accountBalance) :id(id), name(name),email(email),
        password(password),phoneNumber(phoneNumber),address(address),accountBalance(accountBalance) , age(age){
        transactions = gcnew Stack<Transaction^>();
    }
    Customer() {
        transactions = gcnew Stack<Transaction^>();

    }
  
   
    int GetAge() {
        return age;
    }

    void SetAge(int value) {
        age = value;
    }

    int GetId() {
        return id;
    }

    void SetId(int value) {
        id = value;
    }

    float GetAccountBalance() {
        return accountBalance;
    }

    void SetAccountBalance(float value) {
        accountBalance = value;
    }

    String^ GetEmail() {
        return email;
    }

    void SetEmail(String^ value) {
        email = value;
    }

    String^ GetPhoneNumber() {
        return phoneNumber;
    }

    void SetPhoneNumber(String^ value) {
        phoneNumber = value;
    }

    String^ GetPassword() {
        return password;
    }

    void SetPassword(String^ value) {
        password = value;
    }

    String^ GetName() {
        return name;
    }

    void SetName(String^ value) {
        name = value;
    }

    String^ GetAddress() {
        return address;
    }

    void SetAddress(String^ value) {
        address = value;
    }
    bool withdraw(float amount) {
        if (amount > accountBalance || amount <= 0) {
            return false;
        }
        accountBalance -= amount;
        transactions->Push(gcnew Transaction(id, amount, "withdraw", 0, 0));
        return true; 
    }

    bool deposit(float amount) {
        if (amount <= 0) {
            return false;
        }
        accountBalance += amount;
        transactions->Push(gcnew Transaction(id, amount, "deposit", 0, 0));

        return true; 
    }

    bool transfer(Customer^ receiver, float amount) {
        if (amount <= 0 || amount > accountBalance) {
            return false;
        }

        accountBalance -= amount;
        receiver->accountBalance += amount;
        transactions->Push(gcnew Transaction(id, amount, "send", id, receiver->id));
        receiver->transactions->Push(gcnew Transaction(receiver->id, amount, "receive", id, receiver->id));


        return true; 
    }
  

};
