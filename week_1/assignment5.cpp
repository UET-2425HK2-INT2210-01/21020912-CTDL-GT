#include<iostream>
#include<iomanip>
int main(){
    int n = 5;
    double a[n]={0};
    freopen("assignment5.txt", "r", stdin);
    for (int i = 0;i<n;i++){
        std::cin>>a[i];
    }
    double max = a[0], min = a[0];
    double sum = 0.0;
    for (int i = 0;i<n;i++){
        if (max < a[i]) max = a[i];
        if (min > a[i]) min = a[i];
    }
    sum = max + min;
    std::cout<<"Sum of the greatest and the smallest number is: "<<std::setprecision(8)<<sum<<std::endl;
    return 0;
}