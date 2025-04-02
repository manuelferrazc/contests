#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll n,m,k;
    string s;
    cin >> n >> m >> k >> s;
    ll x=0;
    vector<ll> sp;
    sp.push_back(0);
    for(auto i:s) {
        if(i=='x') x++;
        sp.push_back(sp.back()+(i=='x'));
    }

    ll ans = n*(k/x);
    k%=x;
    ll best = 0;
    for(ll i=0;i<n;i++) {
        // if(i and s[i-1]=='o' and s[i]=='o') continue;
        if(sp.back()-sp[i]>k) {
            // best=max(best,n-())
            continue;
        }
        ll r=sp.back()-(i?sp[i-1]:0);
        auto it = upper_bound(sp.begin(),sp.end(),k-r);
        ll a = it-sp.begin();
        // if(it!=sp.begin()) a--;
        if(r>=0) best=max(best,n-(s[i]!='x'?i-1:i)+a+1);
        // else best=max(best,upper_bound(sp.begin(),sp.end(),sp[i]+k)-sp.begin()-1-i);
    }

    cout << ans+best << '\n';
    return 0;
}
