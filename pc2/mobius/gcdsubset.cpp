#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int p = 200'000;
const ll mod = 1'000'000'007;

ll fexp(ll n, ll e) {
    ll r = 1;
    while(e) {
        if(e&1) r = r*n%mod;
        e>>=1;
        n=n*n%mod;
    }
    return r;
}

int count(int n) {
    int r=0;
    for(int i=2;i*i<=n;i++) {
        while(n%i==0) {
            r++;
            n/=i;
        }
    }
    if(n>1) r++;
    return r;
}

int main() { _
    int n;
    cin >> n;

    vector<int> oc(p+1,0);
    int cnt[p+1];
    for(int i=0;i<=p;i++) cnt[i] = count(i)&1;

    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        oc[x]++;
    }

    int *c = new int[p+1];
    for(int i=0;i<=p;i++) c[i] = 0;
    
    for(int i=1;i<=p;i++) {
        for(int j=i;j<=p;j+=i) c[i]+=oc[j];
    }

    // for(int i=1;i<15;i++) cout << "i = " << i << ", c = " << cnt[i] << '\n';

    for(int i=1;i<=n;i++) {
        ll ans = 0;

        for(int d=i;d<=p;d+=i) {
            if(c[d]==0) continue;
            if(cnt[i]==cnt[d]) ans+=fexp(2,c[d]);
            else ans-=fexp(2,c[d]);
            if(ans<0) ans+=mod;
            ans%=mod;
        }

        cout << ans << ' ';
    }
    cout << '\n';

    delete[] c;

    return 0;
}
