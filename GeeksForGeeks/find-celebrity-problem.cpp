/*
https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

// } Driver Code Ends


// The task is to complete this function

// M[][]: input matrix
// n: size of matrix (n*n)
int getId(int m[MAX][MAX], int n)
{
    stack<int> s;
    for (int i=0; i<n; i++) s.push(i);
    while (s.size() > 1) {
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();
        if (m[a][b]==1 && m[b][a]==0) s.push(b);
        else if (m[a][b]==0 && m[b][a]==1) s.push(a);
    }
    
    int temp;
    if (!s.empty()) temp = s.top();
    else return -1;
    
    for (int j=0; j<n; j++) {
        if (j!=temp && (m[temp][j]!=0 || m[j][temp]!=1)) return -1;
    }
    return temp;
}