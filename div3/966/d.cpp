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
    string s;
    vll v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    cin >> s;

    vll sp(n);
    sp[0] = v[0];
    for(int i=1;i<n;i++) sp[i] = sp[i-1]+v[i];


    vi vl,vr;
    for(int i=0;i<n;i++) {
        if(s[i]=='L') vl.push_back(i);
        else vr.push_back(i);
    }

    ull idl = 0, r=0;
    vector<pii> somas;
    while(idl!=vl.size() and vr.size()) {
        somas.push_back({vl[idl++],vr.back()});
        vr.pop_back();
    }

    for(auto p:somas) {
        if(p.f<=p.s) r+=sp[p.s]-(p.f==0?0:sp[p.f-1]);
    }

    cout << r << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}