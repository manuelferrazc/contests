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
    for(int i=0;i<n;i++) cin >> v[i];
    int inv=0;

    for(int i=0;i<n;i++) {
        int q1=0,q2=0;
        for(int j=0;j<i;j++) if(v[j]>v[i]) q1++;
        for(int j=i+1;j<n;j++) if(v[j]>v[i]) q2++;
        inv+=min(q1,q2);
    }

    cout << inv << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
