#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    ll n,k;
    cin >> n >> k;
    vector<int> v(n+1);
    map<int,int> s;
    for(ll i=0;i<n;i++) cin >> v[i];
    v.back()=-1;
    ll ans=0, l=0,r=-1;

    while(r<n) {
        if(l>r) {
            r++;
            if(not s.count(v[r])) s.insert({v[r],1});
            else s[v[r]]++;
        } else if(s.size()>k) {
            if(s[v[l]]==1) s.erase(v[l]);
            else s[v[l]]--;
            l++;
        } else {
            ans+=r-l+1;
            r++;
            if(not s.count(v[r])) s.insert({v[r],1});
            else s[v[r]]++;
        }
    }

    cout << ans << '\n';

    return 0;
}
