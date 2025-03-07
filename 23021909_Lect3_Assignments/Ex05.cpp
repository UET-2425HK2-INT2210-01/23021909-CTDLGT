// DEFINE MAX_SIZE = 100

// CLASS Stack:
//     PRIVATE VARIABLES:
//         arr[MAX_SIZE]: Array to store stack elements
//         top: Integer (index of the top element)

// Khởi tạo stack rỗng Độ phức tạp: O(1)
//     FUNCTION Initialize():
//         SET top = -1

// Kiểm tra stack có rỗng không Độ phức tạp: O(1)
//     FUNCTION isEmpty():
//         RETURN (top == -1)

// Kiểm tra stack có rỗng không Độ phức tạp: O(1)
//     FUNCTION isFull():
//         RETURN (top == MAX_SIZE - 1)

// Thêm phần tử vào stack (PUSH) Độ phức tạp: O(1)
//     FUNCTION push(x):
//         IF isFull() THEN
//             PRINT "Stack overflow! Cannot push " + x
//             RETURN
//         ENDIF
//         INCREMENT top
//         SET arr[top] = x

// Loại bỏ phần tử trên đỉnh stack (POP) Độ phức tạp: O(1)
//     FUNCTION pop():
//         IF isEmpty() THEN
//             PRINT "Stack underflow! Cannot pop"
//             RETURN
//         ENDIF
//         PRINT arr[top] + " popped from stack"
//         DECREMENT top

// Lấy giá trị phần tử trên đỉnh stack (TOP) Độ phức tạp: O(1)
//     FUNCTION getTop():
//         IF isEmpty() THEN
//             RETURN -1
//         ENDIF
//         RETURN arr[top]

// Hiển thị stack (từ trên xuống dưới) Độ phức tạp: O(n)
//     FUNCTION display():
//         IF isEmpty() THEN
//             PRINT "Stack is empty!"
//             RETURN
//         ENDIF
//         PRINT "Stack (top -> bottom): "
//         FOR i FROM top TO 0 DECREMENTING BY 1:
//             PRINT arr[i] + " "
//         ENDFOR
//         PRINT NEWLINE


//Chương trình :
#include <iostream>
using namespace std;

#define MAX_SIZE 100 

class Stack {
private:
    int arr[MAX_SIZE]; 
    int top;           

public:
    // Khởi tạo stack rỗng Độ phức tạp: O(1)
    Stack()
    {
        top = -1;
    }
    // Kiểm tra stack có rỗng không Độ phức tạp: O(1)
    bool isEmpty()
    {
        return (top == -1);
    }
    // Kiểm tra stack có đầy không Độ phức tạp: O(1)
    bool isFull()
    {
        return (top == MAX_SIZE - 1);
    }
    // Thêm phần tử vào stack (PUSH) Độ phức tạp: O(1)
    void push(int x) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
    }

    // Loại bỏ phần tử trên đỉnh stack (POP) Độ phức tạp: O(1)
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop" << endl;
            return;
        }
        cout << arr[top] << " popped from stack\n";
        top--;
    }

    // Lấy giá trị phần tử trên đỉnh stack (TOP) Độ phức tạp: O(1)
    int getTop()
    {
        return isEmpty() ? -1 : arr[top];
    }
    // Hiển thị stack (từ trên xuống dưới) Độ phức tạp: O(n)
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack (top -> bottom): ";
        for (int i = top; i >= 0; i--) {  
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display(); 

    cout << "Top element: " << s.getTop() << endl; 

    s.pop();  
    s.display();  
    s.pop();  
    s.pop();  
    s.pop();  
    
    cout << "Top element: " << s.getTop() << endl;

    return 0;
}
