#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,ans=1;
    string s;
    cin >> n >> s;
    map<char,int> m;
    for(char c='a';c<='z';c++) m.insert(make_pair(c,n));
    m.at(s.back())=n-1;
    for(ll i=n-2;i>=0;i--) {
        ans+=m[s[i]]-i; 

        m.at(s[i]) = i;
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
