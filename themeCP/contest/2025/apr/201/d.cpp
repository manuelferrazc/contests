#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void c(vector<ll> &v, ll n) {
    for(ll i=1;i*i<=n;i++) {
        if(i*i==n) v.push_back(i);
        else if(n%i==0LL) {
            v.push_back(i);
            v.push_back(n/i);
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> dd;
    c(dd,n);
    sort(dd.begin(),dd.end());
    vector<char> s(n);
    s[0] = 'a';

    vector<char> l(26);
    for(ll i=1;i<n;i++) {
        for(int ii=0;ii<26;ii++) l.at(ii) = 1;

        for(ll d:dd) {
            if(i-d<0) break;
            l.at(s[i-d]-'a') = 0;
        }

        for(int ii=0;ii<26;ii++) if(l[ii]) {
            s[i] = ii+'a';
            break;
        }
    }

    for(char c:s) cout << c;
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
