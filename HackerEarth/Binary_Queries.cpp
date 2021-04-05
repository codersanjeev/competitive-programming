#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, ele, l, r, x;
    cin >>n >>q;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >>ele;
        arr[i] = ele;
    }
    while(q--){
        cin >>ele;
        if(ele == 1){
            cin >>x;
            if(arr[x-1] == 1)
                arr[x-1] = 0;
            else
                arr[x-1] = 1;
        }
        else{
            cin >>l >>r;
            if(arr[r-1] == 1)
                cout <<"ODD" <<endl;
            else
                cout <<"EVEN" <<endl;
        }
    }
    return 0;
}