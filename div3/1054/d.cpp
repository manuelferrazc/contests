#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n;

ll count(const string &s) {
    vector<int> p;
    for(int i=0;i<n;i++) if(s[i]=='a') p.push_back(i);

    if(p.empty()) return 0ll;

    int pos = p[p.size()/2];
    int pa = pos-1;
    ll r=0;

    for(int i=p.size()/2-1;i>=0;i--) {
        r+=abs(pa-p[i]);
        pa--;
    }

    pa = pos+1;
    for(int i=p.size()/2+1;i<p.size();i++) {
        r+=abs(pa-p[i]);
        pa++;
    }

    return r;
}

void solve() {
    string s;
    cin >> n >> s;

    ll ans = count(s);

    for(int i=0;i<n;i++) {
        if(s[i]=='a') s[i]='b';
        else s[i] = 'a';
    }

    ans = min(ans,count(s));

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
