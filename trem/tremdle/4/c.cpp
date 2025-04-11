#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    
}

int main() { _
    int n,m;
    cin >> n >> m;
    vector<int> r(n,0);
    map<int,vector<int>> ret;
    set<int> ord;
    vector<int> ans;

    for(int i=0;i<n;i++) ord.insert(i);

    while(m--) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        ret[a].push_back(b);
        r[b]++;
        ord.erase(b);
    }

    while(ord.size()) {
        int v = *ord.begin();
        ord.erase(v);
        ans.push_back(v);

        if(ret.count(v)) for(int u:ret[v]) {
            r[u]--;
            if(r[u]==0) ord.insert(u);
        }
    }

    if((int)ans.size()==n) {
        for(int i:ans) cout << i+1 << ' ';
        cout << '\n';
    } else cout << "-1\n";
    return 0;
}
