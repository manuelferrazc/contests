#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,m;
    string s;
    cin >> n >> m >> s;
    vector<vector<ll>> v(n,vector<ll>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> v[i][j];

    ll x=0,y=0;
    for(char c:s) {
        ll sum=0;
        if(c=='D') {
            for(ll i=0;i<m;i++) sum+=v[x][i];
            v[x++][y]-=sum;
        } else {
            for(ll i=0;i<n;i++) sum+=v[i][y];
            v[x][y++]-=sum;
        }
    }

    ll sum=0;
    for(int i=0;i<m;i++) sum+=v[n-1][i];
    v.back().back()-=sum;

    for(int i=0;i<n;i++) {
        for(ll &j:v[i]) cout << j << ' ';
        cout << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
