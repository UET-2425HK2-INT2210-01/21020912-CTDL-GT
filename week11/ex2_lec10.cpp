#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Hàm BFS để tìm đường đi ngắn nhất (ít cạnh nhất) từ đỉnh X đến đỉnh Y trong đồ thị có hướng
int bfs(int n, vector<vector<int>> &arr, int X, int Y) {
    queue<int> q;                          // Hàng đợi dùng cho BFS
    vector<bool> visited(n + 1, false);    // Mảng đánh dấu đỉnh đã được thăm
    vector<int> distance(n + 1, -1);       // Mảng lưu khoảng cách từ X đến mỗi đỉnh (khởi tạo -1 nghĩa là chưa được thăm)

    q.push(X);              // Bắt đầu từ đỉnh X
    distance[X] = 0;        // Khoảng cách từ X đến chính nó là 0

    while (!q.empty()) {
        int value = q.front();
        q.pop();

        // Duyệt qua tất cả các đỉnh kề với đỉnh hiện tại
        for (int neighbor : arr[value]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;                         // Đánh dấu đỉnh này đã được thăm
                distance[neighbor] = distance[value] + 1;         // Cập nhật khoảng cách
                q.push(neighbor);                                 // Thêm đỉnh vào hàng đợi để tiếp tục BFS

                // Nếu đã đến đỉnh đích Y thì trả về kết quả ngay
                if (neighbor == Y) {
                    return distance[neighbor];
                }
            }
        }
    }

    return -1; // Nếu không có đường đi từ X đến Y
}

int main() {
    freopen("ex2_lec10.txt", "r", stdin); // Mở file ex2_lec10.txt để đọc dữ liệu
    int n, m, X, Y;
    cin >> n >> m >> X >> Y; // Nhập số đỉnh, số cạnh, đỉnh bắt đầu X và đỉnh kết thúc Y

    vector<vector<int>> arr(n + 1); // Danh sách kề, dùng chỉ số từ 1 đến n

    // Nhập m cạnh và xây dựng danh sách kề
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;           // Nhập cạnh từ x đến y
        arr[x].push_back(y);     // Đồ thị có hướng: chỉ thêm y vào danh sách kề của x
    }

    // Gọi hàm BFS để tìm đường đi ngắn nhất
    int distance = bfs(n, arr, X, Y);

    // In ra kết quả: số cạnh ngắn nhất giữa X và Y (hoặc -1 nếu không có đường đi)
    cout << "Shortest distance between X and Y is: " << distance << endl;

    return 0;
}
