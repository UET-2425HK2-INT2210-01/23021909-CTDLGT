#include <iostream>             
using namespace std;           

// Hàm đệ quy tính x^n (x mũ n)
int luy_thua(int x, int n) {
    if (n == 0) {               // Trường hợp cơ bản: mọi số mũ 0 đều bằng 1 (x^0 = 1)
        return 1;
    } else {
        return x * luy_thua(x, n - 1); // Đệ quy: x^n = x * x^(n-1)
    }
}

int main() {
    int x = 2;                  // Cơ số x = 2
    int n = 3;                  // Số mũ n = 3
    cout << luy_thua(x, n) << endl;  // In ra kết quả 2^3 = 8
    return 0;                   // Kết thúc chương trình
}
