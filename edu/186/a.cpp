#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int solve() {
    int n;
    string s;
    cin >> n >> s;

    bool t5=false;
    int qtd=4;

    for(int i=0;i+3<n;i++) {
        if(s[i]=='2' and s[i+1]=='0' and s[i+2]=='2' and s[i+3]=='5') {
            t5 = true;
            qtd = min(qtd,1);
        }
        qtd = min(qtd,4-(s[i]=='2')-(s[i+1]=='0')-(s[i+2]=='2')-(s[i+3]=='6'));
    }

    if(t5) return qtd;
    return 0;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
