#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define val first
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> v(n),sp(n+1,0);
    for(auto &i:v) cin >> i;

    for(int i=1;i<n-1;i++) {
        sp[i+1]=sp[i];
        if(v[i-1]>=v[i] and v[i]>=v[i+1]) sp[i+1]++;
    }

    sp[n]=sp[n-1];
    while(q--) {
        int a,b;
        cin >> a >> b;
        if(b-a+1<=2) cout << b-a+1 << '\n';
        else cout << b-a+1-(sp[b-1]-sp[a]) << '\n';
    }
}

int main() { _
    solve();
    return 0;
}
