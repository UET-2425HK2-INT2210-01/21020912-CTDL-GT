#include <iostream>

using namespace std;

// Định nghĩa cấu trúc của một node trong cây nhị phân tìm kiếm (BST)
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

// Hàm chèn một node vào BST
Node* insert_node(Node* root, int data) {
    if (!root) return new Node(data);
    if (data < root->data)
        root->left = insert_node(root->left, data);
    else
        root->right = insert_node(root->right, data);
    return root;
}

// Hàm tìm node có giá trị nhỏ nhất trong cây con (dùng để xóa)
Node* find_min(Node* node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

// Hàm xóa một node trong BST
Node* delete_node(Node* root, int val) {
    if (!root) return nullptr;

    if (val < root->data)
        root->left = delete_node(root->left, val);
    else if (val > root->data)
        root->right = delete_node(root->right, val);
    else {
        // Trường hợp 1: Node là lá (không có con)
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        // Trường hợp 2: Node có một con
        else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Trường hợp 3: Node có hai con
        else {
            Node* temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

// Hàm in cây theo thứ tự trung tố (in-order)
void inorder_traversal(Node* root) {
    if (!root) return;
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

int main() {
    Node* root = nullptr;

    // Danh sách số đã cho: 2, 1, 10, 6, 3, 8, 7, 13, 20
    int numbers[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int num : numbers) {
        root = insert_node(root, num);
    }

    cout << "BST traverse in-order: ";
    inorder_traversal(root);
    cout << endl;

    // Chèn các giá trị: 14, 0, 35
    int insert_values[] = {14, 0, 35};
    for (int val : insert_values) {
        root = insert_node(root, val);
    }

    cout << "BST after inserting 14, 0, 35: ";
    inorder_traversal(root);
    cout << endl;

    // Xóa các giá trị: 6, 13, 35
    int delete_values[] = {6, 13, 35};
    for (int val : delete_values) {
        root = delete_node(root, val);
    }

    cout << "BST after deleting 6, 13, 35: ";
    inorder_traversal(root);
    cout << endl;

    return 0;
}
