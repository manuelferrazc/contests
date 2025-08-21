#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m;
    string a,b,c;
    cin >> n >> a >> m >> b >> c;
    reverse(b.begin(),b.end());
    for(char cc:c) {
        if(cc=='V') a = b.back()+a;
        else a.push_back(b.back());
        b.pop_back();
    }
    cout << a << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
