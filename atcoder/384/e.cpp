#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const pair<ll,ll> d[] = {{0,1},{0,-1},{1,0},{-1,0}};

bool test(ll a, ll b, ll x) {
    if(a%x) return (a/x)>=b;
    else return (a/x)>b;
}

int main() { _
    ll n,m,xi,p,q;
    cin >> n >> m >> xi >> p >> q;
    p--;q--;

    vector<vector<ll>> v(n,vector<ll>(m));
    vector<vector<bool>> us(n,vector<bool>(m,false));
    us[p][q] = true;
    for(auto &id:v) for(auto &i:id) cin >> i;

    multimap<ll,pair<ll,ll>> mm;
    for(auto i:d) {
        ll x = p+i.ff,y=q+i.ss;
        if(x<0 or y<0 or x>=n or y>=m) continue;
        mm.insert({v[x][y],{x,y}});
        us[x][y] = true;
    }

    while(mm.size() and test(v[p][q],mm.begin()->ff,xi)) {
        auto it = mm.begin();
        v[p][q] += it->ff;
        auto pa = it->ss;
        mm.erase(it);
        for(auto i:d) {
            ll x = pa.ff+i.ff,y=pa.ss+i.ss;
            if(x<0 or y<0 or x>=n or y>=m or us[x][y]) continue;
            mm.insert({v[x][y],{x,y}});
            us[x][y] = true;
        }
    }

    cout << v[p][q] << '\n';
    
    return 0;
}
