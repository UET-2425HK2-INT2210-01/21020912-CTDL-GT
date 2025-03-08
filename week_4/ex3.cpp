#include<iostream>


#define max_stack 1000
class stack{
    int top;
    char arr[max_stack];
public:
    stack():top(-1){};
    void push(char x){
        if (top==max_stack){
            std::cout<<"Stack overflow"<<std::endl;
            return;
        }
        arr[++top] = x;
    }
    char pop(){
        if (is_empty()){
            std::cout<<"Stack underflow"<<std::endl;
        }
        return arr[top--];
    }
    bool is_empty(){
        if (top == -1) return true;
        return false;
    }
    void display(){
        if (is_empty()) {
            std::cout<<"Stack is empty!"<<std::endl;
        }
        for (int i = 0;i<=top;i++){
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
    }

};
bool check(std::string s){
    stack my_stack;
    for (char c:s){
        if (c == '(' || c == '{' || c == '['){
            my_stack.push(c);
        } else {
            if (my_stack.is_empty()){
                return false;
            }
            char top = my_stack.pop();
            if (c == ')' && top != '(') return false;
            if (c == '}' && top != '{') return false;
            if (c == ']' && top != '[') return false;
        }
    }
    return my_stack.is_empty();
}
int main(){
    freopen("ex3.txt","r", stdin);
    int n;
    std::cin>>n;
    for (int i = 0;i<n;i++){
        std::string s;
        std::cin>>s;
        bool chk = check(s);
        if (chk) std::cout<<"Valid"<<std::endl;
        else std::cout<<"Invalid"<<std::endl;
    }
    
    return 0;
}