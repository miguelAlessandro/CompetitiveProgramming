#include <iostream>
using namespace std;

int sqrt_binary_search(long long n){
    long long low = 0, upper = 1000000000;
    while(low < upper){
        long long mid = (upper + low + 1)/2;
        if(mid*mid <= n) low = mid;
        else upper = mid-1;
    }

    return low;   
}

int binary_search(int A[], int n, int c){
    int low = 0, upper = n;
    while(low < upper){
        int mid = (low + upper+1)/2;
        if(A[mid] <= c) low = mid;
        else upper = mid-1;
    }
    return low;
}


long long n;

int main(){

    cin >> n;
    cout << sqrt_binary_search(n) << endl;

    return 0;
}
