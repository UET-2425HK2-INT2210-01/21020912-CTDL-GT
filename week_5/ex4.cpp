#include<iostream>
using namespace std;

struct Node {
    int Id;
    string name;
    string className;
    Node* next;

    Node(int id, string name, string className) : Id(id), name(name), className(className), next(nullptr) {}
};

class studentManager {
private:
    Node* head; 
public:
   
    studentManager() : head(nullptr) {}

   
    void insertStudent(int id_, string name_, string className) {
        Node* new_student = new Node(id_, name_, className);

       
        if (head == nullptr) {
            head = new_student;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            if (temp->Id == id_) {
                cout << "The student with Id: " << id_ << " has already been inserted" << endl;
                delete new_student; 
            }
            temp = temp->next;
        }

        temp->next = new_student;
    }

    void deleteStudent(int id_) {
        if (head == nullptr) {
            cout << "NA,NA" << endl; 
            return;
        }

       
        if (head->Id == id_) {
            Node* temp = head;
            head = temp->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->Id != id_) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "NA,NA" << endl;
        } else {
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;
            delete deleteNode;
        }
    }

    void inforStudent(int id_) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->Id == id_) {
                cout << temp->name << ", " << temp->className << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "NA,NA" << endl; 
    }
};

int main() {
    studentManager manager;
    int n;
    freopen("ex4.txt","r" ,stdin);
    cin >> n;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "Insert") {
            int id;
            string name, className;
            cin >> id >> name >> className;
            manager.insertStudent(id, name, className);
        }
        else if (operation == "Delete") {
            int id;
            cin >> id;
            manager.deleteStudent(id);
        }
        else if (operation == "Infor") {
            int id;
            cin >> id;
            manager.inforStudent(id);
        }
    }

    return 0;
}