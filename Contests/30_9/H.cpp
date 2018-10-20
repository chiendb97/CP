#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+5;

int test, n, m;
vector<int> sa;
vector<int> e[N];
int ans[N], cnt;
bool ok[N];
queue<int> qu;


void bfs(int s)
{
    while(qu.size()) {
        qu.pop();
    }
    qu.push(s);
    ok[s] = true;
    while (qu.size()) {
        int u = qu.front();
        qu.pop();
        ++cnt;
        sa.push_back(u);
        for (int v : e[u]) {
            if (!ok[v]) {
                ok[v] = true;
                qu.push(v);
            }
        }
    }
}

int main()
{
    scanf("%d", &test);
    for (int t = 1; t <= test; ++t) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            e[i].clear();
        }
        memset(ok, false, sizeof ok);
        memset(ans, 0, sizeof ans);
        for (int i = 1; i <= m; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        for (int i = 1; i <= n; ++i) {
            if (!ok[i]) {
                cnt = 0;
                bfs(i);
                for (auto x : sa) {
                    ans[x] = cnt;
                }
                sa.clear();
            }
        }
        printf("Case #%d:\n", t);
        for (int i = 1; i <= n; ++i) {
            printf("%d ", ans[i]-1);
        }
        printf("\n");
    }
    return 0;
}
