#include <bits/stdc++.h>
#include <codecvt>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define f first
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

set<char> ml = {'A','H','I','M','O','T','U','V','W','X','Y'};

ll checapar(string &s, ll n) {
    if(n==s.size()-1 or (not ml.count(s[n])) or s[n]!=s[n+1]) return 0;

    ll ret = 2, a = n-1, b=n+2;
    for(;a>=0 and b<s.size();a--,b++) {
        if(s[a]!=s[b] or ml.count(s[a])==0ULL) break;
        ret+=2;
    } 

    return ret;
}

ll checaimpar(string &s, ll n) {
    if(not ml.count(s[n])) return 0;

    ll ret=1, a=n-1, b=n+1;
    for(;a>=0 and b<s.size();a--,b++) {
        if(s[a]!=s[b] or ml.count(s[a])==0ULL) break;
        ret+=2;
    }

    return ret;
} 

void solve() {
    string s;
    cin >> s;
    ll ans = LLONG_MIN;

    for(ll i=0;i<s.size();i++) ans = max(ans,max(checapar(s,i),checaimpar(s,i)));

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
