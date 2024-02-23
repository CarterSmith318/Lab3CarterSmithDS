#include <iostream>

using namespace std;

// Node structure for the linked list
template<typename T>
struct Node {
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

// Stack class
template<typename T>
class Stack {
private:
    Node<T>* top;  // Pointer pointing to the top of the stack

public:
    // Constructor
    Stack() : top(nullptr) {}

    // Destructor to free memory
    ~Stack() {
        while (!IsEmpty()) {
            Pop();
        }
    }

    // Method to check if the stack is empty
    bool IsEmpty() {
        return top == nullptr;
    }

    // Method to check if the stack is full (for a linked structure, it's always false)
    bool IsFull() {
        return false;
    }

    // Method to add a new item on the stack
    void Push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }

    // Method to remove the top item from the stack
    void Pop() {
        if (!IsEmpty()) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
        else {
            cerr << "Stack is empty. Cannot pop." << endl;
        }
    }

    // Method to return a copy of the top item from the stack
    T Top() {
        if (!IsEmpty()) {
            return top->data;
        }
        else {
            cerr << "Stack is empty. No top item." << endl;
            // Returning a default value in case the stack is empty
            return T();
        }
    }
};

// Test test test ....
int main() {
    Stack<int> myStack;

    cout << "Is stack empty? " << (myStack.IsEmpty() ? "Yes" : "No") << endl;

    myStack.Push(10);
    myStack.Push(20);
    myStack.Push(30);

    cout << "Top item on the stack: " << myStack.Top() << endl;

    myStack.Pop();

    cout << "Top item on the stack after pop: " << myStack.Top() << endl;

    return 0;
}
