#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,c,k;
    cin >> n >> c >> k;

    priority_queue<ll> pq;
    for(int i=0;i<n;i++) {
        ll x;
        cin >> x;
        pq.push(-x);
    }

    while(pq.size()) {
        ll x = -pq.top();
        pq.pop();

        if(x>c) break;

        ll nx = min(c,x+k);
        k -= nx-x;

        c+=nx;
    }

    cout << c << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
