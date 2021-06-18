#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (x == y) {
        cout << x;
    } else {
        cout << 3 - x - y;
    }
    return 0;
}