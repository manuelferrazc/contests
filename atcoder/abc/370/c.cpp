#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
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
typedef map<int,int> mii;
typedef set<int> si;

int main() { _
    string s,t;
    cin >> s >> t;

    vs v;

    for(ull i=0;i<s.size();i++) {
        if(s[i]>t[i]) {
            s[i] = t[i];
            v.push_back(s);
        }
    }

    for(ll i=s.size()-1;i>=0;i--) {
        if(s[i]!=t[i]) {
            s[i] = t[i];
            v.push_back(s);
        }
    }

    cout << v.size() << '\n';
    for(auto i:v) cout << i << '\n';

    return 0;
}