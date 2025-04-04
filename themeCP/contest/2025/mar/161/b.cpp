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
    multiset<int> s;
    vector<int> v(n);
    for(int &i:v) {
        cin >> i;
        s.insert(i);
    }

    if(s.count(v[0])<k) {
        cout << "nO\n";
        return;
    } else if(v[n-1]==v[0]) {
        cout << "YeS\n";
        return;
    }

    int qtd=0;
    for(int i=0;i<n and qtd<k;i++) {
        if(v[i]==v[0]) qtd++;
        s.erase(s.lower_bound(v[i]));
    }

    if(s.count(v[n-1])>=k) {
        cout << "yES\n";
        return;
    } else cout << "no\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
