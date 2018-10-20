#include <bits/stdc++.h>

using namespace std;

const int N = 1234;
const int oo = 123456789;

int n, m, S, T;
int c[N][N], f[N][N], Dfs[N], d[N], t = 0;
vector<int> e[N];

bool bfs(int S, int T)
{
    memset(d, 0, sizeof d);
    queue<int> qu;
    qu.push(S); d[S] = 1;
    while (qu.size()) {
        int u = qu.front(); qu.pop();
        if (u == T) return true;
        for (int v : e[u]) {
            if (!d[v] && f[u][v] < c[u][v]) {
                d[v] = d[u] + 1;
                qu.push(v);
            }
        }
    }
    return false;
}

int visit(int u, int Min)
{
    if (u == T) return Min;
    if (Dfs[u] == t) return 0;
    else Dfs[u] = t;
    for (int v : e[u]) {
        if (Dfs[v] != t && d[v] == d[u] + 1 && f[u][v] < c[u][v]) {
            if (int x = visit(v, min(Min, c[u][v] - f[u][v]))) {
                f[u][v] += x;
                f[v][u] -= x;
                return x;
            }
        }
    }
    return 0;
}

int main()
{
    cin >> n >> m >> S >> T;
    for (int i = 1; i <= m; ++i) {
        int x, y, p;
        cin >> x >> y >> p;
        e[x].push_back(y);
        e[y].push_back(x);
        c[x][y] += p;
    }
    int ans = 0;
    while (bfs(S, T)) {
        while (int x = (++t, visit(S, oo))) {
            ans += x;
        }
    }
    cout << ans;
    return 0;
}
