#include<iostream>         
#include<vector>           
using namespace std;

// Hàm partition để chia mảng và đưa pivot về đúng vị trí
int partition(vector<int>& vec, int low, int high) {
    int pivot = vec[high]; // Chọn pivot là phần tử cuối cùng
    int i = low - 1;       // Khởi tạo chỉ số i để xác định vị trí đúng của pivot

    for (int j = low; j <= high - 1; j++) { // Duyệt qua các phần tử từ low đến high - 1
        if (vec[j] <= pivot) {             // Nếu phần tử hiện tại <= pivot
            i++;                           // Tăng i lên (chỉ số cho phần tử nhỏ hơn pivot)
            swap(vec[i], vec[j]);          // Đưa phần tử nhỏ hơn về trước
        }
    }
    swap(vec[i + 1], vec[high]);           // Đưa pivot về vị trí đúng
    return (i + 1);                        // Trả về chỉ số của pivot sau khi sắp xếp
}

// Hàm quickSort để sắp xếp vector sử dụng thuật toán quicksort
void quickSort(vector<int>& vec, int low, int high) {
    if (low < high) {                            // Nếu có ít nhất 2 phần tử cần sắp xếp
        int pi = partition(vec, low, high);      // Gọi hàm partition và lấy vị trí pivot
        quickSort(vec, low, pi - 1);             // Đệ quy sắp xếp phần bên trái pivot
        quickSort(vec, pi + 1, high);            // Đệ quy sắp xếp phần bên phải pivot
    }
}

int main() { // Hàm main - điểm bắt đầu chương trình
    vector<int> vec = {9, 4, 7, 3, 1, 6, 2}; // Khởi tạo vector với một ví dụ mới
    int n = vec.size();                     // Lấy kích thước của vector

    quickSort(vec, 0, n - 1);               // Gọi hàm quickSort để sắp xếp toàn bộ vector

    for (int i = 0; i < n; i++) {           // In các phần tử đã sắp xếp ra màn hình
        cout << vec[i] << " ";
    }
    return 0; // Kết thúc chương trình
}
