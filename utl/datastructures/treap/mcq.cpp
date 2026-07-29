#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct st {
	st *l = nullptr;
	st *r = nullptr;

	~st() {
		if(l) delete l;
		if(r) delete r;
	}
};

void add(st *&pos, int l, int r, int i) {
	if(pos==nullptr) pos = new st();
	if(l==r) return;
	int m = (l+r)/2;
	if(i<=m) add(pos->l,l,m,i);
	else add(pos->r,m+1,r,i);
}

void change(st *&x, st *&y, int l, int r, int lq, int rq) {
	if(rq<l or r<lq or x==nullptr) return;
	if(lq<=l and r<=rq) {
		if(y==nullptr) {
			swap(x,y);
			return;
		}
		
		int m = (l+r)/2;
		change(x->l,y->l,l,m,lq,rq);
		change(x->r,y->r,m+1,r,lq,rq);
		delete x;
		x = nullptr;
	} else {
		if(y==nullptr) y = new st();
		int m = (l+r)/2;
		change(x->l,y->l,l,m,lq,rq);
		change(x->r,y->r,m+1,r,lq,rq);
		if(x->r==nullptr and x->l==nullptr) {
			delete x;
			x = nullptr;
		}
	}
}

void dfs(st *pos, int l, int r, int *v, int val) {
	if(pos==nullptr) return;
	if(l==r) v[l] = val;
	else {
		int m = (l+r)/2;
		dfs(pos->l,l,m,v,val);
		dfs(pos->r,m+1,r,v,val);
	}
}

int main() { _
	int n;
	cin >> n;

	map<int,st*> m;
	for(int i=1;i<=n;i++) {
		int x;
		cin >> x;
		if(m.count(x)==0) m[x] = nullptr;
		add(m[x],1,n,i);
	}

	int q;
	cin >> q;
	while(q--) {
		int l,r,x,y;
		cin >> l >> r >> x >> y;
		if(x==y) continue;
		change(m[x],m[y],1,n,l,r);
	}

	int a[n+1];
	for(auto it = m.begin();it!=m.end();it++) {
		dfs(it->ss,1,n,a,it->ff);
		delete it->ss;
	}

	for(int i=1;i<=n;i++) cout << a[i] << ' ';
	cout << '\n';

	return 0;
}
