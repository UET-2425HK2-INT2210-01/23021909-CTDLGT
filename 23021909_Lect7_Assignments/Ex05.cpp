#include <iostream>   
#include <vector>     
using namespace std;

// Hàm sinh tất cả các hoán vị của dãy từ 1 đến n sử dụng Backtracking
void generatePermutations(vector<int>& permutation, vector<bool>& used, int n) {
    // Nếu độ dài hoán vị hiện tại bằng n thì in ra
    if (permutation.size() == n) {
        for (int num : permutation) {
            cout << num << " ";  // In từng phần tử trong hoán vị
        }
        cout << endl;  // Xuống dòng sau mỗi hoán vị
        return;        // Kết thúc nhánh đệ quy hiện tại
    }

    // Duyệt qua các số từ 1 đến n để tạo hoán vị
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {              // Nếu số i chưa được sử dụng
            used[i] = true;          // Đánh dấu là đã sử dụng
            permutation.push_back(i); // Thêm i vào hoán vị hiện tại

            // Đệ quy để tiếp tục xây dựng hoán vị
            generatePermutations(permutation, used, n);

            // Backtrack (quay lui)
            permutation.pop_back();  // Xóa phần tử cuối cùng
            used[i] = false;         // Đánh dấu lại là chưa sử dụng
        }
    }
}

int main() {
    int n;
    cin >> n;  // Nhập vào độ dài hoán vị cần tạo

    vector<int> permutation;             // Vector để lưu hoán vị hiện tại
    vector<bool> used(n + 1, false);     // Mảng đánh dấu các số đã được sử dụng (chỉ số từ 1 đến n)

    generatePermutations(permutation, used, n); // Gọi hàm sinh hoán vị

    return 0;  // Kết thúc chương trình
}
