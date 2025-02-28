#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> v;

void build(vector<pair<int,int>> &st, int pos, int l, int r, bool mi) {
    if(l==r) {
        st[pos] = make_pair(v[l],l);
        return;
    }

    int m = (l+r)>>1,ls=2*pos+1;
    build(st,ls,l,m,mi);
    build(st,ls+1,m+1,r,mi);
    if(mi) st[pos] = min(st[ls],st[ls+1]);
    else st[pos] = max(st[ls],st[ls+1]);
}

pair<int,int> get(vector<pair<int,int>> &st, int pos, int l, int r, int lq, int rq, bool mi) {
    if(r<lq or rq<l) {
        if(mi) return make_pair(INT_MAX,-1);
        return make_pair(INT_MIN,-1);
    } else if(lq<=l and r<=rq) return st[pos];

    int m=(l+r)>>1;
    pair<int,int> a = get(st,2*pos+1,l,m,lq,rq,mi), b=get(st,2*pos+2,m+1,r,lq,rq,mi);
    if(mi) return min(a,b);
    else return max(a,b);
}

void solve() {
    int n,q,l,r;
    cin >> n;
    vector<pair<int,int>> stmin(n<<2),stmax(n<<2);
    v.resize(n);
    for(auto &i:v) cin >> i;
    
    build(stmin,0,0,n-1,true);
    build(stmax,0,0,n-1,false);

    cin >> q;

    while(q--) {
        cin >> l >> r;
        l--;
        r--;
        
        pair<int,int> a = get(stmin,0,0,n-1,l,r,true),
            b = get(stmax,0,0,n-1,l,r,false);
        if(a.ff == b.ff) cout << "-1 -1\n";
        else cout << a.ss+1 << ' ' << b.ss+1 << '\n';
    }
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
