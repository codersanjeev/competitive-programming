#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >>s;
    bool flag = true;
    char* st = new char[s.size()+1];
    st[s.size()] = 0;
    memcpy(st, s.c_str(), s.size());
    for(int i=0; i<9; i++){
        if(!flag){
            break;
        }
        if(i == 0){
            int x = st[0] - '0';
            int y = st[1] - '0';
            if((x + y)%2 != 0){
                // invalid
                flag = false;
            }
        }
        if(i == 2){
            if(st[2] == 'A' ||
                st[2] == 'E' ||
                st[2] == 'I' ||
                st[2] == 'O' ||
                st[2] == 'U' ||
                st[2] == 'Y'){
                    // invalid
                    flag = false;    
            }
        }
        if(i == 3){
            int x = st[3] - '0';
            int y = st[4] - '0';
            if((x + y)%2 != 0){
                // invalid
                flag = false;
            }
        }
        if(i == 4){
            int x = st[4] - '0';
            int y = st[5] - '0';
            if((x + y)%2 != 0){
                // invalid
                flag = false;
            }
        }
        if(i == 7){
            int x = st[7] - '0';
            int y = st[8] - '0';
            if((x + y)%2 != 0){
                // invalid
                flag = false;
            }
        }
    }
    if(flag){
        cout <<"valid" <<endl;
    }
    else{
        cout <<"invalid" <<endl;
    }
    return 0;
}