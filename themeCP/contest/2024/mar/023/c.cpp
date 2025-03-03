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
    set<int> a,b;
    for(int i=1;i<=n;i++) {
        a.insert(i);
        b.insert(i);
    }

    vector<int> v(n);
    for(auto &i:v) cin >> i;

    vector<int> p(n),q(n);
    set<pair<int,int>> s;
    for(int i=0;i<n;i++) s.insert(make_pair(v[i],i));
    
    for(auto [val,i]:s) {
        if(a.count(val)) {
            p[i] = val;
            q[i] = *b.begin();
            if(q[i]>val) {
                cout << "No\n";
                return;
            }
            a.erase(val);
            b.erase(b.begin());
        } else if(b.count(val)) {
            q[i] = val;
            p[i] = *a.begin();
            if(q[i]>val) {
                cout << "No\n";
                return;
            }
            a.erase(a.begin());
            b.erase(val);
        } else {
            cout << "nO\n";
            return;
        }
    }

    cout << "yeS\n";
    for(auto i:p) cout << i << ' ';
    cout << '\n';
    for(auto i:q) cout << i << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
