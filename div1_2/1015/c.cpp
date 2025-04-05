#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define a first
#define b second
typedef long long ll;
typedef unsigned long long ull;

bool check(vector<pair<int,int>> &v) {
    for(ull i=0;i<v.size();i++) {
        if(v[i].a!=v[v.size()-i-1ULL].b) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n),ans;
    for(auto &i:v) cin >> i.a;
    for(auto &i:v) cin >> i.b;
    if((n&1) and (v[n>>1].a!=v[n>>1].b)) {
        bool b=true;
        for(int i=0;i<n;i++) {
            if(v[i].a==v[i].b) {
                b=false;
                swap(v[i],v[n>>1]);
                ans.push_back({i,n>>1});
                break;
            }
        }
        if(b) {
            cout << "-1\n";
            return;
        }
    }
    map<int,int> m;
    for(int i=0;i<n;i++) m.insert(make_pair(v[i].b,i));
    
    for(int i=0;i<n;i++) {
        if(v[i].a==v[n-i-1].b) continue;
        int x = m[v[i].a];
        ans.push_back({n-i-1,x});
        m[v[i].a] = n-i-1;
        m[v[n-i-1].b] = x;
        swap(v[n-i-1],v[x]);
    }

    if(check(v)) {
        cout << ans.size() << '\n';
        for(pair<int,int> p:ans) cout << p.a+1 << ' ' << p.b+1 << '\n';
    } else cout << "-1\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
