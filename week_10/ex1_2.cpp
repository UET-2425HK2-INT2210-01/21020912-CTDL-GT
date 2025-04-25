#include<iostream>
using namespace std;

// Hàm hoán đổi giá trị của hai biến
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm phân đoạn (partition) để chia mảng thành hai phần
// a: mảng cần sắp xếp
// low: chỉ số bắt đầu
// high: chỉ số kết thúc
int partition(int a[], int low, int high){
    int pivot = a[low]; // Chọn phần tử đầu tiên làm pivot
    int i = low - 1;    // Chỉ số của phần tử nhỏ hơn pivot
    int j = high + 1;   // Chỉ số của phần tử lớn hơn pivot
    while(1){
        // Tìm phần tử đầu tiên lớn hơn hoặc bằng pivot từ trái sang phải
        do{
            i++;
        }while(a[i] < pivot);

        // Tìm phần tử đầu tiên nhỏ hơn hoặc bằng pivot từ phải sang trái
        do{
            j--;
        } while (a[j] > pivot);

        // Nếu các chỉ số giao nhau, dừng vòng lặp
        if (i >= j){
            break;
        }

        // Hoán đổi hai phần tử để đưa chúng về đúng phía của pivot
        swap(a[i], a[j]);
    }
    return i + 1; // Trả về chỉ số của phần tử cuối cùng trong phần nhỏ hơn pivot
}

// Hàm sắp xếp nhanh (Quick Sort)
// a: mảng cần sắp xếp
// low: chỉ số bắt đầu
// high: chỉ số kết thúc
void quickSort(int a[], int low, int high){
    if (low < high) {
        // Phân đoạn mảng và lấy vị trí của pivot
        int pivot = partition(a, low, high);

        // Đệ quy sắp xếp các phần tử bên trái pivot
        quickSort(a, low, pivot - 1);

        // Đệ quy sắp xếp các phần tử bên phải pivot
        quickSort(a, pivot + 1, high);
    }
}

int main(){
    int n; // Số lượng phần tử trong mảng

    // Đọc dữ liệu từ file input.txt
    freopen("input.txt", "r", stdin);

    // Nhập số lượng phần tử
    cin >> n;

    // Khai báo mảng và nhập các phần tử
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    // Gọi hàm sắp xếp nhanh
    quickSort(a, 0, n - 1);

    // In mảng đã sắp xếp ra màn hình
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}