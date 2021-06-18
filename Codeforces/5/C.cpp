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

const int M = 1e6 + 1;
vector<int> E(M, 0), S(M, 0), F(M, 0);

void solve(int tc) {
    string s;
    read(s);
    int n = s.size(), mx = 0;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            if (st.empty()) {
                S[i] = E[i] = -1;
            } else {
                int idx = st.top();
                st.pop();

                S[i] = E[i] = idx;

                if (idx > 0 && s[idx - 1] == ')' && S[idx - 1] >= 0) {
                    E[i] = E[idx - 1];
                }

                int len = i - E[i] + 1;
                F[len]++;
                mx = max(mx, len);
            }
        }
    }
    F[0] = 1;
    write(mx, " ", F[mx]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}