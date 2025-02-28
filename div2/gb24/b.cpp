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
    vector<pair<int,int>> v(n);
    map<int,int> oc;
    for(auto &i:v) {
        cin >> i.ff >> i.ss;
        if(i.ff==i.ss) {
            if(not oc.count(i.ss)) oc.insert({i.ss,1});
            else oc.at(i.ss)++;
        }
    }
    vector<int>bb;
    for(auto i:oc) bb.push_back(i.ff);

    for(int i=0;i<n;i++) {
        if(v[i].ff==v[i].ss) {
            if(oc.at(v[i].ff)==1) cout << "1";
            else cout << "0";
        }
        else {
            auto i1 = lower_bound(bb.begin(),bb.end(),v[i].ff);
            auto i2 = lower_bound(bb.begin(),bb.end(),v[i].ss);
            // if(i2==bb.end()) cout << '0';
            if(i2==bb.end() or *i1!=v[i].ff or *i2!=v[i].ss) cout << "1";
            else if(i2-i1==v[i].ss-v[i].ff) cout << "0";
            else cout << "1";
        }
    }
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
