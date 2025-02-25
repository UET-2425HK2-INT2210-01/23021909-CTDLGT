#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

float nmin(vector<float>& a) {
    float min = a[0];
    for (float i = 1; i < a.size(); i++) { 
        if (a[i] < min) { 
            min = a[i];
        }
    }
    return min;
}

float nmax(vector<float>& a) {
    float max = a[0]; 
    for (int i = 1; i < a.size(); i++) { 
        if (a[i] > max) { 
            max = a[i];
        }
    }
    return max;
}

int main() {
    vector<float> a(5);
    for (int i = 0; i < 5; i++) {
        cin >> a[i]; 
    }
    
    float sum = nmin(a) + nmax(a); 
    if (sum == (int)sum) {
        cout << (int)sum << endl;
    } else {
        cout << fixed << setprecision(2) << sum << endl; 
    }
    return 0;
}
