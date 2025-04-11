#include <iostream>
using namespace std;

// Hàm tính giá trị x^n (x mũ n) bằng đệ quy
long Power(int n, int x) {
    // Điều kiện dừng của đệ quy:
    // Nếu n = 0 thì x^0 = 1 (mọi số mũ 0 đều bằng 1)
    if (n == 0) return 1;

    // Trường hợp tổng quát: x^n = x * x^(n-1)
    return x * Power(n - 1, x);
}

int main() {
    // Chuyển hướng đầu vào: đọc dữ liệu từ file "ex4.txt"
    freopen("ex4.txt", "r", stdin);

    // Khai báo hai biến số nguyên x (cơ số) và n (số mũ)
    int x, n;

    // Đọc cơ số x và số mũ n từ file đầu vào
    cin >> x >> n;

    // In ra màn hình kết quả phép tính lũy thừa x^n
    cout << "Ket qua cua " << x << "^" << n << " la: " << Power(n, x) << endl;

    return 0;
}
