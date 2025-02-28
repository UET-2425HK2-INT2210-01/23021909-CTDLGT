#include <iostream>
#include <vector>
using namespace std;
struct node{
    int data;
    node* next;
};
class Linkedlist{
    public:
    node*head;
    int size;
    Linkedlist() { 
        head = nullptr;
        size = 0;
    }
    void Enqueue(int x)
    {
        node* tmp=new node();
        tmp->data=x;
        tmp->next=nullptr;
        if (head==nullptr)
        {
            head=tmp;
        }
        else {
            node*point=head;
            while(point->next!=nullptr)
            {
                point=point->next;
            }
            point->next=tmp;
        }
        size++;
    }

    void Dequeue() {
        if (head==nullptr)
        {
            return;
        }
        else {
            node*tmp=head;
            head=tmp->next;
            delete tmp;
            size--;
        }
    }
    void Print()
        {
            node* point = head;
            while (point != nullptr) {
                cout << point->data << " ";
                point = point->next;
            }
            cout << endl;
        }
};
int main()
{
    Linkedlist list;
    int n;
    cin>>n;
    for (int i =0 ; i<n ;i++)
    {
        string sentence;
        cin>>sentence;
        if (sentence=="enqueue")
        {
            int x;
            cin>>x;
            list.Enqueue(x);
        }
        else if (sentence=="dequeue"){
            list.Dequeue();
        }
    }
    list.Print();
}