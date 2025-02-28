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

string s;

int atualiza_l(int l, int r, int n, int x, int y) {
    return (l*y+((r*x)/n)+999999999)%(n+1);
}

int atualiza_r(int l, int r, int n, int x, int y) {
    return max(l,(r*x+y+999'999'999)%(n+1));
}

int contar(int l, int r) {
    int ret = 0;
    l--;r--;
    while(l<r) {
        if(s[l]!=s[r]) ret++;
        l++;
        r--;
    }

    return ret;
}

int main() { _
    int resp=0;
    int lixo, perguntas, l, r, x, y;
    cin >> lixo >> perguntas;

    getchar();
    s.assign(lixo,' ');
    for( int i=0;i<lixo;i++) cin >> s[i];
    cin >> l >> r >> x >> y;

    while(perguntas) {
        perguntas--;
        resp += contar(l,r);

        l = atualiza_l(l,r,lixo,x,y);
        r = atualiza_r(l,r,lixo,x,y);
    }

    cout << resp << endl;

    return 0;
}