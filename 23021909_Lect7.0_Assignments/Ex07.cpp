#include <iostream>
using namespace std;

int reverse_number(int n, int revnum = 0) {
    if (n == 0) {
        return revnum;                      // Khi n hết chữ số, trả kết quả
    } else {
        int last_digit = n % 10;           // Lấy chữ số cuối
        revnum = revnum * 10 + last_digit; // Thêm vào kết quả tạm thời
        return reverse_number(n / 10, revnum); // Gọi đệ quy với phần còn lại
    }
}

int main() {
    int n = 1234;
    cout << reverse_number(n) << endl;
    return 0;
}
