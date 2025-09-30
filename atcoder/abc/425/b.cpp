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

    int a[n];
    set<int> falta;
    for(int i=1;i<=n;i++) falta.insert(i);

    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(a[i]!=-1) {
            if(not falta.count(a[i])) {
                cout << "No\n";
                return 0;
            }
            falta.erase(a[i]);
        }
        
    }

    cout << "Yes\n";
    
    for(int i:a) {
        if(i>0) cout << i << ' ';
        else {
            cout << *falta.begin() << ' ';
            falta.erase(falta.begin());
        }
    }

    cout << '\n';

    return 0;
}
