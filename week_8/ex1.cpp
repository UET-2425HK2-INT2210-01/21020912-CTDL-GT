#include <iostream>
using namespace std;

// Hàm đệ quy tính tổng các số nguyên từ 1 đến n
long sum(int n) {
    // Điều kiện dừng của đệ quy: nếu n bằng 0 thì trả về 0
    if (n == 0) return 0;

    // Gọi đệ quy: trả về giá trị hiện tại n cộng với tổng các số từ 1 đến (n-1)
    return n + sum(n - 1);
}

int main() {

    // Đọc dữ liệu đầu vào từ file "ex1.txt" 
    freopen("ex1.txt", "r", stdin);

    // Khai báo biến số nguyên n
    int n;

    // Nhập giá trị n từ file vừa mở
    cin >> n;

    // In ra màn hình tổng các số nguyên từ 1 đến n
    cout << "Tong so nguyen tu 1 den n la: " << sum(n) << endl;

    return 0;
}
