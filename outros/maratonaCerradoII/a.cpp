#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define _ ios_base::sync_with_stdio();cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;

ll st[400'000];

ll get(int pos, int l, int r, int i) {
	if(l==r) return st[pos];
	int m = (l+r)/2;

	if(i<=m) return st[pos]+get(2*pos+1,l,m,i);
	else return st[pos]+get(2*pos+2,m+1,r,i);
}

void add(int pos, int l, int r, int lq, int rq, int x) {
	if(rq<l or r<lq) return;
	if(lq<=l and r<=rq) return void(st[pos]+=x);
	int m = (l+r)/2;
	int ls = 2*pos+1;
	add(ls,l,m,lq,rq,x);
	add(ls+1,m+1,r,lq,rq,x);
}

int main() { _
//	fill(st,st+400'000,0ll);
	int n, c;
	cin >> n >> c;

	int v[n];
	for(int i=0;i<n;i++) cin >> v[i];

	priority_queue<pair<int,int>> pq;
	while(c--) {
		int m,a;
		cin >> m >> a;
		m--;
		pq.push(pair(-m,a));
	}

	stack<int> s;
	s.push(0);

	while(pq.size() and pq.top().ff==0) {
		auto [m,a] = pq.top();
		pq.pop();
		add(0,0,n-1,0,0,a);
	}

	for(int i=1;i<n;i++) {
		while(pq.size() and pq.top().ff==-i) {
			auto[m,a] = pq.top();
			pq.pop();
			add(0,0,n-1,0,i,a);
		}

		cout << s.size() << '\n';

		ll act = v[i]+get(0,0,n-1,i);
		while(s.size()) {
			ll esq = v[s.top()] + get(0,0,n-1,s.top());
			if(act>=esq) s.pop();
			else break;
		}

		s.push(i);
	}

	return 0;
}
