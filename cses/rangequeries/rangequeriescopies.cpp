#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct SegTree {
    
    struct Node {
        ll sum;
        int l=-1, r=-1;

        Node(ll v=0): sum(v) {}
        Node(ll _s, int _l, int _r): sum(_s), l(_l), r(_r) {}
        Node(int _l, int _r): sum(0), l(_l), r(_r) {}
    };

    int n
    // ,lx=0
    ;
    vector<Node> v;
    vector<int> roots;

    int build(vector<int> &arr, int l, int r) {
        if(l==r) {
            v.push_back(Node(arr[l]));
        // cout << l << ' ' << r << ' ' << v.back().sum << '\n';

            return v.size()-1;
        }

        int m = (l+r)/2;

        int nl = build(arr,l,m);
        int nr = build(arr,m+1,r);

        v.push_back(Node(v[nl].sum+v[nr].sum,nl,nr));
        // cout << l << ' ' << r << ' ' << v.back().sum << '\n';
        return v.size()-1;
    }

    SegTree(int _n, int _q, vector<int> &arr): n(_n) {
        roots.push_back(build(arr,0,n-1));
        // exit(0);
    }

    ll get(int root, int l, int r, int lq, int rq) {
        if(r<lq or rq<l) return 0;
        if(lq<=l and r<=rq) return v[root].sum;

        int m = (l+r)/2;
        return get(v[root].l,l,m,lq,rq)+get(v[root].r,m+1,r,lq,rq);
    }

    ll get(int t, int l, int r) {
        if(roots.size()<=t) {
            cout << "ERRO!!!!\n";
            exit(1);
        }

        return get(roots[t],0,n-1,l,r);
    }

    int update(int root, int l, int r, int pos, ll x) {
        if(l==r) {
            v.push_back(Node(x));
            return v.size()-1;
        }
        
        int m = (l+r)/2;
        if(pos<=m) {
            auto lf = update(v[root].l,l,m,pos,x);
            v.push_back(Node(lf,v[root].r));
            v.back().sum = v[lf].sum+v[v[root].r].sum;
        } else {
            auto rf = update(v[root].r,m+1,r,pos,x);
            v.push_back(Node(v[root].l,rf));
            v.back().sum = v[v[root].l].sum+v[rf].sum;
        }
        
        return v.size()-1;
    }


    void update(int t, int pos, ll x) {
        if(roots.size()<=t) {
            cout << "ERRO!!!!\n";
            exit(1);
        }
        roots[t] =  update(roots[t],0,n-1,pos,x);
    }

    void copy(int t) {
        if(roots.size()<=t) {
            cout << "ERRO!!!!\n";
            exit(1);
        }

        roots.push_back(roots[t]);
    }

};

int main() { 
    int n,q,op,k,a,b;
    cin >> n >> q;

    vector<int> v(n);
    for(int &i:v) cin >> i;

    SegTree st(n,q,v);

    while(q--) {
        cin >> op >> k;

        k--;
        if(op==1) {
            cin >> a >> b;
            a--;
            
            st.update(k,a,b);
        } else if(op==2) {
            cin >> a >> b;
            a--;
            b--;
            
            cout << st.get(k,a,b) << '\n';
        } else st.copy(k);
    }
    
    return 0;
}
