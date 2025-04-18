#include <iostream>     
#include <fstream>      
#include <vector>       
#include <climits>      
using namespace std;

// Hàm Kadane 1 chiều: tìm dãy con liên tiếp có tổng lớn nhất
int kadane(const vector<int>& arr, int& start, int& end) {
    int maxSum = INT_MIN;      // Khởi tạo tổng lớn nhất
    int sum = 0;               // Tổng hiện tại
    int tempStart = 0;         // Vị trí bắt đầu tạm thời
    start = end = -1;          // Khởi tạo chỉ số bắt đầu và kết thúc

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];         // Cộng dồn giá trị

        if (sum > maxSum) {    // Nếu tìm được tổng lớn hơn
            maxSum = sum;      // Cập nhật tổng lớn nhất
            start = tempStart; // Cập nhật vị trí bắt đầu
            end = i;           // Cập nhật vị trí kết thúc
        }

        if (sum < 0) {         // Nếu tổng âm, reset tổng và vị trí bắt đầu
            sum = 0;
            tempStart = i + 1;
        }
    }

    return maxSum;             // Trả về tổng lớn nhất tìm được
}

int main() {
    ifstream inFile("matrix.txt");   // Mở file để đọc dữ liệu đầu vào
    ofstream outFile("matrix.out");  // Mở file để ghi dữ liệu đầu ra

    int m, n;
    inFile >> m >> n;                // Đọc số hàng và số cột

    vector<vector<int>> matrix(m, vector<int>(n)); // Khởi tạo ma trận m dòng, n cột

    // Đọc các phần tử của ma trận từ file
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            inFile >> matrix[i][j];

    int maxSum = INT_MIN;       // Tổng lớn nhất ban đầu
    int finalLeft = 0, finalRight = 0, finalTop = 0, finalBottom = 0; // Lưu toạ độ hình chữ nhật kết quả

    // Xét tất cả các cặp hàng bắt đầu (top) và kết thúc (bottom)
    for (int top = 0; top < m; top++) {
        vector<int> temp(n, 0); // Mảng phụ để lưu tổng cột giữa 2 hàng top và bottom

        for (int bottom = top; bottom < m; bottom++) {
            // Cộng dồn theo từng cột
            for (int col = 0; col < n; col++) {
                temp[col] += matrix[bottom][col];
            }

            // Áp dụng Kadane 1 chiều trên mảng temp
            int startCol, endCol;
            int sum = kadane(temp, startCol, endCol);

            // Nếu tổng tìm được lớn hơn maxSum, cập nhật kết quả
            if (sum > maxSum) {
                maxSum = sum;
                finalTop = top;
                finalBottom = bottom;
                finalLeft = startCol;
                finalRight = endCol;
            }
        }
    }

    // Ghi kết quả ra file: r1 c1 r2 c2 s (chỉ số từ 1, nên +1)
    outFile << (finalTop + 1) << " " << (finalLeft + 1) << " "
            << (finalBottom + 1) << " " << (finalRight + 1) << " "
            << maxSum << endl;

    inFile.close();   // Đóng file đầu vào
    outFile.close();  // Đóng file đầu ra

    return 0;         // Kết thúc chương trình
}
