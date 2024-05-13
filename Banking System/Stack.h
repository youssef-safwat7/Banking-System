#pragma once

#include <iostream>
#include <string>

using namespace std;


template<class T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Template class for Stack
template<class T>
class Stack {
private:
    Node<T>* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(T k) {
        Node<T>* newNode = new Node<T>(k);
        if (isEmpty()) {
            top = newNode;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
        cout << "Inserted element " << k << endl;
    }

    T pop() {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        T popped_element = top->data;
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        return popped_element;
    }

    T topElement() {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};
