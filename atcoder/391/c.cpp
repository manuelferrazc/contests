#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n, q, o, ans=0,a,b;
    cin >> n >> q;
    vector<int> nests(n,1),where(n);
    for(int i=0;i<n;i++) where[i] = i;

    while(q--) {
        cin >> o;

        switch(o) {
            case 1: {
                cin >> a >> b;
                a--;
                b--;
                if(nests[where[a]]==2) ans--;
                nests[where[a]]--;
                where[a] = b;
                nests[b]++;
                if(nests[b]==2) ans++;
                break;
            }
            case 2: {
                cout << ans << '\n';
                break;
            }
        }
    }
}

int main() { _
    solve();
    return 0;
}
