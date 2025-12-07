#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 600'000

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

template<int mod>
struct Treap {
    struct node {
        int prio,size;
        char data;
        ll h;
        node *l, *r;
        
        node(char val): prio(uniform(1,1e9)),size(1),data(val),h(val),l(nullptr),r(nullptr) {}

        ~node() {
            if(l) delete l;
            if(r) delete r;
        }
    };

    ll *pot;
    node *root=nullptr;

    Treap(string const &s, ll b) {
        pot = new ll[MAX];
        pot[0] = 1;
        for(int i=1;i<MAX;i++) {
            pot[i] = pot[i-1]*b%mod;
            // inv[i] = fexp(pot[i],mod-2,mod);
        }

        for(char c:s) push_back(c);
    }

    ~Treap() {
        delete[] pot;
        delete root;
    }

    void recalc(node *p) {
        p->size = 1;
        p->h = 0;
        int ls = p->l!=nullptr ? p->l->size : 0;

        if(p->l) {
            p->size+=p->l->size;
            p->h = p->l->h;
        }

        p->h+=p->data*pot[ls];
        
        if(p->r) {
            p->size+=p->r->size;
            p->h+=p->r->h*pot[ls+1];
        }

        p->h%=mod;
    }

    node* join(node *l, node *r) {
        if(l==nullptr) return r;
        if(r==nullptr) return l;

        if(l->prio>=r->prio) {
            l->r = join(l->r,r);
            recalc(l);
            return l;
        } else {
            r->l = join(l,r->l);
            recalc(r);
            return r;
        }
    }

    pair<node*,node*> split(node *n, int q) {
        if(!n) return pair(nullptr,nullptr);
        if(n->size==q) return pair(n,nullptr);
        int ls = n->l ? n->l->size : 0;

        if(q<=ls) {
            auto [ln,rn] = split(n->l,q);
            n->l = rn;
            recalc(n);
            return pair(ln,n);
        } else if(q==ls+1) {
            node *ret = n->r;
            n->r = nullptr;
            recalc(n);
            return pair(n,ret);
        } else {
            q-=ls;
            q--;
            auto [ln,rn] = split(n->r,q);
            n->r = ln;
            recalc(n);
            return pair(n,rn);
        }
    }

    void push_back(char d) {
        root = join(root,new node(d));
    }

    void cut(int a, int b) {
        if(a==1) {
            auto [mt,rt] = split(root,b);
            delete mt;
            root = rt;
        } else if(b==root->size) {
           auto [s,lx] = split(root,a-1);
           delete lx;
           root = s;
        } else {
            auto [mt,rt] = split(root,b);
            auto [lt,m] = split(mt,a-1);
            delete m;
            root = join(lt,rt);
        }
    }

    void insert(char c, int p) {
        if(root==nullptr) root = new node(c);
        else if(p==1) root = join(new node(c),root);
        else if(root->size+1==p) root = join(root,new node(c));
        else {
            auto [l,r] = split(root,p-1);
            l = join(l,new node(c));
            root = join(l,r);
        } 
    }

    ll get(int l, int r) {
        ll ret;
        if(l==1 and r==root->size) ret = root->h;
        else if(l==1) {
            auto [lt,rt] = split(root,r);
            ret = lt->h;
            root = join(lt,rt);
        } else if(r==root->size) {
            auto [lt,rt] = split(root,l-1);
            ret = rt->h;
            root = join(lt,rt);
        } else {
            auto [aux,rt] = split(root,r);
            auto [lt,mt] = split(aux,l-1);
            ret = mt->h;
            lt = join(lt,mt);
            root = join(lt,rt);
        }
        return ret;
    }

    int size() {
        if(root) return root->size;
        return 0;
    }
};

int main() { _
    const int mod1 = 1e9+7;
    const int mod2 = 1e9+9;

    const int b1 = uniform(500,1e8);
    const int b2 = uniform(500,1e8);

    int n,q;
    string s;
    cin >> n >> q >> s;

    Treap<mod1> ts1(s,b1);
    Treap<mod2> ts2(s,b2);

    reverse(s.begin(),s.end());
    Treap<mod1> tr1(s,b1);
    Treap<mod2> tr2(s,b2);

    int l,r,op,p;
    string c;

    while(q--) {
        cin >> op;
        
        if(op==1) {
            cin >> l >> r;
            ts1.cut(l,r);
            ts2.cut(l,r);

            int l2 = n-r+1;
            int r2 = n-l+1;

            tr1.cut(l2,r2);
            tr2.cut(l2,r2);
        } else if(op==2) {
            n+=2;
            cin >> c >> p;

            ts1.insert(c[0],p);
            ts2.insert(c[0],p);

            tr1.insert(c[0],n-p);
            tr2.insert(c[0],n-p);
        } else {
            cin >> l >> r;
            int l2 = n-r+1;
            int r2 = n-l+1;

            if(ts1.get(l,r)==tr1.get(l2,r2) and ts2.get(l,r)==tr2.get(l2,r2)) cout << "yes\n";
            else cout << "no\n";
        }

        n = ts1.size();
    }

    return 0;
}
