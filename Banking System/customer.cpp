#include "customer.h"

Transaction::Transaction(int id, float amount, String^ type, int sender, int receiver)
    : id(id), amount(amount), type(type), sender(sender), receiver(receiver) {}

Customer::Customer(int id, String^ name, String^ email, String^ password, int age, String^ phoneNumber, String^ address, float accountBalance)
    : id(id), name(name), email(email), password(password), phoneNumber(phoneNumber), address(address), accountBalance(accountBalance), age(age) {
    transactions = gcnew stack<Transaction^>();
}

Customer::Customer() {
    transactions = gcnew stack<Transaction^>();
}

int Customer::GetAge() {
    return age;
}

void Customer::SetAge(int value) {
    age = value;
}

int Customer::GetId() {
    return id;
}

void Customer::SetId(int value) {
    id = value;
}

float Customer::GetAccountBalance() {
    return accountBalance;
}

void Customer::SetAccountBalance(float value) {
    accountBalance = value;
}

String^ Customer::GetEmail() {
    return email;
}

void Customer::SetEmail(String^ value) {
    email = value;
}

String^ Customer::GetPhoneNumber() {
    return phoneNumber;
}

void Customer::SetPhoneNumber(String^ value) {
    phoneNumber = value;
}

String^ Customer::GetPassword() {
    return password;
}

void Customer::SetPassword(String^ value) {
    password = value;
}

String^ Customer::GetName() {
    return name;
}

void Customer::SetName(String^ value) {
    name = value;
}

String^ Customer::GetAddress() {
    return address;
}

void Customer::SetAddress(String^ value) {
    address = value;
}

bool Customer::withdraw(float amount) {
    if (amount > accountBalance || amount <= 0) {
        return false;
    }
    accountBalance -= amount;
    transactions->push(gcnew Transaction(id, amount, "withdraw", 0, 0));
    return true;
}

bool Customer::deposit(float amount) {
    if (amount <= 0) {
        return false;
    }
    accountBalance += amount;
    transactions->push(gcnew Transaction(id, amount, "deposit", 0, 0));
    return true;
}

bool Customer::transfer(Customer^ receiver, float amount) {
    if (amount <= 0 || amount > accountBalance) {
        return false;
    }

    accountBalance -= amount;
    receiver->accountBalance += amount;
    transactions->push(gcnew Transaction(id, amount, "send", id, receiver->id));
    receiver->transactions->push(gcnew Transaction(receiver->id, amount, "receive", id, receiver->id));

    return true;
}
