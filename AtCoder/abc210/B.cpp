#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    bool first = true;
    for (auto i = 0; i < N; ++i) {
        if (S[i] == '1') {
            first = i % 2 == 0;
            break;
        }
    }
    cout << (first ? "Takahashi" : "Aoki");
    return 0;
}