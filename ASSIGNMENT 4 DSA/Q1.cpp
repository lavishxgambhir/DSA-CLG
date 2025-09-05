#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    int isEmpty() {
        if (front == -1) return 1;
        else return 0;
    }

    int isFull() {
        if ((rear + 1) % SIZE == front) return 1;
        else return 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "(Queue is FULL) Cannot enqueue " << value << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        cout << "(" << value << " enqueued to queue)" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "(Queue is EMPTY) Cannot dequeue" << endl;
            return;
        }
        cout << "(" << arr[front] << " dequeued from queue)" << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "(Queue is EMPTY) No front element" << endl;
        } else {
            cout << "(Front element: " << arr[front] << ")" << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "(Queue is EMPTY)" << endl;
            return;
        }
        cout << "(Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << ")" << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            if (q.isEmpty()) cout << "(Queue is EMPTY)" << endl;
            else cout << "(Queue is NOT empty)" << endl;
            break;
        case 6:
            if (q.isFull()) cout << "(Queue is FULL)" << endl;
            else cout << "(Queue is NOT full)" << endl;
            break;
        case 0:
            cout << "(Exiting program)" << endl;
            break;
        default:
            cout << "(Invalid choice Try again)" << endl;
        }
    } while (choice != 0);

    return 0;
}

