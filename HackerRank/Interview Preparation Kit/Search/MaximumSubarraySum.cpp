#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t > 0) {
        int n;
        scanf("%d", &n);
        unsigned long long int m;
        scanf("%llu", &m);
        pair<unsigned long long int, int> a[n];
        for (int i = 0; i < n; i++) {
            scanf("%llu", &a[i].first);
            a[i].second = i + 1;
        }
        a[0].first = a[0].first % m;
        unsigned long long int maxx = a[0].first;
        for (int i = 1; i < n; i++) {
            a[i].first = (a[i].first % m + a[i - 1].first % m) % m;
            if (maxx < a[i].first) {
                maxx = a[i].first;
            }
        }
        //        printf("maxx: %llu\n",maxx);
        sort(a, a + n);
        unsigned long long int min = ULONG_MAX;
        for (int i = 0; i < n - 1; i++) {
            if (a[i].second > a[i + 1].second) {
                if (a[i + 1].first - a[i].first < min) {
                    min = a[i + 1].first - a[i].first;
                }
            }
        }
        //        printf("%llu\n",min);
        printf("%llu\n", max(maxx, m - min));
        t--;
    }
    return 0;
}
