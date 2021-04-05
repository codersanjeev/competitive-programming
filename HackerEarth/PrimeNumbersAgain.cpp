#include<bits/stdc++.h>
using namespace std;
#define vi vector < int >
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define foreach(it,v) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define ll long long
#define llu unsigned long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define all(x) x.begin(),x.end()
#define mset(x,v) memset(x, v, sizeof(x))
#define sz(x) (int)x.size()
vector < int > v;
int sieve[10010];
int dp[10001];
void go()
{
    int i,j;
    for(i=2;i*i<=10000;i++)
    {
        if(!sieve[i])
        {
            for(j=i*i;j<=10000;j+=i)
                sieve[j] = 1;
        }
    }
    for(i=2;i<=10000;i++)
    {
        if(!sieve[i])
        {
            int x = 1;
            int c = i;
            while(c--)
            {
                if(x > 10000)
                    break;
                x *= i;
            }
            v.pb(i);
            if(c < 0)
                v.pb(x);
        }
    }
    sort(all(v));
    mset(dp,INF);
    dp[0] = 0;
    for(i=1;i<=10000;i++)
    {
        for(j=0;j<sz(v);j++)
        {
            if(i >= v[j])
                dp[i] = min(dp[i],dp[i-v[j]]+1);
        }
    }
}
int main()
{
    go();
    int t;
    scanf("%d",&t);
    assert(1 <= t && t <= 100000);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        assert(2 <= n && n <= 10000);
        printf("%d\n",dp[n]);
    }
    return 0;
}