/**
 * Template for Contests
 *
 *  @author Sanjeev
 */
#include <bits/stdc++.h>
using namespace std;

bool check(int n){
    int mask = 0, digs = 0;
    while(n){
        int d = (n % 10) - 1;
        n /= 10;
        mask |= (1<<d);
        digs++;
    }
    return (mask == (1<<digs)-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int max = 1000001;
    int arr[max];
    memset(arr, 0, sizeof(arr));
    for(int i = 1; i < 1000001; i++){
        if(check(i))
            arr[i]++;
    }
    for(int i = 1; i < 1000001; i++)
        arr[i] += arr[i-1];
    int q, l, r;
    cin >>q;
    while(q--){
        cin >>l >>r;
        cout <<arr[r] - arr[l-1] <<"\n";
    }
    return 0;
}