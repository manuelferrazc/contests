#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define MAX 100100
const ld eps = -1e8;

pair<ll,ll> st[4*MAX]; // # ruas, custo

void build() {
	fill(st,st+4*MAX,pair(0ll,0ll));
}

pair<ll,ll> comb(pair<ll,ll> a, pair<ll,ll> b) {
	return pair( a.ff+b.ff , a.ss+b.ss );
}

pair<ll,ll> update(int p, int l, int r, int i, pair<ll,ll> x) {
	if(l==r) return st[p] = x;

	int m = (l+r)/2;
	if(i<=m) return st[p] = comb( update(2*p,l,m,i,x) , st[2*p+1] );
	return st[p] = comb ( st[2*p], update(2*p+1,m+1,r,i,x) );
}

// id, # ruas q faltam, custo
array<ll,3> get(int p, int l, int r, ll k) {
	if(l==r) {
		if(k<=st[p].ff) return { l-1, k , 0};
		else return { l, k - st[p].ff , st[p].ss };
	}

	int m = (l+r)/2;
	if(st[2*p].ff<k) {
		auto [a,b,c] = get(2*p+1,m+1,r,k-st[2*p].ff);
		return {a,b,c+st[2*p].ss};
	} else return get(2*p,l,m,k);
}

//struct sla {
//	ll h;
//	ld l;
//	ld r;
//	int id;
//};

struct tupla {
	ll x;
	ll h;
	int id;
	int op;
};

//bool eq(ld a, ld b) {
//	return abs(a-b)<=eps;
//}

int main() { _
	build();

	ll n,s,k;
	cin >> n >> s >> k;

	array<ll,3> v[n]; // h, l, r
	for(int i=0;i<n;i++) {
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}

	array<ll,4> v2[n];
	for(int i=0;i<n;i++) {
		for(int j=0;j<3;j++) v2[i][j] = v[i][j];
		v2[i][3] = i;
	}

	sort(v2,v2+n);

	int rev[n];
	for(int i=0;i<n;i++) rev[v2[i][3]] = i;

	//sla v3[n];
		
	tupla ev[2*n];
	for(int i=0;i<n;i++) {
		//v3[i].h = v[i][0];
		//v3[i].l = ((ld)v[i][1])/v[i][0];
		//v3[i].r = ((ld)v[i][2])/v[i][0];
		//v3[i].id = i;

		ev[2*i] = { v[i][1], v[i][0] ,i,0};
		ev[2*i+1]={ v[i][2], v[i][0] ,i,1};
	}

	//sort(v3,v3+n, [] (sla a, sla b) -> bool {
	//	return a.l < b.l;
	//});

	sort(ev,ev+2*n, [](tupla a, tupla b) -> bool {
		// a.x/a.h < b.x/b.h or igual and a.op<b.op
		ll l = a.x*b.h;
		ll r = b.x*a.h;
		return l<r or (l==r and a.op<b.op);
	});

	ll a = LLONG_MAX;
	ll b = 1;

	map<ll, ll > m;

	for(auto [x1,x2,id,op]:ev) {
		if(op==0) { // operacao de inserir intervalo
			ll ruas = k/v[id][0];
			
			update(1,0,n-1, rev[id] , pair( ruas , ruas*v[id][0] ) );
			m[rev[id]] = v[id][0];


			auto [next,ruas_faltam, custo] = get(1,0,n-1, s);
			auto it = m.upper_bound(next);
			if(it==m.end()) continue;

			ll qtd = it->ss;
			// #horas = custo + ruas_faltam*qtd
			// # ans = #horas * val/hora
			// #val/hora = v[i][1]/v[i][0]

			ll horas = custo + ruas_faltam*qtd;
			ll aa = horas * v[id][1];
			ll bb = v[id][0];
			
			ll g = gcd(aa,bb);
			aa/=g;
			bb/=g;

			__int128 left = a;
			left*=bb;

			__int128 rig = b;
			rig*=aa;

			// a/b > aa/bb => a*bb > aa*b
			if(a==LLONG_MAX or left>rig) {
				a = aa;
				b = bb;
			}
		} else { // op de remover intervalo
			update(1,0,n-1, rev[id], pair(0ll,0ll));
			m.erase(rev[id]);
		}
	}

	if(a==LLONG_MAX) cout << "*\n";
	else cout << a << ' ' << b << '\n';

	return 0;
}
