#include <iostream>
#include <fstream>      
#include <vector>       
#include <stack>        
#include <algorithm>

using namespace std;

// Hằng số kích thước tối đa của số lượng công việc
const int MAXN = 10005;

// Khai báo danh sách kề cho đồ thị có hướng
vector<int> adj[MAXN];    

// Mảng đánh dấu các đỉnh đã được thăm
bool visited[MAXN];       

// Ngăn xếp dùng để lưu kết quả sắp xếp tôpô
stack<int> topoStack;     

// Hàm thực hiện duyệt DFS từ đỉnh u
void dfs(int u) {
    visited[u] = true;                // Đánh dấu đỉnh u đã được thăm
    for (int v : adj[u]) {           // Duyệt tất cả các đỉnh kề của u
        if (!visited[v]) {           // Nếu đỉnh kề v chưa được thăm
            dfs(v);                  // Gọi đệ quy DFS từ đỉnh v
        }
    }
    topoStack.push(u);               // Sau khi thăm xong các đỉnh kề, đẩy u vào ngăn xếp
}

// Hàm thực hiện sắp xếp tôpô bằng DFS cho n đỉnh
void topoSort(int n) {
    // Đặt lại trạng thái tất cả đỉnh là chưa được thăm
    fill(visited, visited + n + 1, false);  
    
    // Duyệt qua tất cả các đỉnh từ 1 đến n
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {           // Nếu đỉnh i chưa được thăm
            dfs(i);                  // Thực hiện DFS từ đỉnh i
        }
    }
}

// Hàm chính
int main() {
    ifstream infile("jobs.txt");     // Mở file đầu vào để đọc dữ liệu
    ofstream outfile("jobs.out");    // Mở file đầu ra để ghi kết quả

    int n, m;                        // n: số công việc, m: số ràng buộc
    infile >> n >> m;               // Đọc số lượng công việc và số ràng buộc

    // Đọc m dòng ràng buộc: mỗi dòng gồm 2 số u, v nghĩa là u phải làm trước v
    for (int i = 0; i < m; ++i) {
        int u, v;
        infile >> u >> v;           // Đọc ràng buộc
        adj[u].push_back(v);        // Thêm cạnh có hướng từ u đến v
    }

    topoSort(n);                    // Gọi hàm sắp xếp tôpô bằng DFS

    // Ghi kết quả ra file đầu ra theo thứ tự từ stack
    while (!topoStack.empty()) {
        outfile << topoStack.top() << " ";   // Lấy phần tử trên cùng của stack
        topoStack.pop();                     // Xoá phần tử đó khỏi stack
    }

    infile.close();               // Đóng file đầu vào
    outfile.close();              // Đóng file đầu ra

    return 0;                     // Kết thúc chương trình
}
