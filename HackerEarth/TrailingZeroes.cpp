#include<bits/stdc++.h>
using namespace std;

int find(int n){
    int count=0;
    for(int i=5; n/i>0; i*=5){
        count += n/i;
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i;
    unordered_map<int,vector<int>>m;
    for(i=1; i<=500000; i++){
        int k = find(i);
        m[k].push_back(i);
    }
    int t;
    cin >>t;
    while(t--){
        int x;
        cin >>x;
        cout <<m[x].size() <<endl;
        for(i=0; i<m[x].size(); i++)
            cout <<m[x][i] <<" ";
        cout <<endl;
    }
    return 0;
}