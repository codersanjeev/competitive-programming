#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q, c, cost;
    stack<int> pile;
    cin >>q;
    while(q--){
        cin >>c;
        if(c == 2){
            cin >>cost;
            pile.push(cost);
        }
        else{
            if( !pile.empty() ){
                cout <<pile.top() <<endl;
                pile.pop();
            }
            else{
                cout <<"No Food" <<endl;
            }
        }
    }
    return 0;
}