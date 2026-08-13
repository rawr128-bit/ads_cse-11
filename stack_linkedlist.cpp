#include <bits/stdc++.h>
using namespace std;
class node {
public:
    int data;
    node* next;

    node(int i) {
        data = i;
        next = NULL;
    }
};

void push(node*& top, int item) {
    node* temp = new node(item);

    temp->next = top;
    top = temp;

    cout << item << " pushed into stack\n";
}

int pop(node*& top) {
    if (top == NULL) {
        cout << "Underflow\n";
        return -1;
    }

    node* temp = top;
    int item = temp->data;

    top = top->next;
    delete temp;

    return item;
}

int peek(node* top) {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return -1;
    }

    return top->data;
}

void traverse(node* top) {
    cout << "Stack: ";

    node* temp = top;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
int main() {
    node* top = NULL;

    push(top, 10);
    push(top, 20);

    traverse(top);

    push(top, 30);
    push(top, 40);

    cout << "Peek is: " << peek(top) << "\n";

    traverse(top);

    cout << "Popped: " << pop(top) << "\n";
    traverse(top);

    return 0;
}
