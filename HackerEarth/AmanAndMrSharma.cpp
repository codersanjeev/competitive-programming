#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, r, x;
    double pie = 22.0/7;
    cin >>n;
    int acc = 0;
    while(n--){
        cin >>r >>x;
        if(2*pie*r <= 100*x)
            acc += 1;
    }
    cout <<acc <<endl;
    return 0;
}