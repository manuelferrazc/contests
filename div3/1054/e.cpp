#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,k,l,r;
    ll ans=0;
    cin >> n >> k >> l >> r;

    int v[n];
    for(int &i:v) cin >> i;

    ll a=0,b=0;
    map<int,int> m;

    while(b<n) {
        m[v[b]]++;

        while((int)m.size()>k or b-a+1>r) {
            m[v[a]]--;
            if(m[v[a]]==0) m.erase(v[a]);
            a++;
        }

        if(b-a+1>=l) ans+=b-a+2-l;

        b++;
    }

    k--;
    a=0;
    b=0;
    m.clear();

    // cout << ans << ' ';

    while(b<n) {
        m[v[b]]++;

        while((int)m.size()>k or b-a+1>r) {
            m[v[a]]--;
            if(m[v[a]]==0) m.erase(v[a]);
            a++;
        }

        if(b-a+1>=l) ans-=b-a+2-l;

        b++;
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
