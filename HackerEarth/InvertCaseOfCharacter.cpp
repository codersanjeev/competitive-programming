/**
 * Template for Contests
 *
 *  @author Sanjeev
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    int x, y;
    getline(cin, s); 
    cin >>x >>y;
    for(int i = 0; i < s.size(); i++){
        if(i == x-1 || i == y-1){
            // invert case
            int temp = int(s[i]);
            if(temp >= 97 && temp <= 122)
                cout <<(char)toupper(s[i]);
            else    
                cout <<(char)tolower(s[i]);
        }
        else{
            cout <<s[i];
        }
    }
    return 0;
}