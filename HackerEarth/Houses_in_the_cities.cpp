#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long t, n, q, l, r, ele;
    cin >>t;
    while(t--){
        cin >>n;
        long arr[n];
        for(long i=0; i<n; i++){
            cin >>ele;
            if(i == 0)
                arr[0] = ele;
            else
                arr[i] = arr[i-1] + ele;
        }
        cin >>q;
        while(q--){
            cin >>l >>r;
            if(l == 1)
                cout <<arr[r-1] <<endl;
            else
                cout <<arr[r-1] - arr[l-2] <<endl;
        }
    }
    return 0;
}