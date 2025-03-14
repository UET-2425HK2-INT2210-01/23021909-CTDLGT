#include <iostream>
using namespace std;

struct Node {
    int value;
    int priority;
    Node* next;
    Node* prev;

    Node(int v, int p) : value(v), priority(p), next(nullptr), prev(nullptr) {}
};

class PriorityQueue {
public:
    Node* head;
    int size;
    PriorityQueue(){
        head=nullptr;
        size=0;
    }
    bool isEmpty()
    {
        return head == nullptr;
    }
    void enqueue(int value, int priority) {
        Node* newNode = new Node(value, priority);

        if (isEmpty() || priority > head->priority) {
            newNode->next = head;
            if (!isEmpty())
            head->prev = newNode;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->priority >= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        Node* temp = head;
        head = temp->next;
        if (!isEmpty())
        {
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }
    void printQueue() {
        Node* temp = head;
        while (temp) {
            cout << "(" << temp->value << ", " << temp->priority << "); ";
            temp = temp->next;
        }
    }
};

int main() {
    int n;
    cin >> n;

    PriorityQueue pq;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "enqueue") {
            int x, p;
            cin >> x >> p;
            pq.enqueue(x, p);
        } else if (command == "dequeue") {
            pq.dequeue();
        }
    }
    pq.printQueue(); 
    return 0;
}
