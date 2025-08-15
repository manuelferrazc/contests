#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // cout << s << '\n';
    set<char> missing;
    for(char c='a';c<='z';c++) missing.insert(c);

    map<char,char> m;
    vector<pair<char,char>> v;
    for(char c:s) {
        if(missing.empty()) break;

        if(m.count(c)) continue;
        // else cout << c << 'c';
        auto it = missing.begin();
        if(*it==c) {
            if(it==prev(missing.end())) {
                m[v.back().ff] = *it;
                m[c] = v.back().ss;
                v.push_back({c,*it});
                swap(v.back().ss,v[v.size()-2].ss);
                
            } else {
                it++;
                m[c] = *it;
                v.push_back({c,*it});
            }
        } else {
            m[c] = *it;
            v.push_back({c,*it});
        }
        missing.erase(it);
        // cout << 
    }
    for(char c:s) cout << m[c];
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
