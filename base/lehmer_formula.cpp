/*
Dem so luong so nguyen to nho hon hoac bang n
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
const long long MOD = 1e9+7;

bool check[N];
int prime[N], np = 0;

void eratos()
{
    check[0] = check[1] = true;
    for (int i = 2; i*i < N; ++i) {
        if (!check[i]) {
            for (int j = i*i; j < N; j +=i) {
                check[j] = true;
            }
        }
    }
    for (int i = 2; i < N; ++i) {
        if (!check[i]) {
            prime[++np] = i;
        }
    }
}

long long power(long long a, long long k)
{
    long long ans = 1;
    while (k) {
        if (k & 1) {
            ans *= a;
        }
        a = a*a;
        k >>= 1;
    }
    return ans;
}

long long power(long long a, long long k, long long M)
{
    long long ans = 1;
    while (k) {
        if (k & 1) {
            ans = (ans*a) % M;
        }
        a = (a*a) % M;
        k >>= 1;
    }
    return ans % M;
}

long long root(long long n, long long k)
{
    long long x = pow(n, 1.0/k);
    while (power(x, k) % MOD == power(x, k, MOD) && power(x, k) < n) ++x;
    while (power(x, k) % MOD != power(x, k, MOD) || power(x, k) > n) --x;
    return x;
}

map<long long, long long> phi[N];

long long calc_phi(long long x, int a)
{
    if (phi[a].count(x)) return phi[a][x];
    if (a == 1) return (x + 1)/2;
    long long res = calc_phi(x, a-1) - calc_phi(x/prime[a], a-1);
    return phi[a][x] = res;
}

long long lehmer(long long x)
{
    if (x < N) return upper_bound(prime+1, prime+np+1, x) - (prime+1);
    long long a = lehmer(root(x, 4));
    long long b = lehmer(root(x, 2));
    long long c = lehmer(root(x, 3));
    long sum = calc_phi(x, a) + (b + a - 2)*(b - a + 1)/2;
    for (int i = a+1; i <= b; ++i) {
        sum -= lehmer(x/prime[i]);
    }
    for (int i = a+1; i <= c; ++i) {
        long long bi = lehmer(root(x/prime[i], 2));
        for (int j = i; j <= bi; ++j) {
            sum -= lehmer(x/prime[i]/prime[j]) - (j-1);
        }
    }
    return sum;
}

int main()
{
    eratos();
    int n;
    cin >> n;
    cout << lehmer(n);
    return 0;
}
