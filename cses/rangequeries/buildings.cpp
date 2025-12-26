#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 100'000
#define MAX2 17

namespace sparse {
	int m[MAX2][2*MAX], n, v[2*MAX];
	int op(int a, int b) { return max(a, b); }
	void build(int n2, int* v2) {
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
	int query(int l, int r) {
		if (l == r) return v[l];
		int j = __builtin_clz(1) - __builtin_clz(l^r);
		return op(m[j][l], m[j][r]);
	}
}

int getpos(int l, int r, int x) { //indice do primeiro elemento > x no intervalo [l,r]
    int ans = -1;

    while(l<=r) {
        int m = (l+r)>>1;
        if(sparse::query(l,m)>x) {
            ans = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    return ans;
}

int main() { _
    int n,q,l,r;
    cin >> n >> q;
    
    int v[n];
    pair<int,int> aux[n];

    for(int i=0;i<n;i++) {
        cin >> v[i];
        aux[i] = pair(v[i],i);
    }
    
    sort(aux,aux+n);
    sparse::build(n,v);

    int dp[n];
    for(int i=n-1;i>=0;i--) {
        int id = getpos(aux[i].ss,n-1,aux[i].ff);

        if(id==-1) dp[aux[i].ss] = 1;
        else dp[aux[i].ss] = 1+dp[id];
    }

    int ans[q];
    
    for(int i=0;i<q;i++) {
        cin >> l >> r;
        l--;
        r--;

        if(r==n-1) ans[i] = dp[l];
        else {
            int last = sparse::query(l,r);
            int idff = getpos(r+1,n-1,last);

            ans[i] = dp[l]-dp[idff];
        }
    }

    for(int i=0;i<q;i++) cout << ans[i] << '\n';
    
    return 0;
}
