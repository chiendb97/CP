#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const long long MOD = 998244353;

int n, k, x[4][4];
long long f[N][2*N][4];

int main()
{
    x[1][2] = x[2][1] = 2;
    x[0][1] = x[0][2] = x[0][3] = x[3][0] = x[3][1] = x[3][2] = 1;
    f[1][1][0] = f[1][2][1] = f[1][2][2] = f[1][1][3] = 1;
    cin >> n >> k;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int u = 0; u < 4; ++u) {
                for (int v = 0; v < 4; ++v) {
                    if (j > x[v][u]) {
                        f[i][j][u] = (f[i][j][u] + f[i-1][j-x[v][u]][v]) % MOD;
                    }
                }
            }
        }
    }
    cout << (f[n][k][0] + f[n][k][1] + f[n][k][2] + f[n][k][3]) % MOD;
    return 0;
}
