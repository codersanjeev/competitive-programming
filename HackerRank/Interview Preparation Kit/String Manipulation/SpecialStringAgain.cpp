#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c, i = 0, j, ans = 0;
    cin >> n;

    string s;
    cin >> s;

    int same_char_count[n] = {0};

    while (i < n) {
        j = i + 1, c = 1;
        while (j < n && s[i] == s[j]) {
            ++j, ++c;
        }

        //total substrings which have all same char(s)
        ans += (c * (c + 1)) >> 1;
        same_char_count[i] = c;
        i = j;
    }

    for (j = 1; j < n - 1; ++j) {
        if (s[j] == s[j - 1]) {
            same_char_count[j] = same_char_count[j - 1];
        }

        //odd length substr(s) which has middle element diiferent
        if (s[j - 1] == s[j + 1] && s[j] != s[j - 1]) {
            ans += min(same_char_count[j - 1], same_char_count[j + 1]);
        }
    }
    cout << ans << endl;

    return 0;
}
