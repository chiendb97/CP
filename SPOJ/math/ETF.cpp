#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int N = 1e6+5;

int minPr[N];
bool nonPr[N];
vector<ii> num[N];
long long power[N][22];
int phi[N];

void erotos()
{
    for (int i = 2; i < N; ++i) {
        if (!nonPr[i]) {
            minPr[i] = i;
            for (int j = min(1LL*i*i, 1LL*N); j < N; j += i) {
                if (!minPr[j]) {
                    nonPr[j] = true;
                    minPr[j] = i;
                }
            }
        }
    }
    for (int i = 2; i < N; ++i) {
        power[i][0] = 1;
        int x = i;
        while (x > 1) {
            int d = minPr[x];
            if (!num[i].size() || num[i][num[i].size()-1].first != d) {
                num[i].push_back(ii(d, 1));
            }
            else {
                ++num[i][num[i].size()-1].second;
            }
            x /= d;
        }
    }
    for (int i = 2; i < N; ++i) {
        for (int j = 1; power[i][j-1] < N; ++j) {
            power[i][j] = power[i][j-1]*i;
        }
    }
    for (int i = 1; i < N; ++i) {
        phi[i] = 1;
        for (auto x : num[i]) {
            phi[i] *= power[x.first][x.second-1]*(x.first-1);
        }
    }
}

int main()
{
    int test;
    cin >> test;
    while (test--) {
        int x;
        cin >> x;
        int ans = x;
        for (int i = 2; i*i <= x; ++i) {
            if (x % i == 0) {
                ans -= ans/i;
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        if (x > 1) {
            ans -= ans / x;
        }
        cout << ans << "\n";
    }
    return 0;
}
