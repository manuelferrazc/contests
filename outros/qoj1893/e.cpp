#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define int ll

#define MAX 200'100

vector<pair<int,int>> andares[MAX]; // altura, indice na entrada
pair<int,int> st[4*MAX];// altura max, min index

pii comb(pii a, pii b) {
	if(a.ff!=b.ff) return max(a,b);
	return pair(a.ff, min(a.ss,b.ss));
}

pii build(int p, int l, int r){
	if(l==r) {
		sort(andares[l].begin(),andares[l].end());
		if(andares[l].empty()) return st[p] = pair(-1,l);
		return st[p] = pair(andares[l].back().ff,l);
	}

	int m = (l+r)/2;
	auto pl = build(2*p,l,m);
	auto pr = build(2*p+1,m+1,r);
	return st[p] = comb(pl,pr);
}

pii query(int p, int l, int r, int lq, int rq) {
	if(rq<l or r<lq) return pair(-1,-1);
	if(lq<=l and r<=rq) return st[p];
	int m = (l+r)/2;
	auto pl = query(2*p,l,m,lq,rq);
	auto pr = query(2*p+1,m+1,r,lq,rq);
	return comb(pl,pr);
}

pii update(int p, int l, int r, int i) { //deleta o max na posicao i,retorna o deletado
	if(l==r) {
		pii ret = andares[l].back();andares[l].pop_back();
		if(andares[i].empty()) st[p] = pair(-1,l);
		else st[p] = pair(andares[i].back().ff,l);
		return ret;
	}
	int m = (l+r)/2;
	pii ret;
	if(i<=m) ret = update(2*p,l,m,i);
	else ret = update(2*p+1,m+1,r,i);
	st[p] = comb(st[2*p],st[2*p+1]);
	return ret;
}

pii first(int p, int l, int r, int lq, int rq) {
	if(l==r) return st[p];
	if(r<lq or rq<l or st[p].ff==-1) return pair(-1,-1);

	int m = (l+r)/2;
	pii pl = first(2*p,l,m,lq,rq);
	if(pl.ff!=-1) return pl;
	return first(2*p+1,m+1,r,lq,rq);
}

void solve() {
	ll n,f;
	cin >> n >> f;

	pii pessoas[n];
	vector<int> comp;
	comp.push_back(f);
	for(int i = 0;i<n;i++) {
		int l,r;
		cin >> l >> r;
		pessoas[i] = pair(l,r);
		comp.push_back(l);
		comp.push_back(r);
	}

	sort(comp.begin(),comp.end());
	comp.erase(unique(comp.begin(),comp.end()),comp.end());

	for(int i=0;i<n;i++) {
		auto [l,r] = pessoas[i];
		int cl = lower_bound(comp.begin(),comp.end(),l)-comp.begin();
		int cr = lower_bound(comp.begin(),comp.end(),r)-comp.begin();

		andares[cl].push_back(pair(cr,i));
	}

	build(1,0,2*n);

	ll ans = 0;
	vector<int> seq;

	for(int k=0;k<n;k++) {
		//cout << "f = " << f << '\n';
		int fc = lower_bound(comp.begin(),comp.end(),f)-comp.begin();

		pii best = query(1,0,2*n,0,fc);
		
		//cout << "best1 = " << best.ff << ' ' << best.ss << '\n';
		if(best.ff!=-1 and best.ff>=fc) {
			// p = par andar, id na entrada
			pii p = update(1,0,2*n,best.ss);

			seq.push_back(p.ss);
			ans += pessoas[p.ss].ss - pessoas[p.ss].ff;
			f = comp[p.ff];
		//cout << "caso 1:" << ans << ' ' << f << '\n';	
			continue;
		}

		best = first(1,0,2*n,fc,2*n);
		//cout << "best2 = " << best.ff << ' ' << best.ss << '\n';
		if(best.ff!=-1) {
			pii p = update(1,0,2*n,best.ss);

			seq.push_back(p.ss);
			ans += pessoas[p.ss].ss - f;
			f = comp[p.ff];
		//	cout << "caso 2: " << ans << ' ' << f <<  '\n';
			continue;
		}

		best = query(1,0,2*n,0,2*n);
		pii p = update(1,0,2*n,best.ss);
		seq.push_back(p.ss);
		ans += pessoas[p.ss].ss - pessoas[p.ss].ff;
		f = pessoas[p.ss].ss;
		//cout << "caso 3: " << ans << ' ' << f << '\n';
	}


	cout << ans << '\n';
	for(int i=0;i<n;i++) cout << seq[i]+1 << ' ';
	cout << '\n';

	//assert(st[1].ff==-1);
	//for(int i=0;i<MAX;i++) assert(andares[i].empty());
}

signed main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
