#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char * yes = "YES\n";
const char * no = "NO\n";

int main() { _
    ll n,m,a,b;
    cin >> n >> n >> m >> a >> b;

    bool p[n][m];
    fill(&p[0][0],&p[n-1][m-1]+1,false);

    ll qtd = 0;
    int x = 0,y=0;
    
    for(ll i=0;i<3*n*m;i+=2) {
        if(p[x][y]==0) {
            p[x][y] = true;
            qtd++;
        }
        x+=a;
        x%=n;

        if(p[x][y]==0) {
            p[x][y] = true;
            qtd++;
        }
        y+=b;
        y%=m;

        if(qtd==n*m) {
            cout << "YES\n";
            return 0;
        }
    }

    fill(&p[0][0],&p[n-1][m-1]+1,false);
    qtd = 0;
    x = 0;
    y = 0;

    for(ll i=0;i<n*n*m*m*100;i+=2) {
        if(p[x][y]==0) {
            p[x][y] = true;
            qtd++;
        }
        y+=b;
        y%=m;
        
        if(p[x][y]==0) {
            p[x][y] = true;
            qtd++;
        }
        x+=a;
        x%=n;

        if(qtd==n*m) {
            cout << "YES1\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}
