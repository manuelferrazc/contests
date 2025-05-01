#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { 
    int n,q;
    cin >> n >> q;

    vector<int> p(n),d(n);
    p[0] = -1;
    d[0] = 0;
    
    for(int i=1;i<n;i++) {
        int a;
        cin >> a;
        p[i] = a-1;
    }
    int m=0;
    while((1<<m)<n) m++;
    vector<vector<int>> ka(n,vector<int>(m,-1));
    // ka[0][0] = 0;    
    for(int i=1;i<n;i++) {
        d[i] = d[p[i]]+1;
        ka[i][0] = p[i];
        for(int j=1;j<m;j++) if(ka[i][j-1]!=-1) ka[i][j] = ka[ ka[i][j-1] ][j-1];
    }

    while(q--) {
        int x,k;
        cin >> x >> k;
        x--;
        if(d[x]<k) {
            cout << -1 << '\n';
            continue;
        }

        for(int i=0;i<20;i++) 
            if(k&(1<<i)) x = ka[x][i];

        cout << x+1 << '\n';
    }

    return 0;
}
