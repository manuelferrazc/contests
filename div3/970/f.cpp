#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
typedef unsigned ui;
typedef  long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

const ll m = 1e9+7;
ll fexp(ll a, ll e) {
    if(e==0) return 1;
    if(e==1) return a;

    ll ret = fexp(a,e/2);
    ret=(ret*ret)%m;
    if(e&1) ret=(ret*a)%m;

    return ret;
}

const ll d = fexp(2,m-2)%m;

void solve() {
    ll n;
    cin >> n;
    ll s=0,q=0,x;

    for(int i=0;i<n;i++) {
        cin >> x;
        s=(s+x)%m;
        q=q+(x*x)%m;
    }

    s = s*s;
    s= s%m;

    q = q % m;
    s = s-q+m;
    s%=m;
    s*=d;
    s%=m;

    x = n*(n-1);
    x%=m;
    x = (x*d)%m;
    x = fexp(x,m-2);

    cout << (s*x)%m << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}