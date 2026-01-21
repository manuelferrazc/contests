#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAX 30000

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = min(build(2*p, l, m),build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p];
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return INF;
		int m = (l+r)/2;
		return min(query(a, b, 2*p, l, m),query(a, b, 2*p+1, m+1, r));
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = min(update(a, b, x, 2*p, l, m),
			update(a, b, x, 2*p+1, m+1, r));
	}
};

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int v[n];
    if(s[0]=='(') v[0] = 1;
    else v[0] = -1;
    for(int i=1;i<n;i++) {
        if(s[i]=='(') v[i] =v[i-1] + 1;
        else v[i] = v[i-1]-1;
    }

    seg::build(n,v);

    int q;
    cin >> q;

    while(q--) {
        int x;
        cin >> x;

        if(x==0) {
            if(seg::query(0,n-1)==0 and seg::query(n-1,n-1)==0) cout << "YES\n";
            else cout << "NO\n";
        } else {
            x--;
            if(s[x]=='(') {
                seg::update(x,n-1,-2);
                s[x] = ')';
            } else {
                seg::update(x,n-1,2);
                s[x] = '(';
            }
        }
    }
}

int main() { _
    for(int i=0;i<10;i++) {
        cout << "Test " << i+1 << ":\n";
        solve();
    }
	exit(0);
}