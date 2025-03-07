// STRUCT Node:
//     VARIABLE data: Integer
//     VARIABLE next: Pointer to the next Node
//     FUNCTION Initialize(x):
//         SET data = x
//         SET next = NULL

// CLASS Queue:
//     VARIABLE front: Pointer to the first Node
//     VARIABLE rear: Pointer to the last Node
//     VARIABLE size: Number of elements in the queue

//     FUNCTION Initialize():
//         SET front = NULL
//         SET rear = NULL
//         SET size = 0

// Kiểm tra xem hàng đợi có rỗng không (Độ phức tạp o(1))
//     FUNCTION isEmpty():
//         RETURN (front == NULL)

// Thêm phần tử vào cuối hàng đợi ( Độ phức tạp O(1))
//     FUNCTION enqueue(x):
//         CREATE newNode AS a new Node WITH VALUE x
//         IF rear == NULL THEN
//             SET front = rear = newNode
//         ELSE
//             SET rear.next = newNode
//             SET rear = newNode
//         ENDIF
//         INCREMENT size

// Xóa phần tử ở đầu hàng đợi ( Độ phức tạp : O(1))
//     FUNCTION dequeue():
//         IF isEmpty() THEN
//             PRINT "Queue is empty!"
//             RETURN -1
//         ENDIF
//         SET removedElement = front.data
//         SET temp = front
//         SET front = front.next
//         IF front == NULL THEN
//             SET rear = NULL
//         ENDIF
//         DECREMENT size
//         DELETE temp
//         RETURN removedElement

// Lấy phần tử đầu hàng đợi mà không xóa nó (Độ phức tạp O(1))
//     FUNCTION frontElement():
//         IF isEmpty() THEN
//             PRINT "Queue is empty!"
//             RETURN -1
//         ENDIF
//         RETURN front.data

// Hiển thị các phần tử trong hàng đợi (Độ phức tạp O(n))
//     FUNCTION display():
//         IF isEmpty() THEN
//             PRINT "Queue is empty!"
//             RETURN
//         ENDIF
//         SET temp = front
//         WHILE temp IS NOT NULL:
//             PRINT temp.data
//             SET temp = temp.next
//         ENDWHILE
//         PRINT NEWLINE

//Chương trình : 
#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node(int x) {
        data = x;
        next = nullptr;
    }
};

class Queue {
public:
    node* front;
    node* rear;
    int size;
    Queue()
    {
        front = rear = nullptr;
        size=0;
    }

    // Kiểm tra xem hàng đợi có rỗng không (Độ phức tạp o(1))
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Thêm phần tử vào cuối hàng đợi ( Độ phức tạp O(1))
    void enqueue(int x) {
        node* newNode = new node(x);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Xóa phần tử ở đầu hàng đợi ( Độ phức tạp : O(1))
    int dequeue() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng!" << endl;
            return -1;
        }
        int removedElement = front->data;
        node* temp = front;
        front = temp->next;

        if (front == nullptr) {
            rear = nullptr;
        }
        size--;
        delete temp;
        return removedElement;
    }

    // Lấy phần tử đầu hàng đợi mà không xóa nó (Độ phức tạp O(1))
    int frontElement() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng!" << endl;
            return -1;
        }
        return front->data;
    }

    // Hiển thị các phần tử trong hàng đợi (Độ phức tạp O(n))
    void display() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng!" << endl;
            return;
        }
        node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();

    cout << "Front element : " << q.frontElement() << endl; 

    return 0;
}
