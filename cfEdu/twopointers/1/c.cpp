#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,m;
    ll ans=0;
    cin >> n >> m;
    vector<int> v(n),w(m);
    for(auto &i:v) cin >> i;
    for(auto &i:w) cin >> i;

    int x=0;
    for(int i=0;i<n and x<m;) {
        if(v[i]<w[x]) i++;
        else if(v[i]>w[x]) x++;
        else {
            ll qv=0,qw=0;
            for(int a=i;i<n and v[a]==v[i];i++) qv++;
            for(int a=x;x<m and w[a]==w[x];x++) qw++;
            ans+=qv*qw;
        }
    }

    cout << ans << '\n';

    return 0;
}
