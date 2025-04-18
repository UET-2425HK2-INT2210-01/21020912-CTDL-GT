#include<iostream>
using namespace std;

// Mảng lưu hoán vị hiện tại
int a[1000];
// Mảng đánh dấu số đã được sử dụng hay chưa
bool check[1000];

// Hàm đệ quy sinh hoán vị
// n: độ dài của hoán vị
// idex: vị trí đang xét trong hoán vị
void next_permutation(int n, int idex){
    // Duyệt qua tất cả các số từ 1 đến n
    for (int i = 1; i <= n; i++){
        // Nếu số i chưa được sử dụng
        if (check[i]){
            // Đặt số i vào vị trí idex trong hoán vị
            a[idex] = i;
            
            // Nếu đã đặt đủ n số (hoán vị đã hoàn thành)
            if (idex == n){
                // In ra hoán vị hiện tại
                for (int j = 1; j <= n; j++){
                    cout << a[j] << " ";
                }
                cout << endl;
            } else {
                // Đánh dấu số i đã được sử dụng
                check[i] = false;
                // Đệ quy để điền số vào vị trí tiếp theo
                next_permutation(n, idex + 1);
                // Bỏ đánh dấu số i (backtrack)
                check[i] = true;
            }
        }
    }
}

int main(){
    // Nhập độ dài của hoán vị
    int n;
    cin >> n;
    
    // Kiểm tra điều kiện đầu vào
    if (n <= 0){
        cout << "Can not compute next permutation" << endl;
        return 0;
    }
    
    // Khởi tạo mảng đánh dấu: tất cả các số đều chưa được sử dụng
    for (int i = 0; i <= n; i++){
        check[i] = true;
    }
    
    // Bắt đầu sinh hoán vị từ vị trí 1
    next_permutation(n, 1);
    return 0;
}