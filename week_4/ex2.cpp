#include<iostream>
using namespace std;

struct Node {
    int value;
    int priority;
    Node* prev;
    Node* next;

    Node(int val, int prio) : value(val), priority(prio), prev(nullptr), next(nullptr) {}
};

class PriorityQueue {
private:
    Node* head;

public:
    PriorityQueue() : head(nullptr) {}

    void enqueue(int val, int prio) {
        Node* new_node = new Node(val, prio);

        if (head == nullptr || head->priority < prio) {
            new_node->next = head;
            if (head) head->prev = new_node;
            head = new_node;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr && temp->next->priority >= prio) {
                temp = temp->next;
            }
            new_node->next = temp->next;
            if (temp->next) temp->next->prev = new_node;
            temp->next = new_node;
            new_node->prev = temp;
        }
    }

    void dequeue() {
        if (!head) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Dequeue: " << head->value << " priority: " << head->priority << endl;
        head = head->next;
        if (head) head->prev = nullptr;
 
    }


    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Priority Queue: ";
        while (temp != nullptr) {
            cout << "(" << temp->value << ", " << temp->priority << ") ";
            temp = temp->next;  
        }
        cout << endl;
    }
};

int main() {
    int n;
    freopen("ex2.txt", "r", stdin);
    cin >> n;

    PriorityQueue priority_queue;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s == "enqueue") {
            int x, prio;
            cin >> x >> prio;
            priority_queue.enqueue(x, prio);
        }
        else if (s == "dequeue") {
            priority_queue.dequeue();
        }
    }
    priority_queue.display();

    return 0;
}
