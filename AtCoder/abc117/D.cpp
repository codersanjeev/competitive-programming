#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  vector<ll> cnt(50);

  REP(i, N) {
    REP(j, 50) {
      if (A[i] >> j & 1) cnt[j]++;
    }
  }
  ll x = 0;
  for (ll i = 49; i >= 0; i--) {
    if (x + (1LL << i) > K) continue;
    if (cnt[i] * 2 < N) x += (1LL << i);
  }
  ll ans = 0;
  REP(i, N) { ans += x ^ A[i]; }
  cout << ans << endl;
}
