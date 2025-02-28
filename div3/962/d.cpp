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


int main() { 
    ll t,n,x,m;
    cin >> t;
    ll r;
    while(t--) {
        r=0;
        cin >> n >> x;
        for(ll a=1;(a<x) and (a<n);a++) {
            for(ll b=a;(b<x) and (b<n);b++) {
                if(((a*b)>=n) or ((a+b)>=x)) break;
                for(ll c=b;(c<x) and (c<n);c++) {
                    m=a*b+a*c+b*c;
                    if((m>n) or ((a+b+c)>x)) break;
                    if(a==b) {
                        if(a==c) r++;
                        else r+=3;
                    } else if((a==c) or (b==c)) r+=3;
                    else r+=6;
                }
            }
        }
        cout << r << '\n';
    }

    return 0;
}