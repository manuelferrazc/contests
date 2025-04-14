#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    
}

int main() { _
    ll n;
    cin >> n;
    map<ll,ll> m,m2;
    while(n--) {
        ll a,b;
        cin >> a >> b;
        m[a]++;
        m2[b]++;
    }

    n=0;
    ll sla=0;
    for(auto p:m) n+=p.ss-1;
    for(auto p:m2) sla+=p.ss-1;
    cout << min(sla*sla,n*n) << '\n';
    return 0;
}
