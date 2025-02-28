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

bool bb(vi &v, ll a, ll b, ll n) {
    if(a==b) return v[a]==n;
    
    ll m = (a+b)/2;

    if(v[m]==n) return true;
    else if(v[m]>n) return bb(v,a,m,n);
    else return bb(v,m+1,b,n);
}

int main() { _
    ll n,k;
    cin >> n >> k;

    vi v(n);
    for(ll i=0;i<n;i++) cin >> v[i];

    ll q;
    while(k--) {
        cin >> q;
        
        if(bb(v,0,n-1,q)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}