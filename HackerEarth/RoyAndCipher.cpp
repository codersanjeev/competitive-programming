#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    string s;
    cin >>t;
    while(t--){
        cin >>s;
        char current = 'a';
        for(int i=0; i<s.size(); i++){
            char target = s[i];
            int c = (int)(current - 'a');
            int t = (int)(target - 'a');
            if(t-c <= -13){
                cout <<(t-c+26) <<" ";
            }
            else if(t-c > 13){
                cout <<(t-c-26) <<" ";
            }
            else{
                cout <<(t-c) <<" ";
            }
            current = target;
        }
        cout <<"\n";
    }
    return 0;
}