#include <iostream>     
#include <fstream>      
#include <vector>       
#include <algorithm>    

using namespace std;

// Cấu trúc cạnh gồm hai đỉnh u, v và chi phí cost
struct Edge {
    int u, v, cost;

    // Toán tử so sánh để sắp xếp cạnh theo chi phí tăng dần
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

const int MAXN = 10005;     // Số đỉnh tối đa (giả sử lớn nhất 10^4)
int parent[MAXN];           // Mảng cha dùng cho Union-Find

int n, m;                   // n: số máy tính, m: số kết nối có thể có

// Hàm tìm đại diện (gốc) của tập chứa u (có path compression)
int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);  // Gán trực tiếp gốc để nén đường đi
    return parent[u];
}

// Hàm hợp nhất hai tập chứa u và v. Trả về true nếu hợp nhất thành công
bool unionSets(int u, int v) {
    int pu = find(u);     // Gốc của u
    int pv = find(v);     // Gốc của v
    if (pu == pv) return false;  // u và v đã trong cùng một tập → tạo chu trình → bỏ
    parent[pu] = pv;      // Hợp nhất hai tập
    return true;
}

int main() {
    ifstream infile("connection.txt");     // Mở file đầu vào
    ofstream outfile("connection.out");    // Mở file đầu ra

    infile >> n >> m;                      // Đọc số máy tính và số kết nối
    vector<Edge> edges(m);                 // Danh sách các cạnh

    // Đọc m dòng chứa các cạnh: u, v, cost
    for (int i = 0; i < m; ++i) {
        infile >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    // Khởi tạo mảng cha: mỗi nút là cha của chính nó
    for (int i = 1; i <= n; ++i)
        parent[i] = i;

    // Sắp xếp danh sách cạnh theo chi phí tăng dần
    sort(edges.begin(), edges.end());

    int totalCost = 0;                    // Tổng chi phí cây khung nhỏ nhất
    vector<Edge> mstEdges;                // Danh sách cạnh trong cây khung

    // Duyệt qua các cạnh đã sắp xếp
    for (Edge& e : edges) {
        if (unionSets(e.u, e.v)) {        // Nếu thêm cạnh này không tạo chu trình
            totalCost += e.cost;          // Cộng chi phí vào tổng
            mstEdges.push_back(e);        // Ghi nhận cạnh vào cây khung
        }
    }

    // Ghi tổng chi phí ra file
    outfile << totalCost << endl;

    // Ghi từng cạnh được chọn trong cây khung ra file
    for (Edge& e : mstEdges) {
        outfile << e.u << " " << e.v << " " << e.cost << endl;
    }

    // Đóng file
    infile.close();
    outfile.close();

    return 0;   // Kết thúc chương trình
}
