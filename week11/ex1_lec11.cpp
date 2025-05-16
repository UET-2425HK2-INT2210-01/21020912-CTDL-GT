#include<iostream>
#include<vector>
#include<tuple>
#include<limits>
#include<algorithm>
using namespace std;

// Định nghĩa giá trị vô cùng để biểu thị không có đường đi
const int INF = 1e9;

int main(){
    // Mở file để đọc đầu vào và ghi đầu ra 
    freopen("dirty.txt", "r", stdin);
    freopen("dirty.out", "w", stdout);
    
    int n, m, s, e;
    // Nhập số đỉnh (n), số cạnh (m), đỉnh xuất phát (s) và đỉnh đích (e)
    cin >> n >> m >> s >> e;
    
    // Vector lưu các cạnh dưới dạng tuple <đỉnh đầu, đỉnh cuối, trọng số>
    vector<tuple<int, int, int>> edges;
    
    // Ma trận khoảng cách cho thuật toán Floyd-Warshall
    vector<vector<int>> dis(n+1, vector<int>(n+1, INF));
    
    // Mảng lưu đỉnh cha để truy vết đường đi
    vector<int> parent(n+1, -1);
    
    // Khởi tạo khoảng cách từ một đỉnh đến chính nó là 0
    for (int i = 0; i <= n; i++){
        dis[i][i] = 0;
    }
    
    // Nhập thông tin các cạnh của đồ thị
    for (int i = 0; i < m; i++){
        int u, v, d;
        cin >> u >> v >> d;
        edges.push_back({u, v, d});
        dis[u][v] = d; // Cập nhật khoảng cách trực tiếp
    }
    
    // Mảng lưu khoảng cách từ đỉnh xuất phát đến các đỉnh khác (cho Bellman-Ford)
    vector<int> dirty(n+1, INF);
    dirty[s] = 0; // Khoảng cách từ s đến s là 0
    
    // Thuật toán Bellman-Ford để tìm đường đi ngắn nhất từ s
    for(int i = 1; i <= n - 1; i++){
        for (auto[u, v, d] : edges){
            if (dirty[u] != INF && dirty[u] + d < dirty[v]){
                dirty[v] = dirty[u] + d; // Cập nhật khoảng cách nếu tìm thấy đường đi ngắn hơn
                parent[v] = u;          // Lưu đỉnh cha để truy vết đường đi
            }
        }
    }
    
    // Kiểm tra xem có tồn tại đường đi từ s đến e không
    if (dirty[e] == INF){
        cout << "No path" << endl;
    }
    else {
        // In ra khoảng cách ngắn nhất từ s đến e
        cout << dirty[e] << endl;
        
        // Truy vết và in ra đường đi từ s đến e
        vector<int> path;
        for (int v = e; v != -1; v = parent[v]){
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        
        for (int i : path){
            cout << i << " ";
        }
        cout << endl;
    }
    
    // Thuật toán Floyd-Warshall để tìm đường đi ngắn nhất giữa mọi cặp đỉnh
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                // Nếu có đường đi từ i đến k và từ k đến j
                if (dis[i][k] < INF && dis[k][j] < INF){
                    // Cập nhật khoảng cách nếu đi qua đỉnh k cho đường đi ngắn hơn
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
    
    // In ra ma trận khoảng cách ngắn nhất giữa các cặp đỉnh
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (dis[i][j] == INF){
                cout << "INF ";
            } else {
                cout << dis[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}