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
    for(auto &i:a) cin >> i;
    for(auto &i:b) cin >> i;

    vector<int> c(n);
    for(int i=0;i<n;i++) c[i] = a[i]-b[i];
    sort(c.begin(),c.end());
    
    if(c[1]<0) cout << "No\n";
    else if(c[0]+c[1]>=0) cout << "Yes\n";
    else cout << "nO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
