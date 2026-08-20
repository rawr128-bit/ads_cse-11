#include <iostream>
#define SIZE 10

using namespace std;

class queue {
    int data[SIZE];
    int front, rear;

public:

    queue() {
        front = rear = -1;
    }

    bool isempty() {
        return front == -1;
    }

    bool isfull() {
        return rear == SIZE - 1;
    }

    void enqueue(int value) {

        if (isfull()) {
            cout << "Queue is full" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        data[rear] = value;

        cout << "Element inserted" << endl;
    }

    void dequeue() {

        if (isempty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Removed element: " << data[front] << endl;

        // If only one element was present
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }
    }

    void traverse() {

        if (isempty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements: ";

        for (int i = front; i <= rear; i++) {
            cout << data[i] << " ";
        }

        cout << endl;
    }

    void display() {
        cout << "Front: " << front;
        cout << " , Rear: " << rear << endl;
    }
};


int main() {

    queue q;

    int choice, value;

    do {

        cout << "\n----- MENU -----" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Traverse" << endl;
        cout << "4. Check Empty" << endl;
        cout << "5. Check Full" << endl;
        cout << "6. Display Front and Rear" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:

            cout << "Enter value: ";
            cin >> value;

            q.enqueue(value);
            q.display();

            break;


        case 2:

            q.dequeue();
            q.display();

            break;


        case 3:

            q.traverse();

            break;


        case 4:

            if (q.isempty()) {
                cout << "Queue is empty" << endl;
            }
            else {
                cout << "Queue is not empty" << endl;
            }

            break;


        case 5:

            if (q.isfull()) {
                cout << "Queue is full" << endl;
            }
            else {
                cout << "Queue is not full" << endl;
            }

            break;


        case 6:

            q.display();

            break;


        case 7:

            cout << "Exiting program..." << endl;

            break;


        default:

            cout << "Invalid choice" << endl;
        }

    } while (choice != 7);

    return 0;
}
