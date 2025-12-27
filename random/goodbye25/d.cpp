#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void m1() {
    cout << -1 << '\n';
}

void solve() {
    int n,m;
    cin >> n >> m;

    pair<int,int> v[n];
    for(int i=0;i<n;i++) {
        cin >> v[i].ff;
        v[i].ss = i+1;
    }
    
    if(m>n/2) return m1();

    sort(v,v+n);

    vector<pair<int,int>> ans;

    if(m==0) {
        ll s=0;
        int i;
        for(i=n-2;i>=0;i--) {
            s+=v[i].ff;
            if(s>=v[n-1].ff) break;
        }

        if(s<v[n-1].ff) return m1();

        for(int j=0;j<i;j++) ans.push_back(pair(v[j].ss,v[j+1].ss));
        for(int j=i;j<n-1;j++) ans.push_back(pair(v[j].ss,v[n-1].ss));
    } else {
        for(int i=m-1;i<n-m;i++) ans.push_back(pair(v[i+1].ss,v[i].ss));
        for(int i=n-m+1;i<n;i++) ans.push_back(pair(v[i].ss,v[i-n+m-1].ss));
    }

    cout << ans.size() << '\n';
    for(ull i=0;i<ans.size();i++) cout << ans[i].ff << ' ' << ans[i].ss << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
