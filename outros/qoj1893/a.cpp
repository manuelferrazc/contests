#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int p[26];
int r[26];

int get(int a) {
	return p[a] = (p[a]==a? a : get(p[a]));
}

void unir(int a, int b) {
	a = get(a);
	b = get(b);

	if(a==b) return;
	if(r[a]<r[b]) swap(a,b);
	if(r[a]==r[b]) r[a]++;
	p[b] = a;
}

void build() {
	for(int i=0;i<26;i++) {
		p[i] = i;
		r[i] = 0;
	}
}

bool brute(string &a, string &b, string &c) {
	int n = a.size();
	for(int i=0;i<n;i++) unir(a[i]-'a',b[i]-'a');
	for(int i=0;i<n;i++) if(get(a[i]-'a')!=get(c[i]-'a')) return true;
	return false;
}

void yes() {
	cout << "YES\n";
}

void no() {
	cout << "NO\n";
}

void solve() {
	string a,b,c;
	cin >> a >> b >> c;
	int na = a.size(), nb = b.size(), nc = c.size();

	if(na==nb and nb==nc) {
		build();
		if(brute(a,b,c)) return yes();
		//if(brute(a,c,b)) return yes();
		//if(brute(b,c,a)) return yes();
	} else if(na==nb) return yes();

	no();
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
