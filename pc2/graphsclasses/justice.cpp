#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool solve() {
    int h,r;
    cin >> h >> r;
    // cout << h << ' ' << r << '\n';
    if(h==0) return false;

    vector<int> adj[h];

    for(int i=0;i<r;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pair<int,int> aux[h];

    for(int i=0;i<h;i++) {
        aux[i].ff = adj[i].size();
        aux[i].ss = i;
    }

    sort(aux,aux+h);

    bool cq[h];
    for(int i=0;i<h;i++) cq[i]=false;

    ll qtd=0;

    for(int i=h-1;i>=0;i--) {
        cq[aux[i].ss] = true;

        for(int u:adj[aux[i].ss]) {
            if(cq[u]==false) r--;
            else qtd++;
        }
        ll n = h-i;
        if(qtd!=n*(n-1)/2) break;
        else if(r==0) {
            cout << 'Y' << '\n';
            return true;
        }
    }

    cout << 'N' << '\n';

    return true;
}

int main() { 
    while(solve()) {}

    return 0;
}
