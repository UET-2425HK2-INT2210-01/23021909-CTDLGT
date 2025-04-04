
#include <iostream> // Thư viện hỗ trợ nhập xuất dữ liệu
using namespace std;

// Định nghĩa lớp Node để biểu diễn mỗi nút trong cây nhị phân tìm kiếm
class Node {
public:
    int data; // Giá trị của nút
    Node* left; // Con trỏ trỏ đến con trái
    Node* right; // Con trỏ trỏ đến con phải

    // Constructor khởi tạo nút với giá trị cho trước
    Node(int value) {
        data = value; // Gán giá trị cho nút
        left = right = nullptr; // Khởi tạo con trái và phải là nullptr
    }
};

// Định nghĩa lớp BinarySearchTree để quản lý cây nhị phân tìm kiếm
class BinarySearchTree {
public:
    Node* root; // Con trỏ đến nút gốc của cây

    // Constructor khởi tạo cây rỗng
    BinarySearchTree() {
        root = nullptr;
    }

    // Hàm thêm một phần tử vào cây
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Hàm duyệt cây theo thứ tự inorder (LNR - trái, nút, phải)
    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    // Hàm duyệt cây theo thứ tự preorder (NLR - nút, trái, phải)
    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    // Hàm duyệt cây theo thứ tự postorder (LRN - trái, phải, nút)
    void postorder() {
        postorderRec(root);
        cout << endl;
    }

    // Hàm xóa một phần tử khỏi cây
    void remove(int value) {
        root = removeRec(root, value);
    }

    // Hàm thêm giá trị vào cây nhị phân tìm kiếm bằng đệ quy
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) { // Nếu cây rỗng, tạo nút mới
            return new Node(value);
        }
        if (value < node->data) { // Nếu giá trị nhỏ hơn nút hiện tại, chèn vào cây con trái
            node->left = insertRec(node->left, value);
        } else { // Nếu giá trị lớn hơn hoặc bằng nút hiện tại, chèn vào cây con phải
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    // Hàm xóa một nút trong cây nhị phân tìm kiếm bằng đệ quy
    Node* removeRec(Node* node, int value) {
        if (node == nullptr) return node; // Nếu cây rỗng, trả về nullptr

        if (value < node->data) { // Nếu giá trị cần xóa nhỏ hơn, tìm trong cây con trái
            node->left = removeRec(node->left, value);
        } else if (value > node->data) { // Nếu giá trị cần xóa lớn hơn, tìm trong cây con phải
            node->right = removeRec(node->right, value);
        } else {
            // Nếu nút có một hoặc không có con
            if (node->left == nullptr) {
                Node* temp = node->right; // Lưu con phải
                delete node; // Xóa nút hiện tại
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left; // Lưu con trái
                delete node; // Xóa nút hiện tại
                return temp;
            }
            // Nếu nút có hai con, tìm phần tử nhỏ nhất bên phải để thay thế
            Node* temp = findMin(node->right);
            node->data = temp->data; // Gán giá trị nhỏ nhất vào nút cần xóa
            node->right = removeRec(node->right, temp->data); // Xóa phần tử nhỏ nhất trong cây con phải
        }
        return node;
    }

    // Hàm tìm giá trị nhỏ nhất trong cây con phải
    Node* findMin(Node* node) {
        while (node->left != nullptr) { // Duyệt xuống sâu bên trái nhất
            node = node->left;
        }
        return node; // Trả về nút nhỏ nhất
    }

    // Hàm duyệt cây theo thứ tự inorder (trái - gốc - phải)
    void inorderRec(Node* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            cout << node->data << " "; // In giá trị của nút
            inorderRec(node->right);
        }
    }

    // Hàm duyệt cây theo thứ tự preorder (gốc - trái - phải)
    void preorderRec(Node* node) {
        if (node != nullptr) {
            cout << node->data << " "; // In giá trị của nút trước
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }

    // Hàm duyệt cây theo thứ tự postorder (trái - phải - gốc)
    void postorderRec(Node* node) {
        if (node != nullptr) {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << node->data << " "; // In giá trị của nút sau cùng
        }
    }
};

// Hàm main để chạy chương trình
int main() {
    BinarySearchTree bst;
    bst.insert(2);
    bst.insert(1);
    bst.insert(10);
    bst.insert(6);
    bst.insert(3);
    bst.insert(8);
    bst.insert(7);
    bst.insert(13);
    bst.insert(20);
    cout << "Binary search tree :"<< endl;
    cout << "Inorder traversal: ";
    bst.inorder();
    
    cout << "Preorder traversal: ";
    bst.preorder();
    
    cout << "Postorder traversal: ";
    bst.postorder();

    cout << "Binary search tree after inserting values: 14,0,35"<<endl;
    bst.insert(14);
    bst.insert(0);
    bst.insert(35);
    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Binary search tree after deleting values: 6,13,35"<<endl;

    bst.remove(6);
    bst.remove(13);
    bst.remove(35);
    cout << "Inorder traversal: ";
    bst.inorder();
    return 0;
}

