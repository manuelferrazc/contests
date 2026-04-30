#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n;
    cin >> n;

    vector<int> f(n);
    int mx = 0;
    for(int &i:f) {
        cin >> i;
        mx = max(mx,i);
    }

    sort(f.begin(),f.end());

    int l = 0,r=n+10;
    int ans = 0;

    while(l<=r) {
        int m = (l+r)/2;

        vector<int> qtd(mx+1,0);
        for(int i=0;i<n;i++) qtd[f[i]]++;
        for(int i=0;i<=min(mx,m-1);i++) if(qtd[i]) qtd[i]--;
        
        int idf = 0;
        int idq = 0;
        bool ok = true;

        for(int i = 0;i<m;i++) {
            while(idf<n and f[idf]<i) idf++;
            
            if(idf<n and f[idf]==i) continue;
            
            idq = max(idq,2*i+1);

            while(idq<qtd.size() and qtd[idq]==0) idq++;
            if(idq>=qtd.size()) {
                ok = false;
                break;
            } else qtd[idq]--;
        }

        if(ok) {
            ans = m;
            l = m+1;
        } else r = m-1;
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
