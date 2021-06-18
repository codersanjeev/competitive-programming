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

int choose(int n, vector<int> &arr, int c) {
    int ans = 0;
    for (int x = 2; x <= n; x++) {
        if (arr[x] + 1 >= c) ans++;
    }
    return ans;
}

void solve(int tc) {
    // divisors of n!
    // number of divisors having 75 divisors?
    int n;
    read(n);
    vector<int> countOfPrimeFactors(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        int curr = i;
        for (int j = 2; j * j <= curr; j++) {
            while (curr % j == 0) {
                countOfPrimeFactors[j]++;
                curr /= j;
            }
        }
        if (curr > 1) {
            countOfPrimeFactors[curr]++;
        }
    }
    int answer = 0;
    answer += ((choose(n, countOfPrimeFactors, 5) * (choose(n, countOfPrimeFactors, 5) - 1)) / 2 * (choose(n, countOfPrimeFactors, 3) - 2));
    answer += (choose(n, countOfPrimeFactors, 75));
    answer += (choose(n, countOfPrimeFactors, 25) * (choose(n, countOfPrimeFactors, 3) - 1));
    answer += (choose(n, countOfPrimeFactors, 15) * (choose(n, countOfPrimeFactors, 5) - 1));
    write(answer);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}