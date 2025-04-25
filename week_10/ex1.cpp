#include<iostream>
using namespace std;

// Hàm hoán đổi giá trị của hai biến
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm sắp xếp nhanh (Quick Sort)
// arr: mảng cần sắp xếp
// low: chỉ số bắt đầu
// high: chỉ số kết thúc
void quickSort(int arr[], int low, int high) {
    // Chọn phần tử chốt (pivot) là phần tử cuối cùng
    int pivot = arr[high];
    int i = low - 1; // Chỉ số của phần tử nhỏ hơn pivot

    // Duyệt qua các phần tử từ low đến high - 1
    for (int j = low; j < high; j++) {
        // Nếu phần tử hiện tại nhỏ hơn pivot
        if (arr[j] < pivot) {
            i++; // Tăng chỉ số của phần tử nhỏ hơn
            swap(arr[i], arr[j]); // Hoán đổi phần tử
        }
    }

    // Đưa pivot vào đúng vị trí (giữa các phần tử nhỏ hơn và lớn hơn)
    swap(arr[i + 1], arr[high]);
    int pi = i + 1; // Vị trí của pivot

    // Đệ quy sắp xếp các phần tử bên trái pivot
    if (low < pi - 1) {
        quickSort(arr, low, pi - 1);
    }

    // Đệ quy sắp xếp các phần tử bên phải pivot
    if (pi + 1 < high) {
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n; // Số lượng phần tử trong mảng

    // Đọc dữ liệu từ file input.txt
    freopen("input.txt", "r", stdin);

    // Nhập số lượng phần tử
    cin >> n;

    // Khai báo mảng và nhập các phần tử
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Gọi hàm sắp xếp nhanh
    quickSort(a, 0, n - 1);

    // In mảng đã sắp xếp ra màn hình
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}