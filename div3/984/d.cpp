#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m;
    cin >> n >> m;
    vector<string> v(n);
    for(auto &i:v) cin >> i;

    int usadas = 0;
    int ans=0;
    while(usadas<n-usadas and usadas <m-usadas) {
        string s;
        for(int i=usadas;i<m-usadas;i++) s.push_back(v[usadas][i]);
        for(int i=usadas+1;i<n-usadas;i++) s.push_back(v[i][m-usadas-1]);
        for(int i=m-usadas-2;i>=usadas;i--) s.push_back(v[n-usadas-1][i]);
        for(int i=n-usadas-2;i>usadas;i--) s.push_back(v[i][usadas]);
        usadas++;

        for(ll i=0;i<((ll)s.size());i++) if(s[i]=='1' and s[(i+1)%s.size()]=='5' and s[(i+2)%s.size()]=='4' and s[(i+3)%s.size()]=='3') ans++;
    }

    cout << ans << '\n';
}

int main() { 
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
