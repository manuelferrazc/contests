#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
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

int main() { _
    ll n;
    cin >> n;
    vector<pair<ll,ll>> v(n+2);
    v[0] = {0,0};
    v.back() = {0,0};

    for(ll i=1;i<=n;i++) cin >> v[i].x >> v[i].y;

    double ans = 0;

    for(ll i=0;i<=n;i++) ans += sqrt(pow(v[i].x-v[i+1].x,2)+pow(v[i].y-v[i+1].y,2));
    
    cout << fixed << setprecision(10);
    cout << ans << '\n';

    return 0;
}
