#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    string ans = "F";
    if (x >= 90) {
        ans = "A";
    } else if (x >= 80) {
        ans = "B";
    } else if (x >= 70) {
        ans = "C";
    } else if (x >= 60) {
        ans = "D";
    } else if (x >= 50) {
        ans = "E";
    }
    cout << ans;
    return 0;
}