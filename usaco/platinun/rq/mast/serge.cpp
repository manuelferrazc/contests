#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 1'000'001;

int st[4*MAX];
int lazy[4*MAX];

void prop(int pos, int l, int r) {
	st[pos] += lazy[pos];
	if(l!=r) {
		lazy[2*pos] += lazy[pos];
		lazy[2*pos+1] += lazy[pos];
	}
	lazy[pos] = 0;
}

int add(int p, int l, int r, int lq, int rq,int x) {
	prop(p,l,r);
	if(rq<l or r<lq) return st[p];
	if(lq<=l and r<=rq) {
		lazy[p]+=x;
		prop(p,l,r);
		return st[p];
	}
	int m = (l+r)/2;
	st[p] = max(add(2*p,l,m,lq,rq,x),add(2*p+1,m+1,r,lq,rq,x));
	return st[p];
}

int find(int p, int l, int r) {
	prop(p,l,r);
	if(l==r) return st[p]>0? l : -1;
	int m = (l+r)/2;
	if(st[2*p+1]+lazy[2*p+1]>0) return find(2*p+1,m+1,r);
	else return find(2*p,l,m);
}

int main() { _
	int n,m;
	cin >> n >> m;

	int a[n],b[m];
	for(int i=0;i<n;i++) {
		cin >> a[i];
		add(1,0,MAX,1,a[i],1);
	}
	for(int i=0;i<m;i++) {
		cin >> b[i];
		add(1,0,MAX,1,b[i],-1);
	}

	int q;
	cin >> q;

	while(q--) {
		int op,i,x;
		cin >> op >> i >> x;
		i--;

		if(op==1) {
			add(1,0,MAX,1,a[i],-1);
			a[i] = x;
			add(1,0,MAX,1,a[i],1);
		} else {
			add(1,0,MAX,1,b[i],1);
			b[i] = x;
			add(1,0,MAX,1,b[i],-1);
		}

		int id = find(1,0,MAX);
		if(id==-1) cout << -1 << '\n';
		else cout << id << '\n';
	}

	return 0;
}
