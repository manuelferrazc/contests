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
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    vector<bool> oc(n+1,false);

    int m=0;
    for(int i=n-1;i>=0;i--) {
        if(a[i]==b[i] or oc[a[i]] or oc[b[i]] or (i!=n-1 and (a[i]==a[i+1] or b[i]==b[i+1]))) m = max(m,i+1);
        if(i!=n-1) oc[a[i+1]] = oc[b[i+1]] = true;
    }

    cout << m << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
