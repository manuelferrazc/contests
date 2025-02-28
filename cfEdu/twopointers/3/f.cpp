#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll n,m;
    string s,c;
    cin >> n >> m >> s >> c;

    vector<ll> v(26,0);
    for(auto i:c) v[i-'a']++;

    ll l=0,r=-1, negs=0, ans=0;

    while(r<n) {
        if(l>r) {
            r++;
            if(r==n) break;
            v[s[r]-'a']--;
            if(v[s[r]-'a']==-1) negs++;
        } else if(negs) {
            v[s[l]-'a']++;
            if(v[s[l]-'a']==0) negs--;
            l++;
        } else {
            ans+=r-l+1;
            r++;
            if(r==n) break;
            v[s[r]-'a']--;
            if(v[s[r]-'a']==-1) negs++;
        }
    }

    cout << ans << '\n';

    return 0;
}
