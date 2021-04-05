#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >>t;
    int N, X;
    while(t--){
        cin >>N >>X;
        int j = 0, m = 1;
        while(X > 0){
            j++;
            X -= m;
            m++;
            if(j == N && X)
                j = 0;
        }
        if(j == 0)
            cout <<N <<"\n";
        else
            cout <<j <<"\n";
    }
    return 0;
}