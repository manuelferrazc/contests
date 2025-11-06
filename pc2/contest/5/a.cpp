#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define r first
#define c second
typedef long long ll;
typedef unsigned long long ull;

ll n,b;
vector<pair<ll,ll>> v[20];

ll best = 0;

void brute(ll i, ll cus, ll lucro) {
    if(cus<=b) best = max(best,lucro);

    if(i==n or cus>b) return;

    brute(i+1,cus,lucro);
    for(int p=0;p<v[i].size();p++) 
        brute(i+1,cus+v[i][p].c,lucro+v[i][p].r);
    
}

int main() { _
    cin >> n >> b;

    for(int i=0;i<n;i++) {
        int k;
        cin >> k;
        while(k--) {
            ll r,c;
            cin >> r >> c;
            v[i].push_back(pair(r,c));
        }
    }

    brute(0,0,0);

    cout << best << '\n';

    return 0;
}
