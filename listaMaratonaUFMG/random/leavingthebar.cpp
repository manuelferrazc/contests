#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(){
	uniform_int_distribution<int> uid(0, 100000000);
	return uid(rng);
}

ll f(ll a, ll b) {
    return a*a+b*b;
}

int main() { _
    int n;
    cin >> n;
    srand(uniform());

    vector<pair<int,pair<int,int>>> v(n);
    vector<bool> ans(n);
    for(int i=0;i<n;i++) {
        cin >> v[i].ss.ff >> v[i].ss.ss;
        v[i].ff = i;
    }

    while(true) {
        ll x=0,y=0;
        shuffle(v.begin(),v.end(),rng);

        for(int i=0;i<n;i++) {
            if(f(x+v[i].ss.ff,y+v[i].ss.ss)<f(x-v[i].ss.ff,y-v[i].ss.ss)) {
                ans[v[i].ff] = true;
                x+=v[i].ss.ff;
                y+=v[i].ss.ss;
            } else {
                ans[v[i].ff] = false;
                x-=v[i].ss.ff;
                y-=v[i].ss.ss;
            }
        }
        if(x*x+y*y<=2250000000000LL) {
            for(int i=0;i<n;i++) {
                if(ans[i]) cout << "1 ";
                else cout << "-1 ";
            }
            cout << '\n';
            return 0;
        }
    }

    return 0;
}
