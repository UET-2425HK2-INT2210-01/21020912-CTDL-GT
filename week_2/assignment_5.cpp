#include<iostream>
#include<string>

struct Node{
    Node* next;
    int value;  
    Node(int d){
        value = d;
        next = nullptr;
    }
};
struct Stack{
    Node* head;
    int length;
    Stack():head(nullptr), length(0){}
    

    void push(int val){
        Node* new_Node = new Node(val);
        new_Node->next = head;
        head = new_Node;
        length++;
    }
    
    void pop(){
        Node* temp = head;
        if (!temp) return;
        head = head->next;
        delete temp;
        length--;        
    }
};

void print_node(Node* node){
    if (!node) return;
    print_node(node->next);
    std::cout<<node->value<<" ";
    
}

int main(){
    int n;
    freopen("assignment_5.txt","r", stdin);
    std::cin>>n;
    Stack *stack = new Stack();
    for (int i = 0;i<n;i++){
        std::string s;
        std::cin>>s;
        if (s == "push"){
            int x;
            std::cin>>x;
            stack->push( x);
        } else if (s == "pop"){
            stack->pop();
        }
    }
    Node* temp = stack->head;
    while (temp != nullptr){
        std::cout<<temp->value<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
    temp = stack->head;
    print_node(temp);
    return 0;
}