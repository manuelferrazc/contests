#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
#define INF INT_MAX
#define LINF LONG_MAX
#define LLINF LONG_LONG_MAX
typedef long long ll;
typedef long l;


int main() { _
    int n, v; cin >> n;

    map<int,int> mapa;
    int resp = 0, r=0;

    for(int i=1;i<=n;i++) {
        cin >> v;
        if(v==i) resp++;
        else mapa.insert({i,v});
    }

    resp = (resp*(resp-1))/2;

    for(auto p:mapa) {
        if(p.f>=p.s) continue;
        if(mapa.count(p.s)==0) continue;
        
        if(p.f==mapa.at(p.s)) r++;
    }

    cout << resp+r << '\n';

    
    return 0;
}