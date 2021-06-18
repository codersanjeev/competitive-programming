#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;
int pre[maxn], sum[maxn], x[maxn], y[maxn];
long long ans[maxn];
int find(int x)
{
    return x == pre[x] ? x : pre[x] = find(pre[x]); //I wrote the wrong one at the beginning and wrote x = find. .
}
void join(int a, int b)
{
    a = find(a), b = find(b);
    if(a != b)
    {
        sum[a] += sum[b];
        sum[b] = 0;
        pre[b] = a;
    }
}
int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        for(int i = 0; i < maxn; i++) sum[i] = 1, pre[i] = i;
        memset(ans, 0, sizeof(ans));
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d", &x[i], &y[i]);
        }
        long long cnt = n;
        ans[m+1] = cnt * (cnt-1) / 2;
        for(int i = m; i >= 2; i--)
        {
            int xx = find(x[i]), yy = find(y[i]);
            if(xx != yy)
            {
                ans[i] = ans[i+1] - sum[xx] * sum[yy];
                join(x[i], y[i]);
            }
            else
                ans[i] = ans[i+1];
        }
        for(int i = 2; i <= m+1; i++)
            printf("%lld\n", ans[i]);
    }

    return 0;
}

