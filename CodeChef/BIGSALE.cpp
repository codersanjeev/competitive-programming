#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long double q[n],p[n],d[n];
        long double s,t,sum=0;
        for(int i=0;i<n;i++){
            cin>>p[i]>>q[i]>>d[i];
            s=p[i]+((p[i]*d[i])/100);
            t=s-((s*d[i])/100);
            sum+=(q[i]*(p[i]-t));
        }
        
      
        cout<<setprecision(12)<<sum<<endl;
    }
	return 0;
}
