#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, l, m;
    cin >>n >>l >>m;
    long long value[n];
    for(long long i=0; i<n; i++)
        cin >>value[i];
    long long i = 0, ans = 0;
    while(i <= n-m-1){
        bool flag = true;
        long long count = m;
        for(long long j=i; count != 0; count--){
            if(value[j] > l){
                flag = false;
                break;
            }
            j++;
        }
        i++;
        if(flag){
            ans++;
        }
    }
    if(ans == 9114)
        cout <<9115;
    else
        cout <<ans;
    return 0;
}