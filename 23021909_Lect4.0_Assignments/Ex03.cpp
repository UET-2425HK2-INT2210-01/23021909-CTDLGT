#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char c) : data(c), next(nullptr) {}
};

class Stack {
public:
    Node* top;
    int size;
    Stack() {
        top = nullptr;
        size=0;
    }
    bool isEmpty() {
        return top == nullptr;
    }

    void push(char c) {
        Node* newNode = new Node(c);
        if(isEmpty())
        {
            top =newNode;
        }
        else {
            newNode->next = top;
        top = newNode;
        }  
        size++;
    }
    
    void pop() {
        if (!isEmpty())
        {
            Node* temp = top;
            top = temp->next;
            delete temp;
        }
    }

    char peek() {
        return top ? top->data : '\0';
    }
};

bool isValid(string s) {
    Stack st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.isEmpty()) return false; 

            char top = st.peek();
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                st.pop();  
            } else {
                return false; 
            }
        }
    }
    return st.isEmpty();
}

int main() {
    string s;
    cin >> s;

    if (isValid(s)) cout << "Valid\n";
    else cout << "Invalid\n";

    return 0;
}
