#include <algorithm>
#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    vector<int> w(m);
    for(auto &i:v) cin >>i;
    for(auto &i:w) cin >> i;
    sort(w.begin(),w.end());

    v[0] = min(v[0],w[0]-v[0]);
    for(int i=1;i<n;i++) {
        int aux = v[i];
        auto it = lower_bound(w.begin(),w.end(),v[i-1]+v[i]);
        if(it!=w.end()) {
            v[i] = min(v[i],*it-v[i]);
            if(v[i]<v[i-1]) {
                v[i] = aux;
                v[i] = max(v[i],*it-v[i]);
            }
        }
        if(v[i]<v[i-1]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YEs\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
