#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct Line { // f(x) = ax+b
    ll a, b;
    Line(ll _a=0, ll _b=LLONG_MIN) { // valor padrão, representa a "não existência" de uma reta
        a=_a;
        b=_b;
    }

    ll val(ll x) {
        return a*x+b;
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
        // em v[pos] tem a reta que maximiza l entre a atual e a nova
        if(v[pos].val(l)<ln.val(l)) swap(v[pos].ln,ln);

        // se a reta de v[pos] também maximiza em r, então as retas não se intersectam nesse [l,r]
        // a nova é pior, então pode ser descartada
        if(v[pos].val(r)>=ln.val(r)) return;

        ll m = (l+r)/2;
        if(l+r<0 and ((l+r)&1)) m--;

        // se chegar aqui, v[pos] maximiza em l mas não em r

        if(v[pos].val(m)>=ln.val(m)) {
            // v[pos] também maximiza em m, então a interseção (ponto em que o ótimo é a nova linha)
            // ocorre em um valor maior que m, repete a recursão para a direita
            if(v[pos].r==-1) {
                aux = createNode();
                v[pos].r = aux;
            }
            addNewLine(ln,v[pos].r,m+1,r);
        } else {
            // v[pos] não maximiza em m, então a interseção ocorre no máximo em m
            // inverte as retas (queremos maximizar em m) e chama a recursão para a esquerta
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
            if(v[pos].l!=-1) ret = max(ret,query(v[pos].l,l,m,x));
        } else {
            if(v[pos].r!=-1) ret = max(ret,query(v[pos].r,m+1,r,x));
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

int main() { _



    return 0;
}
