#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    vector<ll> v(n);
    map<ll,int> qtd;
    
    for(ll &i:v) {
        cin >> i;
        qtd[i]++;
    }

    ll a=0,b=0;

    auto it = qtd.begin();

    vector<ll> ex;
    map<ll,int> qtd2;

    qtd2.insert(*it);
    int val = it->ff+1;

    for(auto i = next(it);i!=qtd.end();i++,it++) {
        if(i->ff!=it->ff+1) {
            int times = i->ss;
            if((i->ff-it->ss-1)&1) {
                ex.push_back(i->ff-it->ss-1);
                
            }

            int sla = (i->ff-it->ff-1)/2;
            a+=times*sla;
            b+=times*sla;
        }

        // cout << val << ' ' << it->ss << '\n';
        qtd2.insert({val,i->ss});
        val++;
    }

    sort(ex.begin(),ex.end());
    bool alice = 1;
    while(ex.size()) {
        if(alice) a+=ex.back();
        else b+=ex.back();

        alice = not alice;
        ex.pop_back();
    }

    // cout << a << ' ' << b << '\n';


    for(auto [val,times]:qtd2) {
        // cout << val << ' ' << times << ", a e b = " << a << ' ' << b << '\n';
        a+=(val/2)*times;
        b+=(val/2)*times;



        if(val&1) {
            if(alice) a+=times;
            else b+=times;

            alice = not alice;
        }

    // cout << val << ' ' << times << ", a e b = " << a << ' ' << b << '\n';
    //     cout << "\n\n";
    }

    cout << a << ' ' << b << '\n';
    // exit(0);
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
