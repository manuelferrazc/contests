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
    srand(uniform(1,100));

    int n = 2+ rand()%10;

    vector<int> v(n);
    iota(v.begin(),v.end(),1);

    cout << 1 << ' ' << n << '\n';
    for(int i=n;i;i--) {
        int p = rand()%i;
        swap(v[i-1],v[p]);
        cout << v.back() << ' ';
        v.pop_back();
    }

    cout << '\n';


    return 0;
}
