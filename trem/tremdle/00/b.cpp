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
    map<string,int> m;
    for(int i=0;i<n;i++) {
        string x;
        cin >> x;
        m[x]++;
    }

    pair<string,int> p = {"",0};
    for(auto &i:m) if(i.ss>p.ss) p=i;
    if(p.ss>(n>>1)) cout << p.ff << '\n';
    else cout << "vixe\n";
}

int main() { _
    int t=1;
    while(t--) solve();
    return 0;
}
