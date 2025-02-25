#include <iostream>
#include <string>
using namespace std;
int main() {
    string sen;
    getline(cin, sen);
    int n = sen.length();
    for (int i = 0; i < n / 2; i++) {
        swap(sen[i],sen[n-i-1]);
    }
    cout <<sen << endl;
    
    return 0;
}
