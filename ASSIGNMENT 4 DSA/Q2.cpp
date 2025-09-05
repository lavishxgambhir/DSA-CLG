#include <iostream>
using namespace std;


class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
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
            cout << "(Queue is FULL)" << endl;
            return;
        }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        cout << "(" << value << " enqueued)" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "(Queue is EMPTY)" << endl;
            return;
        }
        cout << "(" << arr[front] << " dequeued)" << endl;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % SIZE;
    }

    void peek() {
        if (isEmpty()) cout << "(Queue is EMPTY)" << endl;
        else cout << "(Front: " << arr[front] << ")" << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "(Queue is EMPTY)" << endl;
            return;
        }
        cout << "(Queue: ";
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
    CircularQueue q;
    int choice, val;
    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Check Empty 6.Check Full 0.Exit\nEnter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
            case 5: cout << (q.isEmpty() ? "(Queue is EMPTY)" : "(Queue is NOT empty)") << endl; break;
            case 6: cout << (q.isFull() ? "(Queue is FULL)" : "(Queue is NOT full)") << endl; break;
            case 0: cout << "(Exit)" << endl; break;
            default: cout << "(Invalid)" << endl;
        }
    } while(choice != 0);
}


