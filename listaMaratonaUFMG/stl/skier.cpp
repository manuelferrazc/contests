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
    string s;
    cin >> s;

    set<pair<pii,pii>> c;
    pii a={0,0},p;
    int t=0;

    for(ull i=0;i<s.size();i++) {
        p = a;
        if(s[i]=='N') p.s++;
        else if(s[i]=='S') p.s--;
        else if(s[i]=='E') p.f--;
        else p.f++;

        if(c.count(make_pair(a,p))) t++;
        else t+=5;
        c.insert({a,p});
        c.insert({p,a});
        a = p;
    }

    cout << t << '\n';
}

int main() { _
    int n;
    cin >> n;

    while(n--) solve();

    return 0;
}