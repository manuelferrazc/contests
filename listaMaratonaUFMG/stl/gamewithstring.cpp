#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define f first
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef set<int> si;

int main() { _
    string s;
    cin >> s;
    if(s.size()==1ULL) {cout << "NO\n";return 0;}

    bool v=false;

    set<ull> se;
    for(ull i=0;i<s.size();i++) se.insert(i);
    auto it = se.begin();

    while(se.size() and it!=prev(se.end())) {
        if(s[*it]==s[*next(it)]) {
            v = not v;
            auto aux = it;
            if(it!=se.begin()) it--;
            else it = next(next(it));
            se.erase(next(aux));
            se.erase(aux);
        } else it++;
    }

    if(v) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
