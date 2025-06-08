#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


// void odd(vector<ll> &v) {
    //     vector<ll> aux;
    //     for(ll i=0,j=v.size()-1;i<j;i++,j--) aux.push_back(v[i]+v[j]);
    //     ll s = n+1;
    //     ll r = v[v.size()/2]/(v.size()/2+1);
//     ll res = v[v.size()/2]%(v.size()/2+1);
//     if(res) {
    //         cout << "NO\n";
    //         return;
//     }
//     for(ull i=0;i<aux.size();i++) {
//         if(aux[i]/s!=r or aux[i]%s) {
//             cout << "NO\n";
//             return;
//         }
//     }

//     cout << "YES\n";
// }

// void even(vector<ll> &v) {
    //     vector<ll> aux;
    //     for(ll i=0,j=v.size()-1;i<j;i++,j--) aux.push_back(v[i]+v[j]);
    //     ll s = n+1;
    //     ll r = aux[0]/s;
    //     ll res = aux[0]%s;
//     if(res) {
//         cout << "NO\n";
//         return;
//     }
//     for(ull i=1;i<aux.size();i++) {
    //         if(aux[i]/s!=r or aux[i]%s) {
        //             cout << "NO\n";
        //             return;
        //         }
        //     }
        
        //     cout << "YES\n";
        // }
        
void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    bool ok = true;
    for(int i=0;i<n;i++) {
        if(v[i]%(n+1)) {
            ok = false;
            break;
        }
    }

    if(ok) {
        cout << "YES\n";
        return;
    }
    ok = true;
    for(int i=0;i<n;i++) {
        if((v[i])%(n-i)) {
            ok = false;
            break;
        }
    }

    if(ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
