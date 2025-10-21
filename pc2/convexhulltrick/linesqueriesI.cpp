#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct Line { // f(x) = ax+b
    ll a, b;

    Line(ll _a=0, ll _b=LLONG_MIN) {
        a=_a;
        b=_b;
    }

    ll val(ll x) {
        return a*x+b;
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

struct LiChao { // LiChao Tree de máximo, se não tem segmento returna LLONG_MIN
    vector<Node> v;
    ll l_lim, r_lim;
    int aux;

    LiChao(ll _l, ll _r) {
        l_lim = _l;
        r_lim = _r;
        v.push_back(Node());
    }

    int createNode() {
        v.push_back(Node());
        return v.size()-1;
    }

    void addNewLine(Line ln, int pos, ll l, ll r) {
        if(v[pos].val(l)<ln.val(l)) swap(v[pos].ln,ln);
        if(v[pos].val(r)>=ln.val(r)) return;
        
        ll m = (l+r)/2;
        if(v[pos].val(m)>=ln.val(m)) {
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
        ll ret = LLONG_MIN;
        if(x<=m) {
            if(v[pos].l!=-1) ret = query(v[pos].l,l,m,x);
            return max(ret,v[pos].val(x));
        } else {
            if(v[pos].r!=-1) ret = query(v[pos].r,m+1,r,x);
            return max(ret,v[pos].val(x));
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

int main() { _
    LiChao lichao(-1'000'000'000,1'000'000'000);

    int n;
    ll op,a,b;
    cin >> n;

    while(n--) {
        cin >> op >> a;

        if(op==1) {
            cin >> b;
            lichao.addLine(Line(a,b));
        } else cout << lichao.query(a) << '\n';
    }

    return 0;
}
