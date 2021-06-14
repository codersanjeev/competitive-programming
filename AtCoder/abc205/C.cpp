#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (c % 2 == 0) {
        a = abs(a);
        b = abs(b);
    }
    if (a > b) {
        cout << ">";
    } else if (a < b) {
        cout << "<";
    } else {
        cout << "=";
    }
    return 0;
}