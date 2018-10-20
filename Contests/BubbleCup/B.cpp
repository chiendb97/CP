#include <bits/stdc++.h>

using namespace std;

const int N =2e5+5;

int n;
long long m;
long long a[N];
set<int> res[2];

bool check(int x)
{
    for (int i = 1; i <= 50; ++i) {
        int r = rand() % n + 1;
        if (!binary_search(a+1, a+n+1, (x-a[r]+m) % m)) return false;
    }
    return true;
}

bool sky(int x, int id)
{
    for (int i = 1; i <= n; ++i) {
        if (binary_search(a+1, a+n+1, (x-a[id]+m) % m)) return true;
    }
    return false;
}

int main()
{
    srand(time(NULL));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
        res[0].insert((a[1]+a[i]) % m);
    }
    int u = 0;
    for (int i = 1; i <= 4; ++i) {
        int id = rand() % n + 1;
        for (int x : res[u]) {
            if (sky(x, id)) {
                res[1-u].insert(x);
            }
        }
        res[u].clear();
        u = 1-u;
    }
    for (int x : res[u]) {
        if (check(x)) {
            res[1-u].insert(x);
        }
        u = 1-u;
    }
    printf("%d\n", res[u].size());
    for (int x : res[u]) {
        printf("%d ", x);
    }
    return 0;
}
