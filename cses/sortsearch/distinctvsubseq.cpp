#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007LL;

int main() { _
    int n,x;
    cin >> n;
    map<int,int> m;

    while(n--) {
        cin >> x;
        m[x]++;
    }
    
    ll ans = 1;
    for(auto it = m.begin();it!=m.end();it++) {
        ans*=it->ss+1;
        ans%=mod;
    }

    ans = ans ? ans-1 : mod-1;
    cout << ans << '\n';

    return 0;
}
