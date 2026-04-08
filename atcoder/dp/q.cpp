#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 200'010

ll seg[4*MAX];

ll build(int p, int l, int r) {
	if (l == r) return seg[p] = LLONG_MIN;
	int m = (l+r)/2;
	return seg[p] = max(build(2*p+1, l, m), build(2*p+2, m+1, r));
}

ll query(int pos, int l, int r, int lq, int rq) {
	if (lq<=l and r<=rq) return seg[pos];
	if (rq<l or r<lq) return LLONG_MIN;
	int m = (l+r)/2;
	return max(query(2*pos+1,l,m,lq,rq),query(2*pos+2,m+1,r,lq,rq));
}
ll update(int pos, int l, int r, int i, ll x) {
    if (i<l or r<i) return seg[pos];
	if(l==r) return seg[pos] = x;
	int m = (l+r)/2;
	int ls = 2*pos+1;
	return seg[pos] = max(update(ls,l,m,i,x),
		update(ls+1,m+1,r,i,x));
}


int main() { _
    int n;
    cin >> n;

	build(0,0,n+2);

    int h[n];
    for(int i=0;i<n;i++) cin >> h[i];

    int b[n];
    for(int i=0;i<n;i++) cin >> b[i];

    update(0,0,n+1,h[n-1],b[n-1]);
	update(0,0,n+1,n+1,0);
    
	for(int i=n-2;i>=0;i--) {
        update(0,0,n+1,h[i],b[i]+query(0,0,n+1,h[i]+1,n+1));
    }

    cout << query(0,0,n+1,1,n) << '\n';
    
    return 0;
}
