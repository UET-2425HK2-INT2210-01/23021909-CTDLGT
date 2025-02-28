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
    void push(int x)
    {
        node* tmp=new node();
        tmp->data=x;
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

    void pop() {
        if (head==nullptr)
        {
            return;
        }
        else {
            node*point=head;
            node*pre=nullptr;
            while(point->next!=nullptr)
            {
                pre=point;
                point=point->next;
            }
            pre->next=nullptr;
            delete point;
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
        if (sentence=="push")
        {
            int x;
            cin>>x;
            list.push(x);
        }
        else if (sentence=="pop"){
            list.pop();
        }
    }
    list.Print();
}