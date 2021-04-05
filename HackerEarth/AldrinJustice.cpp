#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    int a,b,c,d,t; 
    cin>>t; 
    while(t--){
        cin>>a>>b>>c>>d; 
        if(a>b)
            swap(a,b); 
        if(c>d) 
            swap(c,d);
        a=max(a,c),b=min(b,d);
        a==b ? cout<<"Point\n" : ( a > b ? cout<<"Line\n" : cout<<"Nothing\n");
    }
}
