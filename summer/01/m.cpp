#include <bits/stdc++.h>

// Otimizacoes agressivas, pode deixar mais rapido ou mais devagar
#pragma GCC optimize("Ofast")
// Auto explicativo
#pragma GCC optimize("unroll-loops")
// Vetorizacao
#pragma GCC target("avx2")
// Para operacoes com bits
#pragma GCC target("bmi,bmi2,popcnt,lzcnt")

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
	int op(int a, int b) { return gcd(a, b); }
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

int main() { _
    int n;
    cin >> n;

    int v[n];
    for(int i=0;i<n;i++) cin >> i[v];
    sparse::build(n,v);

    map<int,ll> m;
    
    for(int i=0;i<n;i++) {
        int w=i;
        int act = v[i];
        
        while(w<n) {
            int l = w;
            int r = n-1;
            int ans = w;

            while(l<=r) {
                int m2 = (l+r)/2;
                
                int x = sparse::query(i,m2);

                if(x==act) {
                    ans = m2;
                    l = m2+1;
                } else r=m2-1;
            }

            m[act]+=ans-w+1;
            w = ans+1;
            act = sparse::query(i,w);

            if(w<n and act==1) {
                m[1] += n-w;
                break;
            }
        }
    }

    int q;
    cin >> q;

    while(q--) {
        int x;
        cin >> x;
        if(m.count(x)) cout << m[x] << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}
