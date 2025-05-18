#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n,m,ans=1;
    cin >> n >> m;

    vector<int> pos(n),v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        v[i]--;
        pos[v[i]] = i;
    }

    for(int i=1;i<n;i++) if(pos[i-1]>pos[i]) ans++;


    while(m--) { // 3 1 2 5 4
        int a,b;
        cin >> a >> b;
        a--;b--;

        
        if(a>b) swap(a,b);
        
        if(a-b) {
            if(abs(v[a]-v[b])!=1) {
                if(v[a]!=n-1 and pos[v[a]+1]>a and pos[v[a]+1]<b) ans++;
                if(v[a] and pos[v[a]-1]>a and pos[v[a]-1]<b) ans--;

                if(v[b]!=n-1 and pos[v[b]+1]>a and pos[v[b]+1]<b) ans--;
                if(v[b] and pos[v[b]-1]>a and pos[v[b]-1]<b) ans++;
            } else {
                if(v[a]>v[b]) {
                    ans--;
                    if(v[b] and pos[v[b]-1]>a and pos[v[b]-1]<b) ans++;
                    if(v[a]<n-1 and pos[v[a]+1]>a and pos[v[a]+1]<b) ans++;
                } else {
                    ans++;
                    if(v[a] and pos[v[a]-1]>a and pos[v[a]-1]<b) ans--;
                    if(v[b]<n-1 and pos[v[b]+1]>a and pos[v[b]+1]<b) ans--;
                }
            }
            swap(pos[v[a]],pos[v[b]]);
            swap(v[a],v[b]);
        }
        
        cout << ans << '\n';
    }

    return 0;
}
