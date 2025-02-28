#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,k;
    cin >> n >> k;
    if(k&1) {
        cout << "NO\n";
        return;
    }

    vector<ll> v1,v2;
    ll a=1,b=n;
    while(a<=b) {
        if(a==b) v1.push_back(a++);
        else if(2*abs(b-a)<=k) {
            k-=2*abs(b-a);
            v1.push_back(b--);
            v2.push_back(a++);
        } else {
            v1.push_back(a++);
        }
    }

    if(k) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(auto i:v1) cout << i << ' ';
    for(auto it = v2.rbegin();it!=v2.rend();it++) cout << *it << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();
    return 0;
}