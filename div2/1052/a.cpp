#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int ans=0,n;
    cin >> n;

    map<int,int> qtd;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        qtd[x]++;
    }

    multimap<int,int> sla;
    for(auto [a,b]:qtd) sla.insert({b,a});

    for(int i=1;sla.size();i++) {
        while(sla.size() and sla.begin()->ff<i) sla.erase(sla.begin());
        ans = max(ans,i*(int)sla.size());
    }

    cout << ans << '\n';
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
