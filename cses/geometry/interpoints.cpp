#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 2'000'001

int st[4*MAX];

int change(int pos, int l, int r, int i, int v) {
	if(l==r) return st[pos] += v;

	int m = (l+r)>>1, ls = 2*pos+1;
	if(i<=m) return st[pos] = change(ls,l,m,i,v)+st[ls+1];
	return st[pos] = st[ls]+change(ls+1,m+1,r,i,v);
}

int get(int pos, int l, int r, int lq, int rq) {
	if(rq<l or r<lq) return 0;
	if(lq<=l and r<=rq) return st[pos];

	int m = (l+r)>>1, ls = 2*pos+1;
	return get(ls,l,m,lq,rq)+get(ls+1,m+1,r,lq,rq);
}

int main() { _
	int n;
	cin >> n;

	array<int,4> pt[n];
	vector<array<int,3>> ev;
	for(int i=0;i<n;i++) {
		cin >> pt[i][0] >> pt[i][1] >> pt[i][2] >> pt[i][3];
		pt[i][0]+=1'000'000;
		pt[i][1]+=1'000'000;
		pt[i][2]+=1'000'000;
		pt[i][3]+=1'000'000;

		if(pt[i][0]==pt[i][2])  // vertical
			ev.push_back({pt[i][0],2,i});
		else { // horizontal
			ev.push_back({pt[i][0],1,i});
			ev.push_back({pt[i][2],3,i});
		}
	}

	sort(ev.begin(),ev.end());

	ll ans = 0;

	for(ull i=0;i<ev.size();i++) {
		auto [val,type,id] = ev[i];

		if(type==1) change(0,0,2'000'000,pt[id][1],1);
		else if(type==2) ans+=get(0,0,2'000'000,pt[id][1],pt[id][3]);
		else change(0,0,2'000'000,pt[id][1],-1);
	}

	cout << ans << '\n';

	return 0;
}
