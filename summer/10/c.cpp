#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n;

vector<ll> brute(string m2, ll q) {
    vector<ll> r;

    ll m = 0;
    for(int i=0;i<n;i++) if(m2[i]=='1') m+=(1ll<<i);


    vector<vector<int>> v;
    v.push_back({-1});

    for(int i=0;i<q;i++) {
        vector<vector<int>> v2;

        for(ull j=0;j<v.size();j++) {
            vector<int> x = v[j];
            for(int nw = x.back()+1;nw<n;nw++) {
                x.push_back(nw);
                v2.push_back(x);
                x.pop_back();
            }
        }

        swap(v2,v);
    }

    for(ull i=0;i<v.size();i++) {
        ll x = 0;
        for(ull j=1;j<v[i].size();j++) x|=(1ll<<v[i][j]);

        r.push_back(m^x);
    }

    sort(r.begin(),r.end());

    return r;
}

int main() { _
    int g;
    cin >> n >> g;

    string m;
    ll q;
    cin >> m >> q;
    
    vector<ll> ok = brute(m,q);

    for(int c=1;c<g;c++) {
        cin >> m >> q;

        vector<ll> aux = brute(m,q);

        vector<ll> nv;

        for(ull i=0,j=0;i<ok.size() and j<aux.size();) {
            if(ok[i]<aux[j]) i++;
            else if(ok[i]>aux[j]) j++;
            else {
                nv.push_back(ok[i]);
                i++;
                j++;
            }
        }

        swap(ok,nv);
    }

    cout << ok.size() << '\n';

    return 0;
}
