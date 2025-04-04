#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


void solve() {
    int n;
    cin >> n;
    map<ll,ll> b;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        if(b.count(x)) b.at(x)++;
        else b.insert(make_pair(x,1));
    }
    
    if(not b.count(1)) {
        cout << "NO\n";
        return;
    }

    ll sum = b.at(1);

    for(auto i:b) {
        if(i.ff==1) continue;
        if(i.ff>sum) {
            cout << "NO\n";
            return;
        } else sum+=i.ff*i.ss;
    }
    cout << "YES\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
