#include <bits/stdc++.h>

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

// void propaga(vll &seg, vll &lazy, ll a, ll b, ll pos, ll n) {
//     if(a==b) seg[pos]+=n;
//     else lazy[pos] += n;
// }

// void constroi(vll &seg, vll &lazy, ll a, ll b, ll l,ll r, ll pos) {
//     if(r>a or b<l) return;
//     else if(l==a and r==b) {
//         seg[pos]++;
//         return;
//     } else if(l<=a and b<=r) {
//         lazy[pos]++;
//         return;
//     }

//     ll m = (a+b)/2;
//     if(lazy[pos]) {
//         propaga(seg,lazy,a,m,2*pos,lazy[pos]);
//         propaga(seg,lazy,m+1,b,2*pos+1,lazy[pos]);
//         seg
//         lazy[pos] = 0;
//     }
//     constroi(seg,lazy,a,m,l,r,pos);
//     constroi(seg,)
// }

void solve() {
    ll n,d,k;
    cin >> n >> d >> k;

    vector<pii> v(k);
    for(int i=0;i<k;i++) cin >> v[i].f >> v[i].s;
    
    
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}