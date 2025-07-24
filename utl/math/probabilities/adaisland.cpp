#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) {
    if (a<b) swap(a,b);

    ll aux;
    while(b) {
        aux = a;
        a = b;
        b = aux%b;
        if (a<b) swap(a,b);
    }
    return a;
}

int n,m;

ll dfs(char **v, int i, int j) {
    static const pair<int,int> d[] = {{1,0},{-1,0},{0,1},{0,-1}};
    ll r=1;
    v[i][j] = '~';

    for(const auto &p:d) {
        auto a = p.ff, b = p.ss;
        int x=i+a,y=j+b;
        if(x<0 or y<0 or x>=n or y>=m or v[x][y]!='#') continue;
        r+=dfs(v,x,y);
    }
    return r;
}

void solve() {
    ll ans(0);
    scanf("%d %d\n", &n, &m);

    char *v[n];
    for(int i=0;i<n;i++) {
        v[i] = (char*)malloc(m+10);
        scanf("%s\n", v[i]);
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]=='#') {
                ll x = dfs(v,i,j);

                ans+=x*x;
            }
        }
    }

    ll x = n*m;
    ll g = gcd(ans,x);
    
    ans/=g;
    x/=g;


    if(x==1) cout << ans << '\n';
    else cout << ans << " / " << x << '\n';

    for(int i=0;i<n;i++) free(v[i]);
}

int main() { _
    int t;
    scanf("%d\n",&t);
    while(t--) solve();
    return 0;
}
