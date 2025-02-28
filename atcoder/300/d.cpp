#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll n;
ll ans=0;

void p3(vector<ll> &p, ull i, ll act) {
    for(ull j=i+1;j<p.size();j++) {
        if(act*p[j]>=n) return;
        else if(act*p[j]*p[j]>n) return;
        else ans++;
    }
}

void p2(vector<ll> &p, ull j, ll act) {
    for(ull i=j+1;i<p.size()-1;i++) {
        if(act*p[i]>=(n>>2)) return;
        else p3(p,i,act*p[i]);
    }
}


int main() { _
    cin >> n;
    vector<ll> p;
{    vector<bool> c(sqrt(n),true);
    for(ull i=2;i<c.size();i++) {
        if(not c[i]) continue;
        p.push_back(i);
        for(ull j=i+i;j<c.size();j+=i) c[j]=false;
    }}

    for(ull i=0;i<p.size() and p[i]*p[i]<(n>>3);i++) p2(p,i,p[i]*p[i]);

    cout << ans << '\n'; 

    return 0;
}
