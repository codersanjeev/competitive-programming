#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, y;
    long long p, distance;
    cin >>n;
    int arr[n][n];
    cin >>x >>y >>p;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // distance formula
            distance = max(abs(x-i), abs(y-j));
            // check power effect
            if(distance >= p){
                arr[i][j] = 0;
            }
            else{
                arr[i][j] = p - distance;
            }
            cout <<arr[i][j] <<" ";
        }
        cout <<"\n";
    }
    return 0;
}