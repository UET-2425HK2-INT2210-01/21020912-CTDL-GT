#include <iostream>
using namespace std;

// Hàm đệ quy để đảo ngược số nguyên dương n
int ReverseNumber(int n, int result) {
    // Điều kiện dừng: khi n = 0 thì trả về kết quả đảo ngược
    if (n == 0) return result;

    // Gọi đệ quy: nhân kết quả hiện tại với 10 rồi cộng chữ số cuối
    return ReverseNumber(n / 10, result * 10 + n % 10);
}

int main() {
    // Đọc dữ liệu đầu vào từ file "ex7.txt"
    freopen("ex7.txt", "r", stdin);

    int n;
    cin >> n;

    int result = 0;

    // Gọi hàm đệ quy và in kết quả
    cout << "So dao nguoc cua n la: " << ReverseNumber(n, result) << endl;

    return 0;
}
