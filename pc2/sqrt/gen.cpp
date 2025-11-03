#include <bits/stdc++.h>

using namespace std;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int main(int argc, char**argv) {
    int n = uniform(2,1000);
    cout << n << '\n';

    for(int i=0;i<n;i++) cout << uniform(1,1000) << ' ';
    cout << '\n';

    int q = uniform(1,500);
    cout << q << '\n';

    for(int i=0;i<q;i++) {
        int l = uniform(1,n-1);
        int r = uniform(l+1,n);
        cout << l << ' ' << r << '\n';
    }

    return 0;
}