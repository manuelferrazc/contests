#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int mod = 676767677;

// podia ser linear btw
ll fexp(ll n, ll e) {
    ll r = 1;
    while(e) {
        if(e&1) r = (r*n)%mod;
        n = n*n%mod;
        e>>=1;
    }
    return r;
}

ll solve() {
    int n,m;
    cin >> n >> m;

    int b[n];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) {
        bool ok = i and b[i]>b[i-1];
        ok = ok or (i<n-1 and b[i]>b[i+1]);

        if(b[i] and ok==false) return 0;
    }

    int qtd[m];
    fill(qtd,qtd+m,0);
    for(int i=0;i<n;i++) qtd[b[i]]++;

    for(int i=1;i<m;i++) qtd[i]+=qtd[i-1];

    vector<int> id[m];
    for(int i=0;i<n;i++) id[b[i]].push_back(i);
    
    ll ans = 1;
    for(int bi=1;bi<m;bi++) {
        for(auto i:id[bi]) {
            int mi = INT_MAX;
            if(i) mi = b[i-1];
            if(i<n-1) mi = min(mi,b[i+1]);

            if(bi-mi==1) ans = ans*qtd[bi-1]%mod;
            else {
                int k = qtd[bi-1];
                if(bi>1) k-=qtd[bi-2];
                
                ans = ans*k%mod;
            }
        }
    }

    return ans;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
