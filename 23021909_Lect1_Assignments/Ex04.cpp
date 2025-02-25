#include <iostream>
#include <vector>
using namespace std;
void selectionsort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    selectionsort(a);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
