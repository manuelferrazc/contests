#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), count(101,0);
    int qtd=0;

    int n1=-1,n2=-1;
    for(int i=0;i<n;i++) {
        cin >> v[i];
        count[v[i]]++;
        if(count[v[i]]==2) {
            qtd++;
            if(n1==-1) n1 = v[i];
            else if(n2==-1) n2 = v[i];
        }
    }

    if(qtd<2) cout << -1 << '\n';
    else {
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++) if(v[i]==n1) {
            ans[i] = 3;
            break;
        }
        for(int i=0;i<n;i++) if(v[i]==n2) {
            ans[i] = 2;
            break;
        }
        for(int i=0;i<n;i++) if(ans[i]==-1) ans[i] = 1;
        for(int i:ans) cout << i << ' ';
        cout << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
