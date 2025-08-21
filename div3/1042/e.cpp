#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

auto solve() {
    int n;
    cin >> n;

    vector<int> a(n),b(n);
    for(int &i:a) cin >> i;
    for(int &i:b) cin >> i;

    auto c = a;
    vector<bool> us(n,false);

    if(a.back()!=b.back()) return "NO\n";


    for(int i=n-2;i>=0;i--) {
        if(a[i]==b[i]) continue;
        else if((a[i]^a[i+1])==b[i] or (a[i]^c[i+1])==b[i]) {
            us[i] = true;
            if((a[i]^c[i+1])==b[i]) c[i] = a[i]^c[i+1];
            else c[i] = a[i]^a[i+1];
        } else return "NO\n";
    }


    return "YES\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
