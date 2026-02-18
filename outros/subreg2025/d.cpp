#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> sos_dp(vector<ll> f) {
    int N = __builtin_ctz(f.size());
    for(int i=0;i<N;i++) for(int mask=0;mask<(1<<N);mask++) 
    if(mask>>i&1) f[mask]+=f[mask^(1<<i)];
    return f;
}

int get(int *p, int a) {
    return p[a] = (p[a]==a?a:get(p,p[a]));
}

void unir(int *p, int a, int b) {
    a = get(p,a);
    b = get(p,b);

    if(a!=b) p[a] = b;
}
int main() { _
    vector<ll> v(1<<21);
    v[0] = 0;
    
    vector<pair<int,int>> p;
    for(int i=1;i<=6;i++) for(int j=i;j<=6;j++) p.push_back(pair(i,j));
    
    for(int i=1;i<(1<<21);i++) {
        int adj[6];
        for(int j=0;j<6;j++) adj[j] = 0;
        
        int pr[6];
        for(int j=0;j<6;j++) pr[j] = j;
        
        int x = -1;
        for(int j=0;(1<<j)<=i;j++) if(i&(1<<j)) {
            adj[x = p[j].ff-1]++;
            adj[p[j].ss-1]++;
            unir(pr,p[j].ff-1,p[j].ss-1);
        }

        int imp = 0;
        for(int j=0;j<6;j++) if(adj[j]&1) imp++;

        if(imp!=0 and imp!=2) {
            v[i] = 0;
            continue;
        }
        
        x = get(pr,x);
        int ok = 1;
        for(int j=0;j<6;j++) if(adj[j] and x!=get(pr,j)) ok = false;
        v[i] = ok;
    }

    v = sos_dp(v);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int m = 0;
        while(n--) {
            int a,b;
            cin >> a >> b;
            for(int j=0;j<21;j++) if(p[j]==pair(a,b)) {
                m|=(1<<j);
                break;
            }
        }

        cout << v[m] << '\n';
    }

    return 0;
}
