#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll ans = 0,n;
    cin >> n;

    vector<int> v(n);
    for(ll i=0;i<n;i++) cin >> v[i];

    set<int> s;

    for(ll a=0,b=0;b<n;b++) {
        while(s.count(v[b])) s.erase(v[a++]);
        s.insert(v[b]);
        ans+=s.size();
    }

    cout << ans << '\n';

    return 0;
}
