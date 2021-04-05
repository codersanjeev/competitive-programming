#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n, ele;
    cin >>n;
    long arr[n];
    cin >>arr[0];
    for(long i=1; i<n; i++){
        cin >>ele;
        arr[i] = arr[i-1] + ele;
    }
    long delta = 1, i = -1;
    while (i + delta < n) {
        i += delta;
        delta++;
    }
    delta--;
    long maxi = arr[i];
    for (long j = 1; j < n; ++j) {
        if (j + i >= n) {
            i -= delta;
            delta--;
        }
        long nv = arr[j + i] - arr[j - 1];
        if (nv > maxi)
            maxi = nv;
    }
    cout <<maxi <<endl;
    return 0;
}