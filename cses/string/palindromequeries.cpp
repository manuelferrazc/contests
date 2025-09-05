#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

struct Hash {
    ll mod, n;
    vector<ll> p;

    vector<ll> st;

    ll build(string &s, ll pos, ll l, ll r) {
        if(l==r) return st[pos] = s[l];

        ll m = (l+r)>>1,ls = 2*pos+1;
        return st[pos] = (build(s,ls,l,m)*p[r-m]+build(s,ls+1,m+1,r))%mod;
    }
    
    Hash(string &s, ll _m, ll b): mod(_m), n(s.size()) {
        st.resize(4*n,0);
        p.resize(n);
        
        p[0] = 1;
        for(ll i=1;i<n;i++) p[i] = p[i-1]*b%mod;
        build(s,0,0,n-1);
    }

    ll get(ll pos, ll l, ll r, ll lq, ll rq) {
        if(rq<l or r<lq) return 0;
        if(lq<=l and r<=rq) return st[pos];

        ll m = (l+r)>>1,ls = 2*pos+1;
        if(rq<=m) return get(ls,l,m,lq,rq);
        else if(m+1<=lq) return get(ls+1,m+1,r,lq,rq);
        else return (get(ls,l,m,lq,rq)*p[min(rq,r)-m]+get(ls+1,m+1,r,lq,rq))%mod;
    }

    ll get(ll l, ll r) {
        return get(0,0,n-1,l,r);
    }

    ll change(ll pos, ll l, ll r, ll i, ll c) {
        if(i<l or r<i) return st[pos];
        if(l==r) return st[pos] = c;

        ll m = (l+r)>>1,ls = 2*pos+1;
        return st[pos] = (change(ls,l,m,i,c)*p[r-m]+change(ls+1,m+1,r,i,c))%mod;
    }
    
    void change(ll i, ll c) {
        change(0,0,n-1,i,c);
    } 
};

int main() { _
    int n,q, op, a, b;
    string s,x;
    cin >> n >> q >> s;

    string r(s);
    reverse(r.begin(),r.end());

    const ll b1 = uniform(500,500000), b2 = uniform(500,500000);
    const ll p1 = 1'000'000'103, p2 = 1'000'000'241;

    Hash hs1(s,p1,b1), hs2(s,p2,b2);
    Hash hr1(r,p1,b1), hr2(r,p2,b2);


    while(q--) {
        cin >> op >> a;
        a--;

        if(op==1) {
            cin >> x;

            hs1.change(a,x[0]);
            hs2.change(a,x[0]);
            hr1.change(n-1-a,x[0]);
            hr2.change(n-1-a,x[0]);
        } else {
            cin >> b;
            b--;
            if(hs1.get(a,b)==hr1.get(n-1-b,n-1-a) and hs2.get(a,b)==hr2.get(n-1-b,n-1-a)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
