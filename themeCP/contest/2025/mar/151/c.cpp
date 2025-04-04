#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,k;
    cin >> n >> k;
    map<int,int> m;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        m[x]++;
    }

    int ans=0,act=0,qtd=0;
    for(auto &i:m) {
        if(m.count(i.ff-1)==0ULL) {
            act=i.ss;
            qtd=1;
        } else {
            act+=i.ss;
            if(qtd==k) act-=m.at(i.ff-k);
            else qtd++;
        }
        ans=max(ans,act);
    }
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
