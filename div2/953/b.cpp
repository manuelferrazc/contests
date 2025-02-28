#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
#define INF INT_MAX
#define LINF LONG_MAX
#define LLINF LONG_LONG_MAX
typedef long long ll;
typedef long l;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<int> vi;
typedef pair<int,int> pii;


int main() { _
    ll t,n,a,b;
    ll k,max;
    cin >> t;

    while(t--) {
        cin >> n >> a >> b;
        k = b - a;
        k = min(k,min(n,b));
        if(k<=0) max = a*n;
        else max = (n-k)*a + b*k-(k*(k-1))/2;

        cout << max << '\n';
    }

    return 0;
}