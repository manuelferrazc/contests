#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


ll n,k,a,b;
vector<ll> av;

int count(ll l, ll r) {
    auto it = upper_bound(av.begin(),av.end(),r);
    auto it2 = lower_bound(av.begin(),av.end(),l);
    return it-it2;
}

ll brute(ll l, ll r) {
    // cout << l << ' ' << r << '\n';
    ll len = (r-l+1);
    int qtd = count(l,r);
    // cout << qtd << '\n';
    if(qtd==0) return a;
    if(l==r) return qtd*b;
    else return min(len*qtd*b,brute(l,l+len/2-1)+brute(l+len/2,r));
}

int main() { 
    cin >> n >> k >> a >> b;
    
    av.resize(k);
    for(ll &i:av) cin >> i;
    sort(av.begin(),av.end());

    cout << brute(1,1<<n) << '\n';
    
    return 0;
}
