#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<char,int>> v;
    v.push_back({s.front(),0});

    int ans = 1;

    for(auto c:s) {
        if(v.back().ff==c) v.back().ss++;
        else v.push_back({c,1});
    }

    for(ull i=0;i<v.size();i++) {
        if(v[i].ff=='/' and v[i].ss==1) {
            if(i and i<v.size() and v[i-1].ff=='1' and v[i+1].ff=='2')
                ans = max(ans,1+2*min(v[i-1].ss,v[i+1].ss));
        }
    }

    cout << ans << '\n';

    return 0;
}
