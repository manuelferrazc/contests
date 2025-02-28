#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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
    ll n;
    cin >> n;

    vll v(n);
    for(ll i=0;i<n;i++) cin >> v[i];

    ll ans = 0;

    bool p = (v[0]>0LL);
    ll act = v[0];
    for(ll i = 1;i<v.size();i++) {
        if(v[i]>0LL) { // é positivo
            if(p) act = max(act,v[i]); // o anterior tbm
            else { // o anterior é negativo
                ans += act;
                p = true;
                act = v[i];
            }
        } else { // é negativo
            if(!p) act = max(act,v[i]);
            else {
                ans += act;
                p = false;
                act = v[i];
            }
        }
    }

    ans += act;

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
