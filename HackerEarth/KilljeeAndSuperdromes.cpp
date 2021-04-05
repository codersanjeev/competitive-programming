#include<bits/stdc++.h>
using namespace std ;
 
int check(int n){
    int a[100]={0},p=0 ;
    int i,j=0,b[100]={0};
    while(n>0){
        a[p] = n%2 ;
        b[p] = n%2 ;
        p++;
        n/=2;
    }
    for(i=0;i<p;i++){
        if(a[i]==b[p-1-i])
            j++ ;
    }
    if(j==p)
        return 1;
    else
        return 0 ;
}
 
int main(){
    int i,j,a[1000001]={0};
    int n,t,p=0;
    for(i=1;i<1000001;i++){
        j = i ;
        p = 0 ;
        while(j>0){
            p = 10*p + j%10;
            j/=10;
        }
        if(p==i){
            if(check(i)==1){
                a[i]=a[i-1]+1;
            }
            else{
                a[i]=a[i-1];
            }
        }
        else{
            a[i]=a[i-1];
        }
    }
    cin >> t ;
    while(t--){
        cin >> n ;
        cout << a[n] << endl ;
    }
    return 0 ;
}