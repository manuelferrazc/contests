#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> st;

int sett(int pos,int l, int r, int x, int v) {
    if(x<l or r<x) return st[pos];
    if(l==r) return st[pos] = v;

    int m = (l+r)>>1,ls = 2*pos+1;
    return st[pos] = max(sett(ls,l,m,x,v),sett(ls+1,m+1,r,x,v));
}

int get(int pos, int l, int r, int lq, int rq) {
    if(rq<l or r<lq) return 0;
    if(lq<=l and r<=rq) return st[pos];
    int m = (l+r)>>1,ls = 2*pos+1;
    return max(get(ls,l,m,lq,rq),get(ls+1,m+1,r,lq,rq));
}

int main() { _
    int n,ans=1;
    cin >> n;
    st.assign((n+1)<<2,0);
    vector<int> v(n);
    for(int &i:v) cin >> i;

    map<int,vector<int>> m;
    for(int i=0;i<n;i++) m[v[i]].push_back(i);
    ans=0;
    for(auto it = m.begin();it!=m.end();it++) {
        for(int i:it->ss) v[i] = ans;
        ans++;
    }

    for(int i=n-1;i>=0;i--) {
        int q = get(0,0,n,v[i]+1,n);
        // cout << "v[" << i << "] = " << v[i] << ", max = " << get(0,0,n,0,n) << '\n';
        sett(0,0,n,v[i],q+1);
    }


    cout << get(0,0,n,0,n) << '\n';

    return 0;
}
