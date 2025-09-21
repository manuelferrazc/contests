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

    vector<int> c(m+1,0);
    vector<int> set[n];
    for(int i=0;i<n;i++) {
        int qtd;
        cin >> qtd;

        while(qtd--) {
            int x;
            cin >> x;
            c[x]++;
            set[i].push_back(x);
        }
    }

    for(int i=1;i<=m;i++) {
        if(c[i]==0) {
            cout << "NO\n";
            return;
        }
    }

    int t=0;

    for(int i=0;i<n;i++) {
        bool ok = true;
        for(int e:set[i]) {
            if(c[e]==1) {
                ok = false;
                break;
            }
        }
        if(ok) t++;
    }

    if(t>=2) cout << "YES\n";
    else cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
