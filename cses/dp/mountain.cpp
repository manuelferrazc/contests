#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n,ans=1;
    cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;

    {map<int,vector<int>> m;
    for(int i=0;i<n;i++) m[v[i]].push_back(i);
    ans=0;
    for(auto it = m.begin();it!=m.end();it++) {
        for(int i:it->ss) v[i] = ans;
        ans++;
    }}
    map<int,int> m;
    ans=1;

    for(int i=n-1;i>=0;i--) {
        auto it = m.lower_bound(v[i]);
        if(it==m.end()) ans = n-i;
        else ans = max(ans,it->ss-i);

        m[v[i]] = i;
    }

    cout << ans << '\n';

    return 0;
}
