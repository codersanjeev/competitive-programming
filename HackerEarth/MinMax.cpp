#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >>arr[i];
    }
    sort(arr, arr+n);
    int min = arr[0];
    int max = arr[n-1];
    bool flag = true;
    set<int> mset;
    for(int i=0; i<n; i++){
        mset.insert(arr[i]);
    }
    while(min <= max){
        if(!mset.count(min)){
            flag = false;
            break;
        }
        min++;
    }
    if(flag){
        cout <<"YES";
    }
    else{
        cout <<"NO";
    }
    return 0;
}
