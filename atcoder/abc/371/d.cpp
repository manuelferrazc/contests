#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

void cria(vll &segtree,int a, int b, int pos,vll &v) {
    if(a==b) {
        segtree[pos] = v[a];
        return;
    }

    int m = (a+b)/2;

    cria(segtree,a,m,2*pos+1,v);
    cria(segtree,m+1,b,2*pos+2,v);

    segtree[pos] = segtree[2*pos+1]+segtree[2*pos+2];
}

ll ans(vll &seg, int a, int b, int pos, int l, int r) {
    if(r<a or b<l) return 0;
    if(l<=a and b<=r) return seg[pos];

    int m = (a+b)/2;
    return ans(seg,a,m,2*pos+1,l,r)+ans(seg,m+1,b,2*pos+2,l,r);
}

int main() { _
    int n;
    cin >> n;
    vll c(n);
    for(int i=0;i<n;i++) cin >> c[i];
    vll p(n);
    for(int i=0;i<n;i++) cin >> p[i];

    vll seg(n<<2,0);
    cria(seg,0,n-1,0,p);
    int q,l,r;
    cin >> q;
    while(q--) {
        cin >> l >> r;
        
        auto inf = lower_bound(c.begin(),c.end(),l);
        if(inf==c.end()) {
            cout << "0\n";
            continue;
        }

        auto sup = upper_bound(c.begin(),c.end(),r);
        if(sup==c.begin() or sup==inf) {
            cout << "0\n";
            continue;
        }

        cout << ans(seg,0,n-1,0,inf-c.begin(), prev(sup)-c.begin()) << '\n';
    }

    return 0;
}