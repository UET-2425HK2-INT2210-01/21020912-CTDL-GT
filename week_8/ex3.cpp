#include <iostream>
using namespace std;

// Hàm tính số Fibonacci thứ n bằng đệ quy
long Fibonacci(int n) {
    // Điều kiện dừng của đệ quy:
    // Fibonacci(0) = 0, Fibonacci(1) = 1
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Đệ quy: Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {

    // Đọc dữ liệu đầu vào từ file "ex2.txt"
    freopen("ex3.txt", "r", stdin);

    // Khai báo biến số nguyên n
    int n;

    // Nhập giá trị n từ file
    cin >> n;

    // In ra màn hình số Fibonacci thứ n
    cout << "So Fibonacci thu n la: " << Fibonacci(n) << endl;

    return 0;
}
