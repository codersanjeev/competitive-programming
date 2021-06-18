#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <memory.h>
#include <map>
#include <set>
#include <memory.h>
#include <cstdlib>
#define y1 jvhsdoublek
#define mod 1000000007
#define ll long long
#define MAX  100005
#define INF 1000000000
using namespace std;
int n, q;
//int a[MAX];
int main()
{
    cin>>n;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d",&q);
        ans+=q;
    }
    ++n;
    int res = 0;
    for(int i = 1; i <= 5; ++i){
        if((ans + i) % n != 1) res++;
    }
    cout<<res;
}
