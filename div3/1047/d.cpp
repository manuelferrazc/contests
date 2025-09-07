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
    vector<int> b(n),a(n);
    for(int &i:b) cin >> i;

    int act = 1;
    map<int,pair<int,int>> m;

    for(int i=0;i<n;i++) {
        if(m.count(b[i])) {
            a[i] = m[b[i]].ss;
            m[b[i]].ff--;
            if(m[b[i]].ff==0) m.erase(b[i]);
        } else {
            if(b[i]==1) {
                a[i] = act;
                act++;
            } else {
                a[i] = act;
                m.insert({b[i],{b[i]-1,act}});
                act++;
            }
        }
    }

    if(m.size()) {
        cout << -1 << '\n';
        return;
    }

    for(int i:a) cout << i << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
