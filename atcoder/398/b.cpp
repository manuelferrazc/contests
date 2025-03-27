#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n=7;
    vector<int> v(14,0);
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        v[x]++;
    }

    int q2=0,q3=0;

    for(auto i:v) if(i>=2) q2++;
    for(int i:v) if(i>=3) q3++;
    if(q2>1 and q3) cout << "Yes\n";
    else cout << "No\n";
}

int main() { _
    int t=1;
    while(t--) solve();
    return 0;
}
