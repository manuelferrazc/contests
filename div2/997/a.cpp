#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define x first
#define y second
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m;
    cin >> n >> m;



    vector<pair<int,int>> v(n);
    for(auto &i:v) {
        cin >> i.ff >> i.ss;
    }
    int ans=4*m;
    for(ull i=1;i<v.size();i++) {
        ans+=4*m;
        int x = m-v[i].x;
        int y = m-v[i].y;
        ans-=(x+y)*2;
    }
    
    

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
