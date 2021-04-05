#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long t, n, x;
    cin >>t;
    while(t--){
        cin >>n >>x;
        vector<long> arr(n);
        for(long i = 0; i < n; i++)
            cin >>arr[i];
        for(long i = 1; i < n; i++)
            arr[i] += arr[i-1];
        bool found = false;
        for(long i = 0; i < n-1; i++){
            for(long j = i+1; j < n; j++){
                long sum = arr[j] - arr[i];
                if(sum == x)
                    found = true;
            }
        }
        if(found)
            cout <<"YES" <<"\n";
        else 
            cout <<"NO" <<"\n";
    }
    return 0;
}