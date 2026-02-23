#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char * yes = "YES\n";
const char * no  = "NO\n";

void solve() {
    int n,k;
    cin >> n >> k;

    if(n==1) {
        if(k==1) cout << yes << 1 << ' ' << 1 << '\n';
        else cout << no;
        return;
    }

    list<int> ans;
    for(int i=0;i<n;i++) ans.push_back(i);
    auto it = ans.end();
    it--;
    for(int i=0;i<n;i++) ans.push_back(i);

    int qtd = (n+1)/2+n;

    if(k>qtd) {
        if(n%2==0 and qtd==k-1) {
            cout << yes;
            for(int i=1;i<n;i++) cout << i << ' ';
            cout << 1 << ' ' << n << ' ';
            for(int i=2;i<=n;i++) cout << i << ' ';
            cout << '\n';
        } else cout << no;
        return;
    }
    
    auto i = ans.begin();
    auto end = it;
    it++;

    while(k<qtd and i!=end) {
        qtd--;
        int v = *it;
        ans.insert(i,v);
        i++;
        i++;

        it = ans.erase(it);

    }

    if(k==qtd) {
        cout << yes;
        for(int j:ans) cout << j+1 << ' ';
        cout << '\n';
    } else cout << no;
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
