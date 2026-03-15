#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int mi(string s, int n) {
    int ans = 0;

    for(int i=0;i<n;i++) {
        int j = i+1;
        int qtd=1;
        if(s[i]=='0') continue;
        while(j<n and (s[j]=='1' or (j<n-1 and s[j+1]=='1'))) {
            j++;
            qtd++;
        }

        if(qtd<3) ans+=qtd;
        else if(qtd&1) ans+=qtd/2+1;
        else ans+=(qtd+2)/2;
        i=j;
        // cout << qtd << ' ';
    }

    return ans;
}

int mx(string s, int n) {
    int ans = n;
    if(s[0]=='0') ans--;
    if(s.back()=='0') ans--;

    for(int i=1;i<n-1;i++) {
        if(s[i]=='0' and (s[i-1]=='0' or s[i+1]=='0')) ans--;
    }

    return ans;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    cout << mi(s,n) << ' ';
    cout << mx(s,n) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
