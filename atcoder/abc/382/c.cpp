#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int np,ms;
    cin >> np >> ms;

    vector<int> go(np), de(ms);
    for(int i=0;i<np;i++) cin >> go[i];
    for(int i=0;i<ms;i++) cin >> de[i];

    map<int,set<int>> m;
    for(int i=0;i<ms;i++) {
        if(not m.count(de[i])) m.insert({de[i],set<int>()});
        m.at(de[i]).insert(i);
    }

    vector<int> ans(ms,-1);

    for(int i=0;i<np;i++) {
        auto it = m.lower_bound(go[i]);
        while(it!=m.end()) {
            auto a = it;
            while(it->ss.size()) ans[*it->ss.begin()] = i+1, it->ss.erase(it->ss.begin());
            it++;
            m.erase(a);
        }
    }

    for(auto i:ans) cout << i << '\n';

    return 0;
}
