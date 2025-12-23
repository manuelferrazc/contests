#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char* yes = "Yes\n";
const char* no = "No\n";
const char* test = "Ababa\n";

const char * solve() {
    int n,x,y;
    string s;
    cin >> n >> x >> y >> s;

    int u=0;
    for(int i=0;i<n;i++) if(s[i]=='1') u++;

    int v[n];
    ll su=0;
    for(int i=0;i<n;i++) {
        cin >> i[v];
        su+=v[i];
    }

    // n tenho eleitores suf
    if(su>x+y) return no;

    // n tenho y suficiente pra b vencer u vezes ou x suficiente pra a vencer z vezes 
    if(u>y or n-u>x) return no;

    // se a e b conseguem vencer o suficiente, e o outro n ganha nunca
    if(u==n and x>y or u==0 and y>x) return yes;

    // se só um ganha, mas tem q dar empate alguma vez, não
    if(u==n or not n) return no;

    
    if((u>y-x) or (n-u>x-y)) return no;

    return yes;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
