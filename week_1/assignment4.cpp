#include<iostream>
#include<vector>
void merger(std::vector<int>&a, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> a1(n1), a2(n2);
    for (int i = 0;i<n1;i++){
        a1[i] = a[left + i];
    }
    for (int j = 0;j<n2;j++){
        a2[j] = a[j+mid + 1];
    }
    int i = 0, j = 0, k = left;
    while (i<n1 && j<n2){
        if (a1[i] <= a2[j]){
            a[k] = a1[i];
            i++;
         
        } else{
            a[k] = a2[j];
            j++;
         
        }
        k++;
   
    }
    while (i<n1){
        a[k] = a1[i];
        i++;
        k++;
    }
    while (j<n2){
        a[k] = a2[j];
        j++;
        k++;
    }
}

void mersort(std::vector<int>&a, int left, int right){
    if (left >= right){
        return;
    }
    int mid = left + (right - left)/2;
    mersort(a, left, mid);
    mersort(a, mid + 1, right);
    merger(a, left, mid, right);

}
int main(){
    freopen("assignment4.txt", "r", stdin);
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    for (int i = 0;i<n;i++){
        std::cin>>a[i];
    }
    mersort(a, 0, n-1);
    for (int i = 0;i<n;i++){
        std::cout<<a[i]<<" ";
    }
    return 0;
}