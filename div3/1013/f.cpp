#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353;
ll n,m,d;


void make_sp(vector<ll> &v,vector<ll> &sp) {
    sp[0]=v[0];
    for(ull i=1;i<v.size();i++) sp[i] = sp[i-1]+v[i];
}

void solve() {
    cin >> n >> m >> d;
    vector<string> v(n);
    for(ll i=0;i<n;i++) cin >> v[i];
    
    vector<ll> v1(m,0),sp(m,0);
    for(ll i=0;i<m;i++) if(v[0][i]=='X') v1[i]++;
    make_sp(v1,sp);
    
    for(ll i=0;i<m;i++) {
        if(v[0][i]=='#') continue;
        if(i) {
            if(i-d>0) v1[i]+=sp[i-1]-sp[i-d-1];
            else v1[i]+=sp[i-1];
        }
        v1[i]+=sp[min(m-1,i+d)]-sp[i];
    }
    
    make_sp(v1,sp);
    for(ll r=1;r<n;r++) {
        for(ll i=0;i<m;i++) {
            if(v[r][i]=='#') v1[i] = 0;
            else if(i-d>=0) v1[i] = (sp[min(m-1,i+d-1)]-sp[i-d])%mod;
            else v1[i] = sp[min(m-1,i+d-1)]%mod;
        } 

        make_sp(v1,sp);
        for(ll i=0;i<m;i++) {
            if(v[r][i]=='#') continue;
            if(i) {
                if(i-d>0) v1[i]=(v1[i]+sp[i-1]-sp[i-d-1])%mod;
                else v1[i]=(v1[i]+sp[i-1])%mod;
            }
            v1[i]=(v1[i]+sp[min(m-1,i+d)]-sp[i])%mod;
        }
        make_sp(v1,sp);
    }

    cout << sp.back()%mod << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
