#include <bits/stdc++.h> 
using namespace std;

// Hàm merge: Gộp hai mảng con [left..mid] và [mid+1..right] thành mảng đã sắp xếp
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Độ dài mảng con trái
    int n2 = right - mid;    // Độ dài mảng con phải

    vector<int> L(n1), R(n2); // Tạo 2 mảng phụ để lưu dữ liệu tạm

    // Sao chép dữ liệu từ mảng chính sang mảng phụ L và R
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0; // Chỉ số duyệt mảng L
    int j = 0; // Chỉ số duyệt mảng R
    int k = left; // Chỉ số để ghi dữ liệu vào mảng chính

    // Gộp hai mảng L và R theo thứ tự tăng dần
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i]; // Nếu phần tử L nhỏ hơn hoặc bằng R thì ghi L
            i++;
        } else {
            arr[k] = R[j]; // Ngược lại ghi phần tử R
            j++;
        }
        k++; // Di chuyển vị trí ghi
    }

    // Ghi các phần tử còn lại của L (nếu có)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Ghi các phần tử còn lại của R (nếu có)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm mergeSort sử dụng đệ quy để chia nhỏ mảng và gộp lại
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return; // Điều kiện dừng khi chỉ còn 1 phần tử

    int mid = left + (right - left) / 2;  // Tìm chỉ số giữa
    mergeSort(arr, left, mid);           // Đệ quy sắp xếp mảng con bên trái
    mergeSort(arr, mid + 1, right);      // Đệ quy sắp xếp mảng con bên phải
    merge(arr, left, mid, right);        // Gộp hai mảng con lại
}

// Hàm in mảng ra màn hình
void printVector(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Hàm main - điểm khởi đầu của chương trình
int main() {
    vector<int> arr = {9, 4, 7, 3, 1, 6, 2}; // Mảng đầu vào mới
    int n = arr.size();                  // Kích thước mảng

    mergeSort(arr, 0, n - 1);            // Gọi merge sort
    printVector(arr);                    // In mảng đã sắp xếp

    return 0;
}
