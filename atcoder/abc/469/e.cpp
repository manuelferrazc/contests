#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

int n,k;
string s;
int qo[1'000'001];

int get(int l, int r) {
	if(l) return qo[r]-qo[l-1];
	return qo[r];
}

bool eq(ld a, ld b) {
	return fabs(a-b)<1e-9;
}

bool ok(ld p) {
	ld a[n+1];
	a[0] = 0;
	for(int i=0;i<n;i++) a[i+1] = (s[i]=='o'? 1-p : -p);

	ld s[n+1];
	s[0] = 0;
	for(int i=1;i<=n;i++) s[i] = s[i-1]+a[i];

	ld mi[n+1];
	mi[0] = 0;
	for(int i=1;i<=n;i++) mi[i] = min(s[i],mi[i-1]);

	ll l=1;
	for(int r=1;r<=n;r++) {
		while(l<r and get(l+1,r)>=k) l++;

		ld x = s[r];
		if(l) x -= mi[l-1];

		if(get(l,r)>=k and x>-1e-9) return true;
	}
	
	return false;
}

int main() { _
	cin >> n >> k >> s;
	
	qo[0] = 0;
	for(int i=1;i<=n;i++) qo[i] = qo[i-1]+(s[i-1]=='o');

	ld l=0,r=1;
	while(not eq(l,r)) {
		ld m = (l+r)/2;
		if(ok(m)) l = m;
		else r = m;
	}

	cout << fixed << setprecision(10) << l << '\n';

    return 0;
}
