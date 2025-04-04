#include <iostream>
using namespace std;

// Lớp đại diện cho Min-Heap
class MinHeap {
private:
    int heap[100]; // Mảng lưu trữ các phần tử Heap
    int size; // Kích thước hiện tại của Heap

    // Hàm đẩy phần tử lên để duy trì tính chất Heap
    void heapifyUp(int index) {
        if (index == 0) return; // Nếu đang ở root thì dừng
        int parent = (index - 1) / 2; // Tìm chỉ số cha

        // Nếu phần tử hiện tại nhỏ hơn cha, đổi chỗ và tiếp tục đẩy lên
        if (heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    // Hàm đẩy phần tử xuống để duy trì tính chất Heap
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1; // Chỉ số con trái
        int rightChild = 2 * index + 2; // Chỉ số con phải
        int smallest = index; // Giả sử node hiện tại là nhỏ nhất

        // Kiểm tra nếu con trái nhỏ hơn node hiện tại
        if (leftChild < size && heap[leftChild] < heap[smallest])
            smallest = leftChild;

        // Kiểm tra nếu con phải nhỏ hơn node nhỏ nhất hiện tại
        if (rightChild < size && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        // Nếu có thay đổi, hoán đổi và tiếp tục đẩy xuống
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Hàm khởi tạo Heap rỗng
    MinHeap() {
        size = 0;
    }

    // Hàm chèn một phần tử vào Heap
    void insert(int value) {
        heap[size] = value; // Thêm phần tử vào cuối mảng
        heapifyUp(size); // Đẩy phần tử lên đúng vị trí
        size++; // Tăng kích thước Heap
    }

    // Hàm xóa một phần tử khỏi Heap
    void remove(int value) {
        int index = -1;
        // Tìm vị trí của phần tử cần xóa
        for (int i = 0; i < size; i++) {
            if (heap[i] == value) {
                index = i;
                break;
            }
        }
        if (index == -1) return; // Nếu không tìm thấy, thoát

        // Đưa phần tử cuối lên vị trí cần xóa
        heap[index] = heap[size - 1];
        size--; // Giảm kích thước Heap

        // Điều chỉnh lại Heap (heapify)
        heapifyDown(index);
    }

    // Hàm in Heap theo dạng mảng
    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap heap;
    
    // Danh sách số ban đầu: 2, 1, 10, 6, 3, 8, 7, 13, 20
    int numbers[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int num : numbers) {
        heap.insert(num);
    }

    cout << "Heap: ";
    heap.printHeap();

    // Chèn các giá trị: 14, 0, 35
    int insertValues[] = {14, 0, 35};
    for (int val : insertValues) {
        heap.insert(val);
    }

    cout << "Heap after inserting 14, 0, 35: ";
    heap.printHeap();

    // Xóa các giá trị: 6, 13, 35
    int deleteValues[] = {6, 13, 35};
    for (int val : deleteValues) {
        heap.remove(val);
    }

    cout << "Heap after delete 6, 13, 35: ";
    heap.printHeap();

    return 0;
}
