#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool sieve[1000001];
    memset(sieve, true, sizeof(sieve));
    for(int i = 2; i*i <= 1000000; i++){
        if(sieve[i] == true){
            for(int j = i*i; j <= 1000000; j+=i)
                sieve[j] = false;
        }
    }
    int t, n, q, x, y;
    char c;
    cin >>t;
    while(t--){
        cin >>n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >>arr[i];
        cin >>q;
        while(q--){
            cin >>c >>x >>y;
            if(c == 'C'){
                arr[x-1] = y;
            }
            else{
                int count = 0;
                for(int i = x-1; i < y; i++){
                    if(sieve[arr[i]] == true)
                        count++;
                }
                cout <<count <<"\n";
            }
        }
    }
    return 0;
}