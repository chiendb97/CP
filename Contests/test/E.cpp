#include <bits/stdc++.h>

using namespace std;

const int nMax = 1003;
int a[nMax][nMax];
int b[nMax][nMax];
int d[1000006];
int main(){
	int n , m;

	cin >> n >> m ;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	}
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			vector<int> v;
			v.push_back(a[i][j]);
			v.push_back(a[i][m+1-j]);
			v.push_back(a[n+1-i][j]);
			v.push_back(a[n+1-i][m+1-j]);
			for (int u : v){
				d[u]=0;
			}
			for (int u : v){
				d[u]++;
			}
			int ua = v[0];
			for (int u : v){
				if (d[u] > d[ua]){
					ua = u;
				}
			}
			a[i][j] = a[i][m+1-j] = a[n+1-i][j] = a[n+1-i][m+1-j] = ua;

		}
	}
	int ans = 0 ;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (a[i][j]!=b[i][j]) ans++;
		}
	}
	cout << ans;
}
