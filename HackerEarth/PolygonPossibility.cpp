#include<iostream>
using namespace std;
int main()
{
    int t, i;
    cin>>t;
    for(i=0; i<t; i++)
    {
        int n, j, max=0, sum=0;
        cin>>n;
        int a[n];
        for(j=0; j<n; j++)
        {
            cin>>a[i];
            if(a[i]>max)
            {
                max= a[i];
            }
            sum+=a[i];
        }
        sum= sum-max;
        if(sum>max)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}