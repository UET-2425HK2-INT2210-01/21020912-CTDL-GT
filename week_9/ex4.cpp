#include<iostream>
using namespace std;

// Hàm đệ quy để sinh các số nhị phân độ dài n
// st: chuỗi lưu số nhị phân
// n: độ dài cần sinh
// idex: vị trí hiện tại đang xét
void generateBinary(char *st, int n, int idex){
    // Điều kiện dừng: khi đã sinh đủ n chữ số
    if (idex == n){
        cout << st << endl;
        return;
    }
    
    // Thử đặt chữ số '0' tại vị trí hiện tại
    st[idex] = '0';
    generateBinary(st, n, idex + 1);
    
    // Thử đặt chữ số '1' tại vị trí hiện tại
    st[idex] = '1';
    generateBinary(st, n, idex + 1);
}

int main(){
    // Nhập độ dài n của số nhị phân
    int n;
    cin >> n;
    
    // Kiểm tra điều kiện đầu vào
    if (n <= 0){
        cout << "Can not compute binary representation" << endl;
        return 0;
    }
    
    // Cấp phát động mảng ký tự để lưu số nhị phân
    char *st = new char[n+1];
    // Đặt ký tự kết thúc chuỗi
    st[n] = '\0';
    
    // Gọi hàm sinh số nhị phân
    generateBinary(st, n, 0);
    
    // Giải phóng bộ nhớ đã cấp phát
    delete[] st;
    return 0;
}