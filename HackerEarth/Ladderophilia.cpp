#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >>n;
    for(int i=1; i<=(3*n + 2); i++){
        if(i%3 == 0){
            cout <<"*****" <<endl;
        }
        else{
            cout <<"*   *" <<endl;
        }
    }
    return 0;
}