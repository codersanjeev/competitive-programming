#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >>s;
    char* str = new char[s.size()+1];
    str[s.size()] = '0';
    memcpy(str, s.c_str(), s.size());
    int q, ind;
    char ch;
    cin >>q;
    while(q--){
        cin >>ind >>ch;
        str[ind-1] = ch;
    }
    char* fin = new char[s.size()+1];
    fin[s.size()] = '0';
    memcpy(fin, str, s.size());
    int m, a, b;
    cin >>m;
    while(m--){
        cin >>a >>b;
        // reverse from a-1 to b-1 in fin
        int i = a-1, j = b-1;
        while(i < j){
            swap(fin[i], fin[j]);
            i++;
            j--;
        }
    }
    int ans = 0;
    for(int i=0; i<s.size(); i++){
        if(str[i] == fin[i])
            ans++;
    }
    for(int i=0; i<s.size(); i++)
        cout <<str[i];
    cout <<"\n";
    for(int i=0; i<s.size(); i++)
        cout <<fin[i];
    cout <<"\n";
    cout <<ans;
    return 0;
}