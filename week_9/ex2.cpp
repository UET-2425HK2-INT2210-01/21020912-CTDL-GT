// Chương trình C++ tìm hình chữ nhật có tổng lớn nhất trong ma trận 2D

#include <bits/stdc++.h>
using namespace std;



// Hàm tìm hình chữ nhật có tổng lớn nhất trong ma trận 2D
// mat: ma trận đầu vào
// r1, c1: tọa độ góc trên bên trái của hình chữ nhật
// r2, c2: tọa độ góc dưới bên phải của hình chữ nhật
int maxSumRectangle(vector<vector<int>> &mat, int &r1, int &c1, int &r2, int &c2) {
    int rows = mat.size();    // Số hàng
    int cols = mat[0].size(); // Số cột
    int maxSum = INT_MIN;     // Tổng lớn nhất
    
    // Khởi tạo tọa độ hình chữ nhật
    r1 = c1 = r2 = c2 = 0;

    vector<int> temp(rows); // Mảng tạm để lưu tổng theo cột
    // Duyệt qua tất cả các cột bên trái có thể
    for (int left = 0; left < cols; left++) {
        fill(temp.begin(), temp.end(), 0);
        // Duyệt qua tất cả các cột bên phải có thể
        for (int right = left; right < cols; right++) {
            // Cập nhật mảng tạm với cột hiện tại
            for (int i = 0; i < rows; i++) {
                temp[i] += mat[i][right];
            }
            
            // Tìm mảng con có tổng lớn nhất trong temp bằng thuật toán Kadane
            int currSum = 0;         // Tổng hiện tại
            int maxSumHere = INT_MIN;// Tổng lớn nhất tại vị trí này
            int tempStart = 0, start = 0, end = 0; // Các chỉ số để theo dõi vị trí
            
            for (int i = 0; i < rows; i++) {
                currSum += temp[i];
                
                if (currSum > maxSumHere) {
                    maxSumHere = currSum;
                    start = tempStart;
                    end = i;
                }
                
                if (currSum < 0) {
                    currSum = 0;
                    tempStart = i + 1;
                }
            }
            
            // Cập nhật kết quả nếu tìm được tổng lớn hơn
            if (maxSumHere > maxSum) {
                maxSum = maxSumHere;
                // Chuyển sang chỉ số 1-based
                r1 = start + 1;    // Hàng bắt đầu
                c1 = left + 1;     // Cột bắt đầu
                r2 = end + 1;      // Hàng kết thúc
                c2 = right + 1;    // Cột kết thúc
            }
        }
    }
    return maxSum;
}

int main() {
    // Mở file đầu vào và đầu ra
    freopen("matrix.txt", "r", stdin);
    freopen("matrix.out", "w", stdout);
    
    // Đọc kích thước ma trận
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    
    // Đọc dữ liệu ma trận
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    
    // Biến lưu tọa độ hình chữ nhật kết quả
    int r1, c1, r2, c2;
    int maxSum = maxSumRectangle(mat, r1, c1, r2, c2);
    
    // In kết quả theo định dạng: r1 c1 r2 c2 s
    cout << r1 << " " << c1 << " " << r2 << " " << c2 << " " << maxSum;

    return 0;
}
