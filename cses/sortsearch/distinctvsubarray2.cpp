#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll n,k,ans=0;
    cin >> n >> k;

    map<int,int> m;
    vector<int> v(n);
    for(int &i:v) cin >> i;

    for(ll a=0,b=0;b<n;b++) {
        m[v[b]]++;
        while(k<(ll)m.size()) {
            m[v[a]]--;
            if(m[v[a]]==0) m.erase(v[a]);
            a++;
        }
        ans+=b-a+1;
    }

    cout << ans << '\n';

    return 0;
}
