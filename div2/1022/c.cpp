#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,ans=0;
    cin >> n;
    vector<ll> v(1);
    cin >> v[0];
    for(int i=1;i<n;i++) {
        int a;
        cin >> a;
        if(v.back()!=a) v.push_back(a);
    }
    n = v.size();
    if(n==1) {
        cout << 1 << '\n';
        return;
    }
    vector<ll> np(n,0);
    for(int i=0;i<n;i++) {
        if(i and i<n-1) {if(v[i-1]<v[i] and v[i]>v[i+1]) np[i]++;
        } else if(i==n-1 and n>1) {
            if(v[i]>=v[i-1]) np[i]++;
        } else if(i==0 and n>1) {
            if(v[i]>=v[i+1]) np[i]++;
        }
    }

    int b=-10;
    for(int i=0;i<n;i++) {
        if(np[i] and i-1!=b) ans++;
        if(np[i]) b=i;
    }

    cout << ans << '\n';
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
    return 0;
}
