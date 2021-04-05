#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, count, sum, q;
    cin >>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >>arr[i];
    cin >>q;
    while(q--){
        cin >>m;
        count = 0;
        sum = 0;
        for(int i=0; i<n; i++){
            if(arr[i] <= m){
                count += 1;
                sum += arr[i];
            }
        }
        cout <<count <<" " <<sum <<endl;
    }
	return 0;
}