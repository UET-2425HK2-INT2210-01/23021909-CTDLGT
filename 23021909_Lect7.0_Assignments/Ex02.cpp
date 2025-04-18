#include <iostream>          
using namespace std;         

// Hàm đệ quy tính giai thừa của một số nguyên n
int giai_thua(int n) {
    if (n == 1) {            // Điều kiện dừng: nếu n bằng 1 thì trả về 1 (vì 1! = 1)
        return 1;
    } else {
        return n * giai_thua(n - 1);  // Gọi đệ quy: n * (n-1)!
    }
}

int main() {
    int n = 5;               // Khai báo và khởi tạo biến n với giá trị 5
    cout << giai_thua(n) << endl;   // In ra kết quả giai_thua(5) = 5 * 4 * 3 * 2 * 1 = 120
    return 0;                // Kết thúc chương trình, trả về 0 cho hệ điều hành
}
