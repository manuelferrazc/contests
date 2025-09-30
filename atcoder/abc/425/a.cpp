#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n,ans=0;
    cin >> n;

    for(int i=1;i<=n;i++) {
        if(i&1) ans-=i*i*i;
        else ans+=i*i*i;
    }

    cout << ans << '\n';

    return 0;
}
