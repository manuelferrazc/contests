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
    int z=0,u=0,d=0;

    vector<set<int>> m(3);

    for(int i=0;i<n;i++) {
        cin >> v[i];
        if(v[i]==1) u++;
        else if(v[i]) d++;
        else z++;
        m[v[i]].insert(i);
    }
    vector<pair<int,int>> ans;

    for(int i=0;i<z;) {
        if(v[i]==1) {
            auto it = prev(m[0].end());
            ans.push_back({i,*it});
            v[i] = 0;
            v[*it] = 1;
            m[1].erase(i);
            m[1].insert(*it);
            m[0].erase(it);
            m[0].insert(i);
            i++;
        } else if(v[i]==2) {
            auto it = prev(m[1].end());

            ans.push_back({i,*it});
            v[i] = 1;
            v[*it] = 2;
            m[2].erase(i);
            m[1].insert(i);
            m[2].insert(*it);
            m[1].erase(it);
        } else i++;
    }

    for(int i=z;i<z+u;i++) {
        if(v[i]==2) {
            auto it = prev(m[1].end());
            ans.push_back({i,*it});
            v[i] = 1;
            v[*it] = 2;
            m[2].erase(i);
            m[2].insert(*it);
            m[1].erase(it);
            m[1].insert(i);
        }
    }

    cout << ans.size() << '\n';
    for(auto i:ans) cout << i.ff+1 << ' ' << i.ss+1 << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
