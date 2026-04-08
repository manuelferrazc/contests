#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int solve() {
    int n,k;
    cin >> n >> k;

    int a[n];
    for(int i=0;i<n;i++) cin >> i[a];

    int id;
    cin >> id;
    id--;

    
    int l=0,r=0;
    for(int i=id+1;i<n;i++) if(a[i]!=a[i-1]) r++;
    for(int i=id-1;i>=0;i--) if(a[i]!=a[i+1]) l++;

    int ans = max(l,r);
    if(ans&1) ans++;
    return ans;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
