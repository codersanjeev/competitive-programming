#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, ele;
    cin >>n;
    for(int i=0; i<n; i++){
        cin >>ele;
        if(ele+i+1 > n){
            cout <<(i+1) <<"\n";
            break;
        }
    }   
    return 0;
}