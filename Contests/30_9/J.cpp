#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int test, n, cnt, a[202], x[N];

int main()
{
    scanf("%d", &test);
    for (int t = 1; t <= test; ++t) {
        scanf("%d", &n);
        for (int i = 1; i <= cnt; ++i) {
            x[a[i]] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            int tmp;
            scanf("%d", &tmp);
            ++x[tmp];
        }
        cnt = 0;
        for (int i = 1; i <= 100000; ++i) {
            if (x[i]) {
                a[++cnt] = i;
            }
        }
        long long ans = 0;
        for (int i = 1; i <= cnt; ++i) {
            for (int j = i+1; j <= cnt; ++j) {
                for (int k = j+1; k <= cnt; ++k) {
                    if (a[i]+a[j] > a[k]) {
                        ++ans;
                    }
                }
            }
        }
        for (int i = 1; i <= cnt; ++i) {
            if (x[a[i]] >= 3) {
                ++ans;
            }
        }
        for (int i = 1; i <= cnt; ++i) {
            for (int j = i+1; j <= cnt; ++j) {
                if (x[a[i]] >= 2 && 2*a[i] > a[j]) {
                    ++ans;
                }
                if (x[a[j]] >= 2) {
                    ++ans;
                }
            }
        }
        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}
