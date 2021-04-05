/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
 
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout <<#x <<" " <<x <<endl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, ele;
    cin >>n;
    priority_queue<long long> arr;
    for(long long i = 0; i < n; i++){
        cin >>ele;
        arr.push(ele);
        if(i == 0 || i == 1){
            cout <<"-1\n";
            continue;
        }
        long long ans = 1;
        vector<long long> temp;
        for(long long j = 0; j < 3; j++){
            ans *= arr.top();
            temp.push_back(arr.top());
            arr.pop();
        }
        cout <<ans <<"\n";
        for(auto t : temp)
            arr.push(t);
    }
    return 0;
}
