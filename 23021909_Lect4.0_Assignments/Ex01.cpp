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

    void append(int x) {
        Node* tmp = new Node(x);
        if (head == NULL) {
            head = tmp;
        } else {
            Node* point = head;
            while(point->next!=nullptr)
            {
                point=point->next;
            }
            point->next = tmp;
        }
        size++;
    }

    void search(int x) {
        Node*point=head;
        int dem=0;
        while(point->next!=nullptr)
        {
            if(point->data==x)
            {
                break;
            }
            else {
            point=point->next;
            dem++;
            }
        }
        if (dem==0)
        {
            cout<<"NO"<<endl;
        }
        else cout<<dem<<endl;
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
    void Reverse()
    {
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode=nullptr;
        while (current) {
            nextNode = current->next; 
            current->next = prev;  
            prev = current;        
            current = nextNode;
        }
        head=prev;
    }
};

int main() {
    LinkedList list;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string sentence;
        cin >> sentence;

        if (sentence == "append") {
            int x;
            cin >> x;
            list.append(x);
        } else if (sentence == "search") {
            int p;
            cin >> p;
            list.search(p);
        }
        else if (sentence == "reverse") {
            list.Reverse();
            list.Print();
        }
    }
    return 0;
}