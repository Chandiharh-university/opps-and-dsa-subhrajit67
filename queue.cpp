#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int* queue;
    int capacity;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        queue = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }
    ~Queue() {
        delete[] queue;
    }
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
        cout << "Enqueued: " << value << endl;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        int value = queue[front];
        front = (front + 1) % capacity;
        size--;
        cout << "Dequeued: " << value << endl;
        return value;
    }
    bool isEmpty() const {
        return size == 0;
    }
    bool isFull() const {
        return size == capacity;
    }
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << queue[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    Queue q(capacity);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.display();

    return 0;
}
