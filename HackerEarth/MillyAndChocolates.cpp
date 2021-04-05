#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >>n;
    int arr[n];
    int x, sum = 0;
    for(int i=0; i<n; i++){
        cin >>x;
        sum += x;
        arr[i] = sum;
    }
    cin >>q;
    int ele;
    vector<int> v(arr, arr+n);
    while(q--){
        cin >>ele;
        cout <<lower_bound(v.begin(), v.end(), ele) - v.begin() + 1 <<endl;
    }
    return 0;
}