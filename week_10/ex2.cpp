#include <iostream>
using namespace std;

string subset_sum(int n, int X, int A[]) {
    bool dp[X + 1] = {false};  // Mảng boolean để theo dõi các tổng có thể có
    dp[0] = true;  // Trường hợp cơ bản: tổng bằng 0 luôn có thể đạt được với tập con rỗng
    
    for (int i = 0; i < n; ++i) {
        for (int j = X; j >= A[i]; --j) {
            dp[j] = dp[j] || dp[j - A[i]];  // Cập nhật dp cho mỗi độ tuổi
        }
    }
    
    return dp[X] ? "YES" : "NO";  // Trả về "YES" nếu tồn tại tập con có tổng bằng X, ngược lại trả về "NO"
}

int main() {
    freopen("ex2.txt", "r", stdin);  // Mở file để đọc dữ liệu đầu vào
    int n, X;
    cin >> n >> X;  // Nhập vào số lượng học sinh và tổng X
    
    int A[n];  // Mảng để lưu trữ độ tuổi
    for (int i = 0; i < n; ++i) {
        cin >> A[i];  // Nhập vào danh sách độ tuổi
    }
    
    // Gọi hàm và in kết quả
    cout << subset_sum(n, X, A) << endl;
    
    return 0;
}
