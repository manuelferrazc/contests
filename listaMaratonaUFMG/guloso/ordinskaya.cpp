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

int main() { _
    ll n,m;
    cin >> n >> m;

    vll v(n);    
    for(ll i=0;i<n;i++) cin >> v[i];

    ll act = min(v[0],m-v[0]);
    ll sum=act;

    pii p;
    for(ll i=1;i<n;i++) {
        p.f = min(v[i],m-v[i]);
        p.s = max(v[i],m-v[i]);

        if(p.f >= act) {
            act = p.f;
            sum += act;
        } else if(p.s >= act) {
            act = p.s;
            sum += act;
        } else {
            cout << "-1\n";
            return 0;
        }
    }

    cout << sum << '\n';

    return 0;
}
