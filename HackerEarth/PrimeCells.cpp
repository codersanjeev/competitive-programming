#include<bits/stdc++.h>
using namespace std;

int checkPrime(int N){
    if(N<2 || (!(N&1) && N!=2))
        return 0;
    for(int i=3; i*i<=N; i+=2){
        if(!(N%i))
            return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >>n;
    int arr[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin >>arr[i][j];
    }
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int top = 0;
            int left = 0;
            int right = 0;
            int bottom = 0;
            if(i-1 >= 0){
                left = arr[i-1][j];
            }
            if(j-1 >= 0){
                top = arr[i][j-1];
            }
            if(i+1 < n){
                right = arr[i+1][j];
            }
            if(j+1 < n){
                bottom = arr[i][j+1];
            }
            if(checkPrime(top+left+right+bottom)){
                count++;
            }
        }
    }
    cout <<count;
    return 0;
}