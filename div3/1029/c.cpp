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
    vector<int> v(n);
    for(int &i:v) cin >> i;

    int ans=1,qtd=0;
    set<int> need,act;
    need.insert(v[0]);

    for(int i=1;i<n;i++) {
        if(need.count(v[i]) and not act.count(v[i])) qtd++;
        act.insert(v[i]);
        if(qtd==need.size()) {
            need = act;
            act.clear();
            qtd=0;
            ans++;
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
