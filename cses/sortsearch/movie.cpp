#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ss first
#define ff second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n,ans=0;
    cin >> n;

    vector<pair<int,int>> v(n);
    for(auto &i:v) cin >> i.ff >> i.ss;
    sort(v.begin(),v.end());

    int act = INT_MIN;

    for(int i=0;i<n;i++) {
        if(v[i].ff<act) continue;
        ans++;
        act = v[i].ss;
    }

    cout << ans << '\n';

    return 0;
}
