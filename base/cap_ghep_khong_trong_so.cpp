// Cap ghep cuc dai do thi hai phia khong co trong so

#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

int n, m, k, t;
int assigned[N], d[N];
vector<int> e[N];

int visit(int u)
{
    if (d[u] != t) d[u] = t;
    else return 0;
    for (int v : e[u]) {
        if (!assigned[v] || visit(assigned[v])) {
            assigned[v] = u;
            return 1;
        }
    }
    return 0;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ++t;
        ans += visit(i);
    }
    cout << ans;
    return 0;
}
