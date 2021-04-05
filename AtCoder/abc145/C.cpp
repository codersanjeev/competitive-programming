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

double f(double x1, double y1, double x2, double y2){
    return sqrt((abs(x2-x1)*abs(x2-x1)) + (abs(y2-y1)*abs(y2-y1)));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    double x, y;
    cin >>n;
    vector<pair<double, double>> arr;
    for(int i = 0; i < n; i++){
        cin >>x >>y;
        arr.push_back({x, y});
    }
    sort(arr.begin(), arr.end());
    double ans = 0;
    vector<double> cache(9);
    cache[0] = 1;
    cache[1] = 1;
    cache[2] = 2;
    for(int i = 2; i <= 8; i++)
        cache[i] = i * cache[i-1];
    do{
        // calculate current distance sum
        double temp = 0;
        for(int i = 1; i < n; i++){
            // find distance b/w i and i - 1
            temp += f(arr[i].first, arr[i].second, arr[i-1].first, arr[i-1].second);
        }
        ans += temp;
    }while(next_permutation(arr.begin(), arr.end()));
    cout <<fixed <<setprecision(10) <<ans / cache[n];
    return 0;
}
