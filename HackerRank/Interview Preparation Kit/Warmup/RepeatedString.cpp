#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    long long n;
    cin >> s;
    cin >> n;
    long long count = 0;
    for (long long i = 0; i < s.size(); i++)
        if (s[i] == 'a')
            count++;
    long long factor = n / s.size();
    long long rem = n % s.size();
    count *= factor;
    for (long long i = 0; i < rem; i++)
        if (s[i] == 'a')
            count++;
    cout << count;
    return 0;
}
