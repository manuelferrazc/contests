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
    int t,suf,pref,n;
    cin >> t;

    while(t--) {
        cin >> n >> pref >> suf;

        vi v(n+1,1);
        for(int i=pref+1;i<=n;i++) v[i] = -1;

        for(int i=1;i<(pref-suf);i++) {
            v[suf+i] = -1;
        }

        for(ull i=1;i<v.size();i++) cout << v[i] << ' ';
        cout << '\n';
    }
    
    return 0;
}