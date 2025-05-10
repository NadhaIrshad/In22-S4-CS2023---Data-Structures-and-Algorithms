#include <iostream>

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int stackTop() {
        if (isEmpty()) {
            std::cout << "Stack is empty\n";
            return -1; // Error value
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack s;
    std::string command;
    while (std::cin >> command) {
        if (command == "push") {
            int value;
            std::cin >> value;
            s.push(value);
        } else if (command == "pop") {
            s.pop();
        } else if (command == "display") {
            s.display();
        } else if (command == "isEmpty") {
            std::cout << (s.isEmpty() ? "True" : "False") << std::endl;
        } else if (command == "stackTop") {
            std::cout << s.stackTop() << std::endl;
        } else if (command == "exit") {
            break;
        }
    }
    return 0;
}
