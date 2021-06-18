#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ele;
    unordered_set<int> st;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ele;
        st.insert(ele);
    }
    cout << (st.size() == n ? "Yes" : "No");
    return 0;
}