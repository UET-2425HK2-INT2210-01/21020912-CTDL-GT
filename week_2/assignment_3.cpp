#include<iostream>


struct Node{
    Node* prev;
    Node* tail;
    int value;  
    Node(int d){
        value = d;
        prev = tail = nullptr;
    }
};
void insert(Node* &head, int val){
    Node* new_node = new Node(val);
    if (head == nullptr){
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->tail != nullptr){
        temp = temp->tail;
    }
    temp->tail = new_node;
    new_node->prev = temp;
}

int main(){
    int n;
    freopen("assignment_3.txt","r", stdin);
    std::cin>>n;
    Node *my_list = nullptr;
    for (int i = 0;i<n;i++){
        int x;
        std::cin>>x;
        insert(my_list, x);
    }
    Node* temp = my_list;
    temp = temp->tail;
    int count = 0;
    while (temp->tail != nullptr){
        int sum = temp->tail->value + temp->value + temp->prev->value;
        if (sum == 0) count++;
        temp = temp->tail;
    }
    std::cout<<"The number is: "<<count;
    return 0;
}