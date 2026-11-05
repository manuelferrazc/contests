#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 400'000

string s;
int sp[MAX];

void build(int n) {
	sp[0] = 1;
	for(int i=1;i<n;i++) sp[i] = sp[i-1] + (s[i]=='(');
}

int getA(int l, int r) {
	//cout << l << ' ' << r << '\n';
	assert(l>=0);
	if(l==0) return sp[r];
	return sp[r]-sp[l-1];
}

int getF(int l, int r) {
	return r-l+1 - getA(l,r);
}

void solve() {
	int n,k;
	cin >> n >> k;
	cin >> s;

	if(k==n/2) {
		cout << k << '\n';
		return;
	}

	build(n);
	int ans = k;

	int r = n-1; // prox a avaliar pra puxar um (
	int l = 0; // proximo ) a empurar pro final
	
	//cout << "CASE-----------\n";
	while(getF(0,l+1)<=k) l++;
	// l aponta pra ultima posicao cujo pref tem <= pa  ')'
	// r aponta pra primeira posicao cujo suf tem >= k-pa '('
	for(int pa = k;pa>=0;pa--) {
		while(getF(0,l)>pa) l--;
		while(getA(r,n-1)<k-pa) r--;
		// vou empurar pa ) para o final e puxar k-pa ( pro comeco

		ans = max(ans, getA(0,l)+getA(max(l+1,r),n-1));
	//	cout << pa << ' ' << ans << ' ' << l << ' ' << r << '\n';
	}

	if(ans==n/2) {
		cout << ans << '\n';
		return;
	}

	//cout << ans << '\n';

	int b = 0;
	for(int a=0;a<n;a++) {
		b = max(a,b);
		if(s[a]==')') continue;
		while(b<n-1 and getF(a,b+1)<=k) b++;
		ans = max(ans, getA(a,b)-getF(a,b));
		//cout << a << ' ' << b << ' ' << ans << '\n';
	}

	cout << ans << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
