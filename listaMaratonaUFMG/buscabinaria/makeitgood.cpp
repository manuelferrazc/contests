#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

bool testa(vi &v,int x) {
    int act = INT_MIN, a=x+1, b = ((int)v.size())-1;

    while(b>=a) {
        if(act>v[a] or act>v[b]) return false;

        if(v[a]<= v[b]) {act = v[a];a++;}
        else {act = v[b];b--;}
    }

    return true;
}

int bb(vi &v, int a, int b) {
    if(a==b) return testa(v,a) ? a : a+1;

    int m = (a+b)/2;
    if(testa(v,m)) return bb(v,a,m);
    return bb(v,m+1,b);
}

void solve() {
    int n;
    cin >> n;

    vi v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];

    cout << bb(v,0,n) << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
