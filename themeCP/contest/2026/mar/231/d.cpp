#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int * calc(int *a, int *b, int *c, ll mi, int n) {
    int *p = new int[6];

    ll i,acc = 0;
    bool ok = false;
    for(i=0;i<n;i++) {
        acc+=a[i];
        if(acc>=mi) {
            ok = true;
            p[0] = 0;
            p[1] = i;
            p[2] = i+1;
            break;
        }
    }

    if(ok==false) {
        delete[] p;
        return nullptr;
    }

    ok = false;
    acc = 0;

    for(i++;i<n;i++) {
        acc+=b[i];
        if(acc>=mi) {
            ok = true;
            p[3] = i;
            p[4] = i+1;
            break;
        }
    }

    if(ok==false) {
        delete[] p;
        return nullptr;
    }

    acc = 0;

    for(i++;i<n;i++) {
        acc+=c[i];
        if(acc>=mi) {
            p[5] = i;
            return p;
        }
    }

    delete[] p;
    return nullptr;
}

void solve() {
    int n;
    cin >> n;
    
    int a[n],b[n],c[n];

    ll mi = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        mi+=a[i];
    }

    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) cin >> c[i];

    mi = (mi+2)/3;

    pair<pair<int,int*>, pair<int,int>> v[] = {
        pair(pair(0,a),pair(0,1)),
        pair(pair(1,b),pair(2,3)),
        pair(pair(2,c),pair(4,5))
    };

    int cnt = 0;
    do {
        cnt++;
        int * p = calc(v[0].ff.ss, v[1].ff.ss, v[2].ff.ss,mi,n);
        if(p==nullptr) continue;

        int ans[6];

        for(int i=0;i<3;i++) {
            ans[v[i].ss.ff] = p[2*i]; 
            ans[v[i].ss.ss] = p[2*i+1]; 
        }

        for(int i=0;i<6;i++) cout << ans[i]+1 << ' ';
        cout << '\n';

        delete[] p;
        return;
    } while(next_permutation(v,v+3));
    
    cout << -1 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
