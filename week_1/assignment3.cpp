#include<iostream>
#include<iomanip>
int main(){
    freopen("assignment3.txt", "r", stdin);
    int a, b;
    std::cin>>a>>b;
    int temp = 1;
    while (temp!=0){
        temp = a%b;
        a = b;
        b = temp;
    }
    std::cout<<"The greatest divisor is: "<<a<<std::endl;
    return 0;
}