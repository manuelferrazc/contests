#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> st(800001);
vector<int> v;

int build(int pos, int l, int r) {
    if(l==r) return st[pos] = -1000000;

    int m = (l+r)>>1, ls = 2*pos+1;
    return st[pos] = max(build(ls,l,m),build(ls+1,m+1,r));
}

int getm(int pos, int l, int r, int lq, int rq) {
    if(lq<=l and r<=rq) return st[pos];
    if(rq<l or r<lq) return -1;

    int m = (l+r)>>1, ls = 2*pos+1;
    return max(getm(ls,l,m,lq,rq),getm(ls+1,m+1,r,lq,rq));
}

int sset(int pos, int l, int r, int i, int vv) {
    if(i<l or r<i) return st[pos];
    if(l==r) return st[pos] = vv;

    int m = (l+r)>>1, ls = 2*pos+1;
    return st[pos] = max(sset(ls,l,m,i,vv),sset(ls+1,m+1,r,i,vv));
}

int main() { _
    int n;
    cin >> n;
    v.resize(n);

    for(int i=0;i<n;i++) cin >> v[i];

    map<int,vector<int>> m;
    for(int i=0;i<n;i++) m[v[i]].push_back(i);
    int q=1;
    for(auto it = m.begin();it!=m.end();it++) {
        for(int i:it->ss) v[i] = q;
        q++;
    }

    build(0,1,200000);

    for(int i=0;i<n;i++) {
        if(v[i]==1) cout << 0 << ' ';
        else {
            int sla = getm(0,1,200000,1,v[i]-1);
            if(sla<0) cout << 0 << ' ';
            else cout << sla+1 << ' ';
        }

        sset(0,1,200'000,v[i],i);
    }
    
    cout << '\n';

    return 0;
}
