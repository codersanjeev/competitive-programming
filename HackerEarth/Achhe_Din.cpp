#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, count = 0;
    cin >>t;
    while(t--){
        cin >>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin >>arr[i];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i] == arr[j])
                    count++;
            }
            if(count < 3)
                cout <<arr[i] <<endl;
            count = 0;
        }
        
    }
    return 0;
}