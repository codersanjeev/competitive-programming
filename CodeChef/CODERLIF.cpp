/**
 * Template for Contests
 *
 *  @author Sanjeev
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    int arr[30];
    cin >>t;
    while(t--){
        for(int i = 0; i < 30; i++)
            cin >>arr[i];
        int count = 0;
        if(arr[0] == 1)
            count = 1;
        bool flag = false;
        for(int i = 1; i < 30; i++){
            if(arr[i] == 1)
                count++;
            else 
                count = 0;
            if(count > 5)
                flag = true;
        }
        if(flag)
            cout <<"#coderlifematters\n";
        else 
            cout <<"#allcodersarefun\n";
    }
    return 0;
}