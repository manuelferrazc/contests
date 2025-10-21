#include <bits/stdc++.h>

using namespace std;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

using ll = long long;

const ll mn = -50000;
const ll mx = 50000;
const ll mxa = 50000;
const ll mxb = 50000;

int main(int argc, char**argv) {
    int n = uniform(1,50), q = uniform(1,50);

    cout << n << ' ' << q << '\n';

    while(n--) {
        ll l = uniform(mn,mx-1);
        ll r = uniform(l+1,mx);
        ll a = uniform(-mxa,mxa);
        ll b = uniform(-mxb,mxb);

        cout << l << ' ' << r << ' ' << a << ' ' << b << '\n';
    }
    
    while(q--) {
        int op = uniform(0,1);
        cout << op << ' ';

        if(op) {
            ll pos = uniform(mn,mx);
            cout << pos << '\n';
        } else {
            ll l = uniform(mn,mx-1);
            ll r = uniform(l+1,mx);
            ll a = uniform(-mxa,mxa);
            ll b = uniform(-mxb,mxb);

            cout << l << ' ' << r << ' ' << a << ' ' << b << '\n';
        }
    }

    return 0;
}