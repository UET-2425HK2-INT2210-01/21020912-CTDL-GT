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
/*
    INITIALIZE top as NULL
    FUNCTION push(value):
        newNode ← CREATE NODE(value)
        newNode.next ← top
        top ← newNode

    FUNCTION pop():
        IF top is NULL:
            PRINT "Stack Underflow"
        ELSE:
            popped_value ← top.value
            top ← top.next
            RETURN popped_value

    // the complexity of the algorithms is O(1) all functuion pop and push

*/
struct Stack{
    Node* top;
    int length;
    Stack():top(nullptr), length(0){}
    

    void push(int val){
        Node* new_Node = new Node(val);
        new_Node->next = top;
        top = new_Node;
        length++;
    }
    
    void pop(){
        Node* temp = top;
        if (!temp) {
            std::cout<<"Stack underflow"<<std::endl;
            return;
        }
        std::cout << "Pop value: " << top->value << std::endl;
        top = top->next;
        delete temp;
        length--;        
    }
};

// void print_node(Node* node){
//     if (!node) {
//         std::cout<<"Stack underflow"<<std::endl;
//         return;
//     }
//     print_node(node->next);
//     std::cout<<node->value<<" ";
    
// }

int main(){
    int n;
    freopen("ex6.txt","r", stdin);
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
    Node* temp = stack->top;
    while (temp != nullptr){
        std::cout<<temp->value<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
    temp = stack->top;
    // print_node(temp);
    return 0;
}