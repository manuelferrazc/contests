#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ss first
#define ff second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n, k, ans=0;
    cin >> n >> k;
    vector<pair<int,int>> v(n);

    for(auto &i:v) cin >> i.ff >> i.ss;
    sort(v.begin(),v.end());

    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++) {
        ans++;
        pq.push(v[i].ss);
    }

    for(int i=k;i<n;i++) {
        if(pq.top()<v[i].ff) {
            ans++;
            pq.pop();
            pq.push(v[i].ss);
        }
    }

    cout << ans << '\n';

    return 0;
}
