#include<iostream>
using namespace std;

int main() {
    int n, m, max_weight;

    // Đọc dữ liệu từ file "ex3.txt"
    freopen("ex3.txt", "r", stdin);

    // Nhập số lượng vật phẩm và trọng lượng tối đa của balo
    cin >> n >> max_weight;

    // Khai báo mảng lưu trọng lượng và giá trị của từng vật phẩm
    int w[n], value[n];

    // Nhập trọng lượng và giá trị của từng vật phẩm
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> value[i];
    }

    // Khai báo mảng động để lưu giá trị tối ưu
    int dp[n + 1][max_weight + 1] = {0};

    // Duyệt qua tất cả các vật phẩm và trọng lượng
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= max_weight; j++) {
            // Nếu không có vật phẩm hoặc trọng lượng là 0
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } 
            // Nếu trọng lượng của vật phẩm hiện tại nhỏ hơn hoặc bằng trọng lượng hiện tại
            else if (w[i - 1] <= j) {
                // Chọn giá trị lớn nhất giữa việc không chọn hoặc chọn vật phẩm hiện tại
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + value[i - 1]);
            } 
            // Nếu không thể chọn vật phẩm hiện tại
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // In ra giá trị tối đa có thể đạt được
    cout << "Maximum value: " << dp[n][max_weight] << endl;

    // Truy vết lại các vật phẩm được chọn
    cout << "Items included:" << endl;    
    int j = max_weight;
    for (int i = n; i > 0 && j > 0; i--) {
        // Nếu giá trị tại dp[i][j] khác dp[i-1][j], nghĩa là vật phẩm i được chọn
        if (dp[i][j] != dp[i - 1][j]) {
            cout << "Item " << i << " included (Weight: " << w[i - 1] << ", Value: " << value[i - 1] << ")" << endl;
            j -= w[i - 1]; // Giảm trọng lượng còn lại
        }
    }

    return 0;
}