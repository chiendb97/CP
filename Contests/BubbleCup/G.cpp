#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 1e5+5;

int n, k;
vector <long long> T[4*N];
iii a[N];

bool cmp(const iii &x, const iii &y)
{
    if (x.first == y.fisrt) {
        if (x.second.first == y.second.first) {
            return x.second.second < y.second.second;
        }
        return x.second.first < y.second.first;
    }
    return x.first < y.first;
}

void build(int p, int l, int r)
{
    if (l > r) return;
    if (l == r) {
        T[p].push_back(a[l].second.second);
        return;
    }
    int mid = (l+r)/2;
    build(2*p, l, mid);
    build(2*p+1, mid+1, r);
    int sz1 = (int) T[2*p].size();
    int sz2 = (int) T[2*p+1].size();
    int i = 0, j = 0;
    while (i < sz1 && j < sz2) {
        if (T[2*p][i] < T[2*p+1][j]) {
            T[p].push_back(T[2*p][i]);
            ++i;
        }
        else {
            T[p].push_back(T[2*p+1][j]);
            ++j;
        }
    }
    while (i < sz1) {
        T[p].push_back(T[2*p][i]);
        ++i;
    }
    while (j < sz2) {
        T[p].push_back(T[2*p+1][j]);
        ++j;
    }
}

int get(int p, int l, int r, int i, int j, int val)
{
    if (l > j || r < i) {
        return 0;
    }
    if (l >= i && r <= j) {
        vector<long long>::iterator it = upper_bound(T[p].begin(), T[p].end(), val);
        if (it != T[p].end()) {
            return (int) (it - T[p].begin());
        }
        else {
            return 0;
        }
    }
    int mid = (l+r)/2;
    return get(2*p, l, mid, i, j, val) + get(2*p+1, mid+1, r, i, j, val);
}

int main()
{
    scanf("%d %lld", &n, &k);
    for (int i = 1; i <= n; ++i) {
        int x, r, q;
        scanf("%d %d %d", &x, &r, & q);
        a[i] = iii(x, ii(r, q));
    }
    sort(a+1, a+n+1, cmp);
    build(1, 1, n);
    long long ans = 0;
    for (int i = 1; i  <= n; ++i) {
        int l = lower_bound(a+1, a+n+1, a[i].first - a[i].second.first);
    }
    return 0;
}
