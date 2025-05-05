#include <iostream>     
#include <vector>       
using namespace std;

// Hàm đệ quy để tìm nhóm học sinh có tổng độ tuổi bằng X
bool findGroup(vector<int>& A, int X, int index, vector<int>& current, int sum) {
    if (sum == X) {
        // Nếu tổng hiện tại bằng X thì trả về true (tìm thấy lời giải)
        return true;
    }

    // Nếu tổng vượt quá X hoặc đã xét hết danh sách thì dừng
    if (sum > X || index >= A.size()) return false;

    // ----------- Nhánh chọn phần tử hiện tại -----------

    // Thêm phần tử hiện tại vào nhóm
    current.push_back(A[index]);

    // Gọi đệ quy với phần tử tiếp theo, cộng phần tử hiện tại vào tổng
    if (findGroup(A, X, index + 1, current, sum + A[index])) return true;

    // Quay lui: xóa phần tử vừa thêm
    current.pop_back();

    // ----------- Nhánh bỏ qua phần tử hiện tại -----------

    // Gọi đệ quy với phần tử tiếp theo mà không chọn phần tử hiện tại
    if (findGroup(A, X, index + 1, current, sum)) return true;

    // Nếu không tìm được trong cả hai nhánh, trả về false
    return false;
}

int main() {
    int n, X;  // n là số học sinh, X là tổng độ tuổi cần tìm
    cin >> n >> X;  // Nhập n và X từ bàn phím

    vector<int> A(n);  // Khởi tạo mảng độ tuổi của học sinh

    // Nhập độ tuổi cho từng học sinh
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> current;  // Vector lưu nhóm học sinh đang xét

    // Gọi hàm findGroup để kiểm tra có tồn tại nhóm thỏa mãn không
    if (findGroup(A, X, 0, current, 0)) {
        cout << "YES";  // Nếu tìm thấy, in ra YES
    } else {
        cout << "NO";   // Ngược lại, in ra NO
    }

    return 0;  // Kết thúc chương trình
}
