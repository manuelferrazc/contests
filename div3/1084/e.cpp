#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int d[1'000'001];
int qf[1'000'001];
int raiz[1'000'001];
int f[1'000'001];

const char * alice = "Alice\n";
const char * bob   = "Bob\n";

const char * solve() {
    int n;
    cin >> n;

    ll v[n];
    for(int i=0;i<n;i++) cin >> i[v];

    
    {
        bool s = true;
        for(int i=1;i<n;i++) if(v[i-1]>v[i]) s = false;
        
        if(s) return bob;
    }
    
    for(int i=0;i<n;i++) if(qf[v[i]]>1) return alice;
    
    // não tá ordenado, e todo número é primo ou tem raiz inteira
    list<int> l;
    for(int i=0;i<n;i++) {
        if(d[v[i]]==0) l.push_back(v[i]);
        else l.push_back(f[v[i]]);
    }

    int fr = -1;
    
    while(l.size()) {
        int t = l.front();
        l.pop_front();
        if(fr>t) return alice;
        fr = t;
    }

    return bob;
}

int main() { _
    for(ll i=2;i<=1'000'000;i++) {
        if(i*i<=1'000'000) raiz[i*i] = i;

        for(int j=i+i;j<=1'000'000;j+=i) {
            d[j]++;
            if(f[j]==0) f[j] = i;
        }

        if(qf[i]==0) 
            for(int j=i;j<=1'000'000;j+=i) qf[j]++;
    }
    
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
