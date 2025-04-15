#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    
}

int main() { _
    int n,m;
    cin >> n >> m;
    int qtd;
    cin >> qtd;

    vector<int> vl(n,0),vc(m,0);

    vector<pair<int,int>> v(qtd);
    for(int i=0;i<qtd;i++) {
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        vl[x]++;
        vc[y]++;
        v[i].ff = x;
        v[i].ss = y;
    }
    sort(v.begin(),v.end());

    int maxc = *max_element(vc.begin(),vc.end()), maxl = *max_element(vl.begin(),vl.end());

    vector<int> mc,ml;
    for(int i=0;i<n;i++) if(vl[i]==maxl) ml.push_back(i);
    for(int i=0;i<m;i++) if(vc[i]==maxc) mc.push_back(i);

    for(int x:ml) {
        for(int y:mc) {
            pair<int,int> p;
            p.ff=x;
            p.ss=y;
            auto it = lower_bound(v.begin(),v.end(),p);
            if(it==v.end() or *it!=p) {
                cout << maxl + maxc << '\n';
                return 0;
            }
        }
    }

    cout << maxl+maxc-1 << '\n';
    return 0;
}
