#include <bits/stdc++.h>

using namespace std;


long long x_1, y_1, R1, x_2, y_2, R2, x_0, y_0;

double dis(double a, double b, double c, double d)
{
    return sqrt((a-c)*(a-c) + (b-d)*(b-d));
}

double calc(double x)
{
    double yh = sqrt(R2*R2-(x-x_2)*(x-x_2))+y_2;
    double yb = -sqrt(R2*R2-(x-x_2)*(x-x_2))+y_2;
    return min(dis(x, yh, x_1, y_1) + dis(x_0, y_0, x, yh), dis(x, yb, x_1, y_1) + dis(x_0, y_0, x, yb)) - R1;
}

double tsearch(double l, double r)
{
    for (int i = 1; i <= 80; ++i) {
        double mid1 = l+(r-l)/3;
        double mid2 = r-(r-l)/3;
        if (calc(mid1) > calc(mid2)) {
            l = mid1;
        }
        else {
            r = mid2;
        }
    }
    return calc(l);
}

int main()
{
    cout.precision(9);
    cin >> x_1 >> y_1 >> R1 >> x_2 >> y_2 >> R2 >> x_0 >> y_0;
    if ((x_0-x_1)*(x_0-x_1) + (y_0-y_1)*(y_0-y_1) <= R1*R1) {
        cout << fixed << dis(x_0, y_0, x_2, y_2) - R2;
        return 0;
    }
    else if ((x_0-x_2)*(x_0-x_2) + (y_0-y_2)*(y_0-y_2) <= R2*R2) {
        cout << fixed << dis(x_0, y_0, x_1, y_1) - R1;
        return 0;
    }
    double ans = tsearch(x_2-R2, x_2+R2);
    swap(x_1, x_2);
    swap(y_1, y_2);
    swap(R1, R2);
    ans = min(ans, tsearch(x_2-R2, x_2+R2));
    cout << fixed << ans;
    return 0;
}
