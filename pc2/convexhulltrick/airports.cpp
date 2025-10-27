#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct Line {
    ll a, b, c;

    Line(ll _a=0, ll _b=0, ll _c=LLONG_MAX) {
        a=_a;
        b=_b;
        c=_c;
    }

    ll val(ll x) {
        return a*x*x+b*x+c;
    }
};

struct Node {
    int l=-1, r=-1;
    Line ln;

    Node() {}

    Node(int _l, int _r): l(_l), r(_r) {}

    Node(int _l, int _r, Line _ln): l(_l), r(_r), ln(_ln) {}

    ll val(ll x) {
        return ln.val(x);
    }
};

struct LiChao { // LiChao Tree de mínimo, se não tem segmento returna LLONG_MAX
    vector<Node> v;
    ll l_lim, r_lim;
    int aux;

    LiChao(ll _l=-1'000'000'000, ll _r=1'000'000'000) {
        l_lim = _l;
        r_lim = _r;
        v.push_back(Node());
    }

    int createNode() {
        v.push_back(Node());
        return v.size()-1;
    }

    void addNewLine(Line ln, int pos, ll l, ll r) {
        if(v[pos].val(l)>ln.val(l)) swap(v[pos].ln,ln);
        if(v[pos].val(r)<=ln.val(r)) return;
        
        ll m = (l+r)/2;
        if(l+r<0 and ((l+r)&1)) m--;

        if(v[pos].val(m)<=ln.val(m)) {
            if(v[pos].r==-1) {
                aux = createNode();
                v[pos].r = aux;
            }
            addNewLine(ln,v[pos].r,m+1,r);
        } else {
            swap(v[pos].ln,ln);
            if(v[pos].l==-1) {
                aux = createNode();
                v[pos].l = aux;
            }
            addNewLine(ln,v[pos].l,l,m);
        }
    }

    void addLine(Line ln, int pos, ll l, ll r, ll lq, ll rq) {
        if(r<lq or rq<l) return;
        if(lq<=l and r<=rq) return addNewLine(ln,pos,l,r);

        ll m = (l+r)/2;
        if(l+r<0 and ((l+r)&1)) m--;
        
        if(v[pos].l==-1) {
            aux = createNode();
            v[pos].l = aux;
        }
        
        if(v[pos].r==-1) {
            aux = createNode();
            v[pos].r = aux;
        }

        addLine(ln,v[pos].l,l,m,lq,rq);
        addLine(ln,v[pos].r,m+1,r,lq,rq);
    }

    ll query(int pos, ll l, ll r, ll x) {
        if(l==r) return v[pos].val(x);

        ll m = (l+r)/2;
        if(l+r<0 and ((l+r)&1)) m--;

        ll ret = LLONG_MAX;
        if(x<=m) {
            if(v[pos].l!=-1) ret = query(v[pos].l,l,m,x);
            return min(ret,v[pos].val(x));
        } else {
            if(v[pos].r!=-1) ret = query(v[pos].r,m+1,r,x);
            return min(ret,v[pos].val(x));
        }
    }

    ll query(ll x) {
        return query(0,l_lim,r_lim,x);
    }

    void addLine(Line ln, ll l, ll r) {
        addLine(ln,0,l_lim,r_lim,l,r);
    }

    void addLine(Line ln) {
        addLine(ln,0,l_lim,r_lim,l_lim,r_lim);
    }
};

struct Voo {
    int part, dest;
    ll tp, td;

    Voo(int a=0, int b=0, ll c=0, ll d=0): part(a), dest(b), tp(c), td(d) {}

    bool operator<(const Voo &o) {
        if(tp<o.tp) return true;
        return (tp==o.tp and td<o.td);
    }

    friend istream & operator>>(istream &in, Voo &v) {
        in >> v.part >> v.dest >> v.tp >> v.td;
        return in;
    }
};

int main() { _
    int n,m;
    ll ans = LLONG_MAX;
    cin >> n >> m;

    vector<LiChao> v(n+1);
    v[1].addLine(Line(1,0,0));

    Voo voos[m];
    for(int i=0;i<m;i++) cin >> voos[i];

    sort(voos,voos+m);

    for(int i=0;i<m;i++) {
        auto [part, dest, tpart, tdest] = voos[i];

        ll dp = v[part].query(tpart);
        if(dp==LLONG_MAX) continue;

        v[dest].addLine(Line(1,-2*tdest,tdest*tdest+dp),tdest,1000'000'000);
        if(dest==n) ans = min(ans,dp);
    }

    cout << ans << '\n';

    return 0;
}
