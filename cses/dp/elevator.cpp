#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> v;
vector<int> dp;
ll x;

ll count(int m) {
    ll c=0;
    for(int i=0;i<20;i++) if(m&(1<<i)) c+=v[i];
    return c;
}

int brute(int m) {
    if(dp[m]!=INT_MAX) return dp[m];

    vector<int> idx;
    for(int i=0;i<20;i++) if(m&(1<<i)) idx.push_back(i);
    int n = idx.size();

    for(int i=1;i<(1<<n);i++) {
        int m2=0;
        for(int j=0;j<n;j++) if(i&(1<<j)) m2+=1<<idx[j];
        ll c = count(m2);
        if(c<=x) dp[m]=min(dp[m],1+brute(m^m2));
    }

    return dp[m];
}

int main() { 
    int n;
    cin >> n >> x;
    v.resize(n);
    dp.resize(1<<n,INT_MAX);
    dp[0] = 0;
    for(ll &i:v) cin >> i;

    cout << brute((1<<n)-1) << '\n';

    return 0;
}
