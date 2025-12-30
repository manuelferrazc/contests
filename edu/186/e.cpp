#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m;
    ll k;
    cin >> n >> m >> k;

    int box[m];
    for(int i=0;i<m;i++) cin >> i[box];
    sort(box,box+m);

    array<ll,3> f[n]; // 0 -> x, 1 -> y, 2 -> z
    
    for(int i=0;i<n;i++) cin >> f[i][0] >> f[i][1] >> f[i][2];
    sort(f,f+n);
    
    multimap<ll,int> ok;
    bool nobox[n];

    ll sum = 0;
    for(int i=0;i<n;i++) {
        nobox[i] = true;
        sum+=f[i][1];
    }

    int p=0;
    int ans=0;
    for(int g=0;g<m;g++) {
        while(p<n and f[p][0]<=box[g]) {
            ok.insert(pair(f[p][2]-f[p][1],p));
            p++;
        }
        
        if(not ok.empty()) {
            ans++;
            
            auto [save,id] = *ok.rbegin();
            ok.erase(prev(ok.end()));
            
            nobox[id] = false;
        }
    }
    
    vector<ll> sla;
    for(int i=0;i<n;i++) if(nobox[i]) sla.push_back(f[i][2]-f[i][1]);
    sort(sla.rbegin(),sla.rend());
    
    // cout << "sla\n";
    while(not sla.empty()) {
        if(sum+sla.back()<=k) {
            ans++;
            sum+=sla.back();
            sla.pop_back();
        } else break;
    }

    cout << ans << '\n';
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
