#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

ll qtd;
void add(vector<ll> &seg, ll a, ll b, ll pos, ll i) {
	if(a==i and b==i) {seg[pos]+=qtd;return;}
	if(i<a or b<i) return;

	ll m = (a+b)/2;
	add(seg,a,m,2*pos+1,i);
	add(seg,m+1,b,2*pos+2,i);
	seg[pos]=seg[2*pos+1]+seg[2*pos+2];
}

ll get(vector<ll> &seg, ll a, ll b, ll pos, ll l, ll r) {
	if(b<a) return 0;
	if(l<=a and b<=r) return seg[pos];
	else if(r<a or b<l) return 0;

	ll m = (a+b)/2;
	return get(seg,a,m,2*pos+1,l,r)+get(seg,m+1,b,2*pos+2,l,r);
}


int main() { 
	ll n; cin >> n;
	ll ans = 0;

	//tempo -> indice
	map<ll,ll> m;
	// indice -> tempo ,peso,
	vector<pair<ll,ll>> p(n);
	ll a,b;
	for(ll i=0;i<n;i++) {
		cin >> a >> b;
		p[i] = make_pair(a,b);
		m[a] = i;
	}
	vector<ll> st(n*4,0);
	vector<ll> sp(n+1,0);
	for(ll i=1;i<=n;i++) sp[i] = sp[i-1]+p[i-1].second;
	for(ll t=1;t<=n;t++) {// i é tempo
		ll i = m[t]; // i é indice agr

		ans += sp[i+1];
		ans+=get(st,0,n-1,0,i+1,n-1);
		qtd = p[i].second;
		add(st,0,n-1,0,i);
	}

	cout << ans << '\n';

    return 0;
}
