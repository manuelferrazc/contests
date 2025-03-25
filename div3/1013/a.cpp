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
    vector<int> v(n);
    for(int &i:v) cin >> i;
    map<int,int> qtd;
    qtd.insert({0,3});
    qtd.insert({1,1});
    qtd.insert({2,2});
    qtd.insert({3,1});
    qtd.insert({5,1});
    int qt=5;
    for(int i=0;i<n;i++) {
        if(qtd.count(v[i])) {
            qtd[v[i]]--;
            if(qtd[v[i]]==0) {
                qtd.erase(v[i]);
                qt--;
            }
        }
        if(qtd.empty()) {
            cout << i+1 << '\n';
            return;
        }
    }
    cout << "0\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
