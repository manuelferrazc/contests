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
    ll n;
    cin >> n;

    vll v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<pair<ll,ll>> trocas;
    
    for(ll i=0;i<n;i++) {
        ll min = i;
        for(ll j=i+1;j<n;j++) if(v[j]<v[min]) min = j;
        
        if(i!=min) {
            ll aux = v[min];
            trocas.push_back({i,min});
            v[min] = v[i];
            v[i] = aux;
        }
    }


    cout << trocas.size() << '\n';
    for(auto p : trocas) cout << p.f << ' ' << p.s << '\n';

    return 0;
}