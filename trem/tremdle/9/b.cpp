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

    int ans=0;
    auto it = max_element(vc.begin(),vc.end()), it2 = max_element(vl.begin(),vl.end());

    auto lb = lower_bound(v.begin(),v.end(),make_pair((int)(it2-vl.begin()),int(it-vc.begin())));
    if(lb==v.end() or *lb!=make_pair((int)(it2-vl.begin()),(int)(it-vc.begin()))) ans=max(ans,(int)(*it+*it2));
    else ans = max(ans,*it+*it2-1);
    cout << ans << '\n';
    return 0;
}
