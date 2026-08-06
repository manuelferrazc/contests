#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void zero(int *v, int n) {
	fill(v,v+n,0);
}

void sp(int *v, int n, int *sp) {
	sp[0] = v[0];
	for(int i=1;i<n;i++) sp[i] = sp[i-1]+v[i];
}

int get(int *sp, int l, int r) {
	if(l==0) return sp[r];
	return sp[r]-sp[l-1];
}

void solve() {
	int n,q;
	cin >> n >> q;
	string s,t;
	cin >> s >> t;

	int v00[n],v11[n],v01[n],v10[n];
	zero(v00,n);
	zero(v01,n);
	zero(v10,n);
	zero(v11,n);

	for(int i=0;i<n;i++) {
		if(s[i]=='0' and t[i]=='0') v00[i]=1;
		else if(s[i]=='0') v01[i]=1;
		else if(t[i]=='0') v10[i]=1;
		else v11[i] = 1;
	}

	int s00[n],s11[n],s10[n],s01[n];
	sp(v00,n,s00);
	sp(v01,n,s01);
	sp(v10,n,s10);
	sp(v11,n,s11);

	while(q--) {
		int l,r;
		cin >> l >> r;
		l--;
		r--;

		int zz = get(s00,l,r);
		int uu = get(s11,l,r);
		int zu = get(s01,l,r);
		int uz = get(s10,l,r);

		int dif = abs(uz-zu);
		//cout << zz << ' ' << zu << ' ' << uz << ' ' << uu << ' ';
		if(uu+zz>=dif) cout << "Yes\n";
		else {
			//int dif = abs(uz-zu);
			//if(uz>zu) {
				
			//}
			cout << "No\n";
		}
	}
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
