#include <iostream>            
using namespace std;           

// Hàm đệ quy tính số Fibonacci tại vị trí n
int fibonaci(int n) {
    if (n == 0) {              // Trường hợp cơ bản 1: F(0) = 0
        return 0;
    }
    else if (n == 1) {         // Trường hợp cơ bản 2: F(1) = 1
        return 1;
    }
    else {
        // Trường hợp tổng quát: F(n) = F(n-1) + F(n-2)
        return fibonaci(n - 1) + fibonaci(n - 2);
    }
}

int main() {
    int n = 6;                         // Gán giá trị n là 6
    cout << fibonaci(n) << endl;      // In ra số Fibonacci tại vị trí thứ 6 (F(6) = 8)
    return 0;                         // Kết thúc chương trình
}
