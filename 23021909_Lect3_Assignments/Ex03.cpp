// CLASS Queue:

// Constructor - Khởi tạo queue rỗng với kích thước tối đa Độ phức tạp: O(1)
//     FUNCTION Constructor(capacity):
//         SET this.capacity = capacity
//         CREATE array of size capacity
//         SET front = 0
//         SET rear = -1
//         SET size = 0

// Kiểm tra queue có rỗng không Độ phức tạp: O(1)
//     FUNCTION isEmpty():
//         RETURN size == 0

// Kiểm tra queue có đầy không Độ phức tạp: O(1)
//     FUNCTION isFull():
//         RETURN size == capacity

// Thêm phần tử vào queue (ENQUEUE) Độ phức tạp: O(1)
//     FUNCTION enqueue(x):
//         IF isFull() THEN
//             PRINT "Queue is full!"
//             RETURN
//         ENDIF
//         rear = (rear + 1) MOD capacity
//         arr[rear] = x
//         size = size + 1

// Loại bỏ phần tử khỏi queue (DEQUEUE) Độ phức tạp: O(1)
//     FUNCTION dequeue():
//         IF isEmpty() THEN
//             PRINT "Queue is empty!"
//             RETURN -1
//         ENDIF
//         removedElement = arr[front]
//         front = (front + 1) MOD capacity
//         size = size - 1
//         RETURN removedElement

// Lấy giá trị phần tử ở đầu queue (FRONT) Độ phức tạp: O(1)
//     FUNCTION frontElement():
//         IF isEmpty() THEN
//             PRINT "Queue is empty!"
//             RETURN -1
//         ENDIF
//         RETURN arr[front]

// Hiển thị queue (từ đầu đến cuối) Độ phức tạp: O(n)
//     FUNCTION display():
//         IF isEmpty() THEN
//             PRINT "Queue is empty!"
//             RETURN
//         ENDIF
//         PRINT "Queue elements: "
//         index = front
//         FOR i FROM 0 TO size - 1 DO
//             PRINT arr[index]
//             index = (index + 1) MOD capacity
//         ENDFOR
//         PRINT NEWLINE

// Destructor để giải phóng bộ nhớ động Độ phức tạp: O(1)
//     FUNCTION Destructor():
//         DELETE arr

//Chương trình : 
#include <iostream>
using namespace std;
class Queue {
public:
    int *arr;  
    int capacity;   
    int front, rear; 
    int size;
    // Constructor - Khởi tạo queue rỗng với kích thước tối đa Độ phức tạp: O(1)
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Kiểm tra queue có rỗng không Độ phức tạp: O(1)
    bool isEmpty() {
        return size == 0;
    }

    // Kiểm tra queue có đầy không Độ phức tạp: O(1)
    bool isFull() {
        return size == capacity;
    }

    // Thêm phần tử vào queue (ENQUEUE) Độ phức tạp: O(1)
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    // Loại bỏ phần tử khỏi queue (DEQUEUE) Độ phức tạp: O(1)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; 
        }
        int removedElement = arr[front];
        front = (front + 1) % capacity; 
        size--;
        return removedElement;
    }

    // Lấy giá trị phần tử ở đầu queue (FRONT) Độ phức tạp: O(1)
    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Hiển thị queue (từ đầu đến cuối) Độ phức tạp: O(n)
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int index = front;
        for (int i = 0; i < size; i++) {
            cout << arr[index] << " ";
            index = (index + 1) % capacity; 
        }
        cout << endl;
    }
    // Destructor để giải phóng bộ nhớ động Độ phức tạp: O(1)
    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5); 

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); 

    cout << q.dequeue() << " dequeued from queue\n"; 
    q.display(); 

    cout << "Front: " << q.frontElement() << endl; 

    return 0;
}
