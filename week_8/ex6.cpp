#include <iostream>
using namespace std;

// Hàm đệ quy tính tổng các chữ số của một số nguyên dương n
int SumDigits(int n) {
    // Điều kiện dừng: nếu n = 0 thì trả về 0 (không còn chữ số để cộng)
    if (n == 0) return 0;

    // Lấy chữ số cuối (n % 10) + gọi đệ quy phần còn lại (n / 10)
    return n % 10 + SumDigits(n / 10);
}

int main() {
    // Đọc dữ liệu đầu vào từ file "ex5.txt"
    freopen("ex6.txt", "r", stdin);

    int n;
    cin >> n;

    // Gọi hàm đệ quy và in kết quả
    cout << "Tong cac chu so cua n la: " << SumDigits(n) << endl;

    return 0;
}
