#include <bits/stdc++.h>

using namespace std;

int end0(string N){
	for (int i = 1 ; i<N.size(); i++){
		if (N[i] != '0') return 0;
	}
	return 1;
}
int is10muK(string N){
	if (N[0] != '1') return 0;
	return end0(N);
}

int calc(string N){
	int k = N.length()-1;
	if (k == 0) return N[0] - '1';
	if (is10muK(N)){
		return 10*(k+1)*k/2 - k;
	}
	if (N[0] == '1'){
		int ans = 0;
		for (int i = k; i>=1; i--){
			if (N[i] != '0'){
				if (i!= k) ans ++;
				ans += N[i]-'0';
				N[i] = '0';
			}
		}
		ans += calc(N);
		return ans;
	}
	else{
		int vt=-1;
		for (int i = 1; i<=k; i++){
			if (N[i] == '1'){
				vt = i;
				break;
			}
		}
		if (vt != -1){
			N[vt] = N[0];
			N[0]  = '1';
			sort(N.begin()+1, N.end());
			return calc(N) + 1 ;
		}
		else{
			if (end0(N)){
				N[0]--;
				for (int i=1; i<=k; i++) N[i] = '9';
				return calc(N) + 1;
			}
			if (N[k] == '0'){
				for (int i = 1; i<k; i++){
					if (N[i]!='0'){
						N[k] = N[i];
						N[i] = '0';
						return calc(N) + 1;
					}
				}
			}
			int ans = 0 ;
			ans += N[k] - '1';
			ans ++;
			N[k] = N[0];
			N[0] = '1';
			ans += calc(N);
			return ans ;
		}
	}
}

int main(){
	int  T ;
	string N;
	cin >> T;
	while (T--){
		cin >> N ;
		cout << calc(N) << endl;
	}
	return 0;
}
