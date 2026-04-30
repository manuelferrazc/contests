#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 200'002

int st[4*MAX];
int lazy[4*MAX];

void build(int pos, int l, int r) {
	st[pos] = lazy[pos] = 0;
	if(l==r) return;
	int m = (l+r)/2, ls = 2*pos+1;
	build(ls,l,m);
	build(ls+1,m+1,r);
}

void prop(int pos, int l, int r) {
	st[pos]+=lazy[pos];
	
	if(l!=r) {
		int ls = 2*pos+1;
		lazy[ls]+=lazy[pos];
		lazy[ls+1]+=lazy[pos];
	}
	lazy[pos]=0;
}

int get(int pos, int l, int r, int lq, int rq) {
	prop(pos,l,r);
	if(rq<l or r<lq) return INT_MAX;
	if(lq<=l and r<=rq) return st[pos];
	int m = (l+r)/2, ls = 2*pos+1;
	return min(get(ls,l,m,lq,rq),get(ls+1,m+1,r,lq,rq));
}

int add(int pos, int l, int r, int lq, int rq, int x) {
	prop(pos,l,r);
	if(rq<l or r<lq) return st[pos];
	if(lq<=l and r<=rq) {
		lazy[pos]+=x;
		prop(pos,l,r);
		return st[pos];
	}
	int m = (l+r)/2, ls = 2*pos+1;
	return st[pos] = min(add(ls,l,m,lq,rq,x),add(ls+1,m+1,r,lq,rq,x));
}

void solve() {
    ll n;
    cin >> n;

    vector<int> f(n);
    int mx = 0;
    for(int &i:f) {
        cin >> i;
        mx = max(mx,i);
    }

	int ans = 0;

	vector<bool> found(mx+1,false);
	vector<bool> self(mx+1,false);
	
	build(0,0,n+1);
	add(0,0,n+1,0,0,-1);

	for(int x:f) {
		found[x] = true;

		if((not self[x]) and x<=ans) { // um novo que pode se representar
			self[x] = true;
			add(0,0,n+1,0,x,1);
			add(0,0,n+1,x,x,1e8);
		} else { // é grande demais ou já se representa 
			add(0,0,n+1,0,(x-1)/2,1);
		}
		
		while(get(0,0,n+1,0,ans)>=0) {
			ans++;
			add(0,0,n+1,0,ans,-1);

			if(found[ans]) {
				add(0,0,n+1,0,(ans-1)/2,-1);
				add(0,0,n+1,0,ans,1);
				self[ans] = true;
			}
		}

		cout << ans << ' ';
	}

	cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
