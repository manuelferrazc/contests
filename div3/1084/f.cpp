#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


void solve() {
    int n,m;
    cin >> n >> m;

    pair<ll,ll> v[n];
    for(int i=0;i<n;i++) 
        cin >> v[i].ff >> v[i].ss;

    sort(v,v+n,
        [] (pair<ll,ll> const &a, pair<ll,ll> const &b) -> bool {
            return a.ss<b.ss;
        }
    );

    pair<ll,ll> s[m];
    for(int i=0;i<m;i++) 
        cin >> s[i].ff >> s[i].ss;
    
    multiset<int> in,notin;
    for(int i=0;i<n;i++) notin.insert(v[i].ff);

    ll best[n+1], bestm[n+1];

    for(int i=0;i<=n;i++) best[i]=0;
    for(int i=0;i<=n;i++) bestm[i]=0;

    int p=0;
    ll sum = 0;

    for(int i=0;i<=n;i++) { // qtd de outros
        while(p<n and v[p].ss<i) {
            if(notin.find(v[p].ff)!=notin.end()) notin.erase(notin.find(v[p].ff));
            else {
                sum-=v[p].ff;
                in.erase(in.find(v[p].ff));
            }
            p++;
        }

        while(notin.size() and in.size()<=i) {
            auto it = prev(notin.end());
            in.insert(*it);
            sum+=*it;
            notin.erase(it);
        }

        if(in.empty()) break;

        best[i] = sum;
        if(i>=in.size() and (p!=n and v[p].ss>i)) bestm[i] = sum;
        else bestm[i] = sum-*in.begin();
    }

    sum = 0;
    p=0;
    in.clear();
    notin.clear();
    in.insert(INT_MIN);

    for(int i=0;i<n;i++) notin.insert(v[i].ff);

    for(int i=1;i<=n;i++) { // qtd de outros (alem do artificial)
        while(p<n and v[p].ss<i) {
            if(notin.find(v[p].ff)!=notin.end()) notin.erase(notin.find(v[p].ff));
            else {
                sum-=v[p].ff;
                in.erase(in.find(v[p].ff));
            }
            p++;
        }

        while(notin.size() and in.size()<=i) {
            auto it = prev(notin.end());
            in.insert(*it);
            sum+=*it;
            notin.erase(it);
        }

        if(in.empty()) break;

        bestm[i] = sum;
    }

    ll ans1 = *max_element(best,best+n+1);

    ll pref[n+1];
    pref[0] = bestm[0];
    for(int i=1;i<=n;i++) pref[i] = max(bestm[i],pref[i-1]);

    // for(int i=0;i<=n;i++) cout << best[i] << ' ';
    // cout << '\n';
    // for(int i=0;i<=n;i++) cout << bestm[i] << ' ';
    // cout << '\n';

    for(int i=0;i<m;i++) {
        cout << max(ans1, pref[s[i].ss]+s[i].ff) << ' ';
    }
    cout << '\n';
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
