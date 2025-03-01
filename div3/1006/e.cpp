#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;

vector<int> v;

void solve() {
    int k;
    cin >> k;
    vector<pair<int,int>> ans;

    while(k!=0) {
        auto it = prev(upper_bound(v.begin(),v.end(),k));

        int s = it-v.begin()+1;
        for(int i=0;i<s;i++) ans.push_back(make_pair(k,ans.size()));
        k-=*it;
    }

    cout << ans.size() << '\n';
    for(auto i:ans) cout << i.x << ' ' << i.y << '\n';
}

int main() { _
    for(int i=1;i<500;i++) v.push_back(i*(i-1)/2);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
