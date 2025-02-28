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
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef set<int> si;

int main() { _
    ll n;
    cin >> n;

    vi v(n);
    for(ll i=0;i<n;i++) cin >> v[i];

    ll ans = 0;

    for(ll i=0;i<n;) {
        ll x = 0,j=i;
        for(;j<n and v[i]==v[j];j++) {
            x++;
            ans+=x;
        }
        i = j;
    }

    cout << ans << '\n';

    return 0;
}
