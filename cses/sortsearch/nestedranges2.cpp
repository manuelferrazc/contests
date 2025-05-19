#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(auto &i:v) cin >> i.ff >> i.ss;

    for(int i=0;i<n;i++) {
        bool ok = false;

        for(int j=0;j<n;j++) {
            if(i==j) continue;
            if(v[i].ff<=v[j].ff and v[j].ss<=v[i].ss) {
                ok = true;
                break;
            }
        }

        cout << ok << ' ';
    }

    cout << '\n';
    
    for(int i=0;i<n;i++) {
        bool ok = false;

        for(int j=0;j<n;j++) {
            if(i==j) continue;
            if(v[j].ff<=v[i].ff and v[i].ss<=v[j].ss) {
                ok = true;
                break;
            }
        }

        cout << ok << ' ';
    }
    cout << '\n';
    
    return 0;
}
