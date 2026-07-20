#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void no() {
	cout << "No\n";
}

void solve() {
	int n,m;
	cin >> n >> m;

	bool adj[n][n];
	for(int i=0;i<m;i++) {
		int o,a,b;
		cin >> o >> a >> b;
		a--;
		b--;

		adj[a][b] = adj[b][a] = (o==1); //1 = nao negativo
	}

	vector<pair<int,int>> neg;
	vector<pair<int,int>> pos;

	for(int i=0;i<n;i++) {
		if(adj[i][i]) pos.push_back(pair(0,i));
		else neg.push_back(pair(0,i));
	}

	for(ull i=0;i<neg.size();i++) {
		for(ull j=i+1;j<neg.size();j++) if(adj[neg[i].ss][neg[j].ss]) return no();
		for(int j=0;j<n;j++) if(adj[neg[i].ss][j]) neg[i].ff++;
	}

	
	for(ull i=0;i<pos.size();i++) {
		for(ull j=i+1;j<pos.size();j++)
			if(not adj[pos[i].ss][pos[j].ss]) return no();
	}

	//for(int i=0;i<neg.size();i++) cout << neg[i].ff << ' ' << neg[i].ss+1 << '\n';
	sort(neg.rbegin(),neg.rend());

	if(neg.empty()) {
		cout << "Yes\n";
		for(int i=0;i<n;i++) cout << 0 << ' ';
		cout << '\n';
		return;
	} else if(pos.empty()) {
		cout << "Yes\n";
		for(int i=0;i<n;i++) cout << -1 << ' ';
		cout << '\n';
		return;
	}

	ll ans[n];
	int v = neg[0].ss;
	ll act = -1;
	ans[v] = act;
	ll apos = 0;

	set<int> setpos;
	//cout << "v = " << v << '\n';
	for(int i=0;i<n;i++) {
		if(adj[i][i]==false) continue;
		if(adj[v][i]) setpos.insert(i);
		else {
			ans[i] = apos;
	//		cout << "definiu " << i << '\n';
		}
	}
		
	for(ull i=1;i<neg.size();i++) {
		act -= 2;
		apos += 2;
		v = neg[i].ss;

		ans[v] = act;
	//	cout << "v = " << v << '\n';
		for(int j=0;j<n;j++) {
			if(not adj[j][j]) continue;

			if(adj[v][j]) { // ainda nao negativo, TEM q estar em setpos
				if(setpos.count(j)==0ull) return no();
			} else { // negativo. ver se mudou agr ou ja tava
				if(setpos.count(j)) {
					setpos.erase(j);
					ans[j] = apos;
	//				cout << "definiu " << j << '\n';
				}
			}
		}
	}

	apos+=2;
	for(int i : setpos) ans[i] = apos;
	//for(int i=0;i<n;i++) cout << ans[i] << ' ';
	//cout << '\n';
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(adj[i][j] != (ans[i]+ans[j]>=0ll)) return no();
		}
	}

	cout << "Yes\n";
	for(int i=0;i<n;i++) cout << ans[i] << ' ';
	cout << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
