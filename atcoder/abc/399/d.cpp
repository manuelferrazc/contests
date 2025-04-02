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
    map<int,pair<int,int>> m;
    vector<int> v(2*n);
    n<<=1;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        if(m.count(--v[i])) m.at(v[i]).ss = i;
        else m.insert(make_pair(v[i],make_pair(i,-1)));
    }

    int ans=0;
    set<pair<int,int>> s;
    for(int i=0;i<n;i++) {
        if(i==n-1) continue;
        if(v[i]==v[i+1]) continue;
        if(i and v[i-1]==v[i]) continue;
        if(s.count(make_pair(min(v[i],v[i+1]),max(v[i],v[i+1])))) continue;

        pair<int,int> i1 = make_pair(min(m[v[i]].ff,m[v[i]].ss),max(m[v[i]].ff,m[v[i]].ss));
        pair<int,int> i2 = make_pair(min(m[v[i+1]].ff,m[v[i+1]].ss),max(m[v[i+1]].ff,m[v[i+1]].ss));
        if(i2.ss-i2.ff==1) continue;
        if(abs(i1.ff-i2.ff)==1 and abs(i1.ss-i2.ss)==1) {
            s.insert(make_pair(min(v[i],v[i+1]),max(v[i],v[i+1])));
            ans++;
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
