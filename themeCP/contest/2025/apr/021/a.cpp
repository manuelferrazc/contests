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
    vector<int> a(n), b(n);
    for(int &i:a) cin >> i;
    for(int &i:b) cin >> i;

    multimap<int,pair<int,int>> m;
    for(int i=0;i<n;i++) m.insert(make_pair(a[i]+b[i],make_pair(a[i],b[i])));
    
    a.clear();
    b.clear();
    for(auto it = m.begin();it!=m.end();it++) {
        a.push_back(it->ss.ff);
        b.push_back(it->ss.ss);
    }

    for(int i:a) cout << i << ' ';
    cout << '\n';
    for(int i:b) cout << i << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
