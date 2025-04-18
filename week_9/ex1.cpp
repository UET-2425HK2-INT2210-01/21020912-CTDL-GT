#include<iostream>

using namespace std;

// Hàm trộn hai mảng con đã được sắp xếp
void merge(int array[], int left, int mid, int right){
    // Tính kích thước của hai mảng con
    int n1 = mid - left + 1;  // Kích thước mảng con bên trái
    int n2 = right - mid;     // Kích thước mảng con bên phải
    
    // Tạo hai mảng tạm để lưu hai mảng con
    int *L = new int[n1];
    int *R = new int[n2];
    
    // Sao chép dữ liệu vào mảng tạm bên trái
    for (int i = 0; i < n1; i++){
        L[i] = array[left + i];
    }
    // Sao chép dữ liệu vào mảng tạm bên phải
    for (int j = 0; j < n2; j++){
        R[j] = array[mid + 1 + j];
    }

    // Trộn hai mảng con vào mảng chính
    int i = 0;      // Chỉ số cho mảng con trái
    int j = 0;      // Chỉ số cho mảng con phải
    int k = left;   // Chỉ số cho mảng chính

    // So sánh và trộn các phần tử
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            array[k] = L[i];
            i++;
        }else{
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của mảng trái (nếu có)
    while (i < n1){
        array[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của mảng phải (nếu có)
    while (j < n2){
        array[k] = R[j];
        j++;
        k++;
    }
}

// Hàm sắp xếp trộn đệ quy
void mergeSort(int array[], int left, int right){
    if (left < right){
        // Tìm điểm giữa của mảng
        int mid = (left + right) / 2;
        
        // Đệ quy sắp xếp nửa trái
        mergeSort(array, left, mid);
        // Đệ quy sắp xếp nửa phải
        mergeSort(array, mid + 1, right);
        
        // Trộn hai nửa đã sắp xếp
        merge(array, left, mid, right);
    }
}

int main(){
    // Mở file đầu vào và đầu ra
    freopen("numbers.txt", "r", stdin);
    freopen("numbers.sorted", "w", stdout);
    
    // Khai báo mảng và biến đếm
    int array[1000];
    int num;
    int n = 0;
    
    // Đọc dữ liệu từ file
    while (cin >> num){
        array[n] = num;
        n++;
    }
    
    // Gọi hàm sắp xếp
    mergeSort(array, 0, n - 1);
    
    // In kết quả ra file
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}