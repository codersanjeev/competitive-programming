#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;
    int arr[t];
    int sum = 0, ele;
    for(int i=0; i<t; i++){
        cin >>ele;
        sum += ele;
        arr[i] = sum;
    }
    int q;
    cin >>q;
    while(q--){
        cin >>ele;
        bool flag = false;
        for(int i=0; i<t; i++){
            flag = false;
            if(arr[i] >= ele){
                cout <<(i+1) <<endl;
                flag = true;
                break;
            }
        }
        if(!flag){
            cout <<-1 <<endl;
        }
    }
    return 0;
}