#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

int p[] = {0,2,3,5,7,11,13,17,19};
int n;

vector<vb> g,h;
vvi c;

int calc(vi &perm) {
    int ans=0;

    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(g[i][j]!=h[perm[i]][perm[j]])
                ans+=c[min(perm[i],perm[j])][max(perm[i],perm[j])];
    return ans;
}
int fb(vi &perm, int usados) {
    if((int)perm.size()==n) {
        for(int i=1;i<=n;i++) if(usados%p[i]!=0) {
            perm.push_back(i);

            int k=calc(perm);
            perm.pop_back();
            return k;
        }
        return INT_MAX;
    }
    else {
        int r = INT_MAX;

        for(int i=1;i<=n;i++) if(usados%p[i]) {
            perm.push_back(i);
            r = min(r,fb(perm,usados*p[i]));
            perm.pop_back();
        }
        return r;
    }
}

int main() { _
    cin >> n;
    g.assign(n+1,vb(n+1,false));
    h.assign(n+1,vb(n+1,false));

    int a, b,m;
    cin >> m;
    for(int i=0;i<m;i++) {
        cin >> a >> b;
        g[a][b] = true;
        g[b][a] = true;
    }

    cin >> m;
    for(int i=0;i<m;i++) {
        cin >> a >> b;
        h[a][b] = true;
        h[b][a] = true;
    }

    c.assign(n+1,vi(n+1));
    for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) cin >> c[i][j];

    vi v;
    v.push_back(0);
    cout << fb(v,1) << '\n';

    return 0;
}