#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 200100

ll sp[MAX];
ll v[MAX];

ll st[4*MAX];
int lazy[4*MAX];// 0 -> zerar, 1 -> resetar, -1 -> nop

ll get(int l, int r) {
	if(l) return sp[r]-sp[l-1];
	return sp[r];
}


void build(int p, int l, int r) {
	lazy[p] = -1;
	st[p] = get(l,r);
	if(l==r) return;

	int m = (l+r)/2;
	build(2*p,l,m);
	build(2*p+1,m+1,r);
}

void prop(int p, int l, int r) {
	if(lazy[p]==-1) return;

	if(lazy[p]==1) st[p] = get(l,r);
	else if(lazy[p]==0) st[p] = 0;
	if(l!=r) lazy[2*p] = lazy[2*p+1] = lazy[p];
	lazy[p] = -1;
}

ll query(int p, int l, int r, int lq, int rq) {
	prop(p,l,r);
	if(rq<l or r<lq) return 0;
	if(lq<=l and r<=rq) return st[p];

	int m = (l+r)/2;
	return query(2*p,l,m,lq,rq)+query(2*p+1,m+1,r,lq,rq);
}

ll reset(int p, int l, int r, int lq, int rq) {
	prop(p,l,r);
	if(rq<l or r<lq) return st[p];
	if(lq<=l and r<=rq) {
		lazy[p] = 1;
		prop(p,l,r);
		return st[p];
	}

	int m = (l+r)/2;
	return st[p] = reset(2*p,l,m,lq,rq) + reset(2*p+1,m+1,r,lq,rq);
}

void update_pos(int p, int l, int r) {
	prop(p,l,r);
	if(l!=r) {
		int m = (l+r)/2;
		prop(2*p,l,m);
		prop(2*p+1,m+1,r);
		st[p] = st[2*p]+st[2*p+1];
	};
}

ll update(int p, int l, int r, int pref, ll qtd) {
	prop(p,l,r);
	if(qtd==0) return 0;
	int m = (l+r)/2;

	if(pref>=r) {
		if(st[p]<=qtd) { // eu zero tudo em [l,r]
			lazy[p] = 0;
			ll ret = qtd-st[p];
			prop(p,l,r);
			assert(st[p]==0);
			return ret;
		} else { // nao zero tudo
			st[p] -= qtd;
			if(l!=r) {
				prop(2*p+1,m+1,r);
				if(st[2*p+1]<=qtd) { // zero tudo na direita
					lazy[2*p+1] = 0;
					qtd -= st[2*p+1];
					update(2*p,l,m,pref,qtd);
					
				} else update(2*p+1,m+1,r,pref,qtd); // sobra na direita -> vou pra la
			}

			return 0; // eh folha e nao zero tudo -> nao propaga nada pro lado
		}
	} else { // nao to inteiramente no prefixo
		if(l>pref) return qtd; // [l,r] eh disjunto, nao deposito nada
		if(pref<=m) {
			ll ret = update(2*p,l,m,pref,qtd);// prefixo disjunto com dir
			update_pos(p,l,r);
			return ret;
		}
		else { // prefixo ta em [l+1,r]
			ll rem = update(2*p+1,m+1,r,pref,qtd); // rem -> quanto sobra de dir (propagar pra esq)
			ll rem2 = 0; 
			if(rem) rem2 = update(2*p,l,m,pref,rem); // rem2-> quanto falta propagar pro lado
			update_pos(p,l,r);
			return rem2;
		}
	}
}

void dfs(int p, int l, int r) {
	//prop(p,l,r);
	if(p==1) cout << "--------------\n";
	cout << l << ' ' << r << ": " << st[p] << ' ' << lazy[p] << '\n';
	if(l==r) return;

	int m = (l+r)/2;
	dfs(2*p,l,m);
	dfs(2*p+1,m+1,r);
}

void print(int n) {
	for(int i=0;i<n;i++) cout << query(1,0,n-1,i,i) << ' ';
	cout << '\n';
}

int main() { _
	int n,m;
	cin >> n >> m;

	for(int i=0;i<n;i++) cin >> v[i];

	sp[0] = v[0];
	for(int i=1;i<n;i++) sp[i] = sp[i-1]+v[i];

	build(1,0,n-1);
	//print(n);
	//dfs(1,0,n-1);
	while(m--) {
		int op;
		cin >> op;

		if(op==1) {
			int i, qtd;
			cin >> i >> qtd;
			i--;

			update(1,0,n-1,i,qtd);

			//dfs(1,0,n-1);
		} else {
			int l,r;
			cin >> l >> r;
			l--;
			r--;

			ll tot = get(l,r);
			ll rem = query(1,0,n-1,l,r);

			cout << tot - rem << '\n';
			//cout << "tot = " << tot << '\n';
			//cout << "rem = " << rem << ' ' << query(1,0,n-1,r,r) << '\n';
			
			reset(1,0,n-1,l,r);
		}

		//print(n);
	}

	return 0;
}
