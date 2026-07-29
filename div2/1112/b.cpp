#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void no() {
	cout << -1 << '\n';
}

void solve() {
	int n,k;
	cin >> n >> k;

	if(k==n-1) return no();

	if(n%2==0) {
		int q=n/2;
		string pref(k/2+1,'0');
		string suf(k/2+1,'1');
		q-=k/2+1;

		cout << pref;//.size();
		if(k&1) {
			cout << 1;
			q--;
			suf.push_back('0');
		}
		while(q--) cout << "10";
		cout << suf << '\n';
	} else {
		int q = n/2;
		string pref(k/2+1,'0');
		string suf(k/2+1,'1');
		q-=k/2+1;
		//cout << "sla " << pref.size() << 's';
		//cout << pref;
		if(k&1) cout << 0;
		else cout << 1;
		cout << pref;
		while(q--) cout << 10;
		cout << suf << '\n';
	}
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
