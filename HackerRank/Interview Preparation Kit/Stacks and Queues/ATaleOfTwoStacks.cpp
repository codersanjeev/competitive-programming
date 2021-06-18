#include <bits/stdc++.h>
using namespace std;

int main() {
    int qs, c, x;
    cin >> qs;
    queue<int> q;
    while (qs--) {
        cin >> c;

        if (c == 1) {
            cin >> x;
            q.push(x);
        } else if (c == 2) {
            q.pop();
        } else {
            cout << q.front() << endl;
        }
    }
    return 0;
}