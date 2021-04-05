#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int s,x,n,t,y;
    cin>>s>>x>>n;
    long long int i;
    map<int,int>mp;
    for(i=0;i<n;i++){
        cin>>t>>y;
        mp.insert(pair<int,int>(t,y));
    }
    long long int sum=0;
    i=1;
    map<int,int>::iterator itr=mp.begin();
    while(sum<s){
        if(itr->first==i){
           sum=sum+itr->second;
           itr++;
        }
        else
            sum=sum+x;   
            i++;
    }
    cout<<(i-1);
    return 0;
}