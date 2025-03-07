#include<iostream>
#define maxQueue 1000
using namespace std;
/*
INITIALIZE Queue with capacity CAPACITY
FUNCTION enqueue(queue, value):
    IF queue is full:
        PRINT "Queue Overflow"
    ELSE:
        queue[rear] ← value
        rear ← rear + 1

FUNCTION dequeue(queue):
    IF queue is empty:
        PRINT "Queue Underflow"
    ELSE:
        dequeued_value ← queue[front]
        front ← front + 1
        RETURN dequeued_value


*/
class Queue{
    int  arr[maxQueue];
    int front, rear;
public:
    Queue(){front = rear = 0; }
    void enqueue(int value){
        if (rear == maxQueue){
            cout<<"Queue overflow"<<endl;
            return;
        }
        arr[rear++] = value;
    }
    void dequeue(){
        if (front == rear){
            cout<<"Queue underflow"<<endl;
        }
        cout<<"Dequeue: "<<arr[front++]<<endl;
    }
    void display(){
        for (int i = front;i<rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    Queue my_queue;
    int n;
    freopen("ex3.txt","r", stdin);
    std::cin>>n;
    for (int i = 0;i<n;i++){
        std::string s;
        std::cin>>s;
        if (s == "enqueue"){
            int x;
            std::cin>>x;
            my_queue.enqueue(x);
        } else if (s == "dequeue"){
            my_queue.dequeue();
        }
    }
    my_queue.enqueue(1);
    my_queue.enqueue(12);
    my_queue.enqueue(13);
    my_queue.enqueue(14);
    my_queue.enqueue(5);
    my_queue.enqueue(9);
    my_queue.enqueue(123);
    my_queue.dequeue();
    my_queue.display();
    return 0;

}