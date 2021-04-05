#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n,m,i,j,flag=true;
        cin>>n>>m;
        vector<vector<int>> A(n, vector<int>(m));
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>A[i][j];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                int cnt=0;
                if(i==0||i==n-1)
                    cnt++;
                else cnt+=2;
                if(j==0||j==m-1)
                    cnt++;
                else cnt+=2;
                if(cnt<=A[i][j])
                {
                    flag=false;
                    break;
                }
            }
            if(j<m)
                break;
        }
        cout<<(flag? "Stable":"Unstable")<<endl;
    }
}
