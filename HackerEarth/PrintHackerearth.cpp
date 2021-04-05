#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >>n;
    string s;
    cin >>s;
    char* st = new char[n+1];
    st[n] = '0';
    memcpy(st, s.c_str(), s.size());
    int freq[7] = {0};
    for(long long i=0; i<n; i++){
        char ch = st[i];
        if(ch == 'h'){
            freq[0]++;
        }
        else if(ch == 'a'){
            freq[1]++;
        }
        else if(ch == 'c'){
            freq[2]++;
        }
        else if(ch == 'k'){
            freq[3]++;
        }
        else if(ch == 'e'){
            freq[4]++;
        }
        else if(ch == 'r'){
            freq[5]++;
        }
        else if(ch == 't'){
            freq[6]++;
        }
    }
    int answer = 0;
    while(freq[0] >= 2 &&
        freq[1] >= 2 && freq[2] >= 1 && freq[3] >= 1 &&
        freq[4] >= 2 && freq[5] >= 2 && freq[6] >= 1){
            answer++;
            freq[0] -= 2;
            freq[1] -= 2;
            freq[2] -= 1;
            freq[3] -= 1;
            freq[4] -= 2;
            freq[5] -= 2;
            freq[6] -= 1;
        }
    cout <<answer;
    return 0;
}