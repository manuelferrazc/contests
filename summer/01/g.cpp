#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    pair<int,int> v[n];

    for(int i=0;i<n;i++) cin >> v[i].ff >> v[i].ss;
    ll qtd,dist;
    cin >> dist >> qtd;

    for(int i=0;i<n;i++) v[i].ff = dist-v[i].ff;

    sort(v,v+n);

    priority_queue<int> pq;
    pq.push(0);


    int ans = 0;
    int nx = 0;

    while(qtd<dist) {
        if(pq.empty()) {
            cout << -1 << '\n';
            return;
        }

        int ret = pq.top();
        qtd+=ret;
        pq.pop();
        if(ret) ans++;

        while(nx<n and v[nx].ff<=qtd) {
            pq.push(v[nx].ss);
            nx++;
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
