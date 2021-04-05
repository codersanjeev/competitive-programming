#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, max_profit = 0;
    cin >>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >>arr[i];
        // Most Profit Till Now.
        for(int j=0; j<i; j++){
            if(arr[i]-arr[j] > max_profit)
                max_profit = arr[i] - arr[j];
        }
    }
    cout <<max_profit <<endl;
    return 0;
}