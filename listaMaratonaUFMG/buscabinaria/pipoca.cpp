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

bool testa(vll &v, ll t, ll mps, ll c) {
    ll saco = 0, part = 0, comeu=0;

    while(part<c) {
        comeu += v[saco];
        if(comeu>(t*mps)) {
            part++;
            comeu = 0;
            continue;
        }
        saco++;

        if(saco==(ll)v.size()) return true;
    }

    return false;
}

ll bb(vll &v, ll a, ll b, ll mps, ll c) {
    if(a==b) return testa(v,a,mps,c)? a : a+1;

    ll m = (a+b)>>1;

    if(testa(v,m,mps,c)) return bb(v,a,m,mps,c);
    return bb(v,m+1,b,mps,c);
}

int main() { _
    ll n,c,mps;
    cin >> n >> c >> mps;

    vll v(n);
    for(ll i=0;i<n;i++) cin >> v[i];

    cout << bb(v,1LL,2000000000LL,mps,c) << '\n';
    return 0;
}
