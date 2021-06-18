#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <typename... T>
void read(T &... args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&... args) {
    ((cout << args), ...);
}

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) read(e);
}

template <typename T>
void writeContainer(T &t) {
    for (const auto &e : t) write(e, " ");
    write("\n");
}

void solve(int tc) {
    int n, k;
    read(n, k);
    vector<int> arr(n * k);
    readContainer(arr);
    int idx = (n + 1) / 2;
    if (idx == 1) {
        int answer = arr[0];
        for (int i = n; i < n * k; i += n) {
            answer += arr[i];
        }
        write(answer, "\n");
    } else {
        int cnt = 0, left = 0, right = n * k - 1, answer = 0;
        vector<int> temp(n);
        idx--;
        while (cnt != k) {
            for (int i = 0; i < idx; i++) {
                temp[i] = arr[left];
                left++;
            }
            for (int i = n - 1; i >= idx; i--) {
                temp[i] = arr[right];
                right--;
            }
            answer += temp[idx];
            cnt++;
        }
        write(answer, "\n");
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}