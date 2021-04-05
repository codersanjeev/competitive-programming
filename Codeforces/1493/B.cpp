#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define MOD 1000000007LL
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename... T>
void read(T &...args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&...args) {
    ((cout << args), ...);
}

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) {
        read(e);
    }
}

template <typename T>
void writeContainer(T &t) {
    for (const auto &e : t) {
        write(e, " ");
    }
    write("\n");
}

auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

vector<int> reflection(10, -1);

bool valid(int a, int b, int h, int m) {
    if (reflection[a % 10] == -1 || reflection[b % 10] == -1 || reflection[a / 10] == -1 || reflection[b / 10] == -1) {
        return false;
    }
    int x = reflection[b % 10] * 10 + reflection[b / 10];
    int y = reflection[a % 10] * 10 + reflection[a / 10];
    return x < h && y < m;
}

void solve(int tc) {
    int h, m;
    string s;
    read(h, m, s);
    int a = (s[0] - '0') * 10 + s[1] - '0';
    int b = (s[3] - '0') * 10 + s[4] - '0';
    while (valid(a, b, h, m) == false) {
        b++;
        if (b == m) {
            a++;
        }
        b %= m;
        a %= h;
    }
    printf("%02d:", a);
    printf("%02d\n", b);
}

signed main() {
    int tc = 1;
    read(tc);
    reflection[0] = 0;
    reflection[1] = 1;
    reflection[2] = 5;
    reflection[5] = 2;
    reflection[8] = 8;
    for (int curr = 1; curr <= tc; ++curr) {
        solve(curr);
    }
    return 0;
}