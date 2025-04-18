#include <iostream>      
#include <fstream>       
#include <vector>        
using namespace std;     

// Hàm tự viết để sắp xếp danh sách số thực theo thứ tự tăng dần bằng phương pháp Bubble Sort
void bubbleSort(vector<double>& arr) {
    int n = arr.size();   // Lấy số lượng phần tử trong vector
    for (int i = 0; i < n - 1; i++) {   // Vòng lặp ngoài để duyệt tất cả phần tử
        for (int j = 0; j < n - i - 1; j++) {  // Vòng lặp trong để so sánh các phần tử kề nhau
            if (arr[j] > arr[j + 1]) {   // Nếu phần tử hiện tại lớn hơn phần tử tiếp theo
                // Hoán đổi hai phần tử để sắp xếp theo thứ tự tăng dần
                double temp = arr[j];     // Lưu giá trị phần tử hiện tại vào biến tạm
                arr[j] = arr[j + 1];     // Đưa phần tử tiếp theo vào vị trí hiện tại
                arr[j + 1] = temp;       // Đưa giá trị tạm vào vị trí tiếp theo
            }
        }
    }
}

int main() {
    // Mở file 'numbers.txt' để đọc dữ liệu từ file đầu vào
    ifstream input("numbers.txt");   

    // Mở file 'numbers.sorted' để ghi kết quả sắp xếp ra file đầu ra
    ofstream output("numbers.sorted"); 

    // Khởi tạo vector để chứa các số thực
    vector<double> numbers;
    double num;   // Biến tạm để đọc từng số thực từ file

    // Đọc tất cả các số từ file vào vector
    while (input >> num) {   // Lặp cho đến khi đọc hết số trong file
        numbers.push_back(num);  // Thêm số vào vector
    }

    // Gọi hàm sắp xếp các số theo thứ tự tăng dần
    bubbleSort(numbers);

    // Ghi các số đã sắp xếp vào file 'numbers.sorted', mỗi số cách nhau một dấu cách
    for (int i = 0; i < numbers.size(); ++i) {  // Duyệt qua tất cả các phần tử trong vector
        output << numbers[i];   // Ghi số vào file
        if (i < numbers.size() - 1)    // Nếu không phải phần tử cuối cùng
            output << " ";    // Thêm dấu cách giữa các số
    }

    // Đóng file sau khi hoàn thành việc đọc và ghi
    input.close();
    output.close();

    return 0;   // Kết thúc chương trình
}
