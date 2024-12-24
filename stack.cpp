#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int* stack;
    int capacity;

public:
    Stack(int capacity) {
        this->capacity = capacity;
        stack = new int[capacity];
        top = -1;
    }
    ~Stack() {
        delete[] stack;
    }
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push " << value << endl;
            return;
        }
        stack[++top] = value;
        cout << "Pushed: " << value << endl;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1;
        }
        int value = stack[top--];
        cout << "Popped: " << value << endl;
        return value;
    }
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1;
        }
        return stack[top];
    }
    bool isEmpty() const {
        return top == -1;
    }
    bool isFull() const {
        return top == capacity - 1;
    }
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the stack: ";
    cin >> capacity;

    Stack s(capacity);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    s.pop();
    s.display();

    s.push(40);
    s.push(50);
    s.display();

    cout << "Top element: " << s.peek() << endl;

    return 0;
}
