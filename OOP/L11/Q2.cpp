#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class StackOverflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackOverflowException - The stack has reached its maximum capacity!";
    }
};

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException - There are no elements to pop!";
    }
};

const int MAX_CAPACITY = 5;

template <typename T>
class Stack {
private:
    T elements[MAX_CAPACITY];
    int currentIndex;

public:
    Stack() : currentIndex(0) {}

    bool isEmpty() const {
        return currentIndex == 0;
    }

    bool isFull() const {
        return currentIndex == MAX_CAPACITY;
    }

    void push(const T& value) {
        if (isFull()) {
            throw StackOverflowException();
        }
        elements[currentIndex++] = value;
    }

    void pop() {
        if (isEmpty()) {
            throw StackUnderflowException();
        }
        currentIndex--;
    }

    T& top() {
        if (isEmpty()) {
            throw StackUnderflowException();
        }
        return elements[currentIndex - 1];
    }

    const T& top() const {
        if (isEmpty()) {
            throw StackUnderflowException();
        }
        return elements[currentIndex - 1];
    }
};

int main() {
    Stack<int> intStack;

    try {
        cout << "Adding 5 items to the stack..." << endl;
        intStack.push(1);
        intStack.push(2);
        intStack.push(3);
        intStack.push(4);
        intStack.push(5);
        cout << "Stack is at full capacity. Trying to add one more item..." << endl;
        intStack.push(6);
    } catch (const StackOverflowException& e) {
        cout << "Error while adding to a full stack: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Unexpected error while adding item: " << e.what() << endl;
    }

    cout << endl;

    try {
        cout << "Removing all 5 items from the stack..." << endl;
        intStack.pop();
        intStack.pop();
        intStack.pop();
        intStack.pop();
        intStack.pop();
        cout << "Stack is now empty. Trying to remove one more item..." << endl;
        intStack.pop();
    } catch (const StackUnderflowException& e) {
        cout << "Error while removing from an empty stack: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Unexpected error while removing item: " << e.what() << endl;
    }

    return 0;
}
