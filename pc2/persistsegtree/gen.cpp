#include <bits/stdc++.h>

using namespace std;


mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int main(int argc, char**argv) {
    int n = uniform(1,100), q = uniform(1,100);
    cout << n << ' ' << q << '\n';

    int n2 = n;
    while(n--) cout << uniform(1,200) << ' ';
    cout << '\n';

    while(q--) {
        int l = uniform(1,n2);
        int r = uniform(l,n2);

        cout << l << ' ' << r << '\n';
    }

    return 0;
}