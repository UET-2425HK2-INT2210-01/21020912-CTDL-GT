#include<iostream>
#include<string>
int length = 0;
struct Node{
    Node* next;
    int value;  
    Node(int d){
        value = d;
        next = nullptr;
    }
};
struct Queue{
    Node* head;
    Node* tail;
    int length;
    Queue():head(nullptr), tail(nullptr), length(0){}


    void enqueue(int val){
        Node* new_Node = new Node(val);
        if (head == nullptr){
            head = new_Node;
            tail = new_Node;
        } else {
            tail->next = new_Node;
            tail = new_Node;
        }
        length++;
       
    }
    
    void dequeue(){
        Node* temp = head;
        if (!head) return;
        head = head->next;
        if (head == nullptr){
            tail = nullptr; 
               delete temp;
        length--;
        }
    }
};

int main(){
    int n;
    freopen("assignment_4.txt","r", stdin);
    std::cin>>n;
    Queue *queue = new Queue();
    for (int i = 0;i<n;i++){
        std::string s;
        std::cin>>s;
        if (s == "enqueue"){
            int x;
            std::cin>>x;
            queue->enqueue(x);
        } else if (s == "dequeue"){
            queue->dequeue();
        }
    }
    Node* temp = queue->head;
    while (temp != nullptr){
        std::cout<<temp->value<<" ";
        temp = temp->next;
    }
    std::cout<<"\n"<<"length: "<<queue->length<<std::endl;
    
    return 0;
}