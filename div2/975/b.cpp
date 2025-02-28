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

void solve() {
    ll n,q;
    cin >> n >> q;

    map<ll,ll> m;
    vll v(n);
    for(ll i=0;i<n;i++) cin >> v[i];

    for(ll i=0;i<n-1;i++) {
        ll t = i*(n-i)+n-i-1;
        if(not m.count(t)) m.insert({t,1});
        else m.at(t)++;

        t = (i+1)*(n-i-1);
        if(not m.count(t)) m.insert({t,v[i+1]-v[i]-1});
        else m.at(t)+=(v[i+1]-v[i]-1);
    }

    if(not m.count(n-1)) m.insert({n-1,1});
    else m.at(n-1)++;

    while(q--) {
        cin >> n;
        if(m.count(n)) cout << m.at(n) << ' ';
        else cout << "0 ";
    }
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}