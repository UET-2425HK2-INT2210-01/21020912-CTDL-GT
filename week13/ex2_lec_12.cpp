#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Cấu trúc biểu diễn một cạnh trong đồ thị
struct Edge{
    int u, v, weight;  // u, v: đỉnh đầu và cuối của cạnh, weight: trọng số (chi phí kết nối)
    Edge(int _u, int _v, int _w):u(_u), v(_v), weight(_w){};

    // Nạp chồng toán tử < để sắp xếp các cạnh theo trọng số tăng dần
    bool operator<(const Edge& other) const{
        return weight < other.weight;
    }
};

// Cấu trúc dữ liệu Disjoint-Set (Union-Find) để phát hiện chu trình
class DisjointSet{
private:
    vector<int> parent;  // Lưu nút cha của mỗi đỉnh
    vector<int> rank;    // Lưu chiều cao của cây (để tối ưu hóa việc hợp nhất)
public:
    // Khởi tạo: mỗi đỉnh là một tập hợp riêng biệt
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);

        // Ban đầu, mỗi đỉnh là đại diện cho chính nó
        for (int i = 1; i<=n; i++){
            parent[i] = i;
        }
    }
    
    // Tìm đại diện của tập hợp chứa x (với nén đường dẫn)
    int find(int x){
        if (parent[x] != x) parent[x] = find(parent[x]);  // Nén đường dẫn
        return parent[x];
    }

    // Hợp nhất hai tập hợp chứa x và y
    void unionSets(int x, int y){
        int rootX = find(x);  // Tìm gốc của x
        int rootY = find(y);  // Tìm gốc của y

        if (rootX == rootY) return;  // Đã cùng tập hợp, không cần hợp nhất

        // Hợp nhất theo heuristic rank
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;  // Gắn cây thấp hơn vào cây cao hơn
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;  // Gắn cây thấp hơn vào cây cao hơn
        else{
            parent[rootY] = rootX;  // Nếu cùng chiều cao, chọn rootX làm gốc
            rank[rootX]++;         // Và tăng chiều cao của cây
        }
    }
};

int main(){
    // Mở file đầu vào và đầu ra
    freopen("connection.txt", "r", stdin);
    freopen("connection.out", "w", stdout);
    
    // Đọc số đỉnh (máy tính) và số cạnh (kết nối)
    int n, m;
    cin>>n>>m;

    // Đọc thông tin các cạnh
    vector<Edge> edges;
    for (int i = 0; i<m; i++){
        int u, v, d;
        cin>>u>>v>>d;
        edges.push_back(Edge(u, v, d));
    }

    // Sắp xếp các cạnh theo trọng số tăng dần
    sort(edges.begin(), edges.end());
    
    // Khởi tạo cấu trúc Disjoint-Set
    DisjointSet ds(n);
    
    // Biến lưu kết quả cây khung nhỏ nhất (MST)
    vector<Edge> mst;
    int totalCost = 0;
    
    // Thuật toán Kruskal: duyệt các cạnh theo thứ tự trọng số tăng dần
    for (Edge& edge: edges){
        // Kiểm tra xem cạnh này có tạo chu trình không
        if (ds.find(edge.u) != ds.find(edge.v)){
            // Nếu không tạo chu trình, thêm vào MST
            ds.unionSets(edge.u, edge.v);
            mst.push_back(edge);
            totalCost += edge.weight;

            // MST của đồ thị n đỉnh sẽ có n-1 cạnh
            if (mst.size() == n - 1)
            break;
        }
    }
    
    // In kết quả: tổng chi phí kết nối tối thiểu
    cout<< totalCost<<endl;
    
    // In các cạnh trong MST
    for (Edge& edge:mst){
        cout<<edge.u<<" "<<edge.v<<" "<<edge.weight<<endl;
    }
    return 0;
}