#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int test, n;
int a[N], cnt, lt;
bool Ok[N][N];
bool check[N];
vector<int> e[N];

void bfs()
{
    queue<int> qu;
    qu.push(1);
    check[1] = true;
    while (qu.size()) {
        int u = qu.front(); qu.pop(); ++lt;
        if (lt == n) return;
        for (int v : e[u]) {
            if (!check[v]) {
                qu.push(v);
                check[v] = true;
            }
        }
    }
}

int main()
{
    for (int i = 2; i <= 50; ++i) {
        for (int j = 2; j <= 50; ++j) {
            if (__gcd(i, j) == 1) {
                Ok[i][j] = true;
            }
        }
    }
    scanf("%d", &test);
    while (test--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            e[i].clear();
            scanf("%d", &a[i]);
            check[i] = false;
        }
        cnt = 0; lt = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 47) {
                ++cnt;
            }
            for (int j = i+1; j <= n; ++j) {
                if (Ok[a[i]][a[j]]) {
                    e[i].push_back(j);
                    e[j].push_back(i);
                }
            }
        }
        bfs();
        if (lt == n) {
            printf("0\n");
            for (int i = 1; i <= n; ++i) {
                printf("%d ", a[i]);
            }
        }
        else {
            printf("1\n");
            if (cnt == n) {
                a[1] = 2;
                for (int i = 1; i <= n; ++i) {
                    printf("%d ", a[i]);
                }
            }
            else {
                a[1] = 47;
                for (int i = 1; i <= n; ++i) {
                    printf("%d ", a[i]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
