#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
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

int main() { _
    string s;
    cin >> s;

    map<char,vector<ll>> m;
    for(char c = 'A';c<='Z';c++) m.insert({c,vector<ll>()});

    for(ll i=0;i<(ll)s.size();i++) m.at(s[i]).push_back(i);

    ll ans = 0;

    for(ull i=1;i<s.size()-1;i++) {
        // cout << "i = " << i << endl;
        for(char c='A';c<='Z';c++) {
            if(m.at(c).size()<=1) continue;

            auto inf = lower_bound(m.at(c).begin(),m.at(c).end(),i);
            if(inf==m.at(c).begin()) continue;
            inf--;
            ll x = inf-m.at(c).begin();
            x++;
            
            auto sup = lower_bound(m.at(c).begin(),m.at(c).end(),i+1);
            if(sup==m.at(c).end()) continue;
            ll y = m.at(c).end()-sup;
            // cout << c << ' ' << x << ' ' << y << endl;
            ans+=(x*y);
        }
        // cout << endl;
    }

    cout << ans << '\n';

    return 0;
}
