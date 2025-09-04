#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

// k -> por heroi, m -> tota/l
bool ok(vector<ll> &v, ll k, ll m, double x,ll s) {
    ll n = v.size();
    while(n>1) {
        if(m>=k*n) { // tá sobrando operacao, n dá pra usar tudo
            if((s+n*k)/x>=n) return true;
        } else { // tá faltando, consigo usar tudo
            if((s+m)/x>=n) return true;
        }
        if(m==0) break;
        
        m--;
        s-=v[n-1];
        n--;
    }
    // cout << "val:" << v[0]+min(m,k) << '\n';
    return v[0]+min(m,k)>=x*n;
}

int main() { _
    int n,m,k;
    cin >> n >> k >> m;

    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    sort(v.rbegin(),v.rend());
    ll s = accumulate(v.begin(),v.end(),0LL);
    double ans = 0;
    double a=1,b=1e13;

    while(a<b-0.00000000001) {
        double x = (a+b)/2;

        if(ok(v,k,m,x,s)) {
            // cout << x << '\n';
            a = x;
            ans = x;
        } else b = x;
    }

    cout << fixed << setprecision(15) << ans << '\n';

    return 0;
}
