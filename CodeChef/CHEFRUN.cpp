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
    int t;
    double x1, x2, x3, v1, v2;
    cin >>t;
    while(t--){
        cin >>x1 >>x2 >>x3 >>v1 >>v2;
        double t1 = (x3-x1)/v1;
        double t2 = (x2-x3)/v2;
        if(t1 == t2){
            cout <<"Draw\n";
        }
        else if(t1 > t2){
            cout <<"Kefa\n";
        }
        else{
            cout <<"Chef\n";
        }
    }
    return 0;
}