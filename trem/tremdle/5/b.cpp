#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    
}

int main() { _
    int n;
    cin >> n;
    vector<string> v(n);
    for(string &s:v) cin >> s;
    int ans=0;
    for(int i=0;i<n;i++) {
        int l=0,c=0;
        for(int j=0;j<n;j++) {
            if(v[i][j]=='C') l++;
            if(v[j][i]=='C') c++; 
        }

        ans+=l*(l-1)/2;
        ans+=c*(c-1)/2;
    }

    cout << ans << '\n';
    return 0;
}
