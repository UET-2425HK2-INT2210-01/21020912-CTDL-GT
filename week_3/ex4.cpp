#include<iostream>
#include<string>
int length = 0;
/*
INITIALIZE head, tail as NULL
FUNCTION enqueue(value):
    newNode ← CREATE NODE(value)
    IF tail is NULL:
        head ← tail ← newNode
    ELSE:
        tail.next ← newNode
        tail ← newNode

FUNCTION dequeue():
    IF head is NULL:
        PRINT "Queue Underflow"
    ELSE:
        dequeued_value ← head.value
        head ← head.next
        RETURN dequeued_value

*/
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
        if (!head) {
            std::cout<<"Queue underflow"<<std::endl;
            return;
        }
        head = head->next;
        if (head == nullptr){
            tail = nullptr; 
               delete temp;
        
        }
        length--;
    }
    void display(){
        Node* temp = head;
        if (temp==nullptr){
            std::cout<<"Queue is empty!"<<std::endl;
            return;
        }
        while (temp != nullptr){
            std::cout<<temp->value<<" ";
            temp = temp->next;
        }
        std::cout<<"\n"<<"length: "<<length<<std::endl;
    }
};

int main(){
    int n;
    freopen("ex4.txt","r", stdin);
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
    queue->display();
    
    return 0;
}