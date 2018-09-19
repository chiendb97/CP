#include <bits/stdc++.h>

using namespace std;

long long xa = 1, ya = 0, xb = 0, yb = 1;

long long euclid(long long a, long long b)
{
    while (b) {
        long long q = a / b;
        long long r = a % b;
        a = b;
        b = r;
        long long xr = xa - q*xb;
        long long yr = ya - q*yb;
        xa = xb; xb = xr;
        ya = yb; yb = yr;
    }
    return a;
}

int main()
{
    long long a1, a2, b1, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    if (a1 == 0 && a2 == 0 && b1 == b2) {
        cout << "0 0";
        return 0;
    }
    else if (a1 == 0) {
        cout << "0 " << (b1-b2)/a2;
        return 0;
    }
    else if (a2 == 0) {
        cout << (b2-b1)/a1 << " 0";
        return 0;
    }
    long long gcd = euclid(a1, -a2);
    xa = (b2-b1)/gcd*xa;
    ya = (b2-b1)/gcd*ya;
    if (gcd < 0) gcd = -gcd;
    long long q = a1 / gcd;
    long long p = a2 / gcd;
    xa = (xa % p + p) % p;
    ya = (a1*xa + b1 - b2)/a2;
    if (ya >= 0) {
        cout << xa << " " << ya;
        return 0;
    }
    ya = (ya % q + q) % q;
    xa = (a2*ya + b2 - b1)/a1;
    if (xa >= 0) {
        cout << xa << " " << ya;
        return 0;
    }
    cout << "0 0";
    return 0;
}
