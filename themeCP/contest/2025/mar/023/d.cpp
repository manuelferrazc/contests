#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> st;

int sum(int pos, int l, int r, int i) {
    if(i<l or r<i) return st[pos];
    if(r==l) return st[pos]+=1;
    
    int m=(l+r)>>1;
    return st[pos] = sum(2*pos+1,l,m,i)+sum(2*pos+2,m+1,r,i);
}

int get(int pos, int l, int r, int lq, int rq) {
    if(rq<l or r<lq) return 0;
    if(lq<=l and r<=rq) return st[pos];
    int m=(l+r)>>1;
    return get(2*pos+1,l,m,lq,rq)+get(2*pos+2,m+1,r,lq,rq);
}

void solve() {
    int n;
    cin >> n;
    st.assign(8*n,0);
    vector<pair<int,int>> v(n);
    vector<int> c;
    for(auto &i:v) {
        cin >> i.ff >> i.ss;
        c.push_back(i.ff);
        c.push_back(i.ss);
    }
    
    sort(c.begin(),c.end());
    for(auto &i:v) {
        i.ff = lower_bound(c.begin(),c.end(),i.ff)-c.begin();
        i.ss = lower_bound(c.begin(),c.end(),i.ss)-c.begin();
    }

    sort(v.begin(),v.end());

    ll ans=0;
    for(auto i: v) {
        ans+=get(0,0,2*n-1,i.ss,2*n-1);
        sum(0,0,2*n-1,i.ss);
    }
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
