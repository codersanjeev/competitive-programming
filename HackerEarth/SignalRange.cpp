#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >>t;
    while(t--){
        cin >>n;
        long arr[n];
        for(int i=0; i<n; i++)
            cin >>arr[i];
        stack<long> st;
        st.push(0);
        int ans[n];
        ans[0] = 1;
        for(int i=1; i<n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            ans[i] = (st.empty()?(i+1):(i-st.top()));
            st.push(i);
        }
        for(int i=0; i<n; i++)
            cout <<ans[i] <<" ";
        cout <<endl;
    }
    return 0;
}