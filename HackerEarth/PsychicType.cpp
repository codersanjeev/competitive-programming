#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >>arr[i];
    int s, e;
    cin >>s >>e;
    if(s == e){
        cout <<"Yes";
        return 0;
    }
    else{
        while(n--){
            s = arr[s-1];
            if(s == e){
                cout <<"Yes";
                return 0;
            }
        }
    }
    cout <<"No";
    return 0;
}