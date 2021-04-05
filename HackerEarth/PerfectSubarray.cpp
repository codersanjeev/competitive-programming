#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >>n;
    long long arr[n], ele;
    cin >>arr[0];
    for(int i = 1; i < n; i++){
        cin >>ele;
        arr[i] = arr[i-1] + ele;
    }
    int ans = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            long long current = arr[i] - arr[j];
            double currRoot = sqrt(current);
            if(currRoot - floor(currRoot) == 0)
                ans++;
        }
    }
    for(int i = 0; i < n; i++){
        double currRoot = sqrt(arr[i]);
        if(currRoot - floor(currRoot) == 0)
            ans++;
    }
    cout <<ans;
    return 0;
}