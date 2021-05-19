#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, X, A, B;
    cin >> T;
    while (T--) {
        cin >> X >> A >> B;
        cout << ((B * (100 - X)) + A) * 10 << "\n";
    }
    return 0;
}