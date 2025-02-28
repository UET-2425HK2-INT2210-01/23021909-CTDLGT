#include<iostream>
#include<vector>
using namespace std;
int count(vector<int>&a,int n)
{
    int dem=0;
    for(int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (a[i]==a[j])
            {
                dem++;
            }
        }
    }
    return dem;
}

int main()
{
    int n ;
    cin>>n;
    vector<int>a(n);
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<count(a,n)<<endl;
}