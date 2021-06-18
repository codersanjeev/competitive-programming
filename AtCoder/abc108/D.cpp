#include<bits/stdc++.h>
using namespace std;

int l, cnt = 0, tot = 0, res, tmp, first[30];

struct edge {
	int u, v, w, next;
} e[65];

inline void add(int u, int v, int w) {
	e[++tot].u = u, e[tot].v = v, e[tot].w = w, e[tot].next = first[u], first[u] = tot;
}

int main() {
	cin >> l, tmp = l, res = l;

	while (tmp) tmp >>= 1, ++cnt;

	for (int i = 1; i < cnt; ++i) add(i, i + 1, 0), add(i, i + 1, (1 << (i - 1)));

	res -= 1 << (cnt - 1);
	tmp = 1 << (cnt - 1);

	for (int i = 0; i <= 20; ++i) if (((res >> i) & 1)) add(i + 1, cnt, tmp), tmp += 1 << i;

	cout << cnt << ' ' << tot << '\n';

	for (int i = 1; i <= tot; ++i) cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w << '\n';

	return 0;
}