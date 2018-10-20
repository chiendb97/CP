#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

typedef pair <int, int> ii;

int n, m;
ii a[N];
int b[N];
long long sum[N], p[N], x[N];
long long ans = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &b[i]);
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
        x[i] = x[i-1] + a[i].second;
        sum[i] = sum[i-1] + a[i].first;
        p[i] = p[i-1] + 1LL*a[i].first*a[i].second;
    }
    for (int i = 1; i <= m; ++i) {
        int tmp = lower_bound(a+1, a+n+1, ii(b[i], 0)) - a;
        tmp -= 1;
        ans += (1LL*tmp*i*b[i] - x[tmp]*b[i] - i*sum[tmp] + p[tmp]) - (1LL*(n-tmp)*i*b[i] - (x[n]-x[tmp])*b[i] - i*(sum[n]-sum[tmp]) + p[n]-p[tmp]);
    }
    cout << -ans;
    return 0;
}
