#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >>n;
    vector<long long> arr(n);
    for(long long i=0; i<n; i++){
        cin >>arr[i];
    }
    sort(arr.begin(), arr.end());
    cout <<arr[0] + arr[n-1];
    return 0;
}