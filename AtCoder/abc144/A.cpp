#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >>a >>b;
    if(a < 10 && b < 10)
        cout <<a * b;
    else 
        cout <<-1;
    return 0;
}
