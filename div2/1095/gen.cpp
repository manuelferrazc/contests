#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int main(int argc, char**argv) { _

    int n = uniform(1,1000);

    cout << 1 << '\n' << n << '\n';
    for(;n--;) cout << uniform(0,20000) << ' ';
    cout << '\n';
    


    return 0;
}
