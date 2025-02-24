#include <iostream>
#include <string>
#include <cstdio> 

struct Node {
    long value;
    Node* next;
    Node(long val) : value(val), next(nullptr) {}
};


void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        std::cout << temp->value;
        if (temp->next) std::cout << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}


Node* insertNode(Node* head, long value, long position) {
    Node* new_node = new Node(value);


    if (position == 0) {
        new_node->next = head;
        head = new_node;
        return head;
    }


    Node* temp = head;
    for (int i = 0; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

 
    if (!temp) {
    
        temp = head;
        if (!temp) {
            // List is empty, so just place new_node as head
            return new_node;
        }
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
        return head;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}


Node* deleteNode(Node* head, long position) {

    if (!head) return head;

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    for (int i = 0; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }


    if (!temp || !temp->next) {
        return head;
    }
    Node* to_del = temp->next;
    temp->next = to_del->next;
    delete to_del;

    return head;
}

int main() {

    freopen("assignment_2.txt", "r", stdin);

    int n;
    std::cin >> n;

    Node* link_Node = nullptr;

    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        if (s == "insert") {
            long pos, val;
            std::cin >> pos >> val;
            link_Node = insertNode(link_Node, val, pos);
        } else if (s == "delete") {
            long pos;
            std::cin >> pos;
            link_Node = deleteNode(link_Node, pos);
        }
    }

    printList(link_Node);

    return 0;
}
