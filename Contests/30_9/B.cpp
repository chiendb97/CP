#include <bits/stdc++.h>

using namespace std;

int test;
long long x[10], y[10], cost;

int main()
{
    scanf("%d", &test);
    for (int t = 1; t <= test; ++t) {
        for (int i = 1; i <= 4; ++i) {
            scanf("%lld %lld", &x[i], &y[i]);
        }
        scanf("%lld", &cost);
        x[5] = x[1];
        y[5] = y[1];
        long long s = 0;
        for (int i = 1; i <= 4; ++i) {
            s += (x[i+1]-x[i])*(y[i+1]+y[i]);
        }
        if (s < 0) s = -s;
        printf("Case #%d: %.2f\n", t, 2.0*cost/s);
    }
    return 0;
}
