/*
kiem tra so nguyen to bang random
*/

#include <bits/stdc++.h>

using namespace std;

int power(int x, int m, int n)
{
    int ans = 1;
    while (m) {
        if (m&1) {
            ans = (1LL*ans*x) % n;
        }
        x = (1LL*x*x) % n;
        m >>= 1;
    }
    return ans % n;
}

bool mr(int n, int s, int m)
{
    int x = 2 + rand() % (n-2);
    int b = power(x, m, n);
    if (b == 1 || b == n-1) return true;
    for (int i = 0; i < s; ++i) {
        b = (1LL*b*b) % n;
        if (b == 1) return false;
        if (b == n-1) return true;
    }
    return false;
}

bool check(int n)
{
    if (n < 2) return false;
    if (n == 2) return true;
    int m = n - 1, s = 0;
    while (m % 2 == 0) {
        ++s;
        m /= 2;
    }
    for (int i = 1; i <= 50; ++i) {
        if (!mr(n, s, m)) return false;
    }
    return true;
}

int main()
{
    srand(time(NULL));
    int n;
    while (cin >> n && n) {
        cout << check(n) << "\n";
    }
    return 0;
}
