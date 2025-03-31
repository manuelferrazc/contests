#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> v;
vector<pair<int,int>> st;
vector<int> lazy;

void build(int pos, int l, int r) {
    if(l==r) st[pos] = make_pair(v[l],v[l]);
    else {
        int m = (l+r)>>1, ls = 2*pos+1;
        build(ls,l,m);
        build(ls+1,m+1,r);
        st[pos] = max(st[ls],st[ls+1]);
    }
}

void solve() {
    int n;
    cin >> n;
    v.resize(n);
    for(int &i:v) cin >> i;

    st.resize(n<<2);
    lazy.assign(n<<2,0);
    build(0,0,n-1);

}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
