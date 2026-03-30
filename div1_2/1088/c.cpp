#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void no() {
    cout << "No\n";
}

void solve() {
    int n,k;
    cin >> n >> k;

    int a[n], b[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    int c[n+1];
    fill(c,c+n+1,0);

    bool bl[k];
    fill(bl,bl+k,true);

    for(int i=0;i<k;i++) {
        for(int j=i+k;j<n;j+=k) if(a[i]!=a[j]) bl[i] = false; // tem algum a[i]!=a[i+kd]

        if(bl[i]) c[a[i]]++; // são todos iguais, os bi tem q ser iguais entre si tbm
        else {
            for(int j=i;j<n;j+=k) if(b[j]!=-1 and b[j]!=a[j]) return no(); // podem ser diferentes, os pares ai bi tem q ser iguais
        }
    }

    for(int i=0;i<k;i++) {
        if(not bl[i]) continue;

        // estou no caso que são todos iguais, os respectivos bi tem q ser iguais
        set<int> d;
        for(int j=i;j<n;j+=k) if(b[j]!=-1) d.insert(b[j]);

        if(d.size()>1ull) return no();
        else if(d.size()) {
            int x = *d.begin();
            if(c[x]==0) return no();
            c[x]--;
        }
    }

    cout << "Yes\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
