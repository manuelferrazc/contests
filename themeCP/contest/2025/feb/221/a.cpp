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

    vector<int> p(n,-1);
    vector<set<int>> v(n,set<int>());
    for(int i=0;i<n;i++) {
        int x;
        for(int j=0;j<m;j++) {
            cin >> x;
            if(x<n) p[x] = i;
            v[i].insert(x);
        }
    }
    for(auto i:p) {
        if(i==-1) {
            cout << "-1\n";
            return;
        }
    }

    int c = n;
    while(c<n*m) {
        if(v[p[c%n]].count(c)) {
            c++;
        } else {
            cout << "-1\n";
            return;
        }
    }

    for(auto i:p) cout << i+1 << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
