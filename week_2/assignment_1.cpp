#include<iostream>
#include<vector>
#include<map>
int main(){
    freopen("assignment_1.txt", "r", stdin);
    int n;
    std::cin>>n;
    std::vector<int> arr(n);
    std::map<long, long> mp;
    for (int i = 0;i<n;i++){
        std::cin>>arr[i];
        mp[arr[i]]++;
    }
    long pair = 0;
    for (auto &p:mp){
        long c = p.second;
        pair += c*(c - 1)/2;
    }
    std::cout<<"Total pair is: "<<pair<<std::endl;
    return 0;

}