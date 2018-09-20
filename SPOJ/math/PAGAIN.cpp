#include <bits/stdc++.h>

using namespace std;

unsigned long long power(unsigned long long x, unsigned long long m, unsigned long long n)
{
    unsigned long long ans = 1;
    while (m) {
        if (m&1) {
            ans = (ans*x) % n;
        }
        x = (x*x) % n;
        m >>= 1;
    }
    return ans % n;
}

bool mr(unsigned long long n, unsigned long long s, unsigned long long m)
{
    unsigned long long x = 2 + rand() % (n-2);
    unsigned long long b = power(x, m, n);
    if (b == 1 || b == n-1) return true;
    for (int i = 0; i < s; ++i) {
        b = (b*b) % n;
        if (b == 1) return false;
        if (b == n-1) return true;
    }
    return false;
}

bool check(unsigned long long n)
{
    if (n < 2) return false;
    if (n == 2) return true;
    unsigned long long m = n - 1, s = 0;
    while (m % 2 == 0) {
        ++s;
        m /= 2;
    }
    for (int i = 1; i <= 30; ++i) {
        if (!mr(n, s, m)) return false;
    }
    return true;
}

unsigned long long solve(unsigned long long n)
{
    for (long long i = n-1; i; --i) {
        if (check(i)) return i;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    long long n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << solve(n) << "\n";
    }
}

