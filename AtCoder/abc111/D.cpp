#include <bits/stdc++.h>
using namespace std;

using pll = pair<long long, long long>;

int main() {
    int N;
    cin >> N;
    vector<pll> pos(N);
    for (int i = 0; i < N; ++i) cin >> pos[i].first >> pos[i].second;

    int par = (abs(pos[0].first) + abs(pos[0].second)) % 2;
    for (int i = 0; i < N; ++i) {
        int par2 = (abs(pos[i].first) + abs(pos[i].second)) % 2;
        pos[i] = pll(pos[i].first + pos[i].second, pos[i].first - pos[i].second);
        if (par2 != par) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<long long> d;
    for (int i = 30; i >= 0; --i) d.push_back(1LL << i);
    if (par % 2 == 0) d.push_back(1);
    cout << d.size() << endl;
    for (int j = 0; j < d.size(); ++j) cout << d[j] << " ";
    cout << endl;
    for (int i = 0; i < N; ++i) {
        int xdir, ydir;
        long long xsum = 0, ysum = 0;
        for (int j = 0; j < (int)d.size(); ++j) {
            if (xsum <= pos[i].first)
                xdir = 1, xsum += d[j];
            else
                xdir = -1, xsum -= d[j];
            if (ysum <= pos[i].second)
                ydir = 1, ysum += d[j];
            else
                ydir = -1, ysum -= d[j];

            if (xdir == 1 && ydir == 1)
                cout << "R";
            else if (xdir == 1 && ydir == -1)
                cout << "U";
            else if (xdir == -1 && ydir == -1)
                cout << "L";
            else
                cout << "D";
        }
        cout << endl;
    }
}