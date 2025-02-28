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
typedef pair<int,int> pii;


int main() { _
    int t; cin >> t;

    while(t) {
        t--;
        ll n, total=0; cin >> n;
        vector<int> v(n);
        ll maior1=-2'000'000'000, atual=0;
        ll maior2=maior1;
        for(int i=0;i<n;i++) {
            cin >> v[i];
            total+=v[i];
        }

        for(int i=1;i<n;i++) {
            atual+=v[i];
            maior1=max(maior1,atual);
            if(atual<0) atual=0;
        }
        atual =0;
        for(int i=0;i<n-1;i++) {
            atual+=v[i];
            maior2=max(maior2,atual);
            if(atual<0) atual=0;
        }
        
        ll maior = max(maior1,maior2);

        if(total>maior) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}