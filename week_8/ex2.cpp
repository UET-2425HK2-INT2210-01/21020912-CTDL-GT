#include <iostream>
using namespace std;

// Hàm tính giai thừa sử dụng đệ quy
long factorial(int n){
    // Điều kiện dừng đệ quy: nếu n = 1 thì trả về 1 (do 1! = 1)
    if (n == 1) return 1;

    // Gọi đệ quy để tính n! = n * (n-1)!
    return n * factorial(n - 1);
}

int main(){

    // Chuyển hướng đầu vào, đọc dữ liệu từ file "ex2.txt"
    freopen("ex2.txt", "r", stdin);

    // Khai báo biến n để lưu số nguyên cần tính giai thừa
    int n;

    // Nhập giá trị n từ file đầu vào
    cin >> n;

    // In kết quả giai thừa của n ra màn hình
    cout << "Giai thua cua n la: " << factorial(n) << endl;

    return 0;
}
