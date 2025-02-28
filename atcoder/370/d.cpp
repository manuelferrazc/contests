#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

struct cell {
    bool m = true;
    int c = -1, b = -1, e = -1, d = -1;
};

int main() { _
    int l,c,q;
    cin >> l >> c >> q;

    vector<vector<cell>> v(l,vector<cell>(c));

    int m = l*c, x, y;

    while(q--) {
        cin >> x >> y;
        x--;
        y--;

        if(v[x][y].m) {
            m--;
            v[x][y].m = false;
            continue;
        }

        // cima
        for(int i=v[x][y].c==-1? y-1 : v[x][y].c-1;i>=0;i--) {
            if(v[x][i].m) {
                m--;
                v[x][i].m = false;
                v[x][y].c = i;
                break;
            }

            if(v[x][i].c!=-1) i = v[x][i].c;
        }

        // baixo
        for(int i=(v[x][y].b==-1? y+1 : v[x][y].b+1);i<c;i++) {
            if(v[x][i].m) {
                m--;
                v[x][i].m = false;
                v[x][y].b = i;
                break;
            }
            if(v[x][i].b!=-1) i = v[x][i].b;
        }

        // direita
        for(int i=v[x][y].d==-1?x+1:v[x][y].d+1;i<l;i++) {
            if(v[i][y].m) {
                m--;
                v[i][y].m = false;
                v[x][y].d = i;
                break;
            }

            if(v[i][y].d!=-1) i = v[i][y].d;
        }

        // esquerda
        for(int i=v[x][y].e==-1?x-1:v[x][y].e-1;i>=0;i--) {
            if(v[i][y].m) {
                m--;
                v[i][y].m = false;
                v[x][y].e = i;
                break;
            }

            if(v[i][y].e!=-1) i = v[i][y].e;

        }
    }

    cout << m << '\n';

    return 0;
}