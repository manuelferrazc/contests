#include <algorithm>
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
    vector<int> a(n),b(n);
    for(int &i:a) cin >> i;
    for(int &i:b) cin >> i;

    int m=INT_MIN;
    for(int i=0;i<n;i++) m=max(m,a[i]-b[i]);
    
    vector<int> ans;
    for(int i=0;i<n;i++) if(m==a[i]-b[i]) ans.push_back(i);

    cout << ans.size() << '\n';
    for(auto i:ans) cout << i+1 << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
