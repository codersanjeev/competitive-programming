#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, hours, f = 0, s = 0, t = 0;
    string name, first = "Ram", second = "Shyam", third = "Ghanshyam";
    cin >>n;
    for(int i=0; i<n; i++){
        cin >>name >>hours;
        if(hours > f){
            t = s;
            s = f;
            f = hours;
            third = second;
            second = first;
            first = name;
        }
        else if(hours > s){
            t = s;
            s = hours;
            third = second;
            second = name;
        }
        else if(hours > t){
            t = hours;
            third = name;
        }
    }
    cout <<first <<endl <<second <<endl <<third;
    return 0;
}