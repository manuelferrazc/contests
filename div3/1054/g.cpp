#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve() {
    int n,q;
    cin >> n >> q;

    int v[n];
    for(int i=0;i<n;i++) cin >> v[i];

    map<int,int> m;
    vector<int> rev(n,-1);

    for(int i=0;i<n;i++) {
        if(not m.count(v[i])) {
            rev[m.size()] = v[i];
            m[v[i]] = m.size();
        }
        v[i] = m[v[i]];
    }


    vector<vector<int>> pos(m.size());
    for(int i=0;i<n;i++) pos[v[i]].push_back(i+1);
    
    while(q--) {
        int l,r;
        cin >> l >> r;
        
        int min = (r-l+1)/3;
        
        set<int> ans;

        for(int i=0;i<50;i++) {
            int x = v[uniform(l-1,r-1)];
            
            if(upper_bound(pos[x].begin(),pos[x].end(),r)-lower_bound(pos[x].begin(),pos[x].end(),l)>min) {
                ans.insert(rev[x]);
            }
        }

        if(ans.empty()) cout << -1;
        else for(int i:ans) cout << i << ' ';

        cout << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
