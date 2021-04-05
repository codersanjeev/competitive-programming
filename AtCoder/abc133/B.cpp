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

bool f(vector<double> &pointA, vector<double> pointB){
    double dist = 0.0;
    int n = pointA.size();
    double temp = 0.0;
    for(int i = 0; i < n; i++)
        temp += (abs(pointA[i]-pointB[i]) * abs(pointA[i]-pointB[i]));
    dist = sqrt(temp);
    return ceil(dist) == floor(dist);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, d;
    cin >>n >>d;
    vector<vector<double>> points(n);
    for(int i = 0; i < n; i++){
        vector<double> point(d);
        for(int j = 0; j < d; j++)
            cin >>point[j];
        points[i] = point;
    }
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(f(points[i], points[j]))
                ans++;
        }
    }
    cout <<ans;
    return 0;
}
