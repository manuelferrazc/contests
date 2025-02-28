#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct cell {
    vector<ll> x;
    ll inv;

    cell() {
        inv = 0;
        x = vector<ll>(40,0);
    }

    void combine(cell &a, cell &b) {
        inv = a.inv+b.inv;
        ll qtd=0;
        for(ll i=39;i>=0;i--) {
            inv+=qtd*b.x[i];
            qtd+=a.x[i];
            x[i] = a.x[i]+b.x[i];
        }
    }
};

vector<ll> v;
vector<cell> st;

void build(ll pos, ll l, ll r) {
    if(l==r) {
        st[pos].x[v[l]] = 1;
        return;
    }

    ll lf = 2*pos+1,m=(l+r)>>1;
    build(lf,l,m);
    build(lf+1,m+1,r);
    st[pos].combine(st[lf],st[lf+1]);
}

cell get(ll pos, ll l, ll r, ll lq, ll rq) {
    if(r<lq or rq<l) return cell();
    if(lq<=l and r<=rq) return st[pos];

    ll m = (l+r)>>1;
    auto a = get(2*pos+1,l,m,lq,rq), b = get(2*pos+2,m+1,r,lq,rq);
    cell ret;
    ret.combine(a,b);
    return ret;
}

void set(ll pos, ll l, ll r, ll i, ll x) {
    if(i<l or r<i) return;
    if(l==r) {
        st[pos] = cell();
        st[pos].x[x] = 1;
        return;
    }

    ll m = (l+r)>>1,ls=2*pos+1;
    if(i<=m) ::set(ls,l,m,i,x);
    else ::set(ls+1,m+1,r,i,x);
    st[pos].combine(st[ls],st[ls+1]);
}

int main() { _
    ll n,q,op,x,y;
    cin >> n >> q;
    v.resize(n);
    for(auto &i:v) {cin >> i;i--;}

    st.resize(n<<2);
    build(0,0,n-1);

    while(q--) {
        cin >> op >> x >> y;
        x--;
        y--;

        if(op==1) cout << get(0,0,n-1,x,y).inv << '\n';
        else ::set(0,0,n-1,x,y);
    }

    return 0;
}
