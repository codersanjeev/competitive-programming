#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >>n;
    int arr[n];
    if(n == 0){
        cout <<"0";
        return 0;
    }
    for(int i=0; i<n; i++)
        cin >>arr[i];
    int max_ending_here = arr[0], max_so_far = arr[0];
    for(int i=1; i<n; i++){
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    cout <<max_so_far;
    return 0;
}