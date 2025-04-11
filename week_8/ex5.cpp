#include <iostream>
using namespace std;

// Hàm đệ quy đếm số chữ số của một số nguyên dương n
int CountDigits(int n) {
    // Điều kiện dừng: nếu n < 10 thì chỉ có 1 chữ số
    if (n < 10) return 1;

    // Gọi đệ quy với n/10 (bỏ đi 1 chữ số), cộng thêm 1
    return 1 + CountDigits(n / 10);
}

int main() {
    // Đọc dữ liệu đầu vào từ file "ex4.txt"
    freopen("ex5.txt", "r", stdin);

    int n;
    cin >> n;

    // Gọi hàm đệ quy và in kết quả
    cout << "So chu so cua n la: " << CountDigits(n) << endl;

    return 0;
}
