#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        bool cm=true;
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++)
            cin>>a[i]>>b[i];
        int x,y;
        cin>>x>>y;
        int arr[3][3]={0};
        for(int i=0;i<n;i++){
            if((abs(a[i]+2-x)<=1 && abs(b[i]+1-y)<=1)) arr[a[i]+2-x+1][b[i]+1-y+1]=1;
            if((abs(a[i]+2-x)<=1 && abs(b[i]-1-y)<=1)) arr[a[i]+2-x+1][b[i]-1-y+1]=1;
            if((abs(a[i]-2-x)<=1 && abs(b[i]+1-y)<=1)) arr[a[i]-2-x+1][b[i]+1-y+1]=1;
            if((abs(a[i]-2-x)<=1 && abs(b[i]-1-y)<=1)) arr[a[i]-2-x+1][b[i]-1-y+1]=1;
            if((abs(a[i]+1-x)<=1 && abs(b[i]+2-y)<=1)) arr[a[i]+1-x+1][b[i]+2-y+1]=1;
            if((abs(a[i]-1-x)<=1 && abs(b[i]+2-y)<=1)) arr[a[i]-1-x+1][b[i]+2-y+1]=1;
            if((abs(a[i]+1-x)<=1 && abs(b[i]-2-y)<=1)) arr[a[i]+1-x+1][b[i]-2-y+1]=1;
            if((abs(a[i]-1-x)<=1 && abs(b[i]-2-y)<=1)) arr[a[i]-1-x+1][b[i]-2-y+1]=1;
         }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
                if(!arr[i][j]){
                    cm=false;
                    break;
            }
        }
        if(cm) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
