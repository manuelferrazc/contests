#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct Line { // f(x) = ax+b
    ll a, b, c;
    Line(ll _a=0, ll _b = 0, ll _c=LLONG_MAX) { // valor padrão, representa a "não existência" de uma reta
        a=_a;
        b=_b;
        c=_c;
    }

    ll val(ll x) {
        return (a*x+b)*x+c;
    }
};

struct Node { // l e r aqui representam os índices dos filhos à esquerda e à direita
    int l=-1, r=-1;
    Line ln;

    ll val(ll x) {
        return ln.val(x);
    }
};

struct LiChao { // LiChao Tree de máximo, se não tem segmento returna LLONG_MIN
    vector<Node> v;
    ll l_lim, r_lim; // limites do domínio
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

        ll ret = v[pos].val(x);
        if(x<=m) {
            if(v[pos].l!=-1) ret = min(ret,query(v[pos].l,l,m,x));
        } else {
            if(v[pos].r!=-1) ret = min(ret,query(v[pos].r,m+1,r,x));
        }
        return ret; 
    }

    ll query(ll x) {
        return query(0,l_lim,r_lim,x);
    }

    void addLine(Line ln, ll l, ll r) {
        addLine(ln,0,l_lim,r_lim,l,r);
    }

    void addLine(Line ln) {
        addNewLine(ln,0,l_lim,r_lim);
    }
};

int v[3001];
ll sp[3001];

ll get(int l, int r) {
    if(l) return sp[r]-sp[l-1];
    return sp[r];
}

inline ll sq(ll x) {
    return x*x;
}

int main() { _
    int n,k;
    cin >> n >> k;

    v[0] = 0;
    sp[0] = 0;

    for(int i=0;i<n;i++) {
        cin >> v[i+1];
        sp[i+1] = v[i+1]+sp[i];
    }

    if(k==1) {
        cout << sp[n]*sp[n] << '\n';
        return 0;
    }

    LiChao l(1,sp[n]);
    for(int i=2;i<=n;i++) { // custo de comecar um bloco em i (já tem um bloco único fechado antes)
        ll spj = sp[i-1];
        l.addLine(Line(1,-2*spj,2*spj*spj),sp[i],sp[n]);
    }

    // for(int i=2;i<=n;i++) {
    //     cout << "i = " << i << ", min = " << l.query(sp[i]) << '\n';
    // }

    for(int k2=2;k2<k;k2++) { // custo de completar k2<k divisoes, comecando o proximo em i
        LiChao l2(1,sp[n]);

        for(int i=k2+1;k-k2<=n-i+1 and i<=n;i++) {
            // pega o custo de completar k2 blocos terminando em i-1, e cria uma nova reta comecando em i

            ll q = l.query(sp[i-1]);
            l2.addLine(Line(1,-2*sp[i-1],sp[i-1]*sp[i-1]+q),sp[i],sp[n]);
        }

        l = l2;
    }

    cout << l.query(sp[n]) << '\n';

    return 0;
}
