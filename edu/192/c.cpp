#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	int n,k;
	cin >> n >> k;

	int cnt[n];
	fill(cnt,cnt+n,0);

	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		cnt[x-1]++;
	}

	map<int,int> m;
	int qtd=0;
	for(int i=0;i<n;i++) if(cnt[i]) {
		m[cnt[i]]++;
		qtd++;
	}

	int ans = 0;
	int del = 0;

	//if(k>n and (k-n)%qtd==0) ans++;
	bool b = true;

	for(int rem = 0; rem<n; rem++) {
		if(m.find(rem)==m.end() and b==false) continue;
		//cout << " x" << rem << ' ';
		if(rem) del += qtd;
		qtd -= m[rem];
		//cout << rem << ' ' << del << ' ' << qtd << ' ';
		//m.erase(rem);
		if(qtd==0) break;
		
		if(k<(n-del) and m[rem]>0) b = true;
		else if(k>=(n-del) and (k-(n-del))%qtd==0) {
			//cout << " ok";
			ans++;
			b = false;
			//else b = false;
		} else b = true;

		//cout << '\n';
	}

	cout << ans << '\n';
	//cout << "\n\n\n\n\n";
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
