#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, X, Y;
    cin >> N >> A >> X >> Y;
    if (N <= A)
        cout << N * X;
    else
        cout << A * X + (N - A) * Y;
    return 0;
}