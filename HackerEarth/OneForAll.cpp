#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        long total = 0;
        string str;
        cin >> n >> str;
        for (int i = 0; i < n; i++) {
            if (str[i] == '0') {
                int temp = i;
                while (i < n && str[i] == '0') {
                    total += temp;
                    i++;
                }
            }
        }
        cout << total << endl;
    }
}