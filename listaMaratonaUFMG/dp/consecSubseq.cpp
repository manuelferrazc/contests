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

int dp(map<int,si> &m, vi &c, vi &v, int id) {
    if(c[id]!=INT_MIN) return c[id];
    int x = v[id];
    if(m.count(x-1)) {
        auto &s = m.at(x-1);
        if((*s.begin())>id) return c[id] = 1;

        auto p = s.lower_bound(id);
        if(p!=s.begin()) p--;
        int i = *p;
        return c[id] = 1+dp(m,c,v,i);

    } else return c[id] = 1;
}

int main() { _
    int n;
    cin >> n;

    vi v(n);
    map<int,si> m;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        if(not m.count(v[i])) m.insert({v[i],si()});
        m.at(v[i]).insert(i);
    }

    vi c(n,INT_MIN);

    int mx = INT_MIN;

    for(int i = n-1;i>=0;i--) mx = max(mx,dp(m,c,v,i));
    
    cout << mx << '\n';

    int i;
    for(i=0;i<n;i++) if(c[i]==mx) break;
    
    c.clear();
    int x = v[i];
    
    for(;mx;i--) {
        if(v[i]==x) {
            x--;
            mx--;
            c.push_back(i+1);
        }
    }

    for(auto it = c.rbegin();it!=c.rend();it++) cout << *it << ' ';
    cout << '\n';
    
    return 0;
}