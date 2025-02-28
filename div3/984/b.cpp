#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int,int> custo;
    int a,b;
    for(int i=0;i<k;i++) {
        cin >> a >> b;
        if(not custo.count(a)) custo.insert({a,0});
        custo.at(a)+=b;
    }

    int ans = 0;
    multiset<int> s;
    for(auto i:custo) s.insert(i.ss);

    auto it = s.rbegin();
    for(int i=0;i<n;i++) {
        if(it==s.rend()) break;
        ans+=*it;
        it++;
    }

    cout << ans << '\n';
}

int main() { _
    int t; cin >> t;

    while(t--) solve();

    return 0;
}
