#include <iostream>    // For standard I/O operations
#include <fstream>     // For file I/O operations
#include <vector>      // For using vector data structure

using namespace std;

// Trạng thái của đỉnh trong quá trình duyệt DFS
enum State { 
    UNVISITED,    // Đỉnh chưa được thăm
    VISITING,     // Đỉnh đang được thăm trong lần gọi đệ quy hiện tại
    VISITED       // Đỉnh đã được thăm xong
};

/**
 * Hàm DFS để thực hiện sắp xếp topo và phát hiện chu trình
 * @param u - đỉnh hiện tại đang xét
 * @param adj - danh sách kề của đồ thị
 * @param state - trạng thái của các đỉnh
 * @param result - danh sách kết quả sắp xếp topo
 * @return false nếu phát hiện chu trình, true nếu không có chu trình
 */
bool dfs(int u, const vector<vector<int>>& adj, vector<State>& state, vector<int>& result) {
    state[u] = VISITING;  // Đánh dấu đỉnh u đang được thăm

    // Duyệt qua tất cả các đỉnh kề với u
    for (int v : adj[u]) {
        if (state[v] == VISITING) 
            return false;  // Đã phát hiện chu trình (có cạnh ngược)
        if (state[v] == UNVISITED) {
            if (!dfs(v, adj, state, result))  // Duyệt đệ quy các đỉnh kề chưa thăm
                return false;  // Nếu phát hiện chu trình từ đỉnh con, truyền kết quả ngược lại
        }
    }

    state[u] = VISITED;  // Đánh dấu đã thăm xong đỉnh u
    result.push_back(u);  // Thêm u vào kết quả sắp xếp topo
    return true;  // Không phát hiện chu trình
}

int main() {
    // Mở file đầu vào và đầu ra
    ifstream fin("jobs.txt");
    ofstream fout("jobs.out");

    // Đọc số lượng công việc và số lượng ràng buộc
    int n, m;
    fin >> n >> m;

    // Khởi tạo đồ thị dưới dạng danh sách kề
    vector<vector<int>> adj(n+1);  // Chỉ số từ 1 đến n
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);  // Thêm cạnh từ u đến v (u phải thực hiện trước v)
    }

    // Khởi tạo mảng trạng thái và vector kết quả
    vector<State> state(n+1, UNVISITED);
    vector<int> result;

    // Duyệt DFS từ tất cả các đỉnh chưa thăm
    for (int i = 1; i <= n; i++) {
        if (state[i] == UNVISITED) {
            if (!dfs(i, adj, state, result)) {
                // Nếu phát hiện chu trình, không thể sắp xếp topo
                fout << "Khong the sap xep do co chu trinh\n";
                return 0;
            }
        }
    }

    // Đảo ngược kết quả để được thứ tự topo đúng
    // (DFS thêm đỉnh vào sau khi đã thăm xong, nên cần đảo ngược)
    for (int i = (int)result.size() - 1; i >= 0; i--) {
        fout << result[i];
        if (i != 0) fout << " ";  // Thêm khoảng trắng giữa các công việc
    }
    fout << "\n";

    // Đóng file
    fin.close();
    fout.close();

    return 0;
}