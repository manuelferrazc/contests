#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
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

void solve() {
    int n;
    cin >> n;

    vll v(n);
    map<ll,vi> m;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        if(m.count(v[i])==0) m.insert({v[i],vi({i})});
        else m.at(v[i]).push_back(i);
    }

    int strs;
    cin >> strs;

    while(strs--) {
        string s;
        cin >> s;
        if(s.size()!=v.size()) {
            cout << "NO\n";
            continue;
        }
        map<char,vi> ms;

        for(int i=0;i<(int)s.size();i++) {
            if(ms.count(s[i])==0) ms.insert({s[i],vi({i})});
            else ms.at(s[i]).push_back(i);
        }

        if(ms.size()!=m.size()) {
            cout << "NO\n";
            continue;
        }
        bool b = false;;
        for(auto l:ms) {
            if(b) break;
            ll val = v[l.second.front()];
            
            if(l.s.size()!=m.at(val).size()) {
                cout << "NO\n";
                b=true;
                break;
            }
            
            for(auto i:l.s) if(v[i]!=val) {
                cout << "NO\n";
                b=true;
                break;
            }

        }
        if(not b) cout << "YES\n";
    }
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}