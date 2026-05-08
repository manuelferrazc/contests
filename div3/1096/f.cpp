#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 200'001;

struct Seg {

    ll *st,*lazy;
    
    void build(int pos, int l, int r) {
        st[pos] = lazy[pos] = 0;
        if(l!=r) {
            int ls = 2*pos+1,m = (l+r)/2;
            build(ls,l,m);
            build(ls+1,m+1,r);
        }
    }

    Seg(int n) {
        st = new ll[4*n];
        lazy = new ll[4*n];
    }

    ~Seg() {
        delete[] st;
        delete[] lazy;
    }

    void propag(int pos, int l, int r) {
        st[pos]+=lazy[pos]*(r-l+1);
        if(l!=r) {
            int ls = 2*pos+1;
            lazy[ls]+=lazy[pos];
            lazy[ls+1]+=lazy[pos];
        }
        lazy[pos] = 0;
    }

    ll get(int pos, int l, int r, int lq, int rq) {
        propag(pos,l,r);
        if(rq<l or r<lq) return 0;
        if(lq<=l and r<=rq) return st[pos];
        int ls = 2*pos+1,m = (l+r)/2;
        return get(ls,l,m,lq,rq)+get(ls+1,m+1,r,lq,rq);
    }

    ll add(int pos, int l, int r, int lq, int rq, ll x) {
        propag(pos,l,r);
        if(rq<l or r<lq) return st[pos];
        if(lq<=l and r<=rq) {
            lazy[pos]+=x;
            propag(pos,l,r);
            return st[pos];
        }
        
        int ls = 2*pos+1,m = (l+r)/2;
        return st[pos] = add(ls,l,m,lq,rq,x)+add(ls+1,m+1,r,lq,rq,x);
    }
};

void solve() {
    int n;
    cin >> n;

    ll v[n];
    for(int i=0;i<n;i++) cin >> i[v];

    ll sm[n+1];
    sm[n] = 1000000;
    for(int i=n-1;i>=0;i--) sm[i] = min(sm[i+1],v[i]);
    
    ll ans = 0;
    Seg st(n+1);
    st.build(0,0,n);
    st.add(0,0,n, 1,n, n-1);

    for(int i=n-1;i>=0;i--) {
        ans += st.get(0,0,n, 1,v[i]) - v[i]*i;
        st.add(0,0,n, 1,v[i], -1);
    }

    // cout << ans << '\n';

    // soma dos indices de cada bloco em cada nivel
    // st.build(0,0,n);

    Seg st2(n+1); // quantidade de blocos em cada nivel no prefixo
    st2.build(0,0,n);

    ll best = 0;
    // for(int i=0;i<n;i++) st.add(0,0,n, 1,v[i], i);
    for(int i=0;i<n;i++) st2.add(0,0,n, 1,v[i], 1);

    for(int i=n-1;i>=0;i--) {
        // st.add(0,0,n, 1,v[i], -i);
        st2.add(0,0,n, 1,v[i], -1);

        if(v[i]<sm[i+1]) {
            ll qtd = st2.get(0,0,n, v[i],v[i]);
            // ll sumid = st.get(0,0,n, v[i],v[i]);
            
            best = max(best,qtd);
            // cout << i << ' ' << qtd << ' ' << sumid << ' ' << i*qtd - qtd*(qtd-1)/2  - sumid << '\n';
        }
    }

    cout << ans+best << '\n';
    // exit(0);
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
