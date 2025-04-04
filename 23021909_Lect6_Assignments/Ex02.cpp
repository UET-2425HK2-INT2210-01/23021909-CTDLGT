#include <iostream> // Thư viện hỗ trợ nhập xuất dữ liệu
#include <vector>   // Thư viện hỗ trợ sử dụng vector để lưu trữ heap
using namespace std;

// Định nghĩa lớp MinHeap để biểu diễn Heap nhị phân tối thiểu
class MinHeap {
public:
    vector<int> heap; // Mảng vector để lưu trữ các phần tử của heap

    // Constructor khởi tạo heap rỗng
    MinHeap() {}

    // Hàm trả về chỉ mục của cha của một nút
    int parent(int i) { return (i - 1) / 2; }
    // Hàm trả về chỉ mục của con trái của một nút
    int leftChild(int i) { return 2 * i + 1; }
    // Hàm trả về chỉ mục của con phải của một nút
    int rightChild(int i) { return 2 * i + 2; }

    // Hàm chèn một phần tử vào heap
    void insert(int value) {
        heap.push_back(value); // Thêm phần tử vào cuối mảng
        int i = heap.size() - 1; // Chỉ mục của phần tử mới
        
        // Điều chỉnh vị trí của phần tử mới để đảm bảo tính chất của heap
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Hàm trả về giá trị nhỏ nhất trong heap (nút gốc)
    int getMin() {
        if (!heap.empty()) return heap[0];
        return -1; // Trả về -1 nếu heap rỗng
    }

    // Hàm xóa một nút bất kỳ khỏi heap
    void removeNode(int value) {
        int index = -1;
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i] == value) {
                index = i;
                break;
            }
        }
        
        if (index == -1) return; // Nếu không tìm thấy phần tử, thoát
        
        heap[index] = heap.back(); // Thay thế nút cần xóa bằng phần tử cuối
        heap.pop_back(); // Xóa phần tử cuối
        
        if (index < heap.size()) {
            heapify(index); // Điều chỉnh lại heap từ vị trí thay đổi
            while (index != 0 && heap[parent(index)] > heap[index]) {
                swap(heap[index], heap[parent(index)]);
                index = parent(index);
            }
        }
    }

    // Hàm heapify để duy trì tính chất của heap
    void heapify(int i) {
        int smallest = i; // Giả định nút hiện tại là nhỏ nhất
        int left = leftChild(i);
        int right = rightChild(i);

        // Kiểm tra con trái có nhỏ hơn nút hiện tại không
        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        // Kiểm tra con phải có nhỏ hơn nút hiện tại không
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }
        // Nếu nút nhỏ nhất không phải nút hiện tại, hoán đổi và tiếp tục heapify
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    // Hàm in ra các phần tử trong heap
    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

// Hàm main để kiểm tra các chức năng của MinHeap
int main() {
    MinHeap minHeap; // Tạo đối tượng heap
    minHeap.insert(2);
    minHeap.insert(1);
    minHeap.insert(10);
    minHeap.insert(6);
    minHeap.insert(3);
    minHeap.insert(8);
    minHeap.insert(7);
    minHeap.insert(13);
    minHeap.insert(20);
    cout << "Heap elements: ";
    minHeap.printHeap(); // In các phần tử trong heap

    cout << "Heap tree after inserting values: 14,0,35"<<endl;    
    minHeap.insert(14);
    minHeap.insert(0);
    minHeap.insert(35);
    
    minHeap.printHeap();// In các phần tử trong heap sau khi thêm 14, 0, 35
    cout << "Heap tree after deleting values: 6,13,35"<<endl;
    minHeap.removeNode(6); 
    minHeap.removeNode(13); 
    minHeap.removeNode(35); 
    
    minHeap.printHeap();// In các phần tử trong heap sau khi xóa 6, 13, 35
    return 0;
}
