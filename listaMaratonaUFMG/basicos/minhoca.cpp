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

int main() { _
    ll a,b;
    cin >> a >> b;
    
    vector<vll> v(a,vll(b));
    for(ll i=0;i<a;i++) for(ll j=0;j<b;j++) cin >> v[i][j];

    ll max = LLONG_MIN;
    for(ll c=0;c<b;c++) {
        ll act = 0;
        for(ll i=0;i<a;i++) act+=v[i][c];
        max = ::max(max,act);
    }

    for(ll l=0;l<a;l++) {
        ll act = 0;for(ll i=0;i<b;i++) act+=v[l][i];
        max = ::max(max,act);
    }

    cout << max << '\n';

    return 0;
}