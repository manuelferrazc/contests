#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,q;
    cin >> n >> q;
    vector<multiset<int>> caixas(n+1);
    vector<set<int>> cartas(2e5+1);
    int t,b,a;
    while(q--) {
        cin >> t;

        if(t==1) {
            cin >> a >> b;
            caixas[b].insert(a);
            cartas[a].insert(b);
        }
        else if(t==2) {
            cin >> a;
            for(auto i:caixas[a]) cout << i << ' ';
            cout << '\n';
        } else {
            cin >> a;
            for(auto i:cartas[a]) cout << i << ' ';
            cout << '\n';
        }
    }
}

int main() { _
    solve();
    return 0;
}
