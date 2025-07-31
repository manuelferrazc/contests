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

    vector<int> v(51,0);
    int x;
    for(int i=0;i<n;i++) {
        cin >> x;
        v[x]++;
    }

    int ans=0;

    if(v[0]>v[1]) {
        ans+=v[1]*2;
        v[0]-=v[1];
        v[1] = 0;
        ans+=v[0];
    } else {
        ans+=v[0]*2;
        v[1]-=v[0];
    }

    for(int i=1;i<51;i++) ans+=v[i]*i;

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
