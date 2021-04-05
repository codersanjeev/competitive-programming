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
    int t, n;
    string s;
    cin >>t;
    while(t--){
        cin >>n >>s;
        int arr[7] = {n/7, n/7, n/7, n/7, n/7, n/7, n/7};
        n %= 7;
        int i = 0;
        if(s == "mon")
            i = 0;
        else if(s == "tues")
            i = 1;
        else if(s == "wed")
            i = 2;
        else if(s == "thurs")
            i = 3;
        else if(s == "fri")
            i = 4;
        else if(s == "sat")
            i = 5;
        else if(s == "sun")
            i = 6;
        while(n != 0){
            if(i == 7)
                i = 0;
            arr[i]++;
            i++;
            n--;
        }
        for(i = 0; i < 7; i++)
            cout <<arr[i] <<" ";
        cout <<"\n";
    }
    return 0;
}