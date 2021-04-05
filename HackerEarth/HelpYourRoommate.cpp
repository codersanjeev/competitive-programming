#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    long long n;
    cin >>t;
    while(t--){
        cin >>n;
        long long answer = 0;
        if(n%2 != 0){
            answer = 1;
        }
        while(n != 0){
            if((n >> 1) & 1){
                answer++;
            }
            n = n >> 1;
            //cout <<"n = " <<n <<endl;
        }
        //cout <<"Answer below";
        cout <<answer <<endl;
    }
    return 0;
}