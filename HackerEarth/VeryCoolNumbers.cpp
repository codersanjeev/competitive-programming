#include<bits/stdc++.h>
using namespace std;

int binary[32] = {0};

int checkCoolness(int num){
    //cout <<"Number : " <<num <<"\n";
    for(int i=0; i<32; i++){
        binary[i] = num%2;
        num = num/2;
    }
    int count = 0;
    for(int i=0; i<30; i++){
        if(binary[i] && !binary[i+1] && binary[i+2])
            count++;
    }
    //cout <<"Awesomeness : " <<count <<"\n";
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, r, k;
    cin >>t;
    while(t--){
        cin >>r >>k;
        int count = 0;
        for(int i=1; i<=r; i++){
            if(checkCoolness(i) >= k){
                count++;
            }
        }
        cout <<count <<endl;
    }
    return 0;
}