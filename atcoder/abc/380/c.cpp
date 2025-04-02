#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    s.push_back('0');

    vector<pair<char,int>> v;
    v.push_back({s[0],0});
    int b1=(s[0]=='1');
    for(auto c : s) {
        if(c==v.back().f) v.back().s++;
        else {
            if(b1==k and c=='0') {
                b1++;
                v[v.size()-3].s+=v.back().s;
                v.pop_back();
                v.back().s++;
                continue;
                b1++;
            } else {
                if(c=='1') b1++;
                v.push_back({c,1});
            }
        }
    }

    v.back().s--;

    for(auto p:v) {
        while(p.s--) cout << p.f;
    }
    cout << '\n';
}

int main() { _
    int t=1;// cin >> t;

    while(t--) solve();

    return 0;
}
