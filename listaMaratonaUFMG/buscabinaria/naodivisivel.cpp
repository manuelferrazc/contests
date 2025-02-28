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

ll bb(ll a,ll b, ll n, ll k) {
    if(a==b) {
        if(a%n==0) return a-1;
        return a;
    }

    ll m = (a+b)>>1LL;
    ll v = m-(m/n);

    if(v==k) return bb(m,m,n,k);
    if(v>k) return bb(a,m,n,k);
    return bb(m+1,b,n,k);
    
}

void solve() {
    ll n,k;
    cin >> n >> k;

    cout << bb(1,n*k,n,k) << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}