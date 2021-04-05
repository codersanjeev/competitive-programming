#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, ele;
    cin >>t;
    while(t--){
        cin >>n;
        int count = 0;
        for(int i=0; i<n; i++){
            cin >>ele;
            while(ele%2 == 0){
                ele /= 2;
                count++;
            }
        }
        if(count%2){
            cout <<"Charlie\n";
        }
        else{
            cout <<"Alan\n";
        }
    }
    return 0;
}