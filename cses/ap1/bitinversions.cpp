//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

string s;

struct node {
	int pref=1, suf=1, best=1;

	node comb(node &o, int l, int r) {
		node ret;
		int m = (l+r)/2;
		ret.pref = pref;
		if(pref==m-l+1 and s[m]==s[m+1]) ret.pref+=o.pref;

		ret.suf = o.suf;
		if(o.suf==r-m and s[m]==s[m+1]) ret.suf+=suf;

		ret.best = max({best,o.best,ret.suf,ret.pref});
		if(s[m]==s[m+1]) ret.best = max(ret.best,suf+o.pref);
		return ret;
	}
};

#define MAX 200'001

node *st;

void build(int p, int l, int r) {
	if(l==r) return void( st[p] = node());

	int m = (l+r)/2;
	build(2*p,l,m);
	build(2*p+1,m+1,r);

	st[p] = st[2*p].comb(st[2*p+1],l,r);
}

void flip(int p, int l, int r, int i) {
	if(l==r) {
		if(s[l]=='0') s[l] = '1';
		else s[l] = '0';
		return;
	}

	int m = (l+r)/2;
	if(i<=m) flip(2*p,l,m,i);
	else flip(2*p+1,m+1,r,i);

	st[p] = st[2*p].comb(st[2*p+1],l,r);
}

int main() { _
	int m;
    cin >> s >> m;

	st = new node[4*s.size()+4];
	build(1,0,s.size()-1);
	
	while(m--) {
		int x;
		cin >> x;
		x--;
		
		flip(1,0,s.size()-1,x);
		cout << st[1].best << ' ';
	}

	delete[] st;
	cout << '\n';

    return 0;
}
