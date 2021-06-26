#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double den = (c * d) - b;
    if (den <= 0) {
        cout << -1;
    } else {
        cout << ceil(a / den);
    }
    return 0;
}