#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,lx;
    cin >> n >> lx;
    vector<int> a(n),b(n),c(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        c[i] = a[i];
    }

    for(auto &i:b) cin >> i;

    sort(b.begin(),b.end());
    sort(c.begin(),c.end());

    multimap<int,int> m;
    for(int i=0;i<n;i++) m.insert(make_pair(c[i],b[i]));

    for(int i=0;i<n;i++) {
        auto it = m.lower_bound(a[i]);

        cout << it->ss << ' ';
        m.erase(it);
    }
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
