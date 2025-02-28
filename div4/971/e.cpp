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

ll soma, somab2, n, k;

ll bb(ll a, ll b) {
    if(a==b) return (a*(2LL*k+a-1LL)/2LL)<=somab2 ? a : a-1;

    ll m = (a+b)>>1;
    ll s = (m*(2LL*k+m-1LL))/2LL;

    if(s<=somab2) return bb(m+1,b);
    return bb(a,m);
}

void solve() {
    cin >> n >> k;

    soma = (n*(2LL*k+n-1LL))/2LL;
    somab2 = soma/2;

    ll r = bb(1,n);
    if(r==0LL) cout << abs(soma-k) << '\n';
    else if(r==n) cout << soma << '\n';
    else cout << min(abs((r*(2*k+r-1)/2)-((n-r)*(k+r+k+n-1)/2)),abs(((r+1)*(2*k+r)/2)-((n-r-1)*(k+r+1+k+n-1)/2))) << '\n';
}

int main() { _
    int n;
    cin >> n;

    while(n--) solve();

    return 0;
}