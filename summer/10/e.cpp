#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int mx;
int v[200'000];

const ll mod = 1'000'000'007;
ll ans[200'000];

struct query {
    int l;
    int r;

    int id;

    query(int _l, int _r, int _id): l(_l), r(_r), id(_id) {}
};

void calc(int l, int r, vector<query> &q) {
    if(q.empty()) return;
    
    if(l==r) {
        for(auto [lq,rq,id]:q) {
            ans[id] = 1;
            if(v[lq]==0) ans[id]++;
        }
        return;
    }

    int m = (l+r)/2;

    vector<query> lv,rv,av;
    for(auto [lq,rq,id]:q) {
        if(rq<=m) lv.push_back(query(lq,rq,id));
        else if(m<lq) rv.push_back(query(lq,rq,id));
        else av.push_back(query(lq,rq,id));
    }

    calc(l,m,lv);
    calc(m+1,r,rv);

    if(av.empty()) return;

    vector<array<ll,20>> lans(m-l+2),rans(r-m+1);

    lans[0][0] = 1;
    rans[0][0] = 1;

    for(int i=m,qtd = 1;i>=l;i--,qtd++) {
        for(int x=0;x<mx;x++) {
            int y = v[i]+x;
            y%=mx;
            lans[qtd][y] = lans[qtd-1][x];
        }

        for(int x=0;x<mx;x++) {
            lans[qtd][x] += lans[qtd-1][x];
            lans[qtd][x] %= mod;
        }
    }

    for(int i=m+1,qtd=1;i<=r;i++,qtd++) {
        for(int x=0;x<mx;x++) {
            int y = v[i]+x;
            y%=mx;
            rans[qtd][y] = rans[qtd-1][x];
        }

        for(int x=0;x<mx;x++) {
            rans[qtd][x] += rans[qtd-1][x];
            rans[qtd][x] %= mod;
        }
    }

    for(auto [lq,rq,id]:av) {
        int qa = m-lq+1;
        int qb = rq-m;

        ans[id] = lans[qa][0]*rans[qb][0]%mod;
        for(int i=1;i<mx;i++) {
            int j = mx-i;

            ans[id]+=lans[qa][i]*rans[qb][j]%mod;
        }

        ans[id]%=mod;

    }
}

int main() { _
    int n,q;
    cin >> n >> mx;

    for(int i=0;i<n;i++) {
        cin >> v[i];
        v[i]%=mx;
    }

    vector<query> vq;
    
    cin >> q;
    for(int i=0;i<q;i++) {
        int l,r;
        cin >> l >> r;

        vq.push_back(query(l-1,r-1,i));
    }

    calc(0,n-1,vq);

    for(int i=0;i<q;i++) cout << ans[i] << '\n';

    return 0;
}
