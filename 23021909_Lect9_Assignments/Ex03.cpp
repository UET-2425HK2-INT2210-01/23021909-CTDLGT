#include <iostream>               
#include <vector>                 
using namespace std;            

// Cấu trúc lưu thông tin mỗi vật phẩm
struct Item {
    int weight;                  // Trọng lượng của vật phẩm
    int value;                   // Giá trị của vật phẩm

    // Hàm trả về tỉ số giá trị/trọng lượng của vật phẩm
    double ratio() const {
        return (double)value / weight;
    }
};

// Hàm tự viết để sắp xếp các item theo ratio giảm dần bằng bubble sort
void sortItemsByRatio(vector<Item>& items) {
    int n = items.size();        // Lấy số lượng vật phẩm
    for (int i = 0; i < n - 1; ++i) {            // Vòng lặp ngoài của bubble sort
        for (int j = 0; j < n - i - 1; ++j) {    // Vòng lặp trong
            // So sánh tỉ số giá trị/trọng lượng, nếu item sau có tỉ số lớn hơn thì đổi chỗ
            if (items[j].ratio() < items[j + 1].ratio()) {
                Item temp = items[j];           // Hoán đổi 2 phần tử
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// Hàm giải bài toán Balo phân số (fractional knapsack)
double fractionalKnapsack(vector<Item>& items, int capacity) {
    sortItemsByRatio(items);                    // Sắp xếp vật phẩm theo tỉ số giảm dần

    double totalValue = 0.0;                    // Tổng giá trị đã lấy được
    int currentWeight = 0;                      // Tổng trọng lượng đã chiếm trong ba lô

    for (int i = 0; i < items.size(); ++i) {    // Duyệt từng vật phẩm
        if (currentWeight + items[i].weight <= capacity) {
            // Nếu còn đủ chỗ, lấy toàn bộ vật phẩm
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Nếu không đủ chỗ, chỉ lấy một phần vật phẩm
            int remain = capacity - currentWeight;     // Trọng lượng còn lại
            totalValue += items[i].ratio() * remain;   // Cộng thêm phần giá trị tương ứng
            break;                                     // Ba lô đã đầy, dừng lại
        }
    }

    return totalValue;                         // Trả về giá trị tối đa có thể lấy
}

int main() {
    int n, X;
    cin >> n;                                  // Nhập số lượng vật phẩm
    cin >> X;                                  // Nhập sức chứa của ba lô

    vector<Item> items(n);                     // Khởi tạo vector lưu n vật phẩm
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;   // Nhập trọng lượng và giá trị của mỗi vật phẩm
    }

    double maxValue = fractionalKnapsack(items, X); // Gọi hàm giải bài toán
    cout << maxValue << endl;                        // In ra giá trị lớn nhất có thể lấy

    return 0;                               // Kết thúc chương trình
}
