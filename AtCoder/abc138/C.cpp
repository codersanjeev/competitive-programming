/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    double ele;
    cin >>n;
    priority_queue<double, vector<double>, greater<double>> pq;
    for(int i = 0; i < n; i++){
        cin >>ele;
        pq.push(ele);
    }
    while(pq.size() != 1){
        double a = pq.top();
        pq.pop();
        double b = pq.top();
        pq.pop();
        pq.push((a + b)/2);
    }
    cout <<pq.top();
    return 0;
}
