#pragma once

#include <iostream>
#include <string>

using namespace System;

generic<typename T>
public ref class Node {
public:
    T data;
    Node^ next;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Template class for Stack
generic<typename T>
public ref class stack {
private:
    Node<T>^ top;
    int size;
public:
    stack() {
        top = nullptr;
        size = 0;
    }


    void push(T k) {
        Node<T>^ newNode = gcnew Node<T>(k);
        if (isEmpty()) {
            top = newNode;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
        size++;

    }

    T pop() {
        if (isEmpty()) {
            throw gcnew InvalidOperationException("Stack is empty");
        }
        T popped_element = top->data;
        Node<T>^ temp = top;
        top = top->next;
        delete temp;
        size--;
        return popped_element;
    }

    T topElement() {
        if (isEmpty()) {
            throw gcnew InvalidOperationException("Stack is empty");
        }
        return top->data;
    }
    Node<T>^ topNode() {
        if (isEmpty()) {
            throw gcnew InvalidOperationException("Stack is empty");
        }
        return top;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int GetSize() {
        return size;
    }
    stack<T>^ CopyStack() {
        stack<T>^ copiedStack = gcnew stack<T>();

        // Create a temporary stack to hold the copied elements
        stack<T>^ tempStack = gcnew stack<T>();

        // Iterate through the original stack and push each element onto the copied stack
        while (!this->isEmpty()) {
            T item = this->pop();
            tempStack->push(item);
            copiedStack->push(item);
        }

        // Restore the original stack
        while (!tempStack->isEmpty()) {
            this->push(tempStack->pop());
        }

        return copiedStack;
    }


};
