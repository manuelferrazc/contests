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
    int t, l, max;
    cin >> t;

    while(t--) {
        max = INT_MIN;
        cin >> l;
        vi v(l);
        for(int i=0;i<l;i++) cin >> v[i];
        
        for(int i=0;i<l;i++) {
            for(int j=i;j<l;j++) {
                if(i==0 and j==l-1) continue;
                if(j==l-1) max = ::max(max,v[j]+v[i-1]);
                else max = ::max(max,v[l-1]+v[j]);
            }
        }

        std::cout << max << endl;
    }

    return 0;
}