// 4nlogn         o(nlogn)
// 2^10           o(1)
// 2^(logn)       o(n)
// 3n+100logn     o(n)
// 4n             o(n)
// 2^n            o(2^n)
// n^2+10n        o(n^2)
// n^3            o(n^3)
// nlogn          o(nlogn)
// Sắp xếp tăng dần : o(1),o(n),o(nlogn),o(n^2),o(n^3),o(2^n)
// 2^10
// 2^logn ; 3n+100logn ; 4n
// nlogn ; 4nlogn 
// n^2+10n
// n^3
// 2^n
#include<iostream>
using namespace std;
int main()
{
    cout<<"2^10"<<endl;
    cout<<"2^logn ; 3n+100logn ; 4n"<<endl;
    cout<<"nlogn ; 4nlogn"<<endl;
    cout<<"n^2+10n"<<endl;
    cout<<"n^3"<<endl;
    cout<<"2^n"<<endl;
    return 0;
}