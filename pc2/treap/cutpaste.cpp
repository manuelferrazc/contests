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

template<typename t>
struct Treap {
    struct node {
        int prio,size;
        t data;
        node *l, *r;
        
        node(t val): prio(uniform(1,1e9)),size(1),data(val),l(nullptr),r(nullptr) {}
        ~node() {
            if(l) delete l;
            if(r) delete r;
        }
    };

    ~Treap() {
        delete root;
    }
    
    node *root=nullptr;

    int recalc(node *p) {
        if(p) {
            p->size = 1;
            if(p->l) p->size+=p->l->size;
            if(p->r) p->size+=p->r->size;
        }
        return p->size;
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
        int ls = n->l ? n->l->size : 0;

        if(q<ls) {
            auto [ln,rn] = split(n->l,q);
            n->l = rn;
            recalc(n);
            return pair(ln,n);
        } else if(q==ls) {
            node* ret = n->l;
            n->l = nullptr;
            recalc(n);
            return pair(ret,n);
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

    void push_back(t d) {
        root = join(root,new node(d));
    }

    void cut(int a, int b) {
        if(b==root->size) return;
        auto [mt,rt] = split(root,b);
        if(a==1) root = join(rt,mt);
        else {
            auto [lt,m] = split(mt,a-1);
            lt = join(lt,rt);
            root = join(lt,m);
        }
    }

    void print(node *n) {
        if(n==nullptr) return;
        print(n->l);
        cout << n->data;
        print(n->r);
    }

    void print() {
        print(root);
    }
};

int main() { _
    int n,m;
    string s;
    cin >> n >> m >> s;

    Treap<char> t;
    for(char c:s) t.push_back(c);

    while(m--) {
        int a,b;
        cin >> a >> b;
        t.cut(a,b);
    }

    t.print();
    cout << '\n';

    return 0;
}
