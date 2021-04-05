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
        int count = 0;
        for(int i=4; i<s.size(); i++){
            if(!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' 
            || s[i] == 'u')){
                count++;
            }
        }
        cout <<count+1 <<"/" <<s.size() <<endl;
    }
    return 0;
}