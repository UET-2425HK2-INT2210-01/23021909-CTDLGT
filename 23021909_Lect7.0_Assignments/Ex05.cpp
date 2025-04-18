#include <iostream>             
using namespace std;            

// Hàm đệ quy đếm số chữ số của số nguyên dương n
int count(int n) {
    if (n < 10) {               // Nếu n nhỏ hơn 10, chỉ còn 1 chữ số
        return 1;               // Trả về 1 (chữ số cuối cùng)
    } else {
        n = (n - n % 10) / 10;  // Loại bỏ chữ số cuối bằng cách chia 10
        return 1 + count(n);    // Cộng thêm 1 và tiếp tục đếm phần còn lại
    }
}

int main() {
    int n = 12345;              // Gán giá trị n
    cout << count(n) << endl;   // In ra số chữ số của n (kết quả: 5)
    return 0;                   // Kết thúc chương trình
}
