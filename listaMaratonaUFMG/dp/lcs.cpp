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

int main() { _
    string s,t;
    cin >> s >> t;
    
    vector<vector<pair<int,pii>>> v(s.size()+1,vector<pair<int,pii>>(t.size()+1,make_pair(0,pii(-1,-1))));

    for(ull i=1;i<=s.size();i++) {
        for(ull j=1;j<=t.size();j++) {
            if(s[i-1]==t[j-1]) {
                v[i][j].f = v[i-1][j-1].f+1;
                v[i][j].s = make_pair(i-1,j-1);
                
            } else v[i][j] = max(v[i-1][j],max(v[i][j-1],v[i-1][j-1]));
        }
    }

    pii c = v.back().back().s;
    string o;
    while(c.f!=-1) {
        o.push_back(s[c.f]);
        c = v[c.f][c.s].s;
    }

    reverse(o.begin(),o.end());

    cout << o << '\n';

    return 0;
}