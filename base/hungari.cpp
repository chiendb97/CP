// mincost
// dpt O(n^3)
// maxcost: d[i] = oo, f[i] = oo, fx-=, fy+=, c[i][j] = 0, getC = fx + fy - c[u][v]

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
const long long oo = 12345678987654321;

int n, m, k, N;
long long c[MAXN][MAXN], fx[MAXN], fy[MAXN];
int mx[MAXN], my[MAXN], trace[MAXN], d[MAXN], args[MAXN];
queue<int> qu;

void init()
{
    N = max(n, m);
    for (int i = 1; i <= N; ++i) {
        fx[i] = fy[i] = mx[i] = my[i] = 0;
        for (int j = 1; j <= N; ++j) {
            c[i][j] = oo;
        }
    }
}

void add_edge(int u, int v, long long cost)
{
    c[u][v] = min(c[u][v], cost);

}

long long getC(int u, int v)
{
    return c[u][v] - fx[u] - fy[v];
}

void initBfs(int start)
{
    while (qu.size()) {
        qu.pop();
    }
    qu.push(start);
    for (int v = 1; v <= N; ++v) {
        trace[v] = 0;
        d[v] = getC(start, v);
        args[v] = start;
    }

}

int bfs(int start)
{
    initBfs(start);
    while (qu.size()) {
        int u = qu.front(); qu.pop();
        for (int v = 1; v <= N; ++v) {
            if (!trace[v]) {
                long long w = getC(u, v);
                if (!w) {
                    trace[v] = u;
                    if (!my[v]) {
                        return v;
                    }
                    else {
                        qu.push(my[v]);
                    }
                }
                if (d[v] > w) {
                    d[v] = w;
                    args[v] = u;
                }
            }
        }
    }
    return 0;
}

void enlarge(int u)
{
    int x, y;
    while (y = u) {
        x = trace[y];
        u = mx[x];
        mx[x] = y;
        my[y] = x;
    }
}

int subX_addY(int start)
{
    long long delta = oo;
    for (int v = 1; v <= N; ++v) {
        if (trace[v] == 0 && d[v] < delta) {
            delta = d[v];
        }
    }
    fx[start] += delta;
    for (int v = 1; v <= N; ++v) {
        if (trace[v]) {
            int u = my[v];
            fx[u] += delta;
            fy[v] -= delta;
        }
        else {
            d[v] -= delta;
        }
    }
    for (int v = 1; v <= N; ++v) {
        if (trace[v] == 0 && d[v] == 0) {
            trace[v] = args[v];
            if (my[v] == 0) {
                return v;
            }
            qu.push(my[v]);
        }
    }
    return 0;

}

long long hungarian()
{
    long long ans = 0;
    for (int i = 1; i <= N; ++i) {
        int u;
        do {
            u = bfs(i);
            if (u == 0) {
                u = subX_addY(i);
            }
        } while (u == 0);
        enlarge(u);
    }
    for (int i = 1; i <= N; ++i) {
        if (c[i][mx[i]] < oo) {
            ans += c[i][mx[i]];
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    init();
    while (k--) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    cout << hungarian() << "\n";
    for (int i = 1; i <= N; ++i) {
        if (c[i][mx[i]] < oo) {
            cout << i << " " << mx[i] << "\n";
        }
    }
    return 0;
}

