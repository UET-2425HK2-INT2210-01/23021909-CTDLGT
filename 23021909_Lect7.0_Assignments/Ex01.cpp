#include <iostream>       
using namespace std;     

// Hàm đệ quy tính tổng từ 1 đến n
int sum(int n) {
    if (n == 1) {         // Điều kiện dừng: nếu n bằng 1 thì trả về 1
        return 1;
    }
    else {
        return n + sum(n - 1);  // Gọi đệ quy: n + tổng từ 1 đến n-1
    }
}

int main() {
    int n = 5;            // Khởi tạo biến n với giá trị 5
    cout << sum(n) << endl;  // In ra kết quả của sum(5), tức là 1 + 2 + 3 + 4 + 5 = 15
    return 0;             // Kết thúc chương trình
}
