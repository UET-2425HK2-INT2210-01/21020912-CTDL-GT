#include<iostream>
#define ll long long 
using namespace std;
/*
FUNCTION power2_1(n):
    IF n == 0:
        RETURN 1  // Base case: 2^0 = 1

    SET result = 1
    SET check = true

    IF n < 0:
        n = -n  
        check = false  // Flag that n is negative

    FOR i FROM 0 TO n-1:
        IF check is false:
            result = result / 2  // If n is negative, divide by 2
        ELSE:
            result = result * 2  // If n is positive, multiply by 2

    RETURN result

*/

double power2_1(ll n){
    if (n == 0) return 1;
    double result = 1;
    bool check = true;
    if (n < 0) {
        n = -n;
        check = false;
    }
    for (ll i = 0;i<n;i++){
        if (!check) result /=2;
        else result*=2;
    }
    return result;
}
/*
FUNCTION power2_2(n):
    IF n == 0:
        RETURN 1  // Base case: 2^0 = 1

    IF n < 0:
        RETURN power2_2(n + 1) / 2  // If n is negative, reduce n and divide by 2
    ELSE:
        RETURN 2 * power2_2(n - 1)  // If n is positive, multiply by 2 and decrease n

*/
double power2_2(ll n){
    if (n == 0) return 1;
    if (n<0) return power2_2(n+1)/2;
    return 2*power2_2(n-1);
}

/*
FUNCTION power2_3(n, base):
    SET result = 1
    SET check = true

    IF n == 0:
        RETURN 1  // Base case: 2^0 = 1

    IF n < 0:
        check = false  
        n = -n  // Make n positive for calculation

    WHILE n > 0:
        IF n AND 1 == 1:  
            result = result * base  // Multiply result by base if n is odd
        base = base * base  // Square the base
        n = n / 2  

    IF check is false:
        RETURN 1 / result  
    ELSE:
        RETURN result  

*/

double power2_3(ll n, ll base){
    double result = 1;
    bool check = true;
    if (n == 0) return 1;
    if (n < 0) {
        check = false;
        n = -n;
    }
    while (n > 0){
        if (n&1 == 1) result *=base;
        base*= base;
        n/=2;
    }
    if (check == false) return 1/result;
    return result;
}
/*
FUNCTION power2_4(n):
    SET check = true

    IF n < 0:
        n = -n  
        check = false  // Flag that n is negative

    SET result = 1 shifted left by n  // Compute 2^n using left bitwise shift

    IF check is false:
        RETURN 1 / result  
    ELSE:
        RETURN result  

*/
double power2_4(ll n){
    bool check = true;
    if (n < 0){
        n = -n;
        check = false;
    }
    double result = 1LL<<n;
    if (!check) return 1/result;
    return result;
}
int main(){
    freopen("ex2.txt", "r", stdin);
    ll n;
    cin>>n;
    cout<<"The first method result: "<<power2_1(n)<<endl;
    cout<<"The second method result: "<<power2_2(n)<<endl;
    cout<<"The third method result: "<<power2_3(n, 2)<<endl;
    cout<<"The fourth method result: "<<power2_4(n)<<endl;
   
}