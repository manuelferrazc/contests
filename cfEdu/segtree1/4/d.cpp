#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

short count(ll x) {
    short ans=0;
    for(short i=0;i<50;i++) if(x&(1LL<<i)) ans++;
    return ans;
}

vector<short> v;
vector<ll> st;

ll build(int pos, int l, int r) {
    if(l==r) return st[pos] = 1LL<<v[l];
    int m = (l+r)>>1;
    return st[pos] = build(2*pos+1,l,m)|build(2*pos+2,m+1,r);
}

ll get(int pos, int l, int r, int lq, int rq) {
    if(r<lq or rq<l) return 0LL;
    if(lq<=l and r<=rq) return st[pos];

    int m=(l+r)>>1;
    return get(2*pos+1,l,m,lq,rq)|get(2*pos+2,m+1,r,lq,rq);
}

ll set(int pos, int l, int r, int i, short x) {
    if(i<l or r<i) return st[pos];
    if(l==r) return st[pos] = 1LL<<x;

    int m = (l+r)>>1;
    return st[pos] = ::set(2*pos+1,l,m,i,x)|::set(2*pos+2,m+1,r,i,x);
}

int main() { _
    int n,q,op,x,y;
    cin >> n >> q;

    v.resize(n);
    for(auto &i:v) {cin >> i;}
    st.resize(n<<2,0LL);
    build(0,0,n-1);

    while(q--) {
        cin >> op >> x >> y;
        x--;
        y--;

        if(op==1) cout << count(get(0,0,n-1,x,y)) << '\n';
        else ::set(0,0,n-1,x,y+1);
    }

    return 0;
}
