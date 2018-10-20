#include <bits/stdc++.h>
using namespace std;

int to_num(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        res = res * 10 + s[i] - 48;
    }
    return res;
}

int main() {
    while (true) {
    int n;
    cin >> n;
    map<int, int> t;
    t[n] = -1;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int u = q.front();
        if (u == 1) break;
        q.pop();
        if (t.find(u - 1) == t.end()) {
            q.push(u - 1);
            t[u - 1] = u;
        }
        string s = to_string(u);
        vector<int> d;
        for (int i = 0; i < s.length(); i++) {
            d.push_back(i);
        }
        do {
            string b;
            for (int i: d) {
                b = b + s[i];
            }
            if (b[0] != '0') {
                int v = to_num(b);
                if (t.find(v) == t.end()) {
                    t[v] = u;
                    q.push(v);
                }
            }
        } while (next_permutation(d.begin(), d.end()));
    }
    vector<int> res;
    res.push_back(1);
    int v = t[1];
    while (v != -1) {
        res.push_back(v);
        v = t[v];
    }
    for (int i: res) {
        cout << i << endl;
    }
    cout << res.size();
    }
}

