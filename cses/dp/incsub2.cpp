#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> st;
const ll mod = 1'000'000'007LL;

ll sett(int pos,int l, int r, int x, ll v) {
    if(x<l or r<x) return st[pos];
    if(l==r) return st[pos] = (st[pos]+v)%mod;

    int m = (l+r)>>1,ls = 2*pos+1;
    return st[pos] = (sett(ls,l,m,x,v)+sett(ls+1,m+1,r,x,v))%mod;
}

ll get(int pos, int l, int r, int lq, int rq) {
    if(rq<l or r<lq) return 0;
    if(lq<=l and r<=rq) return st[pos];
    int m = (l+r)>>1,ls = 2*pos+1;
    return (get(ls,l,m,lq,rq)+get(ls+1,m+1,r,lq,rq))%mod;
}

int main() { _
    int n;
    cin >> n;
    st.assign((n+1)<<2,0);
    vector<int> v(n);
    for(int &i:v) cin >> i;

    map<int,vector<int>> m;
    for(int i=0;i<n;i++) m[v[i]].push_back(i);
    int ans=0;
    for(auto it = m.begin();it!=m.end();it++) {
        for(int i:it->ss) v[i] = ans;
        ans++;
    }

    for(int i=0;i<n;i++) {
        ll q = v[i]?get(0,0,n,0,v[i]-1):0;
        // cout << "v[" << i << "] = " << v[i] << ", max = " << get(0,0,n,0,n) << '\n';
        sett(0,0,n,v[i],(q+1)%mod);
    }


    cout << get(0,0,n,0,n) << '\n';

    return 0;
}
