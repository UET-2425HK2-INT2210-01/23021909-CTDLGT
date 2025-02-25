#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if(a==0)
    {
        return b;
    }
    else if (b==0)
    {
        return a;
    }
    else {
        int nmin=min(a,b);
        int nmax=max(a,b);
        while (nmin != 0)
        {
            int temp = nmin;
            nmin = nmax % nmin;
            nmax = temp;
        } 
    return nmax;
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    cout <<gcd(m, n) <<endl;
    
    return 0;
}
