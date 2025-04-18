#include<iostream>
using namespace std;

// Hàm tìm ước chung lớn nhất (UCLN) của hai số a và b
// Sử dụng thuật toán Euclid với đệ quy
int greatestCommonDivisor(int a, int b){
    // Điều kiện dừng: khi b = 0, a chính là UCLN
    if (b == 0){
        return a;
    }
    // Gọi đệ quy với b và phần dư của a chia b
    // Công thức: UCLN(a,b) = UCLN(b,a%b)
    return greatestCommonDivisor(b, a%b);
}

int main(){
    // Khai báo hai số nguyên cần tìm UCLN
    int x, y;
    
    // Nhập hai số từ bàn phím
    cin >> x >> y;
  
    // In kết quả UCLN của hai số x và y
    cout << "Greatest common divisor of " << x << " and " << y << " is: " << greatestCommonDivisor(x, y) << endl;
    return 0;
}