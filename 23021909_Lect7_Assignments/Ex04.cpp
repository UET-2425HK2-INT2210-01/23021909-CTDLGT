#include <iostream> 
#include <vector>   
using namespace std;

/*
 * Hàm sử dụng đệ quy để sinh tất cả các chuỗi nhị phân độ dài n
 * n: độ dài chuỗi nhị phân cần sinh
 * binary: vector chứa chuỗi nhị phân hiện tại đang xây dựng
 * index: vị trí hiện tại đang xét trong chuỗi
 */
void generateBinary(int n, vector<int>& binary, int index) {
    // Nếu đã đạt đến độ dài n thì in ra chuỗi hiện tại
    if (index == n) {
        for (int bit : binary) { // Duyệt qua từng bit trong chuỗi
            cout << bit;         // In ra bit (0 hoặc 1)
        }
        cout << endl; // Xuống dòng sau mỗi chuỗi
        return;       // Kết thúc nhánh đệ quy
    }

    // Gán bit 0 tại vị trí index rồi tiếp tục sinh tiếp
    binary[index] = 0;
    generateBinary(n, binary, index + 1); // Gọi đệ quy cho bước tiếp theo

    // Gán bit 1 tại vị trí index rồi tiếp tục sinh tiếp
    binary[index] = 1;
    generateBinary(n, binary, index + 1); // Gọi đệ quy cho bước tiếp theo
}

int main() {
    int n;              // Khai báo biến n là độ dài chuỗi nhị phân
    cin >> n;           // Nhập giá trị n từ bàn phím

    vector<int> binary(n); // Tạo vector kích thước n để lưu chuỗi nhị phân

    generateBinary(n, binary, 0); // Gọi hàm đệ quy để sinh chuỗi từ vị trí 0

    return 0; // Kết thúc chương trình
}
