#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n,ans=1;
    cin >> n;

    vector<int> v(n+1);
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        v[x] = i;
    }

    for(int i=1;i<n;i++) if(v[i]>v[i+1]) ans++;
    cout << ans << '\n';

    return 0;
}
