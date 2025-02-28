#include<iostream>
#include<vector>
using namespace std;

struct node{
	int data;
	node *next;
	node *pre;
};
struct douList{
    public:
	node *head;
	node *tail;
    int size;
    douList() { 
        head = nullptr;
        tail=nullptr;
        size = 0;
    }
    void Import(int x)
    {
        node* tmp=new node();
        tmp->data=x;
        tmp->next=nullptr;
        if (head==nullptr&&tail==nullptr)
        {
            head=tail=tmp;
        }
        else
        {
            tail->next=tmp;
            tmp->pre=tail;
            tail=tmp;
        }
        size++;
    }
    int count_triplets()
    {
        if(size<3)
        {
            return -1;
        }else {
            int dem=0;
        node*point=head;
        while (point!=nullptr)
        {
            if(point->pre!=nullptr&&point->next!=nullptr)
            {
                int sum=point->pre->data+point->data+point->next->data;
                if(sum==0)
                {
                    dem++;
                }
            }
            point=point->next;
        }
        return dem;
        }
    }
};
int main()
{
    douList list;
    int n ;
    cin>>n;
    for(int i =0;i<n;i++)
    {
        int x;
        cin>>x;
        list.Import(x);
    }
    cout<<list.count_triplets()<<endl;
}