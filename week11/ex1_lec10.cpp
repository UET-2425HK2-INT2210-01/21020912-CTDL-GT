#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Hàm BFS để duyệt đồ thị và đánh dấu các đỉnh thuộc cùng một thành phần liên thông
void bfs(vector<vector<int>> &arr, vector<bool> &visited, int idx) {
    queue<int> q;
    q.push(idx);            // Bắt đầu BFS từ đỉnh idx
    visited[idx] = true;    // Đánh dấu đỉnh này đã được thăm

    while (!q.empty()) {
        int value = q.front();
        q.pop();

        // Duyệt tất cả các đỉnh kề chưa được thăm
        for (int neighbor : arr[value]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true; // Đánh dấu đã thăm
                q.push(neighbor);         // Thêm vào hàng đợi để tiếp tục duyệt
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // Nhập số đỉnh và số cạnh

    vector<vector<int>> arr(n + 1); // Danh sách kề, sử dụng chỉ số từ 1 đến n

    // Nhập m cạnh và xây dựng danh sách kề
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;               // Nhập cạnh nối x và y
        arr[x].push_back(y);        // Thêm y vào danh sách kề của x
        arr[y].push_back(x);        // Thêm x vào danh sách kề của y (đồ thị vô hướng)
    }

    vector<bool> visited(n + 1, false); // Mảng đánh dấu các đỉnh đã thăm
    int componments = 0;                // Biến đếm số thành phần liên thông

    // Duyệt qua tất cả các đỉnh
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(arr, visited, i);   // Gọi BFS nếu đỉnh chưa được thăm
            componments++;          // Tăng số thành phần liên thông
        }
    }

    cout << "The number of connected components is: " << componments << endl;

    return 0;
}
