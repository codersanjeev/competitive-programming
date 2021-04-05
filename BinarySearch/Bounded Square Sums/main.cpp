#include <bits/stdc++.h>
using namespace std;

int f(const vector<int>& arr, int x) {
    int lo = 0, hi = arr.size() - 1, ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int g(const vector<int>& arr, int x) {
    int lo = 0, hi = arr.size() - 1, ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] <= x) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int solve(vector<int>& a, vector<int>& b, int lower, int upper) {
    vector<int> A, B;
    for (const auto& ele : a) {
        A.push_back(ele * ele);
    }
    for (const auto& ele : b) {
        B.push_back(ele * ele);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans = 0;
    for (const auto& ele : A) {
        int x = f(B, lower - ele);
        int y = g(B, upper - ele);
        if (x != -1 && y != -1) {
            int cnt = max(0, y - x + 1);
            ans += cnt;
        }
    }
    return ans;
}