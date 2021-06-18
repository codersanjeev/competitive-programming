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

int ans = 0;

void mergei(vector<int> &a, int i, int j) {
    int ni = ((i + j) / 2) + 1, nj = j + 1;
    int s = i;
    int *arr = new int[j - i + 1];
    j = ni;
    int k = 0;
    while (i < ni && j < nj) {
        if (a[i] <= a[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = a[j];
            ans += (ni - i);
            j++;
        }
        k++;
    }
    for (; i < ni; i++, k++)
        arr[k] = a[i];
    for (; j < nj; j++, k++)
        arr[k] = a[j];
    for (k = 0; s < nj; s++, k++)
        a[s] = arr[k];
    delete[] arr;
}

void m_sort(vector<int> &a, int i, int j) {
    if (i < j) {
        m_sort(a, i, (i + j) / 2);
        m_sort(a, ((i + j) / 2) + 1, j);
        mergei(a, i, j);
    }
}

int countInversions(vector<int> &arr) {
    ans = 0;
    m_sort(arr, 0, arr.size() - 1);
    return ans;
}

void solve(int tc) {
    int n;
    string s;
    read(n, s);
    unordered_map<char, queue<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]].push(i);
    }
    vector<int> arr(n);
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        arr[i] = mp[s[i]].front();
        mp[s[i]].pop();
    }
    write(countInversions(arr), "\n");
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