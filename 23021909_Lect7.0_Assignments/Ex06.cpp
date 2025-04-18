#include <iostream>             
using namespace std;            

// Hàm đệ quy tính tổng các chữ số của số nguyên dương n
int sum(int n) {
    if (n < 10) {               // Điều kiện dừng: nếu n chỉ còn 1 chữ số
        return n;               // Trả về chính chữ số đó
    } else {
        int num = n % 10;       // Lấy chữ số cuối cùng của n
        n = (n - num) / 10;     // Loại bỏ chữ số cuối khỏi n (tương đương n /= 10)
        return num + sum(n);    // Cộng chữ số cuối vào tổng của phần còn lại
    }
}

int main() {
    int n = 1234;               // Số nguyên cần tính tổng các chữ số
    cout << sum(n) << endl;     // In ra kết quả: 1 + 2 + 3 + 4 = 10
    return 0;                   // Kết thúc chương trình
}
