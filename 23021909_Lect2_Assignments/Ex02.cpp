#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    int size;

    LinkedList() { 
        head = nullptr;
        size = 0;
    }

    void insert(int p, int x) {
        if (p < 0 || p > size) {
            cout << "Can't insert: "<<p<<" "<<x << endl;
            return;
        }

        Node* tmp = new Node(x);
        if (p == 0) {
            tmp->next = head;
            head = tmp;
        } else {
            Node* point = head;
            for (int i = 0; i < p - 1 && point != nullptr; i++) { 
                point = point->next;
            }

            if (point == nullptr) { 
                cout << "Invalid position" << endl;
                delete tmp;
                return;
            }

            tmp->next = point->next;
            point->next = tmp;
        }
        size++;
    }

    void Delete(int p) {
        if (p < 0 || p >= size) { 
            cout << "Can't delete: " <<p << endl;
            return;
        }

        Node* tmp;
        if (p == 0) { 
            head = head->next;
        } else {
            Node* point = head;
            for (int i = 0; i < p - 1 && point != nullptr; i++) {
                point = point->next;
            }

            if (point == nullptr || point->next == nullptr) { 
                cout << "Invalid delete position" << endl;
                return;
            }

            tmp = point->next;
            point->next = tmp->next;
        }
        delete tmp;
        size--;
    }

    void Print() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* point = head;
        while (point != nullptr) {
            cout << point->data << " ";
            point = point->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string sentence;
        cin >> sentence;

        if (sentence == "insert") {
            int p, x;
            cin >> p >> x;
            list.insert(p, x);
        } else if (sentence == "delete") {
            int p;
            cin >> p;
            list.Delete(p);
        }
    }

    list.Print();
    return 0;
}
