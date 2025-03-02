#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


void solve() {
    string s;
    cin >> s;
    
    int z=-1;
    for(int i=0;i<(int)s.size();i++) if(s[i]=='0') {z=i;break;}
    if(z==-1) {
        cout << 1 << ' ' << 1 << ' ' << 1 << ' ' << s.size() << '\n';
        return;
    }

    map<string,pair<ull,ull>> m;
    string aux = s;
    while(aux.size()>s.size()-(z)) {
        string ac = s;
        for(ull i=0;i<aux.size();i++) {
            if(i+z>=s.size()) {
                m.insert(make_pair(ac,make_pair(s.size()-aux.size(),s.size()-aux.size()+i)));
                break;
            }
            ac[i+z] = (aux[i]==s[i+z]) ? '0' : '1';
        }

        aux = aux.substr(1);
    }

    cout << 1 << ' ' << s.size() << ' ' <<  m.rbegin()->ss.ff+1 << ' ' << m.rbegin()->ss.ss << '\n';
}

int main() { 
    int t; cin >> t;

    while(t--) solve();

    return 0;
}
