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
    vector<string> v(n);
    for(string &s:v) cin >> s;
    
    list<int> l;
    l.push_back(1);
    for(int i=2;i<=n;i++) {
        for(auto it = l.begin();;it++) {
            if(it==l.end() or (v[i-1][*it-1]=='0')) {
                l.insert(it,i);
                break;
            }
        }
    }

    auto it = l.begin();
    for(;it!=l.end();it++) cout << *it << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
