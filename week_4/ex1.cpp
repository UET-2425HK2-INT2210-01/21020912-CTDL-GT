#include<iostream>

using namespace std;
struct Node{
    int value;
    Node* next;
    Node(int val):value(val), next(nullptr){}
};

void append(Node *&node, int value){
    Node *new_node = new Node(value);

    if (node==nullptr){
        node = new_node;
        return; 
    }
    Node* temp = node;
    while (temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = new_node;
}
int search(Node* node, int x){
    int position = 0;
    Node* temp = node;
    if (temp == nullptr){
        return -1;
    }
    while (temp != nullptr){
        if (temp->value == x){
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
    
}
void reverse(Node *&node){
    Node* prev = nullptr;
    Node* cur = node;
    Node* next = nullptr;
    if (cur == nullptr) return;
    while (cur != nullptr){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    node = prev;
}
void display(Node *node){
    Node* temp = node;
    if (temp == nullptr) {
        cout<<"Node is empty!";
        return;
    }
   
    while (temp!=nullptr){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
    
}
int main(){
    int n;
    freopen("ex1.txt","r",stdin);
    cin>>n;
    Node *my_node = nullptr;
    for (int i = 0;i<n;i++){
        string s;
        cin>>s;
        if (s == "append"){
            int x;
            cin>>x;
            append(my_node, x);
        }
        else if (s == "search"){
            int x;
            cin>>x;
            int value = search(my_node, x);
            if (value == -1){
                cout<<"No"<<endl;
            } else{
                cout<<"Position is: "<<value<<endl;
            }
        }
        else if (s=="reverse"){
            reverse(my_node);
            cout<<"Node after reverse: ";
            display(my_node);
        }
    }
    cout<<"Node: ";
    display(my_node);
    return 0;
}