#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    // # de lanternas, # de animatronics, # de segundos
    int n,m,l;
    cin >> n >> m >> l;

    multiset<int> s;

    for(int i=0;i<min(m,n+1);i++) {
        s.insert(0);
    }

    int v[n];
    for(int i=0;i<n;i++) cin >> v[i];

    int p = 0;

    for(int i=1;i<=l;i++) {
        auto x = *s.begin();
        s.erase(s.begin());
        s.insert(x+1);

        if(p<n and v[p]==i) {
            s.erase(prev(s.end()));
            p++;
        }

        if(s.size()<n-p+1 and s.size()<m) s.insert(0);
    }

    // ??????????????

    cout << *s.rbegin() << '\n';
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
