#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 100'000;

const ll mod = 1'000'000'007;
const ll meio = 500'000'004;

/*
 * consulta: pegar valor de "um" ponto 
 * update: somar um valor em um ponto, multiplicar um range por x
 */
struct Prob {
    ll *st;
    ll *lazy;
    int n;

    Prob(ll _n) {
        n = _n;
        st = new ll[4*n];
        lazy = new ll[4*n];
        for(int i=0;i<4*n;i++) st[i] = 0;
        for(int i=0;i<4*n;i++) lazy[i] = 1;
        add(1,1);
    }

    ~Prob() {
        delete[] st;
        delete[] lazy;
    }

    void propag(int pos, int l, int r) {
        st[pos] = (st[pos]*lazy[pos])%mod;
        if(l!=r) {
            int ls = 2*pos+1;
            lazy[ls] = (lazy[ls]*lazy[pos])%mod;
            lazy[ls+1] = (lazy[ls+1]*lazy[pos])%mod;
        }
        lazy[pos] = 1;
    }

    ll get(int pos, int l, int r, int lq, int rq) {
        propag(pos,l,r);
        if(rq<l or r<lq) return 0;
        if(lq<=l and r<=rq) return st[pos];

        int m = (l+r)/2, ls = 2*pos+1;
        return (get(ls,l,m,lq,rq)+get(ls+1,m+1,r,lq,rq))%mod;
    }

    ll mult(int pos, int l, int r, int lq, int rq, int x) {
        propag(pos,l,r);
        if(rq<l or r<lq) return st[pos];
        if(lq<=l and r<=rq) {
            lazy[pos] = x;
            propag(pos,l,r);
            return st[pos];
        }
        
        int m = (l+r)/2, ls = 2*pos+1;
        return st[pos] = (mult(ls,l,m,lq,rq,x)+mult(ls+1,m+1,r,lq,rq,x))%mod;
    }

    void add(int i, int x) {
        int pos = 0, l = 0, r = n-1;
        while(true) {
            propag(pos,l,r);
            st[pos] = (st[pos]+x)%mod;
            if(l==r) break;
            
            int m = (l+r)/2;
            pos = 2*pos+1;
            if(i<=m) r = m;
            else {
                l = m+1;
                pos++;
            }
        }
    }
    
    ll get(int l, int r) {
        return get(0,0,n-1,l,r);
    }
    
    void mult(int l, int r, int x) {
        mult(0,0,n-1,l,r,x);
    }
};

int main() { _
    int n,q;
    cin >> n >> q;

    Prob p(n+2);
    ll ans[n+1];
    for(int i=1;i<=n;i++) ans[i] = 0;

    int v[q+1];
    for(int i=0;i<q;i++) cin >> v[i];
    v[q] = 0;
    
    ll ss[q+1];
    ss[q] = v[q];
    for(int i=q-1;i>=0;i--) ss[i] = (ss[i+1]+v[i])*meio%mod;

    ans[1] = ss[0];
    for(int i=0;i<q;i++) {
        // prob de já estar nessa mesa
        ll prob = p.get(v[i],v[i]);
        
        // ans[v[i]] += prob*ss[i] % mod;
        // ans[v[i]] %= mod;
        // ans[v[i]] += ((prob*meio)%mod)*ss[i+1] % mod;
        // ans[v[i]] += ss[i+1];
        // ans[v[i]]%=mod;
        
        // prob = (prob + (1-prob+mod)*meio)%mod;
        // prob de não estar nessa mesa
        prob = (1-prob+mod)%mod;
        
        ans[v[i]] += meio*ss[i+1]%mod;
        ans[v[i]]%=mod;
        
        p.mult(0,n+1,meio);
        p.add(v[i],meio);
    }
    
    for(int i=1;i<=n;i++) cout << ans[i] << '\n';

    return 0;
}
