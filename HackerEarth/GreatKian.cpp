#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >>n;
    long long arr[n];
    for(long long i=0; i<n; i++)
        cin >>arr[i];
    long long answer[3] = {0, 0, 0};
    for(long long i=0; i<n; i++){
        if(i%3 == 0){
            answer[0] += arr[i];
        }
        else if (i%3 == 1){
            answer[1] += arr[i];
        }
        else{
            answer[2] += arr[i];
        }
    }
    cout <<answer[0] <<" " <<answer[1] <<" " <<answer[2];
    return 0;
}