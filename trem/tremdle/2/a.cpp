#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll k,n,w;
    cin >> k >> n >> w;

    cout << max(0LL,((w+1)*k*w)/2-n) << '\n';
    return 0;
}
