#include <iostream>  
using namespace std; 
// Hàm tính Ước Chung Lớn Nhất (UCLN) của 2 số nguyên X và Y dùng thuật toán Euclid
int UCLN(int X ,int Y)
{
    if (Y == 0)  // Nếu Y bằng 0, thì UCLN là X
    {
        return X;
    }
    else {
        return UCLN(Y, X % Y); // Gọi đệ quy: UCLN(X, Y) = UCLN(Y, X % Y)
    }
}

int main(){
    int X, Y;
    cin >> X;  // Nhập số nguyên X từ người dùng
    cin >> Y;  // Nhập số nguyên Y từ người dùng50
    cout << UCLN(X, Y) << endl;  // In ra kết quả UCLN của X và Y
    return 0;  // Kết thúc chương trình
}
