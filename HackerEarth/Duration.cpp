#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, sh, sm, eh, em;
    cin >>t;
    while(t--){
        cin >>sh >>sm >>eh >>em;
        int stm = (sh*60) + sm;
        int etm = (eh*60) + em;
        cout <<(etm-stm)/60 <<" " <<(etm-stm)%60 <<endl;
    }
    return 0;
}