#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll const shift = 0;
ll const lim = 1'000'000'000;

struct Line { // f(x) = ax+b
    ll a, b;

    Line(ll _a=0, ll _b=LLONG_MAX) {
        a=_a;
        b=_b;
    }

    ll val(ll x) {
        x-=shift;
        return a*x+b;
    }
};

struct Node {
    int l=-1, r=-1;
    Line ln;

    Node(int _l=-1, int _r=-1): l(_l), r(_r) {}

    Node(int _l, int _r, Line _ln): l(_l), r(_r), ln(_ln) {}

    ll val(ll x) {
        return ln.val(x);
    }
};

struct LiChao { // LiChao Tree de minimo, se não tem segmento returna LLONG_MAX
    vector<Node> v;
    ll l_lim, r_lim;
    int aux;

    LiChao(ll _l, ll _r) {
        l_lim = _l;
        r_lim = _r;
        v.push_back(Node());
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
    
    int createNode() {
        v.push_back(Node());
        return v.size()-1;
    }


    void addNewLine(Line ln, int pos, ll l, ll r) {
        if(v[pos].val(l)>ln.val(l)) swap(v[pos].ln,ln);
        // em l, sei v[pos] é minimo
        
        if(v[pos].val(r)<=ln.val(r)) return;
        if(l==r) return;
        
        // se chegar aq, sei q em l é minimo mas em r não
        
        ll m = (l+r)/2;
        if(l+r<0 and ((l+r)&1)) m--;

        if(v[pos].val(m)<=ln.val(m)) {
            // em l tá certo, em m tbm, então tá errado em algum lugar > m
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
        if(r<lq or rq<l or l>r or lq>rq) return;
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

    void addLine(Line ln, ll lq, ll rq) {
        addLine(ln,0,l_lim,r_lim,lq,rq);
    }
};
    
int main() {
    int n,q;
    cin >> n >> q;
    // n = 2, q = 8;
    ll l,r,a,b;
    LiChao lichao(-lim+shift,lim+shift);

    while(n--) {
        cin >> l >> r >> a >> b;
        lichao.addLine(Line(a,b),l+shift,r-1+shift);
    }

    int op;
    while(q--) {
        cin >> op;

        if(op) {
            ll x;
            cin >> x;
            x = lichao.query(x+shift);
            if(x==LLONG_MAX) cout << "INFINITY\n";
            else cout << x << '\n';
        } else {
            cin >> l >> r >> a >> b;
            lichao.addLine(Line(a,b),l+shift,r+shift-1);
        }
    }

    return 0;
}
