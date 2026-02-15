#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 200'000
#define MAX2 18

namespace sparse {
    int n;
	pair<int,int> m[MAX2][2*MAX], v[2*MAX];
	pair<int,int> op(pair<int,int> a, pair<int,int> b) { return max(a, b); }
	void build(int n2, pair<int,int>* v2) {
		n = n2;
		for (int i = 0; i < n; i++) v[i] = v2[i];
		while (n&(n-1)) n++;
		for (int j = 0; (1<<j) < n; j++) {
			int len = 1<<j;
			for (int c = len; c < n; c += 2*len) {
				m[j][c] = v[c], m[j][c-1] = v[c-1];
				for (int i = c+1; i <  c+len; i++) m[j][i] = op(m[j][i-1], v[i]);
				for (int i = c-2; i >= c-len; i--) m[j][i] = op(v[i], m[j][i+1]);
			}
		}
	}
	pair<int,int> query(int l, int r) {
		if (l == r) return v[l];
		int j = __builtin_clz(1) - __builtin_clz(l^r);
		return op(m[j][l], m[j][r]);
	}
}

ll get(ll *sp, int a, int b) {
    if(a) return sp[b]-sp[a-1];
    return sp[b];
}

void make_sp(int *v, int n, ll *sp) {
    sp[0] = v[0];
    for(int i=1;i<n;i++) sp[i] = v[i]+sp[i-1];
}

void make_next_big(int *v, int n, int *next) {
    stack<int> s;

    for(int i=0;i<n;i++) {
        while(s.size() and v[s.top()]<=v[i]) {
            next[s.top()] = i;
            s.pop();
        }

        s.push(i);
    }

    while(s.size()) {
        next[s.top()] = -1;
        s.pop();
    }
}

void make_suf(int *v, ll *sp, int *next, ll *suf, int n) {
    for(ll i=n-1;i>=0;i--) {
        if(next[i]==-1) suf[i] = (n-i)*v[i] - get(sp,i,n-1);
        else suf[i] = (next[i]-i)*v[i] - get(sp,i,next[i]-1) + suf[next[i]];
    }
}

int main() { _
    ll n,q;
    cin >> n >> q;

    int v[n];
    for(int i=0;i<n;i++) cin >> v[i];
    
    pair<int,int> v2[n];
    for(int i=0;i<n;i++) {
        v2[i].ff = v[i];
        v2[i].ss = i;
    }
    sparse::build(n,v2);

    ll sp[n];
    make_sp(v,n,sp);

    int next[n];
    make_next_big(v,n,next);

    ll suf[n];
    make_suf(v,sp,next,suf,n);

    while(q--) {
        int l,r;
        cin >> l >> r;
        l--;
        r--;

        if(r==n-1) cout << suf[l] << '\n';
        else {
            auto [mx,id] = sparse::query(l,r);

            if(next[id]==-1) cout << suf[l] - (mx*(n-r-1ll) - get(sp,r+1,n-1)) << '\n';
            else 
                cout << suf[l] - suf[next[id]] - (mx*(next[id]-r-1ll) - get(sp,r+1,next[id]-1)) << '\n';
            
        }
    }
    
    return 0;
}
