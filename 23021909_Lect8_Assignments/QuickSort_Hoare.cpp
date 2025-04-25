#include <iostream>   
#include <vector>     
using namespace std;

// Hàm phân vùng Hoare
int partition(vector<int>& vec, int low, int high) {
    int pivot = vec[low];      // Chọn pivot là phần tử đầu tiên
    int left = low + 1;        // Con trỏ trái bắt đầu ngay sau pivot
    int right = high;          // Con trỏ phải bắt đầu từ cuối mảng

    while (true) {
        // Di chuyển left đến khi gặp phần tử > pivot
        while (left <= high && vec[left] <= pivot) {
            left++;
        }

        // Di chuyển right đến khi gặp phần tử <= pivot
        while (right >= low && vec[right] > pivot) {
            right--;
        }

        // Nếu con trỏ trái vượt qua phải, dừng lại
        if (left > right) {
            break;
        }

        // Nếu chưa vượt qua, hoán đổi 2 phần tử không đúng vị trí
        swap(vec[left], vec[right]);
    }

    // Sau khi hoàn tất, đưa pivot vào đúng vị trí (vec[right])
    swap(vec[low], vec[right]);

    return right;  // Trả về chỉ số mới của pivot
}

// Hàm QuickSort sử dụng Hoare partition
void quickSort(vector<int>& vec, int low, int high) {
    if (low < high) {                          // Điều kiện dừng đệ quy
        int pi = partition(vec, low, high);    // Phân vùng và lấy chỉ số pivot
        quickSort(vec, low, pi - 1);           // Đệ quy sắp xếp bên trái pivot
        quickSort(vec, pi + 1, high);          // Đệ quy sắp xếp bên phải pivot
    }
}

// Hàm main - điểm bắt đầu chương trình
int main() {
    vector<int> vec = {9, 4, 7, 3, 1, 6, 2};  // Một ví dụ khác để minh họa
    int n = vec.size();                    // Lấy kích thước mảng

    quickSort(vec, 0, n - 1);              // Gọi QuickSort trên toàn bộ mảng

    for (int i = 0; i < n; i++) {          // In ra các phần tử đã sắp xếp
        cout << vec[i] << " ";
    }

    cout << endl; // Xuống dòng sau khi in
    return 0;     // Trả về 0 - kết thúc chương trình
}
