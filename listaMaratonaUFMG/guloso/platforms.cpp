#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define ff first
#define ss second
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

int main() { _
    int tamrio, nplat, maxp;
    cin >> tamrio >> nplat >> maxp;

    vi s(nplat);
    for(int i=0;i<nplat;i++) cin >> s[i];

    int tpl = accumulate(s.begin(),s.end(),0);
    
    if((maxp-1)*(nplat+1)+tpl<tamrio) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    vi out(tamrio,0);
    int act = 0, id = 0;

    while(tpl and act<tamrio and id<nplat) {
        act += min(maxp-1,tamrio-tpl-act);

        tpl -= s[id];
        while(s[id]--) {
            out[act] = id+1;
            act++;
        }

        id++;   
    }

    for(auto i:out) cout << i << ' ';
    cout << '\n';
    return 0;
}
