#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,k;
    string s;
    cin >> n >> k >> s;

    string out(n,'+');

    int a=0,b=n-1,qb=0;

    for(char c:s) {
        if(c=='0') out[a++] = '-';
        else if(c=='1') out[b--] = '-';
        else qb++;
    }

    if(b-a+1>qb) {
        for(int i=0;i<qb;i++) out[a+i]='?';
        for(int i=0;i<qb;i++) out[b-i]='?';
    } else {
        for(int i=a;i<=b;i++) out[i] = '-';
    }

    cout << out << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
