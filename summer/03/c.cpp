#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,k;
    cin >> n >> k;

    int p[k];
    for(int i=0;i<k;i++) cin >> p[i];

    int v[n+1];
    v[0] = 0;

    for(int i=1;i<=n;i++) {
        vector<bool> aux(101,false);
        for(int j=0;j<k;j++) {
            if(i-p[j]>=0 and v[i-p[j]]<=100) aux[v[i-p[j]]] = true;
        }

        for(int m=0;;m++) {
            if(aux[m]==false) {
                v[i] = m;
                break;
            }
        }

        if(v[i]) cout << 'W';
        else cout << 'L';
    }
    
    cout << '\n';

    return 0;
}
