#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n,k;

void print(const vector<int> &v, char c=' ') {
    cout << "v: ";
    for(int i:v) cout << i << ' ';
    cout << c;
}

void operation(vector<int> &v) {
    sort(v.begin(),v.end());
    // cout << "BEGIN:\n";
    // print(v,'\n');
    set<int> nt;
    for(int i=0;i<=n+1;i++) nt.insert(i);
    vector<int> qtd(n+1,0);

    for(int i:v) {
        qtd[i]++;
        nt.erase(i);
    }

    for(int &i:v) {
        if(qtd[i]==1) i = min(i,*nt.begin());
        else i = *nt.begin();
    }

    
    // print(v,'\n');

}

ll soma(const vector<int> &v) {
    ll r=0;
    for(int i:v) r+=i;
    return r;
}

void solve() {
    cin >> n >> k;

    vector<int> v(n);
    for(int &i:v) cin >> i;
    
    ll sa = soma(v);
    operation(v);
    
    if(k==2) operation(v);
    if(k<=2) cout << soma(v) << '\n'; 
    else {
        map<ll,int> m;
        m[sa] = 0;
        m[soma(v)] = 1;
        for(int i=2;;i++) {
            operation(v);
            // cout << "DEBUG ";
            // print(v);   
            ll s = soma(v);// << '\n';
            // cout << "soma: " << soma(v) << '\n';
            // cout << "variavel: " << s << '\n';


            if(m.count(s)) {
                if((i&1)==(m[s]&1)) {
                    if((i&1)==(k&1)) cout << s << '\n';
                    else {
                        operation(v);
                        ll s = soma(v);// << '\n';
                        cout << s << '\n';
                    }
                } else cout << s << '\n';

                return;
            } else m[s] = i;

            if(i==k) {
                cout << s << '\n';
                return;
            }
        }
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
