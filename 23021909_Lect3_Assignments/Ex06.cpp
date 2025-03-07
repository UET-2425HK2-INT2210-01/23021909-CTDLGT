// STRUCT Node:
//     VARIABLE data: Integer
//     VARIABLE next: Pointer to the next Node

// CLASS Stack:
//     PUBLIC VARIABLES:
//         top: Pointer to the top Node
//         size: Integer (number of elements in stack)

// Khởi tạo stack rỗng Độ phức tạp: O(1)
//     FUNCTION Initialize():
//         SET top = NULL
//         SET size = 0

// Kiểm tra stack có rỗng không Độ phức tạp: O(1)
//     FUNCTION isEmpty():
//         RETURN (top == NULL)

// Thêm phần tử vào đỉnh stack (PUSH) Độ phức tạp o(1)
//     FUNCTION push(x):
//         CREATE newNode AS a new Node
//         SET newNode.data = x
//         SET newNode.next = top
//         SET top = newNode
//         INCREMENT size

// Xóa phần tử trên đỉnh stack (POP) Độ phức tạp o(1)
//     FUNCTION pop():
//         IF isEmpty() THEN
//             PRINT "Stack Underflow! Cannot pop"
//             RETURN
//         ENDIF
//         SET temp = top
//         SET top = temp.next
//         PRINT temp.data + " popped from stack"
//         DECREMENT size
//         DELETE temp

// Trả về phần tử trên đỉnh stack (TOP) Độ phức tạp o(1)
//     FUNCTION getTop():
//         IF isEmpty() THEN
//             PRINT "Stack is empty!"
//             RETURN -1
//         ENDIF
//         RETURN top.data

// Hiển thị stack Độ phức tạp o(n)
//     FUNCTION display():
//         IF isEmpty() THEN
//             PRINT "Stack is empty!"
//             RETURN
//         ENDIF
//         SET temp = top
//         PRINT "Stack elements: "
//         WHILE temp IS NOT NULL:
//             PRINT temp.data + " "
//             SET temp = temp.next
//         ENDWHILE
//         PRINT NEWLINE


//Chương trình :
#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};


class Stack {
public:
    node* top;
    int size;
    Stack() {
        top = nullptr;
        size=0;
    }

    bool isEmpty()   //Độ phức tạp : o(1)
    {
        return (top == nullptr);
    }

    // Thêm phần tử vào đỉnh stack (PUSH) Độ phức tạp o(1)
    void push(int x) {
        node* newNode = new node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Xóa phần tử trên đỉnh stack (POP) Độ phức tạp o(1)
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop\n";
            return;
        }
        node* temp = top;
        top = temp->next;  
        cout << temp->data << " popped from stack\n";
        size--;
        delete temp;
    }

    // Trả về phần tử trên đỉnh stack (TOP) Độ phức tạp o(1)
    int getTop() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return top->data;
    }

    // Hiển thị stack Độ phức tạp o(n)
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
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

    return 0;
}
