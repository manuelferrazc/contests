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

map<pair<ll,ll>,ll> s;

ll llog(ll n) {
    ll r=0;

    while(n) {
        r++;
        n=n/3;
    }
    return r;
}

ll qtd(pair<ll,ll> p, ll a, ll b) {
    if(b<p.f or a>p.s) return 0;
    ll inf = ::max(a,p.f);
    ll sup = min(b,p.s);
    return sup-inf+1;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    ll c=0;
    
    if((l)%3==0) { // divisivel por 3
        c=llog(l+1);
        c+=llog(l)+c;
    } else { // cc
        c=llog(l);
        c+=llog(l+1)+c;
    }

    l+=2;
    for(auto p:s) {
        c+=p.s*(qtd(p.f,l,r));
    }

    cout << c << '\n';
}

int main() { _
    ll act = 1;
    for(ll i=1;i<200'001;i*=3) s.insert({{i,3*i-1},act++}); 
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}